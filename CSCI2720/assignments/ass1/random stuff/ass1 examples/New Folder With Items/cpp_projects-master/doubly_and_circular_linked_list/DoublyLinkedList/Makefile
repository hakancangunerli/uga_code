ItemType.o: ItemType.h ItemType.cpp
	g++ -c ItemType.cpp

DoublyLinkedList.o: ItemType.h ItemType.cpp DoublyLinkedList.h DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

main: ItemType.o DoublyLinkedList.o Main.o
	g++ -o main Main.o ItemType.o DoublyLinkedList.o

clean:
	/bin/rm -f *.o
	/bin/rm -f *~
	/bin/rm -f *#

run:
	./main input.txt
