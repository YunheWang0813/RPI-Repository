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
    Nlist=[561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973, 75361, 101101, 115921, 126217, 162401, 172081, 188461, 252601, 278545, 294409, 314821, 334153, 340561, 399001, 410041, 449065, 488881]
    for i in Nlist:
        N=i
        k=1000
        primetimes=0
        notprimetimes=0
        for i in range(1000):
            judge=primality2(N,k)
            a=random.randint(1,N-1)
            num=modexp(a,N-1,N)
            if num!=1:
                notprimetimes+=1
            else:
                primetimes+=1
        probability=float(primetimes)/k
        print 'Probability of prime: %f'%probability