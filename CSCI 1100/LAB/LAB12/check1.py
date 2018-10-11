def add(m,n):
    if n == 0:
        return m
    else:
        return add(m,n-1)+1  
    ''' (n-1)*1+1+m '''
    
def mult(m,n):
    if n==0:
        return 0
    else:
        return mult(m,n-1)+m 
    ''' (n-1)*m+m+0'''
    
def power(m,n):
    if n==0:
        return 1
    else:
        return power(m,n-1)*m

print add(7,3)
print mult(8,3)
print power(2,10)





'''
exp(2, 4)
+-- 2 * exp(2, 3)
|       +-- 2 * exp(2, 2)
|       |       +-- 2 * exp(2, 1)
|       |       |       +-- 2 * exp(2, 0)
|       |       |       |       +-- 1
|       |       |       +-- 2 * 1
|       |       |       +-- 2
|       |       +-- 2 * 2
|       |       +-- 4
|       +-- 2 * 4
|       +-- 8
+-- 2 * 8
+-- 16
'''