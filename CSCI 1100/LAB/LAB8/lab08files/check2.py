def get_words(myfile):
    myfile=open(myfile)
    myfile=myfile.read()
    myfile=myfile.split('|')[1]
    myfile=myfile.lower()
    myfile=myfile.replace(',',' ')
    myfile=myfile.replace('.',' ')
    myfile=myfile.replace('(',' ')
    myfile=myfile.replace(')',' ')
    myfile=myfile.split()
    words=set()
    for i in range(len(myfile)):
        if myfile[i].isalpha():
            if len(myfile[i])>=4:
                words.add(myfile[i])
    return words

if __name__=='__main__':
    myfile=raw_input('File1 ==> ')
    myfile2=raw_input('File2 ==> ')
    club1=get_words(myfile)
    club2=get_words(myfile2)
    print len(club1)
    print len(club2)
    print 'Common:',len(club1&club2)
    print 'Unique in the first club:',len(club1-club2)
    print 'Unique in the second club:',len(club2-club1)