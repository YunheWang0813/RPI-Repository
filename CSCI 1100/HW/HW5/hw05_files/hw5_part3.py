if __name__ == '__main__':
    myfile=raw_input('File name => ')
    print myfile
    number=int(raw_input('How many names to display? => '))
    print number
    myfile=open(myfile)
    myfile=myfile.read()
    myfile=myfile.split()
    myfile2=[]
    for i in range(len(myfile)):
        myfile2.append(myfile[i].split(','))
    for i in range(len(myfile2)):
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
    print
    print 'Top female names'
    for i in range(number):
        if (i+1)%3==0:
            print '%s (%s)'%(female[i][2],female[i][0])
        elif i==number-1:
            print '%s (%s)'%(female[i][2],female[i][0])
        else:
            print '%s (%s)'%(female[i][2],female[i][0]),
    print 'Top male names'
    for i in range(number):
        if (i+1)%3==0:
            print '%s (%s)'%(male[i][2],male[i][0])
        else:
            print '%s (%s)'%(male[i][2],male[i][0]),        