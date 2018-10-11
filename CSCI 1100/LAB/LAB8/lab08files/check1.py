def get_words(myfile):
    myfile=open(myfile)
    myfile=myfile.read()
    myfile=myfile.replace('|',' ')
    myfile=myfile.lower()
    for i in range(len(myfile)):
        myfile=myfile.replace(',',' ')
        myfile=myfile.replace('.',' ')
    myfile=myfile.split()
    words=set()
    for i in range(len(myfile)):
        if myfile[i].isalpha():
            if len(myfile[i])>=4:
                words.add(myfile[i])
    print len(words),'words'
    print words

if __name__=='__main__':
    myfile=raw_input('File ==> ')
    print myfile
    get_words(myfile)