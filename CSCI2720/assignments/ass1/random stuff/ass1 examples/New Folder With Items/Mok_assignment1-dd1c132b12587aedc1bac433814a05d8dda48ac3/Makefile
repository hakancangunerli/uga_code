CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c -std=c++14 $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile: main.out

main.out: main.o Student.o Instructor.o
	$(CC)	$(LFLAGS)	-o	main.out	main.o	Student.o	Instructor.o

main.o: main.cpp Student.o Instructor.o
	$(CC)	$(CFLAGS)	main.cpp

Student.o: Student.cpp Student.h
	$(CC)	$(CFLAGS)	Student.cpp

Instructor.o: Instructor.cpp Instructor.h
	$(CC)	$(CFLAGS)	Instructor.cpp

run: main.out
	./main.out instructors.txt students.txt

clean:
	rm *.o
	rm *.out

