import random
from Ball import *
from Tkinter import *



if __name__=='__main__':
    blist=[]
    colorList=["blue", "red", "green", "yellow", "magenta", "orange"]    
    for i in range(10):
        blist.append(Ball(random.randint(10,390),random.randint(10,390),random.randint(-8,8),random.randint(-8,8),random.randint(5,10),random.choice(colorList)))