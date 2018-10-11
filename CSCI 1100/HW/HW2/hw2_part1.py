length=raw_input('Length of rectangular prism (m) ==> ')
print length
width=raw_input('Width of rectangular prism (m) ==> ')
print width
height=raw_input('Height of rectangular prism (m) ==> ')
print height

def volume_prism(length, width, height):
    vol=float(length)*float(width)*float(height)*70*3*30
    return vol

print "Water needed for",'('+str(float(length))+'m,'+str(float(width))+'m,'+str(float(height))+'m'+')', "locks is", str(volume_prism(length, width, height))+"m^3."

import math
volume=volume_prism(length, width, height)
radius=float(raw_input('Radius of cylinder (m) ==> '))
print int(radius)
def find_length(radius, volume):
    height=volume/math.pi/float(radius)**2
    return height
    
print "Lake with radius "+str(radius)+'m'+" will lose %.1f" %(find_length(radius, volume))+"m depth in three months."