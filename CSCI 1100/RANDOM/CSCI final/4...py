def closest(L):
    L.sort()
    minval=L[9]-L[0]
    for i in range(1,len(L)-9):
        newval=L[i+9]-L[i]
        if newval<minval:
            minval=newval
            minindex=i
    return L[minindex:minindex+10]


v = [ 1.2, 5.3, 1.1, 8.7, 9.5, 11.1, 2.5, 3, 12.2, 8.8, 6.9, 7.4,\
0.1, 7.7, 9.3, 10.1, 17, 1.1 ]

print closest(v)