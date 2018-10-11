bpop=int(raw_input('Please enter the starting bunny population ==> '))
print bpop
fpop=int(raw_input('Please enter the starting fox population ==> '))
print fpop
def next_pop(bpop,fpop):
    bpop_next=int(max(0,round((10*bpop)/(1+0.1*bpop)-0.05*bpop*fpop)))
    fpop_next=int(max(0,round(0.4*fpop+0.02*fpop*bpop)))
    return (bpop_next,fpop_next)
def check_convergence(bpop,fpop):
    iter=1
    while iter<=100:
        bpop=next_pop(bpop,fpop)[0]
        fpop=next_pop(bpop,fpop)[1]
        if next_pop(bpop,fpop)[0]==0 or next_pop(bpop,fpop)[1]==0:
            print bpop,fpop
            break
        elif next_pop(bpop,fpop)[0]==next_pop(bpop,fpop)[1]:
            print bpop,fpop
            break
        else:
            if iter==100:
                print bpop,fpop
        iter+=1
            
check_convergence(bpop,fpop)