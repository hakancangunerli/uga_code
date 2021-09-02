#include <fstream>
#include <iostream>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    SortedLinkedList list;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in);
    if (fs.is_open())
    {
        fs >> input;
        while(!fs.eof())
        {
            item.initialize(input);
            list.insertItem(item);
            fs >> input;
        }
    }
    else
    {
        cout << "Failed to open the input file" << endl;
        return 0;
    }

    cout << "Commands:" << endl;
    cout << "(i) - Insert value" << endl;
    cout << "(d) - Delete value" << endl;
    cout << "(s) - Search value" << endl;
    cout << "(n) - Print next iterator value" << endl;
    cout << "(r) - Reset iterator" << endl;
    cout << "(p) - Print list" << endl;
    cout << "(l) - Print length" << endl;
    cout << "(b) - Reverse" << endl;
    cout << "(q) - Quit program" << endl;
    char userInput;
    int counter=0;
    
    while (true) {
        cout << "Enter a command: ";
        cin >> userInput;
        if (userInput=='q') {
            cout << "Quitting program..."<< endl;
            return 0;
        } //terminates the program
        if (userInput=='p') {
            for (int i = 0 ;i < list.getLength();i++) {
                cout << list.GetNextItem().getValue() << " ";
            }
            cout << endl;
        } //printing all elements in the list
        if (userInput == 'i') {
            for (int i = 0 ;i < list.getLength();i++) {
                cout << list.GetNextItem().getValue() << " ";
            }
            cout << endl;
            int insertInt;
            cout << "Enter number: ";
            cin >>insertInt;
            item.initialize(insertInt); //initializing and inserting 
            list.insertItem(item);
            for (int i = 0 ;i < list.getLength();i++) {
                cout << list.GetNextItem().getValue() << " ";
            }
            cout << endl;
        }
        if (userInput == 'd') {
            for (int i = 0 ;i < list.getLength();i++) {
                cout << list.GetNextItem().getValue() << " ";
            }
            cout << endl;
            int insertInt;
            cout << "Enter value to delete: ";
            cin >>insertInt;
            item.initialize(insertInt); //initializing and deleting 
            list.deleteItem(item);
            for (int i = 0 ;i < list.getLength();i++) {
                cout << list.GetNextItem().getValue() << " ";
            }
            cout << endl;
        }
        if (userInput == 's') {
            int searchInt;
            cout << "Enter a value to search :";
            cin >> searchInt;
            item.initialize(searchInt);
            int searchIndex = list.searchItem(item);
            if (searchIndex==-1) { //if not present 
                cout << "value not present in the list" << endl;
            }
            else {
                cout <<"Index " << searchIndex<<endl;
            }
        }
        if (userInput == 'l') {
            cout << "List Length is " << list.getLength() << endl;
        }
        if (userInput == 'n') {
            if (list.getLength()==0) { //if list is empty
                cout << "List is empty" << endl;
            }
            else if  (counter == list.getLength()) {
                cout << "The end of the list has reached" << endl;
            }
            else {
                cout << list.GetNextItem().getValue() << endl;
                counter++; //counter that keeps track of how many iteration
            }
        }
        if (userInput == 'r') {
            list.ResetList();
            cout << "Iterator reset." << endl;
            counter=0; // 'r' resets the iteration counter
        }
        if (userInput == 'b') {
            cout << "Before" << endl;
            for (int i = 0 ;i < list.getLength();i++) {
                cout << list.GetNextItem().getValue() << " ";
            }
            cout << endl;
            cout << "After" << endl;
            list.reverse();
            for (int i = 0 ;i < list.getLength();i++) {
                cout << list.GetNextItem().getValue() << " ";
            }
            cout << endl;
        } //reverse all elements in the list
    } //infinite loop that breaks if q is inputted
    return 0;
} //main

