import math
from Board import *
from Rick import *

if __name__=='__main__':
    myfile=raw_input('Board file name => ')
    print myfile
    myfile=open(myfile)
    myfile=myfile.read()
    myfile=myfile.split()
    myfile2=[]
    for i in range(len(myfile)):
        myfile2.append(myfile[i].split('|'))
    bd=[]
    for i in range(len(myfile2)):
        obs=[]
        for j in range(8,len(myfile2[i]),2):
            obs.append((int(myfile2[i][j]),int(myfile2[i][j+1])))
        bd.append(Board(myfile2[i][0],myfile2[i][1],myfile2[i][2],myfile2[i][3],myfile2[i][4],myfile2[i][5],myfile2[i][6],myfile2[i][7],obs))
    rickfile=raw_input('Rick file name => ')
    print rickfile
    rickfile=open(rickfile)
    rickfile=rickfile.read()
    rickfile=rickfile.split()
    rickfile2=[]
    for i in range(len(rickfile)):
        rickfile2.append(rickfile[i].split('|'))
    R=[]
    for i in range(len(rickfile)):
        R.append(Rick(rickfile2[i][0],rickfile2[i][1],rickfile2[i][2],rickfile2[i][3],rickfile2[i][4],rickfile2[i][5],bd))
    
    for i in range(len(myfile2)):    
        print Board(myfile2[i][0],myfile2[i][1],myfile2[i][2],myfile2[i][3],myfile2[i][4],myfile2[i][5],myfile2[i][6],myfile2[i][7],obs)
        
    caught=[]
    for time in range(1,101):
        if time==1:
            print
            print 'All Ricks'
            for r in R:
                print 'Time 0: Rick of %s is in %s board at (%d,%d) with speed (%.1f,%.1f)'%(r.bdname,r.curbd.name,r.x0,r.y0,r.dx,r.dy)
            print '---------------------------------------------------------------------------'
            
        for r in R:
            if r.alive:
                r.move()
                if r.clash(bd):
                    n=r.loc
                    print
                    print 'Time %d: Rick of %s crashed into object at (%d,%d) in %s board\n\tNew speed is (%.1f, %.1f)'\
                          %(time,r.bdname,r.curbd.obs[n][0],r.curbd.obs[n][1],r.curbd.name,r.dx,r.dy)
                if r.newloc(bd):
                    print
                    print 'Time %d: Rick of %s moved from %s board to %s board'\
                          %(time,r.bdname,r.oriloc,r.curbd.name)
                    print '\tPast location: Rick of %s is in %s board at (%d,%d) with speed (%.1f,%.1f)'\
                          %(r.bdname,r.oriloc,r.orix,r.oriy,r.dx,r.dy)
                    print '\tCurrent location: Rick of %s is in %s board at (%d,%d) with speed (%.1f,%.1f)'\
                          %(r.bdname,r.curbd.name,r.curbd.portx,r.curbd.porty,r.dx,r.dy)

        for r in R:
            if r.collide(R,bd):
                print
                print 'Time %d: Rick of %s collided with Rick of %s in %s board'%(time,r.bdname,R[r.orbd].bdname,r.oriloc)
                print '\tRick of %s is in %s board at (%d,%d) with speed (%.1f,%.1f)'%(r.bdname,r.bdname,r.curbd.portx,r.curbd.porty,r.dx,r.dy)
                print '\tRick of %s is in %s board at (%d,%d) with speed (%.1f,%.1f)'%(R[r.orbd].bdname,R[r.orbd].bdname,R[r.orbd].curbd.portx,R[r.orbd].curbd.porty,R[r.orbd].dx,R[r.orbd].dy)
            if r.stop(bd):
                print
                print 'Time %d: Rick of %s in %s board location (%d,%d) with speed magnitude %.1f stops'\
                      %(time,r.bdname,r.curbd.name,r.x0,r.y0,r.mgn)
            if r.alive==False:
                caught.append(r)
                        
        if time%10==9:
            print
            print '---------------------------------------------------------------------------'
            print 'End of time %d: all free Ricks'%time
            for r in R:
                if r.alive:
                    print 'Rick of %s is in %s board at (%d,%d) with speed (%.1f,%.1f)'%(r.bdname,r.curbd.name,r.x0,r.y0,r.dx,r.dy)
            print '---------------------------------------------------------------------------'
            
        if len(caught)==len(rickfile):
            print
            print '---------------------------------------------------------------------------'
            print 'Time %d: Simulation ended'%time
            print
            print 'No Ricks were left alive!'
            print
            print 'The following Ricks were caught by Transdimensional Council of Ricks:'
            for i in range(len(caught)):
                print '\tRick of %s'%caught[i].bdname
            print '---------------------------------------------------------------------------'
            print
            break
        
        if time==100:
            print
            print '---------------------------------------------------------------------------'
            print 'Time 100: Simulation ended'
            print
            print 'The following Ricks are still alive:'
            for r in R:
                if r.alive:
                    print '\tRick of %s is in %s board at (%d,%d) with speed (%.1f,%.1f)'%(r.bdname,r.curbd.name,r.x0,r.y0,r.dx,r.dy)
            print
            if len(caught)==0:
                print 'No Ricks were caught by Transdimensional Council of Ricks'
            else:
                print 'The following Ricks were caught by Transdimensional Council of Ricks:'
                for r in caught:
                    print '\tRick of %s'%r.bdname
            print '---------------------------------------------------------------------------'
            
    
    out=open('out6.txt')
    out=out.read()