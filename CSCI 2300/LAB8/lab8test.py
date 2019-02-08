if __name__ == '__main__':
    x='CATAAGCTTCTGACTCTTACCTCCCTCTCTCCTACTCCTGCTCGCATCTGCTATAGTGGAGGCCGGAGCAGGAACAGGTTGAACAG'
    y='CGTAGCTTTTTGGTTAATTCCTCCTTCAGGTTTGATGTTGGTAGCAAGCTATTTTGTTGAGGGTGCTGCTCAGGCTGGATGGA'
    
    m=len(x)
    n=len(y)
    
    table=[[0]*(n+1) for i in range(m+1)]
    
    for i in range(m+1):
        table[i][0]=i
    for i in range(n+1):
        table[0][i]=i
            
    for i in range(1,m+1):
        for j in range(1,n+1):
            if y[j-1]==x[i-1]:
                table[i][j]=min(table[i-1][j]+1, table[i][j-1]+1, table[i-1][j-1])
            else:
                table[i][j]=min(table[i-1][j]+1, table[i][j-1]+1, table[i-1][j-1]+1)
                
    print table[m][n]
    print
    
    for i in table:
        print i
         
    backtrace=[]
    check=table[m][n]
    judge=[]
    
    while check!=0:
        if m>=1:
            if table[m-1][n]<check:
                check=table[m-1][n]
                backtrace.append([m-1,n])
                judge.append('U')
                m=m-1
                continue
        if n>=1:
            if table[m][n-1]<check:
                check=table[m][n-1]
                backtrace.append([m,n-1])
                judge.append('H')
                n=n-1
                continue
        check=table[m-1][n-1]
        backtrace.append([m-1,n-1])
        judge.append('N')
        m=m-1
        n=n-1
    
    judge=judge[::-1]
    
    xnew=[]
    ynew=[]
    xtrace=0
    ytrace=0
    for i in range(len(judge)):
        if judge[i]=='U':
            xnew.append(x[xtrace])
            ynew.append('-')
            xtrace+=1
        if judge[i]=='H':
            ynew.append(y[ytrace])
            xnew.append('-')
            ytrace+=1        
        if judge[i]=='N':
            xnew.append(x[xtrace])
            ynew.append(y[ytrace])
            xtrace+=1
            ytrace+=1
    xfinal=(''.join(xnew))
    yfinal=(''.join(ynew))
    
    print
    print xfinal
    print yfinal