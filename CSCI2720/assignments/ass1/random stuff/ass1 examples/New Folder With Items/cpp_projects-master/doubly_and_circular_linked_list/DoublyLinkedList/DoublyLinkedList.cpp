#include "ItemType.h"
#include "NodeType.h"
#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList(){
    length = 0;
    head=NULL;
} //default constructor 

DoublyLinkedList::~DoublyLinkedList(){
    NodeType* temp;
    for (int i =0;i<length;i++) {
        temp = head;
        head = head->next;
        delete temp;
    }
} //destructor

void DoublyLinkedList::findItem(NodeType* head, ItemType item, NodeType*& location, NodeType*& predLoc, bool& found){
    bool moreToSearch=true;
    location = head;
    predLoc = head;
    int counter = 0;
    found=false;
    while(moreToSearch&&!found) {
        if (item.compareTo(location->data)==LESS) {
            moreToSearch=false;
        }
        else if (item.compareTo(location->data)==EQUAL) {
            found = true; // if item exists
        }
        else {
            location = location->next;
            if (counter==0) {
                counter++;
            }
            else {
                predLoc = predLoc->next;
            }
            moreToSearch = (location !=NULL);
        }
    }
} //helper function for index shifting 

void DoublyLinkedList::insertItem(ItemType item){
    if (length==0) { //if list is empty
        NodeType *newNode = new NodeType;
        newNode->data = item;
        head = newNode;
        newNode->next=NULL;
        newNode->back=NULL;
        length++;
        return;
    }
    
    NodeType* location;
    NodeType* predLoc;
    bool found;

    findItem(head, item, location, predLoc, found); //find the correct location for insertion
    if (found) { //if duplicates
        cout << "Item already in list" << endl;
        return;
    }
    
    NodeType* newNode = new NodeType;
    newNode->data = item;
    
    if (location == NULL) { //if inserting at the end
        newNode->back = predLoc;
        newNode->next = NULL;
        NodeType* temp = predLoc;
        temp->next = newNode;
        length++;
        return;
    }
    if (item.compareTo(head->data)==LESS) { //if inserting at the front
        newNode->back = NULL;
        newNode->next = predLoc;
        predLoc->back = newNode;
        head = newNode;
        length++;
        return;
    } 
    
    //general case
    newNode->back = location->back;
    newNode->next = location;
    NodeType* temp = location->back;
    temp->next = newNode;
    location->back = newNode;

    length++;
} //inserting item

void DoublyLinkedList::deleteItem(ItemType item){
    
    if (length==0) { //if attempting to delete from an empty list
        cout << "item not in list" << endl;
        return;
    } 

    if (length==1&item.compareTo(head->data)==EQUAL) { //deleting the only node
        length = 0;
        head=NULL;
        return;
    } 


    if (item.compareTo(head->data)==EQUAL) { //deleting first node
        head = head->next;
        head->back = NULL;
        length--;
        return;
    }
    
    NodeType* location;
    NodeType* predLoc;
    bool found;

    findItem(head, item, location, predLoc, found); //find the correct location for deletion
    if (!found) { //if item does not exist
        cout << "Item not in list" << endl;
        return;
    }

    
    if (location->next == NULL) { //deleting the last node
        location->back->next = NULL;
        length--;
        return;
    }
    
    //general case
    location->back->next = location->next;
    location->next->back = location->back;
    length--;
} //deleting item

int DoublyLinkedList::lengthIs() const{
    return length;
} //returns length as an int

void DoublyLinkedList::print(){
    NodeType* temp = head; 
    for (int i =0;i<length;i++) {
        cout << temp->data.getValue() << " ";
        temp = temp->next;
    }
    cout << endl;
} //print list to standard output