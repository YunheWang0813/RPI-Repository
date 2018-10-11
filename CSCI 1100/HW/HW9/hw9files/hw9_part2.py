import json
import textwrap

if __name__=='__main__':
    f=open('reviews.json')
    f2=open('businesses.json')
    data=[]
    data2=[]
    for line in f:
        data.append(json.loads(line))
    for line in f2:
        data2.append(json.loads(line))
    busname=raw_input('Enter a business name => ')
    print busname
    reqid=[]
    for i in range(len(data2)):
        if data2[i]['name']==busname:
            reqid.append(data2[i]['business_id'])
    if reqid==[]:
        print 'This business is not found'
    else:
        just=False
        cnt=1
        for j in range(len(data)):
            if data[j]['business_id'] in reqid:
                if cnt!=1:
                    print
                    print
                print 'Review %d:'%cnt
                txt=data[j]['text'].split('\n')
                for k in txt:
                    for x in textwrap.wrap(k,70):
                        print '    '+x
                just=True
                cnt+=1
        if not just:
            print 'No reviews for this business is found'