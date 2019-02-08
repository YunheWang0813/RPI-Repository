def E(x,y):
    m=len(x)
    n=len(y)
    
    table=[[0]*(n+1) for i in range(m+1)]
    
    for i in range(m+1):
        table[i][0]=i
    for i in range(1,n+1):
        table[0][i]=i
            
    for i in range(1,m+1):
        for j in range(1,n+1):
            if y[j-1]==x[i-1]:
                table[i][j]=min(table[i-1][j]+1, table[i][j-1]+1, table[i-1][j-1])
            else:            
                table[i][j]=min(table[i-1][j]+1, table[i][j-1]+1, table[i-1][j-1]+1)
    
    return table[m][n]
        
    

if __name__ == '__main__':
    x='CATAAGCTTCTGACTCTTACCTCCCTCTCTCCTACTCCTGCTCGCATCTGCTATAGTGGAGGCCGGAGCAGGAACAGGTTGAACAG'
    y='CGTAGCTTTTTGGTTAATTCCTCCTTCAGGTTTGATGTTGGTAGCAAGCTATTTTGTTGAGGGTGCTGCTCAGGCTGGATGGA'
    
    print E(x,y)