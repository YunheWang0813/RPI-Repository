def closest1(L):
    if len(L)<2:
        return None, None
    close1=abs(L[0]-L[1])
    close2=L[0],L[1]
    for i in range(len(L)):
        for j in range(len(L)):
            if i!=j and abs(L[i]-L[j])<close1:
                close1=abs(L[i]-L[j])
                close2=L[i],L[j]
    return close2

if __name__=='__main__':
    L3=[67,23]
    L4=[23,67]
    L1 = [-2,20,299,5,697,1990]
    L2 = [-2,5,20,299,1990,697]
    L5 = [-2,299,1990,697,20,5]    
    print closest1(L3)
    print closest1(L4)
    print closest1(L1)
    print closest1(L2)
    print closest1(L5)