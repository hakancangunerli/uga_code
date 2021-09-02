compile:
	g++ -c -Wall -std=c++1y -pedantic-errors -g -O0 Student.cpp
	g++ -c -Wall -std=c++1y -pedantic-errors -g -O0 Instructor.cpp
	g++ -c -Wall -std=c++1y -pedantic-errors -g -O0 main.cpp
	g++ -o main Student.cpp Instructor.cpp main.cpp

run:
	./main instructors.txt students.txt

clean:
	rm main

