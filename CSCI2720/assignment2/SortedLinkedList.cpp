// DO THE TODOS AND WE'RE DONE HERE.
#include <iostream>
#include "SortedLinkedList.h"

using namespace std;

SortedLinkedList::SortedLinkedList()
{
    head = nullptr;
    currentPos = nullptr;
    length = 0;
} // start with the constructor.

SortedLinkedList::~SortedLinkedList()
{
    // the destructor deletes the curr node which is Comparison::EQUAL to the head unless the head is empty.
    ListNode *curr;
    while (head != nullptr)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

int SortedLinkedList::getLLLength() const
{ // return the length, const to not be altered.
    return length;
}

void SortedLinkedList::insertItem(ItemType item)
{
    ListNode *newNode = new ListNode;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    newNode->item = item;
    bool isDuplicate = false; // we don't actually check this here, this is to use for !isDuplicate later on

    while (curr != nullptr)
    {
        if (item.compareTo(curr->item) == Comparison::GREATER)
        { // continue
            prev = curr;
            curr = curr->next;
        }

        else if (item.compareTo(curr->item) == Comparison::EQUAL)
        { // if the item's do exist already (aka Comparison::EQUAL ), it's  a duplicate.
            cout << "\nSorry. You cannot insert the duplicate item\n"
                 << endl;
            isDuplicate = true;
            delete newNode;
            break;
        }

        else // if none of these are conditions, then that means we've found where to insert. (because it's not a duplicate or greater. )
            break;
    }

    if (prev == nullptr && !isDuplicate)
    { // since it's not a duplicate and previous is null, then we're inserting at the head.
        newNode->next = curr;
        head = newNode;
        length++;
    }

    else if (!isDuplicate)
    { // if it's just not isDuplicate, then we're inserting somewhere in the middle. (aka general case)
        prev->next = newNode;
        newNode->next = curr;
        length++;
    }
} // end insertItem

void SortedLinkedList::deleteItem(ItemType item)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    if (head == nullptr)
    { // if the head's empty, that means there's nothing here.
        cout << "You cannot delete from an empty list" << endl;

        return;
    }

    if (item.compareTo(curr->item) == Comparison::EQUAL)
    { // if it's equal, that means it's first item special case.
        head = curr->next;

        length--;

        delete curr;

        return;
    }

    if ((item.compareTo(curr->item) == Comparison::EQUAL) && (curr->next == nullptr))
    { // if it's equal and curr is null that means it's the only item.
        length--;

        delete curr;

        head = nullptr;

        return;
    }

    bool isFound = false;
    while (curr != nullptr)
    {
        if (item.compareTo(curr->item) == Comparison::GREATER)
        { // not done yet, keep going.
            prev = curr;
            curr = curr->next;
        }

        else if (item.compareTo(curr->item) == Comparison::EQUAL)
        { // we found the item!
            isFound = true;

            break;
        }

        else
            break;
    }

    if (isFound)
    { // if we found it, and the special cases above are not done, then it's a general case delete.
        prev->next = curr->next;

        length--;

        delete curr;
    }

    else
    {
        cout << "Item not found\n"
             << endl;
    }
} // end deleteItem

int SortedLinkedList::searchItem(ItemType item)
{
    int index = 0;

    ListNode *curr = head;
    while (curr != nullptr)
    {
        if (item.compareTo(curr->item) == Comparison::GREATER)
        { // if the comparison value is higher, we need to keep going.
            curr = curr->next;
            index++;
        }

        else if (item.compareTo(curr->item) == Comparison::EQUAL) // we found it!
            return index;

        // we can also implement this code in the comment, but i mean if it's not equal or greater, we pretty much couldn't find it thus we can just write an else here.
        /* else if (item.compareTo(curr->item) == Comparsion::LESS){
        cout << "Item not found" << endl;
        return -1;
    }
    */
        else
            break;
    }
    cout << "Item not found\n"
         << endl; // aka Comparison::LESS

    return -1; // well, we couldn't find it so that's kind of an error here.
} // end searchItem

