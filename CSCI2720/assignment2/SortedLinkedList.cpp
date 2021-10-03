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

    
    while(head != nullptr) {
	current = head;
	head = head->next;
	delete current;
    }
}

int SortedLinkedList::getLength() const {
    return lengthValue; 
}

void SortedLinkedList::insertItem(ItemType item) {
    ListNode* newNode = new ListNode;
    newNode->item = item;
    
    ListNode* prev = nullptr;
    ListNode* current = head;

    bool isDuplicate = false;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { 
	    prev = current;
	    current = current->next;
	}

	else if(item.compareTo(current->item) == EQUAL) { 
	    cout << "\nSorry. You cannot insert the duplicate item\n" << endl;
	    isDuplicate = true;
	    delete newNode; 
	    break;
	}

	else 
	    break;
    }

    
    if(prev == nullptr && !isDuplicate) {
	newNode->next = current;
	head = newNode;
	lengthValue++;
    }

    else if(!isDuplicate) { 
	prev->next = newNode;
	newNode->next = current;
	lengthValue++;
    }
}

void SortedLinkedList::deleteItem(ItemType item) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    if(head == nullptr) { 
	cout << "You cannot delete from an empty list" << endl;

	return;
    }

    if(item.compareTo(current->item) == EQUAL) { 
	head = current->next;

	lengthValue--;

	delete current;

	return;
    }

    
    if((item.compareTo(current->item) == EQUAL) && (current->next == nullptr)) {
	lengthValue--;

	delete current;

	head = nullptr;

	return;
    }
    
    bool isFound = false;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { 
	    prev = current;
	    current = current->next;
	}

	else if(item.compareTo(current->item) == EQUAL) { 
	    isFound = true;
	    
	    break;
	}

	else 
	    break;
    }

    if(isFound) { 
	prev->next = current->next;
    
	lengthValue--;
   
	delete current;
    }

    else
	cout << "Item not found\n" << endl;
}


void SortedLinkedList::deleteItem(int index) {
    deleteItem(searchItem(index));
}

int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;

    ListNode* current = head;
    while(current != nullptr) {
	if(item.compareTo(current->item) == GREATER) { 
	    current = current->next;
	    index++;
	}

	else if(item.compareTo(current->item) == EQUAL) 
	    return index;

	else 
	    break;
    }

    cout << "Item not found\n" << endl;

    return -1;
}


ItemType SortedLinkedList::searchItem(int index) {
    ItemType item;

    
    if(index < 0 || index > lengthValue-1 || head == nullptr) {
	cout << "Item not found" << endl;

	return item;
    }

    ListNode* current = head;
    int i = 0;
    while(current != nullptr) {
	if(i == index) 
	    return current->item;

	current = current->next;
	i++;
    }

    return item;
}

ItemType SortedLinkedList::GetNextItem() {
    ItemType item;

    if(head == nullptr) { 
	cout << "List is empty" << endl;

	return item;
    }

    if(currentPos != nullptr) {
	
	if(currentPos->next == nullptr) {
	    item = currentPos->item;
	    currentPos = head;

	    return item;
	}
    }

    
    if(currentPos == nullptr)
	currentPos = head;

    
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
    
    if(head == nullptr) { 
	cout << "Cannot reverse, list is empty" << endl;

	return;
    }

    if(head->next == nullptr) { 
	cout << "Cannot reverse, list has only one item" << endl;

	return;
    }

    while(current->next != nullptr) { 
	prev = current;
	current = current->next;
    }

    
    firstItemTemp = current;

    while(prev != nullptr) { 
	current->next = prev;

	current = prev;

	prev = findPrevNode(current);
    }

    current->next = nullptr; 

    
    head = firstItemTemp;
}



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

// TODO: comment about this on readme file 
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


// TODO: comment about this in readme. 
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

