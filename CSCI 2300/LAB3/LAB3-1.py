import random

def modexp(x,y,N):
    if y==0:
        return 1
    z=modexp(x,y/2,N)
    if y&1==0:
        return z**2%N
    else:
        return x*z**2%N
    
def primality2(N,k):
    judge=1
    for i in range(1,k):
        a=random.randint(1,N-1)
        num=modexp(a,N-1,N)
        if num!=1:
            judge=0
            break
    if judge==1:
        return True
    else:
        return False
        
    
if __name__ == '__main__':
    N=int(raw_input('Enter N ==> '))
    k=int(raw_input('Enter k ==> '))
    judge=primality2(N,k)
    if judge==True:
        print '%d is prime'%(N)
    else:
        print '%d is not prime'%(N)