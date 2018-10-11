def closest2(L):
    L.sort()
    close1=abs(L[0]-L[1])
    close2=L[0],L[1]
    for i in range(len(L)-1):
        if abs(L[i]-L[i+1])<close1:
            close1=abs(L[i]-L[i+1])
            close2=L[i],L[i+1]
    return close2
    
if __name__=='__main__':
    L1=[67,23]
    L4=[23,67]
    print closest2(L1)
    print closest2(L4)