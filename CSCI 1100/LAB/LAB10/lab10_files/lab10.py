""" This is the skeleton for your lab 10. We provide a function
    here to show the use of nose.

"""

import random

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
    L1 = [67,23]
    L2 = [23,67]
    L3 = []
    for i in range(2000):
        L3.append(random.uniform(0.0,1000.0))
    print closest1(L1)
    print closest1(L2)
    print closest2(L1)
    print closest2(L2)