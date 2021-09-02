Sorting.o: Sorting.cpp Sorting.h
	g++ -c Sorting.cpp

Main.o: Main.cpp Sorting.cpp Sorting.h
	g++ -c Main.cpp

main: Sorting.o Main.o
	g++ -o main Main.o Sorting.o

run:
	./main input.txt

clean:
	/bin/rm -f *.o
	/bin/rm -f *~
	/bin/rm -f *#
