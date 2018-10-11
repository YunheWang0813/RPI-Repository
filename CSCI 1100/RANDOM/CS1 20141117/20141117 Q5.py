def second_min(number):
    x=set(number)
    if len(x)>=2:
        x=list(x)
        x.sort()
        print x[1]
    else:
        print 'None'
        
second_min([1,9,2,3,5,0,6,3])