import time
import matplotlib.pyplot as plt

def fib1(n):
    if n==0:
        return 0
    if n==1:
        return 1
    return fib1(n-1)+fib1(n-2)

def fib2(n):
    f=[]
    for i in range(0,n+1):
        f.append(i)
    for i in range(2,n+1):
        f[i]=f[i-1]+f[i-2]
    return f[n]
    

if __name__ == '__main__':

    
    start1=time.time()
    a=fib1(10)
    end1=time.time()
  
