#include<iostream>
#include<fstream>
#include<string>
#include <sstream>

using namespace std;

template <class T>
struct NodeType {  
  T data;
  NodeType<T> *next;
  NodeType<T> *back;  // doubly 
};

template <class T>
class DoublyLinkedList {
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertItem(T &item);
  void deleteItem(T &item);
  int lengthIs() const;
  void print();
  void printReverse();
  void readFile(char *input); // reading file 
  void deleteSubsection(T &lb, T &ub);
  T mode();
  void swapAlternate();
private:
  NodeType<T> *head;
  NodeType<T> *tail;
  int length; 
};
