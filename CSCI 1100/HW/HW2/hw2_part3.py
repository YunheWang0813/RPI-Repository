A=int(raw_input('Enter a value ==> '))
print A
print ''
print "Here is the computation:"
def reverse(A):
    X=A%100%10*100+A%100/10*10+A/100
    return X
B=reverse(A)
C=abs(B-A)
print max(A,B),"-",min(A,B),"=",C
D=reverse(C)
print C,"+",D,"=",C+D
if C+D==1089:
    print "You see, I told you."
else:
    print "Are you sure your input is valid?"