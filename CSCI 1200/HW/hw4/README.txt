HOMEWORK 4: GROCERY LISTS


NAME:  Yunhe Wang


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

www.cplusplus.com
Andrew Yale
Srinivasan Iyer 
Yihao Zhu

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF 12 OF HOURS SPENT ON THIS ASSIGNMENT:  < insert # hours >



ORDER NOTATION:
For each request/command,

i = # of different ingredients in the kitchen
u = maximum units of a single ingredient in the kitchen
r = # of different recipes
k = maximum # of different ingredients in a single recipe
v = maximum units of single ingredient in a single recipe
a = maximum # of different ingredients added with a single ’a’ command 
w = maximum units of a single ingredient added with a single ’a’ command


command 'r' / add a recipe:
O(r)
command 'a' / add ingredients to the kitchen:
O(i)
command 'p' / print a recipe:
O(k)
command 'm' / make a recipe:
O(r*u*k*v)
command 'k' / print the contents of the kitchen:
O(i)
command 's' / suggest recipes:
O(r*i*k)

(extra credit) command 'd' / suggest dinner menu:



EXTRA CREDIT:
Describe your implementation of the "suggest dinner menu" option.



MISC. COMMENTS TO GRADER:  
(optional, please be concise!)


