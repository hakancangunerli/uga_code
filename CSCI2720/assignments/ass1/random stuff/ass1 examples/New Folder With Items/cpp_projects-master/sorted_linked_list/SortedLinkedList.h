#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "ItemType.h"
#include "ListNode.h"

class SortedLinkedList {
    
private:
    int length;
    ListNode *head;
    ListNode *currentPos;

public:
    SortedLinkedList();
    ~SortedLinkedList();
    int getLength() const;
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int searchItem(ItemType &item);
    ItemType GetNextItem();
    void ResetList();
    void reverse();

};
#endif
