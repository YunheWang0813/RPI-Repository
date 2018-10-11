webster={}
webster['python']=['a large heavy-bodied nonvenomous constrictor snake occurring throughout the Old World tropics',\
                   'a high-level general-purpose programming language']
                   

word=raw_input('Word ==> ')
if word in webster.keys():
    for i in range(len(webster[word])):
        print '%d. %s'%(i+1,webster[word][i])
else:
    print 'Word "%s" not found in webster'%word