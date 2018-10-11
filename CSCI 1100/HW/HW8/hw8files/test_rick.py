import math

class Rick(object):
    def __init__(self,bdname,x0,y0,length,dx,dy,curbd):
        self.bdname=bdname
        self.x0=int(x0)
        self.y0=int(y0)
        self.length=int(length)
        self.dx=float(dx)
        self.dy=float(dy)
        for i in range(len(curbd)):
            if self.bdname==curbd[i].name:
                self.curbd=curbd[i]
                break
        self.alive=True
        
    def move(self):
        self.x0=int(self.x0+self.dx/self.curbd.grav)
        self.y0=int(self.y0+self.dy/self.curbd.grav)
        
    def stop(self,curbd):
        self.mgn=math.sqrt(self.dx**2+self.dy**2)
        if self.mgn<=self.length*2:
            self.alive=False
            return True
        return False
    
    def clash(self,curbd):
        for i in range(len(self.curbd.obs)):
            if self.x0<=self.curbd.obs[i][0]<=self.x0+self.length and self.y0<=self.curbd.obs[i][1]<=self.y0+self.length or\
               self.x0<=self.curbd.obs[i][0]<=self.x0-self.length and self.y0<=self.curbd.obs[i][1]<=self.y0-self.length:
                self.loc=i
                self.dx=-self.dx/2
                self.dy=-self.dy
                return True
        return False
    
    def collide(self,other_rick):
        for r in other_rick:
            if self!=r:
                if self.x0<=r.x0<=self.x0+self.length and self.y0<=sr.y0<=self.y0+self.length or\
                   self.x0<=self.curbd.obs[i][0]<=self.x0-self.length and self.y0<=self.curbd.obs[i][1]<=self.y0-self.length:
        return False
    
    def newloc(self,curbd):
        self.oriloc=self.curbd.name
        self.orix=self.x0
        self.oriy=self.y0
        if self.x0<=0:
            for i in range(len(curbd)):
                if self.curbd.lb==curbd[i].name:
                    self.curbd=curbd[i]
                    break
            self.x0=self.curbd.portx
            self.y0=self.curbd.porty
            return True
        if self.x0+self.length>=1000:
            for i in range(len(curbd)):
                if self.curbd.rb==curbd[i].name:
                    self.curbd=curbd[i]
                    break
            self.x0=self.curbd.portx
            self.y0=self.curbd.porty            
            return True
        if self.y0<=0:
            for i in range(len(curbd)):
                if self.curbd.ub==curbd[i].name:
                    self.curbd=curbd[i]
                    break
            self.x0=self.curbd.portx
            self.y0=self.curbd.porty             
            return True
        if self.y0+self.length>=1000:
            for i in range(len(curbd)):
                if self.curbd.db==curbd[i].name:
                    self.curbd=curbd[i]
                    break
            self.x0=self.curbd.portx
            self.y0=self.curbd.porty             
            return True
        return False
            
    def __str__(self):
        return 'Rick of %s is in %s board at (%d,%d) with speed (%.1f,%.1f)'%(self.bdname,self.curbd.name,self.x0,self.y0,self.dx,self.dy)