ItemType.o: ItemType.h ItemType.cpp
	g++ -c ItemType.cpp

SortedLinkedList.o: ItemType.h ItemType.cpp SortedLinkedList.h SortedLinkedList.cpp
	g++ -c SortedLinkedList.cpp

main.o: main.cpp 
	g++ -c main.cpp

main: ItemType.o SortedLinkedList.o main.o
	g++ -o main main.o ItemType.o SortedLinkedList.o

clean:
	/bin/rm -f *.o
	/bin/rm -f *~
	/bin/rm -f *#

run:
	./main input.txt
