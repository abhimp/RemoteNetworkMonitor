import SimpleHTTPServer
import BaseHTTPServer
import SocketServer
import os
import time
import json
import sys

PORT = 8000

class IfcHandler(SimpleHTTPServer.SimpleHTTPRequestHandler) :
    x = []
    stats = {}
    last_bytes = {}
    lastTime = ""

    def getIfcs(self):
        ifpath = "/tmp/viscous_ifconf/"
        ifcNames = []
        if os.path.exists(ifpath):
            for con in os.listdir(ifpath):
                with open(os.path.join(ifpath, con)) as fp:
                    for line in fp:
                        key,val = line.strip().split("=")
                        if key == "iface":
                            ifcNames += [val]
            return ifcNames
        ifcNames = []
        return [x for x in os.listdir("/sys/class/net/") if x!="lo"]

    def parseGet(self):
        query = []
        qsnLoc = self.path.find("?")
        if qsnLoc < 0:
            return query, ""
        queryStr = self.path[qsnLoc+1:]
        for x in queryStr.split("&"):
            amp = x.find("=")
            if amp < 0:
                query += [[amp]]
            key = x[:amp]
            val = x[amp+1:]
            query += [[key, val]]
        return query, queryStr


    def do_GET(self):
        now = time.time()
        q,qs = self.parseGet()
        data = {"time": now, "ifcs":{}, "query":qs}
        for ifc in self.getIfcs():
            tx_bytes = open(os.path.join("/sys/class/net/", ifc, "statistics/tx_bytes")).read().strip()
            rx_bytes = open(os.path.join("/sys/class/net/", ifc, "statistics/rx_bytes")).read().strip()
            data["ifcs"][ifc] = {"tx_bytes" : tx_bytes, "rx_bytes" : rx_bytes}

        # print self.rfile.read()
        # print self.path
        jdata = json.dumps(data)
        self.send_response(200)
        self.send_header("Content-Length", len(jdata))
        self.send_header("Content-Type", "application/json")
        self.send_header('Access-Control-Allow-Origin', '*')
        # self.send_header("Last-Modified", self.date_time_string(fs.st_mtime))
        self.end_headers()
        self.wfile.write(jdata)
        # return jdata



def getSpeed():
    tmNow = time.time()
    tm = tmNow - firstTime
    tmDiff = tmNow - lastTime
    lastTime = tmNow

    for ifc in interfaces:
        stat_path = path_t%ifc
        if not os.path.exists(stat_path):
            continue
        value = getValue(stat_path)
        diff = value - last_bytes[ifc]
        last_bytes[ifc] = value
        diff = diff/(1000*tmDiff)
        y = stats.setdefault(ifc, [])
        y += [diff]
    x += [tm]


Handler = IfcHandler

if len(sys.argv) > 1:
    PORT = int(sys.argv[1])

httpd = SocketServer.TCPServer(("", PORT), Handler)

print "serving at port", PORT
httpd.serve_forever()
