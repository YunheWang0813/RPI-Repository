HOMEWORK 9:  PRIORITY QUEUES FOR MESH SIMPLIFICATION


NAME:  < insert name >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

people:
Jassiem Ifill;
Jon Harris;
Joseph Grogan;
Prof Thompson;

resources:
www.cpluplus.com;
stackoverflow.com;
en.wikiversity.org;

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF 19 OF HOURS SPENT ON THIS ASSIGNMENT:  < insert # hours >


ALGORITHM ANALYSIS: 
Assume v_0 vertices, e_0 edges, and e_0 triangles in the initial mesh,
reduced to t_final triangles using the -shortest criteria.  What is
the overall order notation for the program?  Analyze the separate
compoenents of the program to justify your answer.

ALGORITHM ANALYSIS -- LINEAR:
O(e_0)(go through all triangles);
O(3)(check the 3 vertices);
O(t_final)(add function);

final::O(e_0+t_final)


ALGORITHM ANALYSIS -- PRIORITY QUEUE:
O(logn)(for parcolate up, down)




EXTRA CREDIT:  COLOR & OVERALL APPERANCE
Discuss the quality of your results in your README.txt and include
screenshots of your more impressive results.  If you have submitted
screenshots, give the file names and describe the results.



MISC. COMMENTS TO GRADER:  
Optional, please be concise!

I stacked at collapse function for 10 hours, and I still didn't figure the problem out. It seems all right to me, and I asked some TAs, and they couldn't 
discover the problem either. I'm really confused and I'm very upset because I don't have anymore late days... I implemented all the required place, so please
check these place even there is error on the server, thanks!




