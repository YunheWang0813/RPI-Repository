A=raw_input('Please enter a name ==> ')
print A
B=raw_input('Count in 1970 => ')
print B
C=raw_input('Count in 1980 => ')
print C
D=raw_input('Count in 1990 => ')
print D
E=raw_input('Count in 2000 => ')
print E
F='\nBabies named '+A+'\n'
G='*'*(len(F)-2)+'\n'
H='\nYear / Total / % change from previous decade'+'\n'
I='1970 / '+str(int(B))+'\n'
N=100*(float(C)-float(B))/float(B)
O=100*(float(D)-float(C))/float(C)
P=100*(float(E)-float(D))/float(D)
J='1980 / '+str(int(C))+' / %% %.2f' %(N)+'\n'
K='1990 / '+str(int(D))+' / %% %.2f' %(O)+'\n'
L='2000 / '+str(int(E))+' / %% %.2f' %(P)+'\n'
M='Average change: %% %.2f' %((N+O+P)/3)
print F,G,H,I,J,K,L,M