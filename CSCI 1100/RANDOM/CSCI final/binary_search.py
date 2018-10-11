def binary_search( x, L):
    low = 0
    high = len(L)
    while low != high:
        mid = (low+high)/2
        if x > L[mid]:
            low = mid+1
        else:
            high = mid
    return low

L = [ 1.3, 7.9, 11.2, 15.3, 18.5, 18.9, 19.7 ]