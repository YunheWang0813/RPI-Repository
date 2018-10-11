HOMEWORK 6: BATTLESHIP RECURSION


NAME:  Yunhe Wang



COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

people:
Srinivasan Iyer;
Yihao Zhu;
Katherine Colon;
Renjie Xie;
Jassiem Ifill;
Jon Harris;
Joseph Grogan;
Hendrik Weideman;
Greg Cowan;
Dan Gay;
John Andrews;
Prof Thompson;
Prof Gonsiorowski;

resources:
www.cpluplus.com;
stackoverflow.com;
en.wikiversity.org;

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF 32 OF HOURS SPENT ON THIS ASSIGNMENT:  < insert # hours >



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(order notation & concise paragraph, < 200 words)
The dimensions of the board (w and h) 
The number of ships (s)? 
The total number of occupied cells (o) or open water (w)? 
The number of constraints (c)? 
The number of unknown sums (u) or unspecified ship types (t)? 
Etc. 

The program will go through every part of the coordinate twice, so O(w*h) first.
Then, it need to call itself recursively the number of ships times, so O(w*h*s).
In addition, when a new ship add to the map, it need to check the availability of
it, so it need to check the occupied cells, so O(w*h*s*o).
If there are constraints, it should go through the solution to check if the 
solution match the constraint, so O(w*h*s*o*c).
If there are unknown data, it will try all of the possible solutions by continuously changing
col/row sums and ship types.
So finally, order notation is O(w*h*s*o*c*u*t)

SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES:
# of solutions & approximate wall clock running time for different
puzzles for a single solution or all solutions.

name					single-time     all-time	solutions
puzzle_sample.txt 		0.1s			0.1s		2
puzzle1.txt				0.1s			0.1s		1
puzzle2.txt				0.3s			4s			1
puzzle3.txt				1s				3s			1
puzzle4.txt             1s				3s			1
puzzle5.txt				0.1s			0.2s        2
puzzle6.txt				12s 			20s			24
puzzle7.txt				4s				10s			14
puzzle8.txt             x				x			x
puzzle9.txt				x				x			x
puzzle10.txt			x				x			x
("x" means I didn't get the answer)

MISC. COMMENTS TO GRADER:  
I know my program is inefficient, but it is because I fixed a lot of bugs at friday and
there is no more available time... If I have more time, I will make some changes about
loops (add break, skip unnessesary procedure, etc), and also use more sort method to 
make the program more efficient.


