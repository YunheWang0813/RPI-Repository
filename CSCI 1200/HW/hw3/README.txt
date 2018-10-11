HOMEWORK 3: DYNAMIC TETRIS ARRAYS


NAME:  Yunhe Wang


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

www.cpluplus.com
Srinivasan Iyer

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF 27 OF HOURS SPENT ON THIS ASSIGNMENT:  < insert # hours >



MISC. COMMENTS TO GRADER:  
Optional, please be concise!

Personal comment:
I really don't know the reason of memory leak in my program...
I check it again and again, and ask some TA's, but still not figure out. 
It may because I need to put:

for(int i=0;i<width;i++){
	delete [] data[i];
}

in some places, but it gives error when I put it inside the add/remove function...

it's 2/19/2016 now, and I can just submit it...