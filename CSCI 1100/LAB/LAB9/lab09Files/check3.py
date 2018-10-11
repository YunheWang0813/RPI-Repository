from Date import *

myfile=open('birthdays.txt')
myfile=myfile.read()
myfile=myfile.split('\n')
myfile2=[]
for i in range(len(myfile)-1):
    myfile2.append(myfile[i].split())
ed=Date(myfile2[0][0],myfile2[0][1],myfile2[0][2])
for i in range(1,len(myfile2)):
    date=Date(myfile2[i][0],myfile2[i][1],myfile2[i][2])
    if date<ed:
        ed=date
ld=Date(myfile2[0][0],myfile2[0][1],myfile2[0][2])
for i in range(1,len(myfile2)):
    date=Date(myfile2[i][0],myfile2[i][1],myfile2[i][2])
    if date>ld:
        ld=date
month_all=[]
for i in range(len(myfile2)):
    month_all.append(myfile2[i][1])
cnt_ex=month_all.count('1')
for i in range(2,13):
    cnt=month_all.count(str(i))
    if cnt>cnt_ex:
        mon=i
        cnt_ex=cnt
print 'The earliest birthday: '+str(ed)
print 'The latest birthday: '+str(ld)
print 'the name of the month that has the most birthdays: '+month_names[mon]