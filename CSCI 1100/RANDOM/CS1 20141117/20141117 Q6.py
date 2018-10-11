word=raw_input('Word ==> ')
letters=set(word)
X=[]
for letter in list(letters):
    X.append((word.count(letter),letter))
X.sort(reverse=True)
for i in range(len(X)):
    print '%s: %d'%(X[i][1],X[i][0])