class Board(object):
    def __init__(self,name,grav,portx,porty,rb,ub,lb,db,obs):
        self.name=name
        self.grav=int(grav)
        self.portx=int(portx)
        self.porty=int(porty)
        self.rb=rb
        self.ub=ub
        self.lb=lb
        self.db=db
        self.obs=obs
             
    def __str__(self):
        return 'Board %s: Portal location: (%d,%d), Gravity: %d\n\tObstacles at: %s\n\tPortals to: right: %s, up: %s, left: %s, down: %s'\
               %(self.name,self.portx,self.porty,self.grav,self.obs,self.rb,self.ub,self.lb,self.db)