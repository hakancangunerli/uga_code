#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include "ItemType.h"
#include "SortedLinkedList.h"

// should not allow duplicate elements
// elements should be of type itemType
// itemType class should have the private integer value
// elements of the linkedlist should be ordered in ascending order according to the integer value

int main(int argc, char const *argv[])
{
    ifstream linkedListFile(argv[1], ios::in);
    SortedLinkedList *list = new SortedLinkedList();

    cout << "Commands: " << endl;
    cout << "(i) -  Insert value " << endl;
    cout << "(d) -  Delete value " << endl;
    cout << "(s) -  Search value " << endl;
    cout << "(n) -  Print next iterator value" << endl;
    cout << "(r) -  Reset iterator " << endl;
    cout << "(a) -  Delete alternate nodes" << endl;
    cout << "(m) -  Merge two lists" << endl;
    cout << "(t) -  Intersection" << endl;
    cout << "(p) -  Print list" << endl;
    cout << "(l) -  Print length" << endl;
    cout << "(q) -  Quit Program" << endl;

    bool working = true;
    // big switch-case here:
    while (working)
    {
        char selection;

        switch (selection)
        {

        case 'i':
            list->printList(list);
            // insert
            int num;
            cout << "Enter number";
            cin >> num;
            ItemType it;
            it.initialize(num);
            list->insertItem(it);
            list->printList(list);
            break;

        case 'd':
            list->printList(list);
            int num;
            cout << "Enter number for deletion";
            cin >> num;
            ItemType it;
            it.initialize(num);
            list->deleteItem(it);
            list->printList(list);

            break;
        case 's':
            int num;
            cout << "enter value for searching";
            cin >> num;
            ItemType it;
            it.initialize(num);
            int indexing = list->searchItem(it);
            if (it == -1)
            {
                cout << "item not found";
            }
            else
            {
                cout << "index" << indexing << endl;
            }
            break;
        case 'n': // TODO:IMPLEMENT CASE N
            if (list->isEnd())
            {
            }
            break;
        case 'r':
            list->resetList();
            cout << "Iterator has been reset";
            break;
        case 'a':
            list->deleteAlternate(); // TODO: IMPLEMENT deleteAlternate
            break;
        case 'm':
            break;
        case 't':
            break;
        case 'p':
            list->printList(list);
            break;
        case 'l':
            cout << "List length";
            cout << list->getLLLength();
            << endl;
            break;
        case 'q':
            working = false;
            break;

        default:
            cout << "Invalid command, try again!" << endl;
            break;
        }
    }

    return 0;
}
