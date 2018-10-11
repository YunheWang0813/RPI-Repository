def winner(name1,name2,outcome):
    name1ini=name1[0]
    name2ini=name2[0]
    out1=int(outcome[0])
    out2=int(outcome[2])
    if out1>out2:
        if (win1+1)*5+tied1*2+(vote1+out1)/2>(win2*5+tied2*2+(vote2+out2)/2):
            return name1ini
        elif (win1+1)*5+tied1*2+(vote1+out1)/2==(win2*5+tied2*2+(vote2+out2)/2):
            return '-'
        elif (win1+1)*5+tied1*2+(vote1+out1)/2<(win2*5+tied2*2+(vote2+out2)/2):
            return name2ini
    elif out1==out2:
        if win1*5+(tied1+1)*2+(vote1+out1)/2>(win2*5+(tied2+1)*2+(vote2+out2)/2):
            return name1ini
        elif win1*5+(tied1+1)*2+(vote1+out1)/2==(win2*5+(tied2+1)*2+(vote2+out2)/2):
            return '-'
        elif win1*5+(tied1+1)*2+(vote1+out1)/2<(win2*5+(tied2+1)*2+(vote2+out2)/2):
            return name2ini
    if out1<out2:
        if win1*5+tied1*2+(vote1+out1)/2>((win2+1)*5+tied2*2+(vote2+out2)/2):
            return name1ini
        elif win1*5+tied1*2+(vote1+out1)/2==((win2+1)*5+tied2*2+(vote2+out2)/2):
            return '-'
        elif win1*5+tied1*2+(vote1+out1)/2<((win2+1)*5+tied2*2+(vote2+out2)/2):
            return name2ini

def make_board(name1,name2):
    list=[]
    for i in range(5):
        for j in range(5):
            list.append(str(winner(name1,name2,str(j)+'-'+str(i))))
    list=[list[i:i+5] for i in range(0,25,5)]
    final1='    '.join(list[0])
    final2='    '.join(list[1])
    final3='    '.join(list[2])
    final4='    '.join(list[3])
    final5='    '.join(list[4])
    print '  0  |  '+final1+'  '
    print '  1  |  '+final2+'  '
    print '  2  |  '+final3+'  '
    print '  3  |  '+final4+'  '
    print '  4  |  '+final5+'  '
    
        
if __name__ == '__main__':
    candidate1=raw_input('Enter candidate 1 stats ==> ')
    print candidate1
    candidate2=raw_input('Enter candidate 2 stats ==> ')
    print candidate2
    stats1=candidate1.split(',')
    stats2=candidate2.split(',')
    name1=stats1[0]
    name2=stats2[0]
    win1=int(stats1[1])
    win2=int(stats2[1])
    tied1=int(stats1[2])
    tied2=int(stats2[2])
    vote1=int(stats1[3])
    vote2=int(stats2[3])
    
    print "Columns are %s's votes, rows are %s's votes"%(name1,name2)
    print 'Votes|  0    1    2    3    4  '
    print '-----|-------------------------'
    make_board(name1,name2)