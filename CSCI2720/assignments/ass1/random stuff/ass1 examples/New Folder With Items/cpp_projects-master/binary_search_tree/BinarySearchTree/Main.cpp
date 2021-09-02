#include <fstream>
#include <iostream>
#include "ItemType.h"
#include "Node.h"
#include "BinaryTree.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    BinaryTree list;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in);

    if (fs.is_open()) {
        fs >> input;
        while (!fs.eof()) {
            item.initialize(input);
            list.insert(item);
            fs >> input;
        }
    }
    else {
        cout << "Failed to open the input file" << endl;
        return 0;
    }

    cout << "Commands:" << endl;
    cout << "insert (i), delete (d), retreieve (r), length (l), in-order (n), pre-order (p), post-order (o), getSameLevelNonsiblings (c), quit (q)" << endl;
    char userInput;
    int userInt;
loop:
    cout << "Enter a command: ";
    cin >> userInput;
    if (userInput=='q') {//terminate program
        cout << "Quitting program..." << endl;
        return 0;
    }
    else if (userInput=='n') {
        cout << "In-Order: "; 
        list.inOrder();
        cout << endl;
    } //prints binary tree in in-order
    else if (userInput=='p') {
        cout << "Pre-Order: ";
        list.preOrder();
        cout << endl;
    } //prints binary tree in pre-order
    else if (userInput=='o') {
        cout << "Post-Order: ";
        list.postOrder();
        cout << endl;
    } //prints binary tree in post-order
    else if (userInput=='c') {
        cout << "not yet implemented" << endl;
    } //prints elements that are in same level except its siblings
    else if (userInput=='i') {
        cout << "Item to insert: " ;
        cin >> userInt;
        item.initialize(userInt);
        bool itemfound;
        list.retrieve(list.root, item, itemfound);
        if (!itemfound) {
            list.insert(item);
        }
        else {
            cout << "Item already in tree" << endl;
        }
        cout << "In-Order: ";
        list.inOrder();
        cout << endl;
    } //inserting an element
    else if (userInput=='d') {
        cout << "Item to delete: ";
        cin >> userInt;
        item.initialize(userInt);  
        bool itemfound;
        list.retrieve(list.root, item, itemfound);
        if (itemfound) {
            list.deleteItem(item);
        }
        else {
            cout << "Item not in tree." << endl;
        }
        cout << "In-Order: ";
        list.inOrder();
        cout << endl;
    } //deleting an element
    else if (userInput=='l') {
        cout << "List Length: " << list.getLength() << endl;;
    } //prints the length of the list
    else if (userInput=='r') {
        cout << "Item to be retrieved: " ;
        cin >> userInt;
        item.initialize(userInt);
        bool itemfound;
        list.retrieve(list.root, item, itemfound);
        if (itemfound) {
            cout << "Item found in tree." << endl;
        }
        else {
            cout << "Item not in tree." << endl;
        }
    }
    else {
        cout << "Command not recognized. Try again." << endl;
    } //invalid input
    goto loop; 
} //main
