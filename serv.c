#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>
#include <assert.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/wait.h>

#include "files.h"

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

#define ALARM_INTERVAL 1000
#define BUF_LEN 4096

char PERIODIC_DATA[2][BUF_LEN];
int PERIODIC_DATA_LEN[2] = {0,0};
char PERIODIC_DATA_CONSUMED[2] = {1,0}; //to force first period load
char PERIODIC_DATA_INDEX = 0;
char PERIODIC_DATA_BUSY = 0;
char PERIOD_COUNT = 0;


pid_t childpid;
int exitSignal = 0;




void produceInfoDataPeriodically(int signal);
void respond(int sockFd, struct sockaddr_in clientaddr, socklen_t addrlen);
void runServerForever(int listenfd);


int startServer(const char *port) {
	int listenfd;
    struct sockaddr_in serv_addr;
    int portno;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        perror("Error in socket()");
        exit(1);
    }

    portno = atoi(port);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    int option = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0){
        perror("setsockopt()");
    }

    if (bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        perror("Error in bind()");
        exit(2);
    }

    printf("Server listening on port %d\n", portno);
    if ( listen(listenfd, 10) != 0 )
    {
        perror("listen() error");
        exit(1);
    }

    return listenfd;
}

void term_init(int signum)
{
    if(childpid) {
        kill(childpid, SIGINT);
        exitSignal = 1;
    }
    else{
        exit(0);
    }
    printf("Caught terminit from childpid: %d, pid: %d, exitSignal=%d\n", childpid, getpid(), exitSignal);
}

void serve_forever(const char *PORT) {
    int listenfd;
    int wstatus;


    listenfd = startServer(PORT);

    if (signal(SIGTERM, term_init) == SIG_ERR) {
        perror("Unable to catch SIGTERM");
        exit(1);
    }
    if (signal(SIGINT, term_init) == SIG_ERR) {
        perror("Unable to catch SIGINT");
        exit(1);
    }


#ifdef NOFORK
    runServerForever(listenfd);
#else
    // ACCEPT connections
    while(1) {
        childpid = 0;
        childpid = fork();
        if(childpid < 0){
            perror("fork()");
            break;
        }
        if(childpid == 0) {
            runServerForever(listenfd);
            exit(0);
        }

        pid_t pid = wait(&wstatus);
        if(childpid != pid) {
            fprintf(stderr, "pid not matching\n");
        }

        if(exitSignal) {
            printf("ExitSignal recved\n");
            break;
        }

    }
#endif

    close(listenfd);
}

void setupTimer() {
    if (signal(SIGALRM, (void (*)(int)) produceInfoDataPeriodically) == SIG_ERR) {
        perror("Unable to catch SIGALRM");
        exit(1);
    }
    struct itimerval it_val;
    it_val.it_value.tv_sec = ALARM_INTERVAL/1000;
    it_val.it_value.tv_usec = (ALARM_INTERVAL*1000) % 1000000;
    it_val.it_interval = it_val.it_value;
    if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
        perror("error calling setitimer()");
        exit(1);
    }
}

void runServerForever(int listenfd) {
    struct sockaddr_in clientaddr;
    socklen_t addrlen;
    char c;
    int clientFd;

    setupTimer();

    while (1)
    {
        addrlen = sizeof(clientaddr);
        clientFd = accept (listenfd, (struct sockaddr *) &clientaddr, &addrlen);
        if(clientFd <= 0)
            continue;

        respond(clientFd, clientaddr, addrlen);
        close(clientFd);

    }
}


int sprintfTime(char *buf, size_t len) {
    struct timeval start;
    gettimeofday(&start, NULL);
    return snprintf(buf, len, "%lu.%06lu", start.tv_sec, start.tv_usec);
}

int readLong(char *fpath, char *buf, size_t len) {
    int fd;
    fd = open(fpath, O_RDONLY);

    buf[0] = '0';
    buf[1] = 0;
    if(fd < 0)
        return 1;

    int rd = read(fd, buf, len);
    if (rd <= 0)
        return 1;
    int ln = rd;
    while(ln){
        if(isdigit(buf[ln - 1])){
            break;
        }
        ln--;
    }
    buf[ln] = 0;
    close(fd);
    return ln;
}

int sprintInterface(char *buf, size_t len, char *ifcname) {
    char fpath[1024];
    char dt[1024];
    int64_t tx_bytes, rx_bytes;

    int rd = 0;
    int wrote = 0;

    snprintf(fpath, 1024, "/sys/class/net/%s/statistics/tx_bytes", ifcname);
    rd = snprintf(buf + wrote, len - wrote, "\"tx_bytes\":");
    wrote += rd;
    rd = readLong(fpath, buf + wrote, len - wrote);
    wrote += rd;

    buf[wrote++] = ',';

    snprintf(fpath, 1024, "/sys/class/net/%s/statistics/rx_bytes", ifcname);
    rd = snprintf(buf + wrote, len - wrote, "\"rx_bytes\":");
    wrote += rd;
    rd = readLong(fpath, buf + wrote, len - wrote);
    wrote += rd;

    return wrote;
}

int isDirectory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

