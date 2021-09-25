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
    cout << "(i) -  Insert value" << endl;
    cout << "(d) -  Delete value" << endl;
    cout << "(s) -  Search value" << endl;
    cout << "(n) -  Print next iterator value" << endl;
    cout << "(r) -  Reset iterator" << endl;
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
            break;

        case 'd':
            break;
        case 's':
            break;
        case 'n':
            break;
        case 'r':
            break;
        case 'a':
            break;
        case 'm':
            break;
        case 't':
            break;
        case 'p':
            break;
        case 'l':
            break;
        case 'q':
            break;

        default:
            cout << "Invalid command, try again!" << endl;
            break;
        }
    }

    return 0;
}
