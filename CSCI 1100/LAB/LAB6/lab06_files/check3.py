import lab06_util

def make_board(board):
    for i in range(9):
        board[i].insert(3,'|')
        board[i].insert(7,'|')
        if i==3 or i==6:
            print '-'*(len(board[i])*2-1+4)
        print '| '+' '.join(board[i])+' |'
        board[i].remove('|')
        board[i].remove('|')        

def ok_to_add(row, column, number, board):
    if number in board[row]:
        return False
    else:
        for i in range(9):
            if number==board[i][column]:
                return False
            
        for j in range(row/3*3,row/3*3+3):
            for k in range(column/3*3,column/3*3+3):
                if number==board[j][k]:
                    return False
    return True

def verify_board(board):
    for i in range(9):
        for j in range(9):
            if board[i][j]=='.':
                return False
    return True

fname=raw_input("Print enter a file name ==> ")
board=lab06_util.read_sudoku(fname)    

while verify_board(board)==False:
    row=int(raw_input('Enter a row => '))
    column=int(raw_input('Enter a column => '))
    number=raw_input('Enter a number => ')
    if ok_to_add(row, column, number, board)==False:
        print 'This number cannot be added'
    else:
        board[row][column]=number
        make_board(board)