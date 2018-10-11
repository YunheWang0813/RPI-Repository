got = [ ['tyrion',9], ['cersei',3], ['jon',8], ['daenerys',5], ['arya',9], ['sansa',6], ['tywin',4] ]

m=got[0][1]
for item in got:
    if item[1]>m:
        m=item[1]
for item in got:
    if m in item:
        print item[0],