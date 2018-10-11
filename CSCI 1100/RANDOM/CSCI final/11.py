def interleave(L1,L2):
    i=0
    L=[]
    while i<len(L1) or i<len(L2):
        if i<len(L1):
            L.append(L1[i])
        else:
            L.append('*')
        if i<len(L2):
            L.append(L2[i])
        else:
            L.append('*')
        i+=1
    print L

interleave([1,2],['a','b','c','d'])
