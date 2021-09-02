Student.o: Student.h Student.cpp
	g++ -c Student.cpp

Instructor.o: Instructor.h Instructor.cpp Student.h Student.cpp
	g++ -c Instructor.cpp

main.o: main.cpp
	g++ -c main.cpp

main: Student.o Instructor.o main.o
	g++ -o main main.o Student.o Instructor.o

clean:
	/bin/rm -f *.o
	/bin/rm -f *~
	/bin/rm -f *#

run:
	./main instructors.txt students.txt
