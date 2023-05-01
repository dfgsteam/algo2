input()

zaehler = input().split(" ")
zaehler = [ int(x) for x in zaehler]

nenner = input().split(" ")
nenner = [ int(x) for x in nenner]

zahlen = []
for nen in nenner:
    for zae in zaehler:
        res = []
        res.append(zae/nen)
        res.append(zae)
        res.append(nen)
        zahlen.append(res)
zahlen.sort(key=lambda x:x[0])

for item in zahlen:
    print("{0}/{1}".format(item[1], item[2]))