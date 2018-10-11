def mystery( L, v ):
    if v < len(L):
        x = L[v]
        mystery( L, x )
        print x
    else:
        print v
        
mystery( [2, 5, 4, 7, 1], 0 )