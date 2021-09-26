
#include <iostream>
#include <string>
#include "ItemType.h"
#include "SortedLinkedList.h"

using namespace std;

SortedLinkedList::SortedLinkedList()
{
    length = 0;
    head = NULL;
    currentPos = NULL;
} // end default constructor

SortedLinkedList::~SortedLinkedList()
{

} // destructor

int SortedLinkedList::getLLLength() const
{
    return length;
} // end getLLLength

// TODO:
void SortedLinkedList::insertItem(ItemType newItem)
{
    // ○ General Case: Insert at the middle or end.
    // ○ Special Cases:
    // ■ Insert the first element
    // ■ Insert in an empty list
    // ■ Print “Sorry. You cannot insert the duplicate item” when the user tries to
    // insert duplicate item

    if (length ==0){
     ListNode* newNode = new ListNode();
     newNode-> item = item;
     newNode-> next = NULL;
     head = newNode;
    length++;
    return;
    }// the length being zero taken care of.
    ListNode* newNode;
    ListNode* predLoc;
    ListNode* location;
    bool moreSearch;

    location = head;
    predLoc = NULL;
    moreSearch = (location != NULL);

    while (moreSearch){
        if (location->item.compareTo(item) == Comparison::GREATER) {
            predLoc = location;
            location = location->next;
            moreSearch = (location != NULL);
        }else if (location-> item.compareTo(item) == Comparison::EQUAL){
            cout << "you cannot insert the duplicate item" << endl;
            return;
        }else{
            moreSearch = false;
        }
    }


}// insertItem

void SortedLinkedList::deleteItem(ItemType item)
{

    // ○ General Case: Deleting the last element or an element in the middle.
    // ○ Special Cases:
    // ■ Deleting the first element.
    // ■ Deleting the only element.
    // ■ Attempt to delete a non-existing item should print “Item not found”.
    // ■ Attempt to delete from an empty list should print “You cannot delete from
    // an empty list”.
    if (length == 0)
    {
        cout << "You cannot delete from an empty list" << endl;
        return;
    }

    ListNode *predloc = NULL;
    ListNode *location = head;
    bool foundYet = false;
    bool searchBool = (location != NULL);
    // deletion always requires a search first
    switch (location->item.compareTo(item))
    {
        {
        case Comparison::EQUAL:
            foundYet = true;

            /* code */
            break;
        case Comparison::GREATER:
            predloc = location;
            location = location->next;
            searchBool = (location != NULL);

            break;
        case Comparison::LESS:
            searchBool = false;
            break;

        default:
            cout << "issue within the switch statement." << endl;
            break;
        }
    }

    ListNode *temp = location;
    if (searchBool == false)
    {
        cout << "Item not found" << endl;
        return;
    }
    else if ((foundYet == true) && (predloc == NULL))
    {
        head = temp->next;
        delete temp;
    }
    else if (foundYet == true)
    {
        predloc->next = temp->next;
        delete temp;
    }
    length--;

} // deleteItem

int SortedLinkedList::searchItem(ItemType item)
{

    int index;
    index = 0;
    ListNode *location = head;
    bool foundYet = false;
    bool searchBool = (location != NULL);

    while (searchBool && !foundYet)
    {

        switch (location->item.compareTo(item))
        {
            {
            case Comparison::EQUAL:
                foundYet = true;

                /* code */
                break;
            case Comparison::GREATER:
                location = location->next;
                searchBool = (location != NULL);
                index++;
                break;
            case Comparison::LESS:
                searchBool = false;
                break;

            default:
                cout << "issue within the switch statement." << endl;
                break;
            }

            if (searchBool == false)
            {
                cout << "Item not found." << endl;
                return -1;
            }
            else
            {
                return index;
            }
        } // end switch statement
    }
} // end searchItem
ItemType SortedLinkedList::getNextItem()
{
    // Notice: The code in the slides is not correct in this case because it didn’t check the end of the list or the empty list.
    // ○ Print “List is empty” when the list is empty
    // ○ Print “The end of the list has reached” when reach the end of the list or you can
    // start printing the list again when end of list is reached (i.e go back to the first
    // element from last last element)

    if (currentPos == NULL)
    {
        currentPos = head;
    }
    else
    {
        currentPos = currentPos->next;
    }
    ItemType nextItem = currentPos->item;
    return (nextItem);
} // end getNextItem

void SortedLinkedList::resetList()
{
    currentPos = NULL;
} // resetList

void SortedLinkedList::printList(SortedLinkedList* list){
    ListNode* position = list->getHead(); 
    bool searchBool = (position != NULL);
    while (searchBool){
        cout << position->item.getValue()<< endl;
        position = position->next;
        searchBool = (position != NULL);
    }

}// printList