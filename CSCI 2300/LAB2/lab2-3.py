import math

def method3(x, y):
    n=max(x.bit_length(), y.bit_length())
    if n==1:
        return x*y
    if x==0 or y==0:
        return 0    
    shift=n/2
    m=math.floor(n/2)
    

    xl=x>>shift
    yl=y>>shift
    xr=x&(2**shift-1)
    yr=y&(2**shift-1)
    
    P1=method3(xl, yl)
    P2=method3(xr, yr)
    P3=method3(xl+xr, yl+yr)
    
    return P1*2**(2*m)+(P3-P1-P2)*2**m+P2
    


if __name__ == '__main__':
    num1=int(raw_input('Enter number1 ==> '))
    num2=int(raw_input('Enter number2 ==> '))
    ans=method3(num1, num2)
    print ans