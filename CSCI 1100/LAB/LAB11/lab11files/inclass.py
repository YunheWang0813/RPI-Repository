from Tkinter import *

root=Tk()

main_frame=Frame(root)
main_frame.pack()
top_frame=Frame(main_frame)
top_frame.pack(side=TOP)
bottom_frame=Frame(main_frame)
bottom_frame.pack(side=BOTTOM)

button1=Button(top_frame,text='Top Left')
button1.pack(side=LEFT)
button2=Button(top_frame,text='Top Right')
button2.pack(side=RIGHT)

canvas=Canvas(top_frame,height=400,width=400)
canvas.pack()

button3=Button(bottom_frame,text='Bottom Left')
button3.pack(side=LEFT)
button4=Button(bottom_frame,text='Bottom Right')
button4.pack(side=RIGHT)

root.mainloop()

print 'Hello'