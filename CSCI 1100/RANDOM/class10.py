months = ['jan', 'feb', 'mar', 'apr', 'may', 'jun', \
          'jul', 'aug', 'sep', 'oct', 'nov', 'dec']

agents = ['skye','may','fitz','simmons','caulson',\
          'hunter', 'mack', 'morse', 'triplett', \
          'hartley', 'deathlok', 'koenig', \
          'gonzales', 'fury']



word = 'bookkeeper'


i=0
cnt=0
while i<len(agents):
    A=agents[i].capitalize()
    if A[0]=='S':
        cnt+=1
    print A
    i+=1

print 'sss',cnt