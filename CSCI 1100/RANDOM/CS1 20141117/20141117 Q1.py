myfile=open('m.txt')
myfile=myfile.read()
myfile=myfile.split('\n')
myfile2=[]
for i in range(len(myfile)):
    myfile2.append(myfile[i].split('|'))
cnt=0
for i in range(len(myfile2)):
    if  'J. Lawrence'==myfile2[i][4] or 'J. Lawrence'==myfile2[i][5]:
        if myfile2[i][2]>=4 and myfile2[i][3]>=5:
            print '%s, %s'%(myfile2[i][0],myfile2[i][1])
            cnt+=1
print 'Found %d movies'%cnt
