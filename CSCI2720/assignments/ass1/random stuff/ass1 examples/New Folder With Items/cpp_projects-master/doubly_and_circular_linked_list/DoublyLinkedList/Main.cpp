#include <fstream>
#include <iostream>
#include "ItemType.h"
#include "NodeType.h"
#include "DoublyLinkedList.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    DoublyLinkedList list;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in);

    if (fs.is_open()) {
        fs >> input;
        while (!fs.eof()) {
            item.initialize(input);
            list.insertItem(item);
            fs >> input;
        }
    }
    else {
        cout << "Failed to open the input file" << endl;
        return 0;
    }

    list.print();
    cout << "insert (i), delete (d), length (l), print (p), quit (q)" << endl;
    char userInput;
    int userInt;
loop:
    cout << "Enter a command: ";
    cin >> userInput;
    if (userInput=='q') {//terminate program
        cout << "Quitting program..." << endl;
        return 0;
    }
    else if (userInput=='p') {
        list.print();
    } //prints the list
    else if (userInput=='i') {
        cout << "Number to insert: " ;
        cin >> userInt;
        item.initialize(userInt);
        list.insertItem(item);
        list.print();
    } //inserting an element
    else if (userInput=='d') {
        cout << "Number to delete: ";
        cin >> userInt;
        item.initialize(userInt);
        list.deleteItem(item);
        list.print();
    } //deleting an element
    else if (userInput=='l') {
        cout << list.lengthIs() << endl;;
    } //prints the length of the list
    else {
        cout << "Command not recognized. Try again." << endl;
    } //invalid input
    goto loop; 
}
