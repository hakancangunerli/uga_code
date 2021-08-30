/* 
Let's say our code has 5 files, 
main.cpp, a main program.
•Point.h, header file for the Point class.•
Point.cpp, implementation file for the Point class.
•Rectangle.h, header file for the Rectangle class.
•Rectangle.cpp, implementation file for the Rectangle class.


to compile the headers etc you just do what it says here, 
gcc -c main.cpp 
gcc -c Point.cpp 
gcc -c Rectangle.cpp 

 without makefile
 gcc -c Gradebook.cpp 
 gcc -c main.cpp 
 gcc -o main main.o Gradebook.o
 this'll produce the a.out



this will generate object files which then can be linked using the linker. 

gcc - o main.o Point.o Rectangle.o


*/ 



