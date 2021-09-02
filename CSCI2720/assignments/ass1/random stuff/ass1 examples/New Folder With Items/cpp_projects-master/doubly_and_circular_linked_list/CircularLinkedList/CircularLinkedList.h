#ifndef CLIST_H
#define CLIST_H

#include "ItemType.h"
#include "NodeType.h"

class CircularLinkedList {

private:
    int length;
    NodeType *head;

public:
    CircularLinkedList();
    ~CircularLinkedList();
    void findItem(NodeType* head, ItemType item, NodeType*& location, NodeType*& predLoc, bool& found);
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int lengthIs() const;
    void print();
    
};

#endif
