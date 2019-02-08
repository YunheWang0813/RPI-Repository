import time
import matplotlib.pyplot as plt

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
    
    start1=time.time()
    fib2(10**6)
    b=f[10**6]
    end1=time.time()
    time1=end1-start1    
    
    start2=time.time()
    fib2(5*10**6)
    b=f[5*10**6]
    end2=time.time()
    time2=end2-start2
    
    start3=time.time()
    fib2(10*10**6)
    b=f[10*10**6]
    end3=time.time()
    time3=end3-start3
    
    start4=time.time()
    fib2(15*10**6)
    b=f[15*10**6]
    end4=time.time()
    time4=end4-start4
        
    plt.plot([1,5,10,15], [time1,time2,time3,time4])
    plt.ylabel('time of fib2')
    plt.xlabel('n value')
    plt.show()