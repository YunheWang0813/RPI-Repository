D={1: set(['a','b']), 2: set(['b','c'])}

D2={}

for key in D:
    s=D[key]
    for string in s:
        if string in D2:
            D2[string].add(key)
        else:
            D2[string]=set([key])
            
print D2