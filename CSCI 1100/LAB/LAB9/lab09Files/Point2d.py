"""
    Class for creating and manipulating 2-dimensional points
"""

import math

class Point2d(object):
    def __init__(self, x0=0, y0=0):
        """ Method to initialize. x=0,y=0 provides default values.
            Example calls::

                   x = Point2d(5,10) 
                   x = Point2d()  ## same as x = Point2d(0,0)

        """
        self.x = x0
        self.y = y0
        
    def __str__(self): 
        """ Method to print the object   """

        return '(%d, %d)' %(self.x, self.y)
    
    def scale(self, c): 
        """ Method to scale a point """
        self.x *= c
        self.y *= c
        
    def magnitude(self): 
        """ Returns the magnitude of an object """
        return math.sqrt( self.x**2 + self.y**2 )
    
    def distance(self, other):
        """ Returns the distance of an object to another """
        dx = self.x - other.x
        dy = self.y - other.y
        return math.sqrt ( dx**2 + dy**2 )
    
    def grid_distance(self, other):
        """ Returns the grid distance between two points """
        dx = self.x - other.x
        dy = self.y - other.y
        return abs(dx) + abs(dy)

    def copy(self):
        """ Returns a new object identical to the current one. """
        return Point2d(self.x, self.y)
    
    def __add__(self, other): 
        """ Called when adding two points: pt1 + pt2, returns a new object """
        newx = self.x+other.x
        newy = self.y+other.y
        pt = Point2d(newx, newy)  ## create a new object to return
        return pt

    def __sub__(self, other): 
        """ Called when subtracting two points: pt1 - pt2, returns a new object  """
        
        return Point2d( self.x-other.x, \
                        self.y-other.y )

    def __eq__(self, other):
        """ Called when checking if two points are equal: pt1 == pt2.
            Returns a Boolean """
        return self.x==other.x and self.y==other.y
    
    
    def move(self, command):
        command = command.lower()
        if command == 'up':
            self.y += 1
        elif command == 'down':
            self.y -= 1
        elif command == 'left':
            self.x -= 1
        elif command == 'right':
            self.x += 1
        
if __name__ == '__main__':
    ### first let us tests all the implemented methods 
    pt1 = Point2d(5, 10)  ##cals to __init__
    pt2 = Point2d(10, 20)  ##cals to __init__
    print pt1, pt2 ##cals to __str__
    pt1.scale(10)  ## function that returns no value is called like this
    m = pt1.magnitude()  ## function returns value but takes no arguments
    print m
    d = pt1.distance(pt2)  ## function to find distance between two points
    d2 = pt2.distance(pt1) ## which returns a value
    print d, d2   ## the two different ways to call should be equal

    pt3 = pt1+pt2 ## calls __add__
    print pt3
    pt3 = pt1-pt2 ## calls __sub__
    print pt3
    
    pt4 = pt1.copy()
    print pt4
    print pt4==pt1, '(True if copy works)' ## calls __eq__, they should be the same
    print pt1==pt2, '(should be False)' ## they should be different


    ## Let us use the points to move two objects 
    print
    print 'HW solution'
    pt1 = Point2d(5, 10)
    cmd1 = ['up','down','left']
    pt2 = Point2d(15, 3)
    cmd2 = ['right','stay', 'down']

    print "Wallace at:", pt1, "Gromit at:", pt2
    for i in range(len(cmd1)):
        pt1.move( cmd1[i] )
        pt2.move( cmd2[i] )
        print pt1, pt2, pt1.grid_distance(pt2)
