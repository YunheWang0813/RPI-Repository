A=raw_input('Width of box ==> ')
print A
B=raw_input('Height of box ==> ')
print B
X=raw_input('Enter frame character ==> ')
print X
C=X*int(A)+'\n'
D=X+" "+str(int(A))+'x'+str(int(B))+" "*(int(A)-len(X+" "+str(int(A))+'x'+str(int(B)))-1)+X+'\n'
E=(X+" "*(int(A)-2)+X+'\n')*(int(B)-3)
F=X*int(A)
G='\n'
H='Box:\n'
print G,H,C,D,E,F