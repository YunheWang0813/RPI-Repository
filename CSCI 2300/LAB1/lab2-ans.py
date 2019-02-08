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
    #recursive
    s1=time.time()
    a=fib1(15)
    e1=time.time()
    t1=e1-s1    
    
    s2=time.time()
    a=fib1(20)
    e2=time.time()
    t2=e2-s2
    
    s3=time.time()
    a=fib1(25)
    e3=time.time()
    t3=e3-s3
    
    s4=time.time()
    a=fib1(30)
    e4=time.time()
    t4=e4-s4
    
    s5=time.time()
    a=fib1(35)
    e5=time.time()
    t5=e5-s5
    
    plt.plot([15,20,25,30,35], [t1,t2,t3,t4,t5])
    plt.ylabel('time of fib1')
    plt.xlabel('n value')
    plt.show()
    
    
    
    #iterative
    f=[]
    
    start1=time.time()
    for i in range(10**6):
        fib2(5)
        b=f[5]
    end1=time.time()
    time1=end1-start1    
    
    start2=time.time()
    for i in range(10**6):
        fib2(10)
        b=f[10]
    end2=time.time()
    time2=end2-start2
    
    start3=time.time()
    for i in range(10**6):
        fib2(15)
        b=f[15]
    end3=time.time()
    time3=end3-start3
    
    start4=time.time()
    for i in range(10**6):
        fib2(20)
        b=f[20]
    end4=time.time()
    time4=end4-start4
    
    start5=time.time()
    for i in range(10**6):
        fib2(25)
        b=f[25]
    end5=time.time()
    time5=end5-start5
    
    plt.plot([5,10,15,20,25], [time1,time2,time3,time4,time5])
    plt.ylabel('time of fib2')
    plt.xlabel('n value')
    plt.show()
    