ItemType.o: ItemType.h ItemType.cpp
	g++ -c ItemType.cpp

CircularLinkedList.o: ItemType.h ItemType.cpp CircularLinkedList.h CircularLinkedList.cpp
	g++ -c CircularLinkedList.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

main: ItemType.o CircularLinkedList.o Main.o
	g++ -o main Main.o ItemType.o CircularLinkedList.o

clean:
	/bin/rm -f *.o
	/bin/rm -f *~
	/bin/rm -f *#

run:
	./main input.txt
