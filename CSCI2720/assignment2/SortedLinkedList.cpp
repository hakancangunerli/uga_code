#include "SortedLinkedList.h"
#include <iostream>
#include <string>
#include "ItemType.h"
using namespace std;

// mon dieu many lines of aq


SortedLinkedList::SortedLinkedList()
{
    length =0; 
    head = NULL;
    currentPos = NULL; 
}// end default constructor

SortedLinkedList::~SortedLinkedList(){

} // destructor


int SortedLinkedList::getLLLength() const{
    return length;
} // end getLLLength


// TODO: 
void SortedLinkedList::insertItem(ItemType newItem){
// ○ General Case: Insert at the middle or end.
// ○ Special Cases:
// ■ Insert the first element
// ■ Insert in an empty list
// ■ Print “Sorry. You cannot insert the duplicate item” when the user tries to
// insert duplicate item




}

// TODO: 
void SortedLinkedList::deleteItem(ItemType item){

// ○ General Case: Deleting the last element or an element in the middle.
// ○ Special Cases:
// ■ Deleting the first element.
// ■ Deleting the only element.
// ■ Attempt to delete a non-existing item should print “Item not found”.
// ■ Attempt to delete from an empty list should print “You cannot delete from
// an empty list”.


}

int SortedLinkedList::searchItem(ItemType item){


    
}// end searchItem

// TODO
ItemType SortedLinkedList::getNextItem(){
// Notice: The code in the slides is not correct in this case because it didn’t check the end of the list or the empty list.
// ○ Print “List is empty” when the list is empty
// ○ Print “The end of the list has reached” when reach the end of the list or you can
// start printing the list again when end of list is reached (i.e go back to the first
// element from last last element)


}// end getNextItem

void SortedLinkedList::resetList(){
currentPos = NULL;
}// resetList
