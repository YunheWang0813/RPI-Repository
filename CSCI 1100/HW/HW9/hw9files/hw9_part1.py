import json

if __name__=='__main__':
    f = open('businesses.json')
    cata=raw_input('Enter a category ==> ')
    print cata
    cutoff=int(raw_input('Cutoff for displaying categories => '))
    print cutoff
    data=[]
    for line in f:
        data.append(json.loads(line)['categories'])
    reqdata={}
    for i in range(len(data)):
        if cata in data[i]:
            for j in data[i]:
                if j!=cata:
                    if reqdata.get(j,0)==0:
                        reqdata[j]=1
                    else:
                        reqdata[j]+=1
    if reqdata=={}:
        print 'Searched category is not found'
    else:
        finaldata=[]
        just=False
        for key in reqdata:
            if reqdata[key]>=cutoff:
                finaldata.append((key,reqdata[key]))
                just=True
        if not just:
            print 'Categories co-occurring with %s:'%cata
            print 'None above the cutoff'     
        else:
            finaldata.sort()
            print 'Categories co-occurring with %s:'%cata
            for i in range(len(finaldata)):
                print '%s: %d'%(finaldata[i][0].rjust(30),finaldata[i][1])