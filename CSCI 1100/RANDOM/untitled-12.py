def compare_list(L1,L2):
    out=[]
    i=0
    while i<len(L1):
        if L1[i]>L2[i]:
            out.append('1')
        elif L1[i]<L2[i]:
            out.append('2')
        else:
            out.append('0')
        i+=1
    return ''.join(out)