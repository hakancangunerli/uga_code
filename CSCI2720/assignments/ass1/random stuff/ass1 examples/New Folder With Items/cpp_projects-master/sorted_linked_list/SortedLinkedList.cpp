#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"
#include <iostream>

using namespace std;

SortedLinkedList::SortedLinkedList() {
    length = 0;
    head = NULL;
    currentPos = NULL;
} //default constructor

SortedLinkedList::~SortedLinkedList() {
    ListNode* tempPtr;
    while(head != NULL) {
        tempPtr = head;
        head = head->next;
        delete tempPtr;
    } //traverse each node
} // deletes all nodes

int SortedLinkedList::getLength() const {
    return length;
} //returns length

void SortedLinkedList::insertItem(ItemType item) {
    if (SortedLinkedList::searchItem(item) != -1) {
        cout << "item already in the list" << endl;
        return;
    } // if dulplicate
    ListNode* newNode; //inserted
    ListNode* predLoc; //trailing pointer
    ListNode* location; //traverling pointer
    bool moreToSearch; //if more nodes to search

    location = head;
    predLoc = NULL;
    moreToSearch=(location!=NULL);
    while (moreToSearch){
        switch(item.compareTo(location->item)) {
        case GREATER:
            predLoc = location;
            location = location->next;
            moreToSearch = (location!=NULL);
            break;
        case LESS:
            moreToSearch = false;
            break;
        }
    }
    newNode = new ListNode;
    newNode->item = item;

    if (predLoc == NULL) {
        newNode->next=head;
        head=newNode;
    } //inserting as a first element
    else {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

void SortedLinkedList::deleteItem(ItemType item) {
    if (SortedLinkedList::searchItem(item) == -1) {
        cout << "Item not present in the list" << endl;
        return;
    } //if item is not present 
    ListNode* location = head;
    ListNode* tempLocation;
    if (item.compareTo(head->item) == EQUAL) {
        tempLocation = location;
        head=head->next;
    } //deleting first node
    else {
        while((item.compareTo(location->next->item)) != EQUAL) {
            location = location->next;
        }
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
        
}

int SortedLinkedList::searchItem(ItemType &item) {
    int counter = -1; //counter that keeps trach of item index
    if (length == 0) {
        return -1;
    }
    ListNode* temp = head;
    for (int i = 0 ;i<length;i++) {
        if (item.compareTo(temp->item)==EQUAL) {
            counter = i ;
            break;
        }
        temp=temp->next; //next iteration 
    }
    return counter; 
} //search for an item and returns its index

ItemType SortedLinkedList::GetNextItem() {
    ItemType item;
    if (currentPos ==NULL) {
        currentPos = head;
    } 
    item=currentPos->item;
    currentPos=currentPos->next;
    return item;
} //iterate through each elements 

void SortedLinkedList::ResetList() {
    currentPos = NULL;
} //resets the iteration by setting the current position to null

void SortedLinkedList::reverse() {
    ListNode* current = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while (current!=NULL) { //storing next element
        next = current->next;
        current->next = prev;
        prev = current;
        current= next;
    }
    head = prev;
} //reverses the list 

