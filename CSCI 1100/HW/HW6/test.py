import textwrap

def top10list(myfile):
    for i in range(10):
        print '%d. %s'%(i+1,select[i][1])
    print 'Please enter a number between 1 and 10, or -1 to end'

if __name__ == '__main__':
    myfile=open('DrWhoVillains.tsv')
    myfile=myfile.read()
    myfile=myfile.split('\n')
    select=[]
    for i in range(1,(len(myfile)-1)):
        select.append((int(myfile[i].split('\t')[6]),myfile[i].split('\t')[0]))
    select.sort(reverse=True)
    top10list(myfile)
    number=int(raw_input('Enter a villain ==> '))
    story=[]
    for i in range(1,len(myfile)-1):
        story.append((myfile[i].split('\t')[8].split(','),myfile[i].split('\t')[0]))
    for i in range(len(story)):
        for j in range(len(story[i][0])):
            story[i][0][j]=story[i][0][j].strip()
    villain1=select[number-1][1]
    for i in range(len(story)):
        if story[i][1]==villain1:
            villain1ex=set(story[i][0])
    name=[]
    diff=villain1ex
    for i in range(len(story)):
        villain2=story[i][1]
        villain2ex=set(story[i][0])
        if villain1ex&villain2ex!=set([]):
            if villain1!=villain2:
                name.append(villain2)
        if villain1!=villain2:
            diff=diff-villain2ex
    name.sort()
    name=', '.join(name)
    diff=', '.join(list(diff))
    print '%s in %d stories, with the following other villains:'%(villain1,select[number-1][0])
    print '=================================================='
    for i in textwrap.wrap(name,70):
        print '\t'+i
    print
    print 'The stories that only features %s are:'%villain1
    print '=================================================='
    for i in textwrap.wrap(diff,70):
        print '\t'+i
    print
    print