#include <iostream>

#include "SortedLinkedList.h"

using namespace std;

SortedLinkedList::SortedLinkedList() {
    head = nullptr;
    currentPos = nullptr;
    lengthValue = 0;
}

SortedLinkedList::~SortedLinkedList() {
    ListNode* current;

    // iterate through the list and delete all the nodes
    while(head != nullptr) {
	current = head;
	head = head->next;
	delete current;
    }
}

int SortedLinkedList::getLength() const {
    return lengthValue; // a getLength variable will be used for the getLength
}

void SortedLinkedList::insertItem(ItemType item) {
    ListNode* newNode = new ListNode;
    newNode->item = item;
    
    ListNode* prev = nullptr;
    ListNode* current = head;

    bool isDuplicate = false;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { // keep going
	    prev = current;
	    current = current->next;
	}

	else if(item.compareTo(current->item) == EQUAL) { // duplicate item
	    cout << "\nSorry. You cannot insert the duplicate item\n" << endl;
	    isDuplicate = true;
	    delete newNode; // delete the unused new node to avoid a memory leak
	    break;
	}

	else // found the location to insert item
	    break;
    }

    // if newNode is being inserted into the very beginning or is being inserted to empty list
    if(prev == nullptr && !isDuplicate) {
	newNode->next = current;
	head = newNode;
	lengthValue++;
    }

    else if(!isDuplicate) { // general case insert
	prev->next = newNode;
	newNode->next = current;
	lengthValue++;
    }
}

void SortedLinkedList::deleteItem(ItemType item) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    if(head == nullptr) { // list is empty
	cout << "You cannot delete from an empty list" << endl;

	return;
    }

    if(item.compareTo(current->item) == EQUAL) { // deleting the first item
	head = current->next;

	lengthValue--;

	delete current;

	return;
    }

    // deleting the only item
    if((item.compareTo(current->item) == EQUAL) && (current->next == nullptr)) {
	lengthValue--;

	delete current;

	head = nullptr;

	return;
    }
    
    bool isFound = false;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { // keep going
	    prev = current;
	    current = current->next;
	}

	else if(item.compareTo(current->item) == EQUAL) { // item found
	    isFound = true;
	    
	    break;
	}

	else // if given item is less than current item has not been found by now, item isn't in list
	    break;
    }

    if(isFound) { // general case delete
	prev->next = current->next;
    
	lengthValue--;
   
	delete current;
    }

    else
	cout << "Item not found\n" << endl;
}

// same as the other deleteItem, but works with the given index integer
void SortedLinkedList::deleteItem(int index) {
    deleteItem(searchItem(index));
}

int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;

    ListNode* current = head;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { // item is further down the list
	    current = current->next;
	    index++;
	}

	else if(item.compareTo(current->item) == EQUAL) // item has been found
	    return index;

	else // aka compareTo == LESS, which means item is not in list and has not been found
	    break;
    }

    cout << "Item not found\n" << endl;

    return -1;
}

// like the other searchItem, but returns an ItemType given an index integer
ItemType SortedLinkedList::searchItem(int index) {
    ItemType item;

    // index is out of bounds or list is empty 
    if(index < 0 || index > lengthValue-1 || head == nullptr) {
	cout << "Item not found" << endl;

	return item;
    }

    ListNode* current = head;
    int i = 0;
    while(current != nullptr) {
	if(i == index) // found item
	    return current->item;

	current = current->next;
	i++;
    }

    return item;
}

ItemType SortedLinkedList::GetNextItem() {
    ItemType item;

    if(head == nullptr) { // list is empty
	cout << "List is empty" << endl;

	return item;
    }

    if(currentPos != nullptr) {
	// if the pointer is about to reach the end, go back to the beginning
	if(currentPos->next == nullptr) {
	    item = currentPos->item;
	    currentPos = head;

	    return item;
	}
    }

    // if currentPos is null, set to head so it can be used
    if(currentPos == nullptr)
	currentPos = head;

    // prepare item to be returned and advance the pointer
    item = currentPos->item;
    currentPos = currentPos->next;

    return item;
}

void SortedLinkedList::ResetList() {
    currentPos = nullptr;
}

void SortedLinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* firstItemTemp = nullptr;
    
    if(head == nullptr) { // list is empty
	cout << "Cannot reverse, list is empty" << endl;

	return;
    }

    if(head->next == nullptr) { // list only has one item
	cout << "Cannot reverse, list has only one item" << endl;

	return;
    }

    while(current->next != nullptr) { // go to end of list and assign appropriate pointers
	prev = current;
	current = current->next;
    }

    // make a temporary pointer to the first item (or the last item in the non-reversed version
    firstItemTemp = current;

    while(prev != nullptr) { // do the reversal
	current->next = prev;

	current = prev;

	prev = findPrevNode(current);
    }

    current->next = nullptr; // make the last item (used to be the first item) point to null

    // now that the list is reversed, make head point to the first item (used to be the last item)
    head = firstItemTemp;
}

// A helper function that iterates through the list and finds the previous node
// of the given node. Used in the reverse() function
ListNode* SortedLinkedList::findPrevNode(ListNode* node) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while(current->next != nullptr) {
	if(current == node)
	    return prev;

	prev = current;
	current = current->next;
    }

    return prev;
}

void SortedLinkedList::printList() {
    ResetList();
    
    for(int i = 0; i < lengthValue; i++) {
	ItemType item = GetNextItem();

	cout << item.getValue() << " ";
    }

    cout << endl;
}

void SortedLinkedList::mergeList(SortedLinkedList* list) {
  ListNode* position = list->head;
  bool moreToSearch = (position != NULL);
  cout << "List 1: ";
  printList(this);
  cout << "List 2: ";
  printList(list);
  while (moreToSearch) {
    if(isDuplicate(position->item)) {
      cout << "Sorry, you cannot insert a duplicate item" << endl;
      return;
    }
    insertItem(position->item);
    position = position->next;
    moreToSearch = (position !=NULL);
  }
  printList(this);
} //mergeList


bool SortedLinkedList::isDuplicate(ItemType item) {
  ListNode* location = head;
  bool found = false;
  bool moreToSearch = (location != NULL);
  while (moreToSearch && !found) {
    switch(location->item.compareTo(item)) {
    case Comparison::GREATER: 
      location = location->next;
      moreToSearch = (location != NULL);
      break;
    case Comparison::EQUAL:
      found = true;
      break;
    case Comparison::LESS:
      moreToSearch = false;
      break;
    }
  }
  return found;
} //isDuplicate


void SortedLinkedList::printList(SortedLinkedList* list) {
  ListNode* position = list->getHead();
  bool moreToSearch = (position != NULL);
  while (moreToSearch) {
    cout << position->item.getValue() << " ";
    position = position->next;
    moreToSearch = (position != NULL);
  }
  cout << "\n";
} //printList


void SortedLinkedList::deleteAlternate() {
  cout << "List before alternate delete: ";
  printList(this);
  ListNode* position;
  position = head;
  bool moreToSearch = (position != NULL);

  while (moreToSearch) {
    if (position->next == NULL) {
	moreToSearch = false;
    } else if ((position->next)->next == NULL) {
      position->next = NULL;
    } else {
      position->next = (position->next)->next;
    }
    position = position->next;
    moreToSearch = (position != NULL);
  }
  cout << "List after alternate delete: ";
  printList(this);
} //deleteAlternate

void SortedLinkedList::findCommonElements(SortedLinkedList* list) {
  cout << "List 1: ";
  printList(this);
  cout << "List 2: ";
  printList(list);

  ListNode* position = head;
  bool moreToSearch = (position != NULL);
  while (moreToSearch) {
    ListNode* location = list->head;
    bool more = (location != NULL);
    bool common = false;
    while (more) {
      switch (position->item.compareTo(location->item)) {
      case Comparison::GREATER:
	location = location->next;
	more = (location != NULL);
	break;
      case Comparison::EQUAL:
	common = true;
	more = false;
	break;
      case Comparison:: LESS:
	more = false;
	break;
      }
    }
    if (common == false) {
      deleteItem(position->item);
    }
    position = position->next;
    moreToSearch = (position != NULL);
  }

  cout << "Intersection";
  printList(this);
} //findCommonElements

ListNode* SortedLinkedList::getHead() {
  return head;
} //getHead

