myfile='babies_short.txt'
myfile=open(myfile)
myfile=myfile.read()
myfile=myfile.split()
myfile2=[]
for i in range(len(myfile)):
    myfile2.append(myfile[i].split(','))
for i in range(len(myfile)):
    myfile2[i][0],myfile2[i][2]=myfile2[i][2],myfile2[i][0]
male=[]
female=[]
for i in range(len(myfile2)):
    if myfile2[i][1]=='M':
        male.append(myfile2[i])
    elif myfile2[i][1]=='F':
        female.append(myfile2[i])
for i in range(len(myfile2)):
    myfile2[i][0]=int(myfile2[i][0])
male.sort(reverse=True)
female.sort(reverse=True)
print male
print female