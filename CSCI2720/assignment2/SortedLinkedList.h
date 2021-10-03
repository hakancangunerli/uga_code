// DONE

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "ItemType.h"
#include "ListNode.h"

class SortedLinkedList {
 public:
    SortedLinkedList(); // initialize sorted linked list object
    ~SortedLinkedList(); // destructor
    int getLLLength() const; // return length 
    void insertItem(ItemType item); // item insertion with general and special cases 
    void deleteItem(ItemType item);  // item deletion with general and special cases
    int searchItem(ItemType item); // item search, if cannot be found say item not found or if empty say empty list. 
    ItemType GetNextItem(); //  get next item pointed by the currentPos
    void ResetList(); // currentPos pointer too null. 
   ItemType GetNextItemEndofList();
    ListNode* findPrevNode(ListNode* node); 
    ListNode* getLastNode();
    void printList();
   ListNode* getHead(); // get the head of the list
   void mergeList(SortedLinkedList* list); // merging list pseucode on readme file. 
  void printList(SortedLinkedList* list); // printlist the list
  bool isDuplicate(ItemType item); // finding duplicates
  void deleteAlternate(); // alternating deletion
  void findCommonElements(SortedLinkedList* list); // finding common elements, somewhat similar to isDuplicate.
   
 private:
    ListNode* head;
    ListNode* currentPos;
    int length;
};

#endif
