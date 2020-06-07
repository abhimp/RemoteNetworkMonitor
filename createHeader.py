### current bpython session - make changes and save to reevaluate session.
### lines beginning with ### will be ignored.
### To return to bpython without reevaluating make no changes to this file
### or save an empty file.
p = "flot/jquery.js flot/jquery.flot.js plugin/curvedLines.js plugin/jquery.flot.axislabels.js plugin/jquery.modal.min.js plugin/jquery.modal.min.css chart.html".split(" ")
p[0]

mimes = {
        "js": "application/javascript",
        "css": "text/css",
        "html": "text/html"
        }
### 'flot/jquery.js'
with open("files.h", "w") as wfp:
    for i, f in enumerate(p):
        stlen = 0
        print("#define DATA_"+str(i), " \\", file=wfp)
        with open(f) as fp:
            for l in fp:
                st = '"'+l.replace('\\', '\\\\').replace('"', '\\"').replace('\n','\\n') + '"'
                try:
                    stlen += len(eval(st))
                except Exception as e:
                    print(st)
                    raise e
                print(st + ' \\', file=wfp)

        print("\n", file=wfp)
        print("#define DATA_LEN_"+str(i), f"\"{stlen}\"\n", file=wfp)
    print("char *files[][4] = {", file=wfp)
    for i, f in enumerate(p):
        mime = "application/octate-stream"
        ext = f.rfind(".")
        if ext >= 0:
            mime = mimes.get(f[ext+1:].lower(), mime)
        print("\t{", '"' + f + '",', "DATA_"+str(i), ", DATA_LEN_"+str(i)+",", "\"" + mime + "\"", "}, ", file=wfp)
    print("\t{ NULL, NULL, NULL }", file=wfp)
    print("};\n", file=wfp)


