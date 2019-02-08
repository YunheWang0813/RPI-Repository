import random
import time
import math

def method1(num1, num2):
    total=0
    while num1!=0:
        test=num1&1
        if test!=0:
            total+=num2
        num1=num1>>1
        num2=num2<<1
    return total

def method2(num1, num2):
    if num2==0:
        return 0     
    z=method2(num1, num2>>1)   
    if num2&1==0:
        return z<<1
    else:
        return num1+(z<<1)
    
def method3(x, y):
    n=max(x.bit_length(), y.bit_length())
    if n==1:
        return x*y
    if x==0 or y==0:
        return 0    
    shift=n>>1
    m=math.floor(n>>1)
    

    xl=x>>shift
    yl=y>>shift
    xr=x&(shift<<1-1)
    yr=y&(shift<<1-1)
    
    P1=method3(xl, yl)
    P2=method3(xr, yr)
    P3=method3(xl+xr, yl+yr)
    
    return P1*2**(2*m)+(P3-P1-P2)*2**m+P2



if __name__ == '__main__':
    digit=int(raw_input('Enter digit ==> '))
    
    result1=[]
    result2=[]
    result3=[]
    
    for i in range(10):
        num1=random.randint(1,10**digit)
        num2=random.randint(1,10**digit)
        
        start1=time.time()
        ans1=method1(num1, num2)
        end1=time.time()
        gottime1=end1-start1
        result1.append(gottime1)
        
        start2=time.time()
        ans2=method2(num1, num2)
        end2=time.time()
        gottime2=end2-start2
        result2.append(gottime2)
        
        start3=time.time()
        ans3=method3(num1, num2)
        end3=time.time()
        gottime3=end3-start3
        result3.append(gottime2)        
        
        
    print float(sum(result1))/len(result1)
    print float(sum(result2))/len(result2)
    print float(sum(result3))/len(result3)