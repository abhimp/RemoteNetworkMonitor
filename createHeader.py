### current bpython session - make changes and save to reevaluate session.
### lines beginning with ### will be ignored.
### To return to bpython without reevaluating make no changes to this file
### or save an empty file.
import glob
import os
p = "flot/jquery.js flot/jquery.flot.js plugin/curvedLines.js plugin/jquery.flot.axislabels.js plugin/jquery.modal.min.js plugin/jquery.modal.min.css chart.html".split(" ")

path = {x:"jsui/"+x for x in p}

# path.update({x.replace('jsui/', ''):x for x in glob.glob("jsui/**", recursive=True) if os.path.isfile(x)})
path.update({x.replace('reactui/', ''):x for x in glob.glob("reactui/**", recursive=True) if os.path.isfile(x)})

mimes = {
        "js": "application/javascript",
        "css": "text/css",
        "html": "text/html",
        "json": "application/json",
        "txt": "text/plain",
        "map": "text/plain"
        }

path = list(path.items())
### 'flot/jquery.js'
with open("files.h", "w") as wfp:
    for i, f in enumerate(path):
        ext = f[0].rfind(".")
        ext = '' if ext < 0 else f[0][ext+1:].lower()
        if ext in ["map", 'txt']: continue
        stlen = 0
        if ext in mimes:
            print("#define DATA_"+str(i), " \\", file=wfp)
            with open(f[1]) as fp:
                print("opened", f[1])
                for l in fp:
                    st = '"'+l.replace('\\', '\\\\').replace('"', '\\"').replace('\n','\\n').replace('\r', '\\r') + '"'
                    try:
                        stlen += len(l.encode())
                    except Exception as e:
                        print(st)
                        raise e
                    print(st + ' \\', file=wfp)
        else:
            with open(f[1], "rb") as fp:
                print(f"opened as binary: ext: `{ext}`", f[1])
                print("unsigned char DATA_STR_"+str(i)+"[] = {", file=wfp)
                while True:
                    l = fp.read(255)
                    if len(l) == 0:
                        break
                    stlen += len(l)
                    print(",".join(str(x) for x in l), ",", " \\", file=wfp)

                print("};", file=wfp)
                print("#define DATA_"+str(i), "DATA_STR_"+str(i)+" \\", file=wfp)


        print("\n", file=wfp)
        print("#define DATA_LEN_"+str(i), f"\"{stlen}\"\n", file=wfp)
    print("unsigned char *files[][4] = {", file=wfp)
    for i, f in enumerate(path):
        mime = "application/octate-stream"
        ext = f[0].rfind(".")
        ext = '' if ext < 0 else f[0][ext+1:].lower()
        if ext in ["map", 'txt']: continue
        mime = mimes.get(ext, mime)
        print("\t{", '"' + f[0] + '",', "DATA_"+str(i), ", DATA_LEN_"+str(i)+",", "\"" + mime + "\"", "}, ", file=wfp)
    print("\t{ NULL, NULL, NULL }", file=wfp)
    print("};\n", file=wfp)


