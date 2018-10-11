import time
from lab10 import *

if __name__=='__main__':
    L1 = []
    for i in range(20000):
        L1.append(random.uniform(0.0,1000.0))
    start1=time.time()
    print closest1(L1)
    end1=time.time()
    print end1-start1
    start2=time.time()
    print closest2(L1)
    end2=time.time()
    print end2-end1