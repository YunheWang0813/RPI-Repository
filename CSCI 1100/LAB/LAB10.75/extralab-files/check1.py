f1=open(raw_input('File ==> '))
f1=f1.read()
f1=f1.split('\n')
f2=[]
for i in range(len(f1)-1):
    f2.append(f1[i].split())
f3={}
for i in range(len(f2)):
    f4=set()
    for j in range(len(f2[i])-1):
        f4.add(int(f2[i][j+1]))
    f3[int(f2[i][0])]=f4
f5=sorted(f3.items())
print '%d people total'%len(f5)
for i in range(len(f5)):
    print '%d: %s'%(f5[i][0],f5[i][1])