""" Class example, a simple class of 2d objects 


"""

class Point2d(object):
    def __init__(self, x0, y0):
        """Initialize to make sure each point has an x, y value. """
        self.x = x0
        self.y = y0
        
    def length(self):
        """ Return the length of a point. """
        return (self.x**2 + self.y**2)**(0.5)
    
    def __str__(self):
        """ Returns the string representation of object. 
            Call as:
 
            str(x)
            print x  ##calls this function and prints the result string

        """
        return "(%d, %d)" %(self.x, self.y)
      
    def distance(self, other):
        """ Returns the distance between two points. """
        d = (self.x-other.x)**2 + (self.y-other.y)**2
        return d**(0.5)
      
    def __add__(self, other):
        """ Adds two points and returns a new point with the 
            addition of values. You can call this as:

            pt1.__add__(pt2)
            pt1+pt2
   
        """

        new = Point2d(self.x, self.y)
        new.x += other.x
        new.y += other.y
        return new
    
    def __sub__(self, other):
        """ Subtracts other from self, and returns a new point 
            containing the result. You can call this as:

            pt1.__sub__(pt2)
            pt1-pt2
   
        """
        new = Point2d(self.x, self.y)
        new.x -= other.x
        new.y -= other.y
        return new

if __name__ == "__main__":
    ##Test code here
    pt1 = Point2d(10, 20)
    pt2 = Point2d(3, 4)
    
    print pt1.x, pt1.y
    print pt2.x, pt2.y

    print pt1 ## calls the __str__ method
    print str(pt1) ## this is identical to the above call
    
    print "Length of pt1 is", pt1.length()
    print "Length of pt2 is", pt2.length()
    
    print "Distance between", pt1, "and", pt2, "is:", pt1.distance(pt2)
    print pt1  ##calls str
     
    pt3 = pt1+pt2
    print pt3

    print "Subtraction:", pt1-pt2
    print "Pt1:", pt1, "Pt2:", pt2
    print "Add/Subtract do not change the input objects"
