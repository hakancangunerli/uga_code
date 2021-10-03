#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "ItemType.h"
#include "ListNode.h"

class SortedLinkedList {
 public:
    SortedLinkedList();
    ~SortedLinkedList();
    int getLength() const;
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    void deleteItem(int index);
    int searchItem(ItemType item);
    ItemType searchItem(int index);
    ItemType GetNextItem();
    void ResetList();
    void reverse();
    ListNode* findPrevNode(ListNode* node);
    ListNode* getLastNode();
    void printList();
   ListNode* getHead();
   void mergeList(SortedLinkedList* list);
  void printList(SortedLinkedList* list);
  bool isDuplicate(ItemType item);
  void deleteAlternate();
  void findCommonElements(SortedLinkedList* list);
    
 private:
    ListNode* head;
    ListNode* currentPos;
    int lengthValue;
};

#endif
