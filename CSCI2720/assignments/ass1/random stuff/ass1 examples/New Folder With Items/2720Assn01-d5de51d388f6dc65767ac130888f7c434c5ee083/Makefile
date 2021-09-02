main: Student.o main.o Instructor.o
	g++ -o main Student.o main.o Instructor.o
# Add Instructor.o to both top and bottom line

Student.o: Student.cpp Student.h
	g++ -std=c++14 -Wall -pedantic-errors -c -g -O0 Student.cpp

Instructor.o: Instructor.cpp Instructor.h Student.h
	g++ -std=c++14 -Wall -pedantic-errors -c -g -O0 Instructor.cpp

main.o: main.cpp Student.h Instructor.h 
	g++ -std=c++14 -Wall -pedantic-errors -c -g -O0 main.cpp

run: assn01
	./assn01

clean:
	/bin/rm -f *.o main
