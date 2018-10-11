def get_words(myfile):
    myfile=myfile.replace('|',' ')
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
    myfile=raw_input('File ==> ')
    myfile=open(myfile)
    myfile=myfile.read()
    myfile2=open('allclubs.txt')
    myfile2=myfile2.read()
    myfile2=myfile2.split('\n')    
    club1=get_words(myfile)
    result=[]
    for i in range(len(myfile2)-1):
        club2=get_words(myfile2[i])
        result.append((len(club1&club2),myfile2[i].split('|')[0]))
    result.sort(reverse=True)
    print result[1:6]