int sprintfStat(char *buf, size_t len) {
    char *path = "/sys/class/net/";
    char dpath[1024];
    DIR *folder;
    folder = opendir(path);
    if(folder == NULL) {
        perror("opendir");
        return 0;
    }

    int rd = 0;
    int wrote = 0;
    struct dirent *entry;

    buf[wrote++] = '{';
    int cnt = 0;
    while( (entry=readdir(folder)) )
    {
        snprintf(dpath, 1024, "%s%s", path, entry->d_name);
        if(!isDirectory(dpath) || strcmp("lo", entry->d_name) ==0 || entry->d_name[0] == '.')
            continue;

        if (cnt > 0) buf[wrote++] = ',';
        rd = snprintf(buf + wrote, len - wrote, "\"%s\": {", entry->d_name);
        wrote += rd;
        rd = sprintInterface(buf + wrote, len - wrote, entry->d_name);
        wrote += rd;
        buf[wrote++] = '}';
        cnt ++;
    }

    if(closedir(folder) < 0)
        perror("closedir()");

    buf[wrote++] = '}';

    return wrote;
}

int sprintfNetworkStat(char *response, int retlen, char *query) {
    int rd = 0;
    int wrote = 0;

    response[wrote++] = '{';

    rd = snprintf(response + wrote, retlen - wrote, "\"time\":");
    wrote += rd;
    rd = sprintfTime(response + wrote, retlen - wrote);
    wrote += rd;
    response[wrote++] = ',';

    rd = snprintf(response + wrote, retlen - wrote, "\"ifcs\":");
    wrote += rd;
    rd = sprintfStat(response + wrote, retlen - wrote);
    wrote += rd;
    response[wrote++] = ',';

    rd = snprintf(response + wrote, retlen - wrote, "\"query\": \"%s\"}", query);
    wrote += rd;

    response[wrote] = 0;

    return wrote;
}

void produceInfoDataPeriodically(int signal) {
    PERIOD_COUNT += 1;
    if (!PERIODIC_DATA_CONSUMED[PERIODIC_DATA_INDEX]) return;

//     printf("Reading periodially\n");
    PERIODIC_DATA_BUSY = 1;
    int nextPeriod = 1 - PERIODIC_DATA_INDEX; // zero or one
    PERIODIC_DATA_LEN[nextPeriod] = sprintfNetworkStat(PERIODIC_DATA[nextPeriod], sizeof(PERIODIC_DATA[nextPeriod]), ""); //query is no longer useful.
    PERIODIC_DATA_CONSUMED[nextPeriod] = 0;
    PERIODIC_DATA_INDEX = nextPeriod;
    PERIODIC_DATA_BUSY = 0;
}

int getPeriodicData(char **data) {
    char periodIndex = PERIODIC_DATA_INDEX;
    *data = PERIODIC_DATA[periodIndex];
    PERIODIC_DATA_CONSUMED[periodIndex] += 1;
    return PERIODIC_DATA_LEN[periodIndex];
}

void respondWithHeaders(int sockFd, char *path/*, char *query */) {
    char header[BUF_LEN];
    int hcapa = BUF_LEN;
    char *response;
    int clen = 0;
    int findex = -1;
    int wrote = 0;
    char *mime = "application/json";

    if(path[0] == '/' && path[1]) {
        int i;
        for(i = 0; files[i][0]; i++){
            if(strcmp(files[i][0], path+1) == 0) {
                findex = i;
                break;
            }
        }
    }

    if(findex > -1) {
        clen = atoi(files[findex][2]);
        response = files[findex][1];
        mime = files[findex][3];
    }
    else{
        clen = getPeriodicData(&response);
    }



    wrote += snprintf(header + wrote, hcapa - wrote, "HTTP/1.0 200 OK\r\n");
    wrote += snprintf(header + wrote, hcapa - wrote, "Server: AONGBONG\r\n");
    wrote += snprintf(header + wrote, hcapa - wrote, "Content-Length: %d\r\n", clen);
    wrote += snprintf(header + wrote, hcapa - wrote, "Access-Control-Allow-Origin: *\r\n");
    wrote += snprintf(header + wrote, hcapa - wrote, "Content-Type: %s\r\n", mime);
    wrote += snprintf(header + wrote, hcapa - wrote, "\r\n");
    header[wrote] = 0;

    write(sockFd, header, wrote);

    write(sockFd, response, clen);
}

/*
 * In simple application like this, I only need to read the querystring in the
 * first line of the request. I can safely ignore each and every line here.
 * Once I read the querystring, I can start responding without any hesitation.
 *
 * To read querystring, I utilize fdopen command to wrap socket with buffer reader
 * and perform getdelim on the socket.
 */
void respond(int sockFd, struct sockaddr_in clientaddr, socklen_t addrlen) {
    char *buf;
    int rcvd, bytes_read;
    FILE *fp;

    char rbuf[BUF_LEN]; //TODO add dynaic memory to support extreamly large num of interfaces
    char *response = rbuf;


    fp = fdopen(sockFd, "r+");
    if(!fp){
        perror("fdopen()");
        close(sockFd);
        return;
    }

    buf = malloc(BUF_LEN);
    size_t buflen = BUF_LEN;

    size_t readline = getdelim(&buf, &buflen, '\n', fp);

    if(buf[readline-1] != '\n' || buf[readline-2] != '\r'){
        fprintf(stderr, "Some error");
        fclose(fp);
        free(buf);
        return;
    }

//     char *query = strchr(buf, '?');
    char *method = strtok(buf, " ");
    char *path = strtok(NULL, "? ");
//     query = query ? strtok(NULL, " ") : NULL;

    respondWithHeaders(sockFd, path);

    free(buf);
    fclose(fp);

}



int main(int argc, char *argv[]) {
    char *port = "9889";
    if(argc > 1)
        port = argv[1];
    serve_forever(port);
}
