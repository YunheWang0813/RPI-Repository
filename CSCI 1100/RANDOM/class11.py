def cap_value(mystr):
    mystr=mystr.capitalize()
    return mystr
def arrange_value(mylist):
    mylist.sort()


myvals=[]
finished=False
while not finished:
    newval=raw_input('Enter a value (stop to end) ==> ')
    if newval=='stop':
        finished=True
    else:
        newval=cap_value(newval)
        myvals.append(newval)
        arrange_value(myvals)
        print myvals