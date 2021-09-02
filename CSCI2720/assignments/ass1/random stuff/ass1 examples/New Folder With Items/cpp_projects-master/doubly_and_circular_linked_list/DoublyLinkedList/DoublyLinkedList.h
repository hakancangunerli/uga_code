#ifndef DLIST_H
#define DLIST_H

#include "ItemType.h"
#include "NodeType.h"

class DoublyLinkedList {

private:
    int length;
    NodeType *head;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void findItem(NodeType* head, ItemType item, NodeType*& location, NodeType*& predLoc, bool& found);
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int lengthIs() const;
    void print();
};

#endif
