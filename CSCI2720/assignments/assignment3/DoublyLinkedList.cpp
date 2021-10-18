#include "DoublyLinkedList.h"

using std::ios;
using namespace std;

template <class T>


DoublyLinkedList<T>::DoublyLinkedList()
{
  head = NULL;
  tail = NULL;
  length = 0;
}

template <class T>

DoublyLinkedList<T>::~DoublyLinkedList()
{
  NodeType<T> *temp; // create a temp
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    delete temp; // head will be null at the end of these operations.
  }
  tail = NULL; // just take care of the tail
}

template <class T>

void DoublyLinkedList<T>::insertItem(T &item)
{
  NodeType<T> *newNode = new NodeType<T>;
  NodeType<T> *current = head;
  newNode->data = item;
  newNode->next = nullptr; // start null doubly-s.
  newNode->back = nullptr;

  bool emptyList = head == nullptr && tail == nullptr;

  if (emptyList) // if the head and the tail are both empty, then the list's empty.
  {
    head = newNode; // the new insertion is both the head and the tail
    tail = newNode;
    length++; // one element in the list.
    return;
  }

  bool isDuplicate = (false);
  while (current != nullptr)
  {
    if (item > current->data) // keep iterating.
      current = current->next;

    else
    {
      break; // get out of the loop, we found it the general case insertion/ just have to make sure the beginning/ending case.
    }
  }

  if (current == nullptr && !isDuplicate) // insert at the last.
  {
    tail->next = newNode;
    newNode->back = tail;

    tail = newNode;

    length++;
  }

  else if (current->back == nullptr && !isDuplicate) // insert at the first.
  {
    newNode->next = current;
    current->back = newNode;

    head = newNode;

    length++;
  }

  else if (!isDuplicate)
  {
    // no cause matches, general insert.
    newNode->back = current->back;
    current->back->next = newNode;
    newNode->next = current;
    current->back = newNode;
    length++;
  }
}

template <class T>

void DoublyLinkedList<T>::deleteItem(T &item) // delete always req a find
{
  NodeType<T> *temp = head;

  bool listEmpty = (head == nullptr && tail == nullptr);
  if (listEmpty)
  { // trying to delete from empty list
    cout << endl;
    cout << "You cannot delete from an empty list." << endl;

    return;
  }

  if ((item == temp->data) && (temp->next != nullptr))
  { // deleting the first item, not ONLY
    temp->next->back = nullptr;
    head = temp->next;
    delete temp;
    length--;
    return;
  }

  if ((item == temp->data) && (temp->next == nullptr))
  {
    // only item in the list
    // head and tail empty, since it's the last item, there's nowhere to point to.
    head = nullptr;
    tail = nullptr;
    delete temp;
    length--;
    return;
  }

  if (item == tail->data)
  { // deleting the last item
    NodeType<T> *temp = tail->back;

    temp->next = nullptr; // the next is null

    delete tail;
    tail = temp; // tail is now the temp, or it's now the "current" last.

    length--;
    return;
  }

  bool isFound = false;
  bool untilNil = (temp != nullptr);
  while (untilNil)
  {
    if (item > temp->data)
    { // keep going
      temp = temp->next;
    }

    else if (item == temp->data)
    { // item found
      isFound = true;

      break;
    }

    else
    {
      break; // we got it, leave this loop
    }
  }

  if (isFound)
  {
    // found it, aka the search complete. general case deletion.
    temp->back->next = temp->next;
    temp->next->back = temp->back;

    delete temp;
    length--;
  }

  else
  { // tried everything, not in the list.
    cout << endl;
    cout << "Item not in list!" << endl;
  }
}

template <class T>

int DoublyLinkedList<T>::lengthIs() const
{
  return length;
}

template <class T>

void DoublyLinkedList<T>::print()
{
  NodeType<T> *current = head; // start from head go start printing, printreverse starts from tail to print.

  while (current != nullptr)
  {
    cout << current->data << " ";

    current = current->next;
  }

  cout << endl;
}

template <class T>

void DoublyLinkedList<T>::printReverse()
{
  NodeType<T> *temp;
  temp = tail; // instead of pointing to head, point to tail
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->back;
  }
  cout << endl;
}


template <class T>

