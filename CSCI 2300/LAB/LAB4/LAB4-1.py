import numpy as np
import time

def normal(n, X, Y):
    Z=[]
    for i in range(n):
        row=[]
        for j in range(n):
            ans=0
            for k in range(n):
                ans+=X[i][k]*Y[k][j]
            row.append(ans)
        Z.append(row)
    return Z

def strassen(n, X, Y):
    if n==1:
        Z=X[0][0]*Y[0][0]
        return np.array(Z)
    else:
        A=np.split(np.hsplit(X,2)[0],2)[0]
        B=np.split(np.hsplit(X,2)[1],2)[0]
        C=np.split(np.hsplit(X,2)[0],2)[1]
        D=np.split(np.hsplit(X,2)[1],2)[1]
        E=np.split(np.hsplit(Y,2)[0],2)[0]
        F=np.split(np.hsplit(Y,2)[1],2)[0]
        G=np.split(np.hsplit(Y,2)[0],2)[1]
        H=np.split(np.hsplit(Y,2)[1],2)[1]
        
        P1=strassen(n/2,A,(F-H))
        P2=strassen(n/2,(A+B),H)
        P3=strassen(n/2,(C+D),E)
        P4=strassen(n/2,D,(G-E))
        P5=strassen(n/2,(A+D),(E+H))
        P6=strassen(n/2,(B-D),(G+H))
        P7=strassen(n/2,(A-C),(E+F))
        
        O=P5+P4-P2+P6
        P=P1+P2
        Q=P3+P4
        R=P1+P5-P3-P7
        top=np.hstack((O,P))
        bottom=np.hstack((Q,R))
        return np.vstack((top,bottom))

        
    

if __name__ == '__main__':
    n=int(raw_input('Enter n ==> '))
    X=np.random.rand(n,n)
    Y=np.random.rand(n,n)
    start1=time.time()
    Z=normal(n,X,Y)
    end1=time.time()
    #Zbar=np.dot(X,Y)
    start2=time.time()
    Zstr=strassen(n,X,Y)
    end2=time.time()
    time1=end1-start1
    time2=end2-start2
    print np.matrix(Z)
    #print Zbar
    print Zstr
    print 'time for normal method: %f'%time1
    print 'time for strassen method: %f'%time2