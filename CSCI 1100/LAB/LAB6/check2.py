def make_board(bd):
    for i in range(9):
        bd[i].insert(3,'|')
        bd[i].insert(7,'|')
        if i==3 or i==6:
            print '-'*(len(bd[i])*2-1+4)
        print '| '+' '.join(bd[i])+' |'

def ok_to_add(bd_ini, row, column, number):
    if number in bd_ini[row]:
        return False
    else:
        for i in range(9):
            if number==bd_ini[i][column]:
                return False
            
        for j in range(row/3*3,row/3*3+3):
            for k in range(column/3*3,column/3*3+3):
                if number==bd_ini[j][k]:
                    return False
    return True

bd = [ [ '1', '.', '.', '.', '2', '.', '.', '3', '7'],
       [ '.', '6', '.', '.', '.', '5', '1', '4', '.'],
       [ '.', '5', '.', '.', '.', '.', '.', '2', '9'],
       [ '.', '.', '.', '9', '.', '.', '4', '.', '.'],
       [ '.', '.', '4', '1', '.', '3', '7', '.', '.'],
       [ '.', '.', '1', '.', '.', '4', '.', '.', '.'],
       [ '4', '3', '.', '.', '.', '.', '.', '1', '.'],
       [ '.', '1', '7', '5', '.', '.', '.', '8', '.'],
       [ '2', '8', '.', '.', '4', '.', '.', '.', '6'] ]

bd_ini = [ [ '1', '.', '.', '.', '2', '.', '.', '3', '7'],
       [ '.', '6', '.', '.', '.', '5', '1', '4', '.'],
       [ '.', '5', '.', '.', '.', '.', '.', '2', '9'],
       [ '.', '.', '.', '9', '.', '.', '4', '.', '.'],
       [ '.', '.', '4', '1', '.', '3', '7', '.', '.'],
       [ '.', '.', '1', '.', '.', '4', '.', '.', '.'],
       [ '4', '3', '.', '.', '.', '.', '.', '1', '.'],
       [ '.', '1', '7', '5', '.', '.', '.', '8', '.'],
       [ '2', '8', '.', '.', '4', '.', '.', '.', '6'] ]
    
row=int(raw_input('Enter a row => '))
column=int(raw_input('Enter a column => '))
number=raw_input('Enter a number => ')

if ok_to_add(bd_ini, row, column, number)==False:
    print 'This number cannot be added'
else:
    bd_ini[row][column]=number
    make_board(bd_ini)