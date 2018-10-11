class Ball(object):
    def __init__(self,x,y,dx,dy,radius,color):
        self.x,self.y=x,y
        self.radius=radius
        self.dx,self.dy=dx,dy
        self.color=color
        
    def position(self):
        return self.x,self.y
    
    def move(self):
        self.x+=self.dx
        self.y+=self.dy
        
    def bounding_box(self):
        return (self.x-self.radius,self.y-self.radius,self.x+self.radius,self.y+self.radius)
    
    def get_color(self):
        return self.color
    
    def some_inside(self,maxx,maxy):
        if maxx>=self.x>=0 or maxy>=self.y>=0:
            return True
        return False
    
    def check_and_reverse(self,maxx,maxy):
        if self.x>=maxx or self.x<=0:
            self.dx=-self.dx
        if self.y>=maxy or self.y<=0:
            self.dy=-self.dy