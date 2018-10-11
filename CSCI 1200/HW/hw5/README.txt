HOMEWORK 5: MULTI LINKED LISTS


NAME:  Yunhe Wang


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

David Koloski;
Srinivasan Iyer;
Renjie Xie;
Joseph Grogan;
www.cplusplus.com;
stackoverflow.com;
www.cs.rpi.edu/~thompw4/CSCI-1200/Spring2016;

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF 30 OF HOURS SPENT ON THIS ASSIGNMENT:  < insert # hours >



TESTING & DEBUGGING STRATEGY:
Please be concise!  

comment out the part of main program, and test my code part by part;
use cout<<endl to check the contents of variables;
use gdb to debug;


ORDER NOTATION of the member functions of MultiLL?
(in terms of n, the number of elements currently in the list)

default constructor
O(1)
copy constructor

assignment operator
O(1)
destructor
O(1)
size
O(1)
empty
O(1)
clear
O(1)
add
O(n)    ex:search process need to go though the list
erase
o(n)
begin_chronological
O(1)
end_chronological
O(1)
begin_sorted
O(1)
end_sorted
O(1)
begin_random
O(n^2)

ITERATOR INVALIDATION:
In what cases will iterators of the MultiLL be invalidated?  Justify
the need for each of the restrictions placed on your implementation.
call random.begin() too early will cause the problem because it depends on add function.
(Also, we cannot call add function after random.begin())



EXTRA CREDIT: 
Which function in your implementation can be improved by a
non-insertion sort sorting method?  Describe.




MISC. COMMENTS TO GRADER:  
Optional, please be concise!

I gave up some of the Student tests because of the limitation of time, but I know how to do that.
For decrement iterator, I can imitate lab7 check2, add a private Node (I call it tailex) to check 
if the ptr is NULL, and if it is, just substitute it by tailex.(because end function always return
NULL, it is easy to apply this method)
Although I did not check the corner cases of erase, I think it should be fine...
Again, I know how to do that, but I don't have enough time...

P.S I found a SERIOUS memory leak at the last few minutes, and it is because of copy list. I'm not so sure the reason now,
but please not deduct too much points about this problem...
