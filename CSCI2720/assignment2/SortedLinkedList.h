#include <iostream> 
#include <string>
#include "ListNode.h"
// DONE 

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "ItemType.h"
//ifndef stuff 

class SortedLinkedList{
    public:
    SortedLinkedList();
    ~SortedLinkedList(); // destructor 
    int getLLLength() const; // get length of list, had to name it like this cause i also need the int length; 
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int searchItem(ItemType item);
    ItemType getNextItem();
    void resetList();
    void printList(SortedLinkedList* list);

    private:
    ListNode *head;
    ListNode *currentPos; 
    int length; 
};

#endif