import sys
import glob

files = [x for x in glob.glob(sys.argv[1])]

for fil in files:
    print("========================", fil)
    with open(fil, "r") as f:
        timemap = {}
        for line in f:
            res = line.strip().split(' ')

            linetime = 0
            linedelta = 0
            haveline = False

            for part in res:
                if part.startswith('delta='):
                    linedelta = int(part.split('=')[1])
                    haveline = True
                if part.startswith('time='):
                    linetime = int(part.split('=')[1])

            if haveline:
                if linetime in timemap.keys():
                    timemap[linetime].append(linedelta)
                else:
                    timemap[linetime] = [linedelta]

    for x in sorted(list(timemap.keys())):
        print(','.join([str(y) for y in timemap[x]]))