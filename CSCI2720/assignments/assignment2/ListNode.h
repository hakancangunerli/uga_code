// DONE

#ifndef LISTNODE_H
#define LISTNODE_H

#include "ItemType.h"

// node to use as the nodes in the linkedlist 
struct ListNode {
    ItemType item;
    ListNode* next;
};

#endif
