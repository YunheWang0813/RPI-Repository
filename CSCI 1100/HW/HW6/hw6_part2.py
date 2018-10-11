if __name__ == '__main__':
    myfile=open('DrWhoVillains.tsv')
    myfile=myfile.read()
    myfile=myfile.split('\n')
    villain1=raw_input('Enter name of villain => ')
    print villain1
    story=[]
    for i in range(1,len(myfile)-1):
        story.append((myfile[i].split('\t')[8].split(','),myfile[i].split('\t')[0].strip()))          
    for i in range(len(story)):
        for j in range(len(story[i][0])):
            story[i][0][j]=story[i][0][j].strip()
    for i in range(len(story)):
        if story[i][1]==villain1:
            villain1ex=set(story[i][0])
    name=[]
    thestory=[]
    for i in range(len(story)):
        villain2=story[i][1]
        villain2ex=set(story[i][0])
        if villain1ex&villain2ex!=set([]):
                name.append(villain2)
                thestory.append(list(villain2ex))
    storyname=list(villain1ex)
    storyname.sort()
    print
    print 'Stories featuring "%s"'%villain1
    print '---------------------------'
    for i in range(len(storyname)):
        cnt=0
        for j in range(len(thestory)):
            if storyname[i] in thestory[j]:
                cnt+=1
        print '%s: %s'%(storyname[i],'*'*cnt)