ItemType SortedLinkedList::GetNextItem()
{
    ItemType item;

    if (head == nullptr)
    { // there's no head, list's empty.
        cout << "List is empty" << endl;

        return item;
    }

    if (currentPos != nullptr)
    { // if we are reaching the end, we need to the beginning.

        if (currentPos->next == nullptr)
        { //
            item = currentPos->item;
            currentPos = head;
            cout << "The end of the list has been reached.\n"; // to print.
            return item;
        }
    }

    if (currentPos == nullptr) // if null, then it needs to become the head
        currentPos = head;

    item = currentPos->item; // advance pointer, return item at the end.
    currentPos = currentPos->next;

    return item;

} // end GetNextItem

void SortedLinkedList::ResetList()
{
    currentPos = nullptr;
} // end ResetList

ListNode *SortedLinkedList::findPrevNode(ListNode *node)
{ // an iterator to find the previous node.
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr->next != nullptr)
    {                     // while we're not at the end of the list.
        if (curr == node) // if we've found the node, then we're done.
            return prev;

        prev = curr;       // otherwise, we need to keep going.
        curr = curr->next; // advance the iterator.
    }

    return prev;
}

void SortedLinkedList::printList()
{ // loop through, print the list.
    ResetList();

    for (int i = 0; i < length; i++)
    {
        ItemType item = GetNextItem();

        cout << item.getValue() << " ";
    }

    cout << endl;
}

// TODO: comment about this on readme file
void SortedLinkedList::mergeList(SortedLinkedList *list)
{
    ListNode *position = list->head;
    bool whileSearching = (position != NULL);
    cout << "List 1: ";
    printList(this);
    cout << "List 2: ";
    printList(list);
    while (whileSearching)
    {
        if (isDuplicate(position->item))
        {
            cout << "Sorry, you cannot insert a duplicate item" << endl;
            return;
        }
        insertItem(position->item);
        position = position->next;
        whileSearching = (position != NULL);
    }
    printList(this);
} //mergeList

bool SortedLinkedList::isDuplicate(ItemType item)
{
    ListNode *location = head;
    bool found = false;
    bool whileSearching = (location != NULL);
    while (whileSearching && !found)
    {
        switch (location->item.compareTo(item))
        {
        case Comparison::GREATER:
            location = location->next;
            whileSearching = (location != NULL);
            break;
        case Comparison::EQUAL:
            found = true;
            break;
        case Comparison::LESS:
            whileSearching = false;
            break;
        }
    }
    return found;
} //isDuplicate

void SortedLinkedList::printList(SortedLinkedList *list)
{
    ListNode *position = list->getHead();
    bool whileSearching = (position != NULL);
    while (whileSearching)
    {
        cout << position->item.getValue() << " ";
        position = position->next;
        whileSearching = (position != NULL);
    }
    cout << "\n";
} //printList

void SortedLinkedList::deleteAlternate()
{
    cout << "List before alternate delete: ";
    printList(this);
    ListNode *position;
    position = head;
    bool whileSearching = (position != NULL);

    while (whileSearching)
    {
        if (position->next == NULL)
        {
            whileSearching = false;
        }
        else if ((position->next)->next == NULL)
        {
            position->next = NULL;
        }
        else
        {
            position->next = (position->next)->next;
        }
        position = position->next;
        whileSearching = (position != NULL);
    }
    cout << "List after alternate delete: ";
    printList(this);
} //deleteAlternate

// TODO: comment about this in readme.
void SortedLinkedList::findCommonElements(SortedLinkedList *list)
{
    cout << "List 1: ";
    printList(this);
    cout << "List 2: ";
    printList(list);

    ListNode *position = head;
    bool whileSearching = (position != NULL);
    SortedLinkedList *list3 = new SortedLinkedList();
    while (whileSearching)
    {
        ListNode *location = list->head;
        bool commonElement, untilNull;
        commonElement = false;
        untilNull = (location != NULL);

        while (untilNull)
        {
            switch (position->item.compareTo(location->item))
            {
            case Comparison::GREATER:
                location = location->next;
                untilNull = (location != NULL);
                break;
            case Comparison::EQUAL:

                commonElement = true;
                untilNull = false;

                break;
            case Comparison::LESS:
                untilNull = false;
                break;
            }
        }
        if (commonElement)
        {
            list3->insertItem(position->item);
        }

        position = position->next;
        whileSearching = (position != NULL);
    } // end while

    cout << "Intersection: ";
    printList(list3);
} //findCommonElements

ListNode *SortedLinkedList::getHead()
{
    return head;
} //getHead
