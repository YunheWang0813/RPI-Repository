Bchar=raw_input('Background char => ')
print Bchar
Fchar=raw_input('Foreground char => ')
print Fchar
Height=raw_input('Height => ')
print Height
print
if len(Bchar)==1 and len(Fchar)==1 and Height.isdigit():
    i=0
    while 0<=i<int(Height)/2:
        if int(Height)<10:
            if i==2:
                print str(i+1)+Bchar*(int(Height)-i)+Fchar+Bchar*i*2+'o'+Bchar*(int(Height)-i)
            else:
                print str(i+1)+Bchar*(int(Height)-i)+Fchar+Bchar*i*2+Fchar+Bchar*(int(Height)-i)                        
        else:
            if i==2:
                print str(i+1).rjust(2)+Bchar*(int(Height)-i)+Fchar+Bchar*i*2+'o'+Bchar*(int(Height)-i)
            else:
                print str(i+1).rjust(2)+Bchar*(int(Height)-i)+Fchar+Bchar*i*2+Fchar+Bchar*(int(Height)-i)
        i+=1
    while int(Height)/2<=i<int(Height):
        if int(Height)<10:
            print str(i+1)+Bchar*(i+1)+Fchar+Bchar*(int(Height)-i-1)*2+Fchar+Bchar*(i+1)
        else:
            print str(i+1).rjust(2)+Bchar*(i+1)+Fchar+Bchar*(int(Height)-i-1)*2+Fchar+Bchar*(i+1)
        i+=1
else:
    if Height.isdigit()==False:
        print 'Please enter a number for height'
    if len(Bchar)<>1:
        print 'Please enter one character for background'
    if len(Fchar)<>1:
        print 'Please enter one character for foreground'