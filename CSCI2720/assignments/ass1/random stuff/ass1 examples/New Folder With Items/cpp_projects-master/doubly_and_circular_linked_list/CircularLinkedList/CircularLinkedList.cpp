#include "ItemType.h"
#include "NodeType.h"
#include "CircularLinkedList.h"
#include <iostream>

using namespace std;

CircularLinkedList::CircularLinkedList() {
    length = 0;
    head = NULL;
} //default constructor

CircularLinkedList::~CircularLinkedList() {
    NodeType* temp;
    for (int i =0;i<length;i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
} //destructor

void CircularLinkedList::findItem(NodeType *head, ItemType item, NodeType*& location, NodeType*& predLoc, bool& found) {
    bool moreToSearch = true;
    location = head->next;
    predLoc = head;
    found = false;
    while (moreToSearch && !found) {
        if (item.compareTo(location->data) ==LESS) {
            moreToSearch = false;
        }
        else if (item.compareTo(location->data) ==EQUAL) {
            found = true;
        }
        else {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != head->next);
        }
    }
} //helper function for index shifting 

void CircularLinkedList::insertItem(ItemType item) {
    NodeType *temp = head;
    bool duplicate = false;
    for (int i =0; i<length; i++) {
        if (temp->data.compareTo(item)==EQUAL) {
            cout << "Item already exists." << endl;
            duplicate = true;
            break;
        }
        temp = temp->next;
    } //checking if it is a duplicate
    if (duplicate) {
        return;
    }
    
    NodeType* newNode; //inserted
    NodeType* predLoc; //trailing pointer
    NodeType* location; //traverling pointer
    bool moreToSearch; //if more nodes to search

    location = head;
    predLoc = NULL;
    moreToSearch=(location!=NULL);
    while (moreToSearch){
        switch(item.compareTo(location->data)) {
        case GREATER:
            predLoc = location;
            location = location->next;
            moreToSearch = (location!=head);
            break;
        case LESS:
            moreToSearch = false;
            break;
        }
    }
    newNode = new NodeType;
    newNode->data = item;

    if (predLoc == NULL) {
        newNode->next=head;
        head=newNode;
    } //inserting as a first element
    else {
        newNode->next = location;
        predLoc->next = newNode;
    }
    
    NodeType* temp2 = head; //this code links the last element with  the first element
    for (int i =0;i<length;i++) {
        temp2 = temp2->next;
    }
    temp2->next = head;
    length++;
} //insert item

void CircularLinkedList::deleteItem(ItemType item){

    NodeType *temp = head;
    bool duplicate = false;
    for (int i =0; i<length; i++) {
        if (temp->data.compareTo(item)==EQUAL) {
            duplicate = true;
            break;
        }
        temp = temp->next;
    } //checking if it is a duplicate
    if (!duplicate) {
        cout << "Item not in list!" << endl;
        return;
    }
    if (head->data.compareTo(item)==EQUAL) {
        if (length>1) {
            head = head->next;
            NodeType* tempp= head;
            for (int i =0;i<length-2;i++) {
                tempp=tempp->next;
            }
            tempp->next = head;
            length--;
            return;
        }
    }
    NodeType* location;
    NodeType* predLoc;
    bool found;

    findItem(head, item, location, predLoc, found);
    if (predLoc==location){ //if only node in list
        head = NULL;
    }
    else {
        predLoc->next = location->next;
        if (location == head) { //if deleting last node
            head = predLoc;
        }
    }
    delete location;
    length--;
} //delete item

int CircularLinkedList::lengthIs() const {
    return length;
}

void CircularLinkedList::print() {
    NodeType* temp = head; 
    for (int i =0;i<length;i++) {
        cout << temp->data.getValue() << " ";
        temp = temp->next;
    }
    cout << endl;
} //print values to standard output


    
