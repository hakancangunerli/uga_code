#ifndef LISTNODE_H
#define LISTNODE_H

#include "ItemType.h"

struct ListNode {
    ItemType item;
    ListNode* next;
};

#endif
