import hw4_util
legos=hw4_util.read_legos()
print 'Current legos',legos
Type=raw_input('Type of lego wanted => ')
print Type
Quantity=int(raw_input('Quantity wanted => '))
print Quantity
Nsmall=legos.count('1x1')
Nmiddle=legos.count('2x1')
Nbig=legos.count('2x2')
i=Quantity*2
j=Quantity*2
k=Quantity*4
l=Quantity
if Quantity<=legos.count(Type):
    while l>0:
        legos.remove(Type)
        l-=1
    print 'I can use',Quantity,Type,'legos for this'
    print 'Remaining legos',legos
else:
    if Type=='2x1':
        if Nsmall>=i:
            while i>0:
                legos.remove('1x1')
                i-=1
            print 'I can use',Quantity*2,'1x1','legos for this'
            print 'Remaining legos',legos
        else:
            print 'I don\'t have',Quantity,Type,'legos'
    else:
        if Nmiddle>=j:
            while j>0:
                legos.remove('2x1')
                j-=1
            print 'I can use',Quantity*2,'2x1','legos for this'
            print 'Remaining legos',legos
        else:
            if Nsmall>=k:
                while k>0:
                    legos.remove('1x1')
                    k-=1
                print 'I can use',Quantity*4,'1x1','legos for this'
                print 'Remaining legos',legos
            else:
                print 'I don\'t have',Quantity,Type,'legos'    
