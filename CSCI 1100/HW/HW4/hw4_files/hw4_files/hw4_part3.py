import hw4_util
country1=raw_input('First country => ')
print country1
country2=raw_input('Second country => ')
print country2
c1data=hw4_util.read_flu(country1)
c2data=hw4_util.read_flu(country2)
list1=[]
list2=[]
i=0
j=0
if len(c1data)==52:
    if len(c2data)==52:
        cutoff1=(sum(c1data)/len(c1data)+max(c1data))/2
        cutoff2=(sum(c2data)/len(c2data)+max(c2data))/2        
        while i<len(c1data):
            if c1data[i]>=cutoff1:
                list1.append('+')
            else:
                list1.append('-')
            i+=1
        while j<len(c1data):
            if c2data[j]>=cutoff2:
                list2.append('+')
            else:
                list2.append('-')
            j+=1
        print ' '*12+'1   2   3   4   5   6   7   8   9   10  11  12  '
        print country1.ljust(12)+''.join(list1)
        print country2.ljust(12)+''.join(list2)
    else:
        print 'I could not find country',country2
else:
    if len(c2data)==52:
        print 'I could not find country',country1
    else:
        print 'I could not find country',country1
        print 'I could not find country',country2