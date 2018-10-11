import hw3_util
teams = hw3_util.read_fifa()
id1=int(raw_input('Team 1 id => '))
print id1
id2=int(raw_input('Team 2 id => '))
print id2
name1=str(teams[id1][0])
win1=str(teams[id1][2])
draw1=str(teams[id1][3])
lose1=str(teams[id1][4])
gf1=str(teams[id1][5])
ga1=str(teams[id1][6])
name2=str(teams[id2][0])
win2=str(teams[id2][2])
draw2=str(teams[id2][3])
lose2=str(teams[id2][4])
gf2=str(teams[id2][5])
ga2=str(teams[id2][6])
Pts1=int(win1)*3+int(draw1)
Pts2=int(win2)*3+int(draw2)
GD1=int(gf1)-int(ga1)
GD2=int(gf2)-int(ga2)
print
print 'Team                Win   Draw  Lose  GF    GA    Pts   GD    '
print name1+' '*(20-len(name1))+win1.ljust(6)+draw1.ljust(6)+lose1.ljust(6)+gf1.ljust(6)+ga1.ljust(6)+str(Pts1).ljust(6)+str(GD1).ljust(6)
print name2+' '*(20-len(name2))+win2.ljust(6)+draw2.ljust(6)+lose2.ljust(6)+gf2.ljust(6)+ga2.ljust(6)+str(Pts2).ljust(6)+str(GD2).ljust(6)
if Pts1>Pts2:
    print name1,'is better'
elif Pts1<Pts2:
    print name2,'is better'
else:
    if GD1>GD2:
        print name1,'is better'
    elif GD1<GD2:
        print name2,'is better'
    else:
        if int(gf1)>int(gf2):
            print name1,'is better'
        elif int(gf1)<int(gf2):
            print name2,'is better'
        elif int(gf1)==int(gf2):
            print 'Both teams are tied'
