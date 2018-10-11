i=0
j=0
X=200
Y=200
direction='right'
entered=[]
print 'Turtle: (200,200) facing: right'
while i<5:
    command=raw_input('Command (move,jump,turn) => ')
    print command
    entered.append(command)
    dirc=['right','up','left','down','right','up']
    if command.lower()=='turn':
        direction=dirc[j+1]
        j+=1
    if command.lower()=='jump':
        if direction=='right':
            X=X+50
        elif direction=='up':
            Y=Y-50
        elif direction=='left':
            X=X-50
        elif direction=='down':
            Y=Y+50
    if command.lower()=='move':
        if direction=='right':
            X=X+20
        elif direction=='up':
            Y=Y-20
        elif direction=='left':
            X=X-20
        elif direction=='down':
            Y=Y+20
    print 'Turtle: ('+str(X)+','+str(Y)+') facing:',direction
    i+=1
print
print 'All commands entered',entered
entered.sort()
print 'Sorted commands',entered
