'''
This is code to test your functions in this lab.  It is driven by a
Python module called nose, which has been imported here.  

We assume your program is called lab10.py, and we import all the
function in your program here. Make sure any other code in lab10.py
is under the 

     if __name__ == "__main__":

line.

Nose testing module is actually relative simple.

To understand it, start by looking at the main code at the bottom of
the file.  The function call nose.runmodule() causes nose to scan back
up through the preceeding code and find all functions that start with
test_.  Nose runs these functions in turn.  Each function must end
with an 'assert' statement followed by a boolean condition.  If the
boolean condition evaluate to True, nose does not say anything.  If a
condition evaluates to False, the "assert" is said to "fail".  Nose
detects these failures and tells you about them.  To see the behavior
of Nose, change some of the assert statements (for example, try == 3 for 
any test) and see what happens.

'''

import nose
from lab10 import *

def test_closest1_1():
    L1 = [23,67]
    L2 = [67,23]
    L3 = [-2,20,299,5,697,1990]
    L4 = [-2,5,20,299,1990,697]
    L5 = [-2,299,1990,697,20,5]
    L6 = [1,4,6]
    L7 = [2,2,4]
    L8 = [3,3,3]
    out1 = closest1(L1)
    out2 = closest1(L2)
    out3 = closest1(L3)
    out4 = closest1(L4)
    out5 = closest1(L5)
    out6 = closest1(L6)
    out7 = closest1(L7)
    out8 = closest1(L8)
    assert out1 == (23,67)
    assert out2 == (67,23)
    assert out3 == (-2,5)
    assert out4 == (-2,5)
    assert out5 == (-2,5)
    assert out6 == (4,6)
    assert out7 == (2,2)
    assert out8 == (3,3)
    
def test_closest2_1():
    L1 = [23,67]
    L2 = [67,23]
    L3 = [-2,20,299,5,697,1990]
    L4 = [-2,5,20,299,1990,697]
    L5 = [-2,299,1990,697,20,5]
    L6 = [1,4,6]
    L7 = [2,2,4]
    L8 = [3,3,3]    
    out1 = closest2(L1)
    out2 = closest2(L2)
    out3 = closest2(L3)
    out4 = closest2(L4)
    out5 = closest2(L5)
    out6 = closest2(L6)
    out7 = closest2(L7)
    out8 = closest2(L8)
    assert out1 == (23,67)
    assert out2 == (23,67)
    assert out3 == (-2,5)
    assert out4 == (-2,5)
    assert out5 == (-2,5)
    assert out6 == (4,6)
    assert out7 == (2,2)
    assert out8 == (3,3)
    
    
if __name__ == "__main__":
    nose.runmodule()
