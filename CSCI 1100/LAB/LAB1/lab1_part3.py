D1 = 483632000.
D2 = 92957100.
Dr = D1/D2
print "Jupiter is", Dr, "times further from the Sun than Earth is."
pi = 3.14159
radius1 = 88846/2
radius2 = 7926/2
V1 = 4/3.*pi*radius1**3
V2 = 4/3.*pi*radius2**3
Vr = V1/V2
print "Jupiter's volume is", Vr, "times bigger than that of the Earth is."
v = 186000
t1 = D2/v
t2 = t1/60
T1 = int(t1)
T2 = int(t2)
T3 = T1-T2*60
print "It takes", T2 ,"minutes", T3 ,"seconds for light to travel from the Sun to Earth."
t4 = D1/v
t5 = t4/60
T4 = int(t4)
T5 = int(t5)
T6 = T4-T5*60
print "It takes", T5 ,"minutes", T6 ,"seconds for light to travel from the Sun to Jupiter."