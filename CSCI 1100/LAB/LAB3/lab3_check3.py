bpop=raw_input('Number of bunnies ==> ')
fpop=raw_input('Number of foxes ==> ')

def bpop_next(bpop,fpop):
    A=(10*int(bpop))/(1+0.1*int(bpop)) - 0.05*int(bpop)*int(fpop)
    A=max(0,A)
    return A

def fpop_next(bpop,fpop):
    B=0.4*int(fpop)+0.02*int(fpop)*int(bpop)
    B=max(0,B)
    return B

print 'Year 1: '+str(bpop)+' '+str(fpop)
print 'Year 2: '+str(int(bpop_next(bpop,fpop)))+' '+str(int(fpop_next(bpop,fpop)))
print 'Year 3: '+str(int(bpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop))))+' '+str(int(fpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop))))
print 'Year 4: '+str(int(bpop_next(bpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop)),fpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop)))))+' '+str(int(fpop_next(bpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop)),fpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop)))))
print 'Year 5: '+str(int(bpop_next(bpop_next(bpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop)),fpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop))),fpop_next(bpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop)),fpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop))))))+' '+str(int(fpop_next(bpop_next(bpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop)),fpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop))),fpop_next(bpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop)),fpop_next(bpop_next(bpop,fpop),fpop_next(bpop,fpop))))))