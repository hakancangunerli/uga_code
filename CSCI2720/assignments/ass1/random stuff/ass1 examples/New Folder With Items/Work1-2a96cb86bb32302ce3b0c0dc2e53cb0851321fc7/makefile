main: Main.o Instructor.o Student.o
	g++ -o main -g Main.o Instructor.o Student.o

Main.o: main.cpp
	g++ -g -c -Wall main.cpp

Instructor.o: Instructor.cpp Instructor.h
	g++ -g -c -Wall Instructor.cpp

Student.o: Student.cpp Student.h
	g++ -g -c -Wall Student.cpp

clean:
	rm -f *.o main