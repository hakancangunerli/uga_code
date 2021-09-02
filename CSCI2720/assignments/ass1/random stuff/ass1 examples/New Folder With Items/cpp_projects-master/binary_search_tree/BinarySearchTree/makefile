ItemType.o: ItemType.h ItemType.cpp
	g++ -c ItemType.cpp

BinaryTree.o: ItemType.h ItemType.cpp BinaryTree.h BinaryTree.cpp
	g++ -c BinaryTree.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

main: ItemType.o BinaryTree.o Main.o
	g++ -o main Main.o ItemType.o BinaryTree.o

clean:
	/bin/rm -f *.o
	/bin/rm -f *~
	/bin/rm -f *#

run:
	./main input.txt
