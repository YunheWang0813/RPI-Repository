word=raw_input('Enter cipher text ==> ')
print word
print ''
def encrypt(word):
    A=str(word).replace('rxr',' a')
    B=str(A).replace('vw','he')
    C=str(B).replace('az az','e')
    D=str(C).replace('eie','y')
    E=str(D).replace('yyy','u')
    F=str(E).replace('uq','an')
    G=str(F).replace('aige','th')
    H=str(G).replace('tzzt','o')
    return H
print "Deciphered as ==>",encrypt(word)
X=abs(len(word)-len(encrypt(word)))
print "Difference in length ==>",X
print ''
word=raw_input('Enter regular text ==> ')
print word
print ''
def decrypt(word):
    A=str(word).replace(' a','rxr')
    B=str(A).replace('he','vw')
    C=str(B).replace('e','az az')
    D=str(C).replace('y','eie')
    E=str(D).replace('u','yyy')
    F=str(E).replace('an','uq')
    G=str(F).replace('th','aige')
    H=str(G).replace('o','tzzt')
    return H
print "Encrypted as ==>",decrypt(word)
Y=abs(len(word)-len(decrypt(word)))
print "Difference in length ==>",Y