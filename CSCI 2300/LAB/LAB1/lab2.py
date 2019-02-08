import time

def fib1(n):   #recursive
    if n==0:
        return 0
    if n==1:
        return 1
    return fib1(n-1)+fib1(n-2)

def fib2(n):   #iterative
    for i in range(0,n+1):
        f.append(i)
    for i in range(2,n+1):
        f[i]=f[i-1]+f[i-2]
    

if __name__ == '__main__':
    f=[]
    test=30
    
    
    start2=time.time()
    for i in range(10**6):
        fib2(test)  #modify f[]
        b=f[test]   #b=nth fib number
    end2=time.time()
    
    print (end2-start2)
    