void DoublyLinkedList<T>::deleteSubsection(T &lb, T &ub)
{
  NodeType<T> *lowerBound;
  NodeType<T> *upperBound;
  NodeType<T> *middleContent; // we have 3 nodes, the middle content, the lower bound, and the upper bound.

  bool headUpperBound = head->data > ub;
  bool tailLowerBound = tail->data < lb;

  if (head == NULL || headUpperBound || tailLowerBound)
  {
    return; // since it's void we can't return 0 here, just return empty
  }
  lowerBound = head; // start from head as lowerbound
  while (lowerBound != NULL && lowerBound->data < lb)
  {
    lowerBound = lowerBound->next; // keep looking for the head aka the lower bound
  }
  if (lowerBound != NULL)
  {

    if (lowerBound->back == NULL)
    {
      // if it's the first element, then make head point next back empty and deleteLowerBound. that's the subsection
      head = head->next;
      head->back = NULL;
      delete lowerBound;
      deleteSubsection(lb, ub); // "recursive"
      return;
    }

    else if (lowerBound->back == NULL && lowerBound->next == NULL)
    {
      // somewhere in the middle of the list, but the only element in the list.
      head = NULL;
      tail = NULL;
      delete lowerBound;
      return;
    }

    else if (lowerBound->next == NULL)
    {
      // last element on the list, then that means the tail is the bound
      tail = tail->back;
      tail->next = NULL;
      deleteSubsection(lb, ub); // "recursive"
      delete lowerBound;
      return;
    }

    else
    {
      // general case, the lower bound is in the middle of the list.
      upperBound = tail;
      while (upperBound != NULL && upperBound->data > ub) // keep looking for the upper bound
      {
        upperBound = upperBound->back;
      }

      if (upperBound->next == lowerBound) // if the lowerbound is the same as the upper bound, return nothing.
      {
        return;
      }
      else
      {
        lowerBound->back->next = upperBound->next;

        while (lowerBound != upperBound)
        {
          // delete all the content between the middle.
          middleContent = lowerBound;
          lowerBound = lowerBound->next;
          delete middleContent;
        }
      }
      return;
    }
  }
}

// swap nodes 1,2 etc with each other.
template <class T>

T DoublyLinkedList<T>::mode()
{
  NodeType<T> *temp;
  NodeType<T> *modeNode;
  NodeType<T> *placeH;
  temp = head;
  placeH = head;

  int bigMode = 0;

  while (placeH->next != NULL)
  {
    temp = head;
    int iterator = 0;
    int mode = 0;
    while (temp != NULL) // while the head's not empty
    {
      if (placeH->data == temp->data)
      {
        iterator++; // iterate the mode, until the temp's (head's empty)
        mode = iterator;
      }
      temp = temp->next;
    }

    // when it's empty, if bigMode (0) is smaller than mode (iterator), then make bigMode = mode.
    if (bigMode < mode)
    {
      modeNode = placeH;
      bigMode = mode;
    }
    placeH = placeH->next; // placeholder continue to next node.
  }
  return modeNode->data;
}

template <class T>

void DoublyLinkedList<T>::swapAlternate()
{
  NodeType<T> *temp = head->next;
  NodeType<T> *temporaryHead;
  bool HeadEmpty = (head == nullptr || head->next == nullptr);
  bool isEven = (lengthIs() % 2 == 0);

  if (HeadEmpty) // if head's empty, return nothing
  {
    return;
  }

  if (lengthIs() < 3)
  {                          // lengthIs is the length of the list we've defined at .h file, if the length is less than 3, that means it's only 2 or less, we can just insert at the beginning
    head->back = temp;       // head's back is the temp
    head->next = temp->next; // head's next is the temp's next
    temp->next = head;       // temp's next is the head
    temporaryHead = head;
    temp->back = nullptr;
    head = temp;
    temp = temporaryHead;
  }
  else
  {

    head->back = temp;       // head's back is the temp
    head->next = temp->next; // head's next is the temp's next
    temp->next = head;       // temp's next is the head, pretty similar to what we've done above.
    temp->back = nullptr;
    head->next->back = head;

    temporaryHead = head;

    head = temp;          // we can now make head the temp's value
    temp = temporaryHead; // and temp then is equal to the temporaryHead we made

    temp = temp->next->next;

    if (isEven && temp->next == NULL)
    {
      goto DIVISIBLE; // had to do a double check here since if I don't it misses the final one.
    }
    else
    {

      while (temp != nullptr)
      {
        // we're checking the middle ones right now.

        temp->next->back = temp->back; // temp's next's back is temp's back
        temp->back->next = temp->next; // temp's back's next is temp's next
        temp->next = temp->back;       // temp's next is now the temp's back,

        temp->back = temp->back->back; // temp's back is now the temp's back's back
        temp->back->next = temp;       // temp's back's next is now the temp
        temp->next->back = temp;       // temp's next's back is now the temp

        temp = temp->next->next->next; // finally, we can say that temp can look at the further nodes.

        if (lengthIs() % 2 == 0 && temp->next == NULL)
        {
          goto DIVISIBLE; // had to do a double check here since if I don't it misses the final one.
          // this time we're checking the back of the list
        }
      }
    }
  }

DIVISIBLE:
  if (isEven && temp->next == NULL)
  {
    NodeType<T> *tempTail = tail->back;

    tail->next = tempTail; // tail's next is the tempTail

    tail->back = tempTail->back; // tail's back is the tempTail's back

    tempTail->back = tail;    // tail's back (tempTail) is the tail
    tempTail->next = nullptr; // there's no next

    tail->back->next = tail; // tail's back's next is the tail

    tail = tail->next; // tail can now point to the next

    temp = nullptr; // temp's null, can also delete but it's safe to keep it this way
  }
}

// requested by the assignment.
template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<string>;