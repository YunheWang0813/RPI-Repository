s=raw_input('input ==> ').strip('_')
while s.replace('__','_')!=s:
    s=s.replace('__','_')
print s