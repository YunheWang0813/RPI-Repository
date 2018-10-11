def get_line(fname,parno,lineno):
    f=open(fname+'.txt')
    cnt=1
    line=1
    fix=f.readline()
    while fix!='\n':
        fix=f.readline()
        fix
        if fix=='\n':
            cnt+=1
        if cnt==parno:
            break
    while line<lineno:
        f.readline()
        line+=1
    print f.readline(),
    
if __name__=='__main__':
    fname=raw_input('Please file number ==> ')
    parno=int(raw_input('Please enter paragraph number ==> '))
    lineno=int(raw_input('Please enter the line number ==> '))
    get_line(fname,parno,lineno)