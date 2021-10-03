FLAGS = -g -Wall -std=c++11

compile: main

main: ItemType.cpp SortedLinkedList.cpp main.cpp
	g++ $(FLAGS) -o main ItemType.cpp SortedLinkedList.cpp main.cpp

run:
	./main input.txt

clean:
	rm main
