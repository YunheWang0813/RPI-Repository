import timeit

def fib1(n):
    if n==0:
        return 0
    if n==1:
        return 1
    return fib1(n-1)+fib1(n-2)

def fib2(n):
    for i in range(0,n+1):
        f.append(i)
    for i in range(2,n+1):
        f[i]=f[i-1]+f[i-2]
    

if __name__ == '__main__':
    f=[]
    test=30
    a=fib1(test)
    fib2(test)
    b=f[test]
    print '1: %d 2: %d'%(a,b)