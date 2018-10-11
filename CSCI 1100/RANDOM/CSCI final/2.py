def three_way_merge(L1,L2,L3):
    L=[]
    i1=0
    i2=0
    i3=0
    done1=False
    done2=False
    done3=False
    while not (done1 and done2 and done3):
        if not done1 and done2 and done3:
            L.append(L1[i1])
            i1+=1
            done1=i1>=len(L1)
        elif not done2 and done3:
            L.append(L2[i2])
            i2+=1
            done2=i2>=len(L2)
        else:
            L.append(L3[i3])
            i3+=1
            done3=i3>=len(L3)
    return sorted(L)
       
print three_way_merge( [2,3, 4,4, 4, 5], [1, 5, 6, 9], [ 6, 9, 13] )

'''
def three_way_merge(L1,L2,L3):
    L = []
    i1 = 0
    i2 = 0
    i3 = 0
    done1 = False
    done2 = False
    done3 = False
    while not (done1 and done2 and done3):
        if not done1 and (done2 or L1[i1] < L2[i2]) and (done3 or L1[i1] < L3[i3]):
            L.append(L1[i1])
            i1 += 1
            done1 = i1 >= len(L1)
        elif not done2 and (done3 or L2[i2] < L3[i3]):
            L.append(L2[i2])
            i2 += 1
            done2 = i2 >= len(L2)
        else:
            L.append(L3[i3])
            i3 += 1
            done3 = i3 >= len(L3)
    return L

print three_way_merge( [2,3, 4,4, 4, 5], [1, 5, 6, 9], [ 6, 9, 13] )
'''