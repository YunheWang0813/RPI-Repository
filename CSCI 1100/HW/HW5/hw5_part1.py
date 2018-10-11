def next_pop(bpop,fpop):
    bpop_next=int(max(0,round((10*bpop)/(1+0.1*bpop)-0.05*bpop*fpop)))
    fpop_next=int(max(0,round(0.4*fpop+0.02*fpop*bpop)))
    return (bpop_next,fpop_next)

def check_convergence(bpop,fpop):
    iter=1
    while iter<=100:
        bpop_next=next_pop(bpop,fpop)[0]
        fpop_next=next_pop(bpop,fpop)[1]
        bpop=bpop_next
        fpop=fpop_next
        if bpop_next==0 or fpop_next==0:
            print '(Bunny, Fox): Start (%d, %d) End: (%d, %d), Converged: True in %d generations'%(bpop_ini,fpop_ini,bpop,fpop,iter)
            break
        elif bpop_next==fpop_next:
            iter+=1
            print '(Bunny, Fox): Start (%d, %d) End: (%d, %d), Converged: True in %d generations'%(bpop_ini,fpop_ini,bpop,fpop,iter)
            break
        else:
            if iter==100:
                print '(Bunny, Fox): Start (%d, %d) End: (%d, %d), Converged: False in %d generations'%(bpop_ini,fpop_ini,bpop,fpop,iter)
        iter+=1

if __name__ == '__main__':
    bpop=int(raw_input('Please enter the starting bunny population ==> '))
    print bpop
    fpop=int(raw_input('Please enter the starting fox population ==> '))
    print fpop
    bpop_ini=bpop
    fpop_ini=fpop
          
    check_convergence(bpop,fpop)