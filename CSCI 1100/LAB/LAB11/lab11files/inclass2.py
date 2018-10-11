from Tkinter import *

class Myapp(object):
    def __init__(self,parent):
        self.main_frame=Frame(root)
        self.main_frame.pack()
        self.top_frame=Frame(self.main_frame)
        self.top_frame.pack(side=TOP)
        self.bottom_frame=Frame(self.main_frame)
        self.bottom_frame.pack(side=BOTTOM)
        self.button1=Button(self.top_frame,text='Top Left')
        self.button1.pack(side=LEFT)
        self.button2=Button(self.top_frame,text='Top Right')
        self.button2.pack(side=RIGHT)
        self.canvas=Canvas(self.top_frame,height=400,width=400)
        self.canvas.pack()
        self.button3=Button(self.bottom_frame,text='Bottom Left')
        self.button3.pack(side=LEFT)
        self.button4=Button(self.bottom_frame,text='Bottom Right')
        self.button4.pack(side=RIGHT)
        
    def draw(self):
        if self.isdraw:
            x,y=250,250
            radius=200/self.numcircles    
    
if __name__=='__main__':
    root=Tk()
    root.title("Tkinter: Lab 11")
    myapp=Myapp(root)
    root.mainloop()