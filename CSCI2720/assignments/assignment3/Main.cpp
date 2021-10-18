// TODO: RE_TEST THE FILE

#include "DoublyLinkedList.cpp"
#include <string>
#include <iostream> // std::cout
#include <fstream>  // std::ifstream
using namespace std;
char command;

template <class T>
void commandSwitch(DoublyLinkedList<T> doubleLinkedlist)
{
  T lowerBound, upperBound;
  T convertedItem;

  do
  {

    cout << "\nEnter a command: ";
    cin >> command;
    cout << endl;

    switch (command)
    {
    case 'q':
      goto QUIT;
    case 'i':

      cout << "Item to insert: ";
      cin >> convertedItem;
      cout << endl;
      doubleLinkedlist.insertItem(convertedItem);
      doubleLinkedlist.print();
      break;
    case 'd':
      cout << "Item to delete: ";
      cin >> convertedItem;
      cout << endl;
      doubleLinkedlist.deleteItem(convertedItem);
      doubleLinkedlist.print();
      break;
    case 'l':
      cout << "The length is: " << doubleLinkedlist.lengthIs() << endl;
      break;
    case 'p':
      doubleLinkedlist.print();
      break;
    case 'b':
      cout << "Enter lower bound: ";
      cin >> lowerBound;
      cout << endl;
      cout << "Enter upper bound: ";
      cin >> upperBound;
      cout << endl;
      cout << "Original List: ";
      doubleLinkedlist.print();
      doubleLinkedlist.deleteSubsection(lowerBound, upperBound);
      cout << "\nModified List: ";
      doubleLinkedlist.print();
      break;
    case 'm':
      doubleLinkedlist.print();
      cout << "\nMode: " << doubleLinkedlist.mode() << endl;
      break;
    case 'r':
      doubleLinkedlist.printReverse();
      break;
    case 's':
      cout << "Original List: ";
      doubleLinkedlist.print();
      doubleLinkedlist.swapAlternate();
      cout << "\nSwapped List: ";
      doubleLinkedlist.print();
      break;
    default:
      cout << "Invalid command.\n";
      break;
    }
  } while (command != 'q' || command == ' '); // a do-while check in order to continue with the switch statement.

QUIT: // quit gives me a hard time, so i just put it here. it still works.
  cout << "Quitting program...\n"
       << endl;
  exit(0);
}

int main(int argc, char *argv[])
{
  string line;
  string convert; // the file to be converted in the main to the appropiate type, such as stoi stof or just string.

  ifstream inputFile(argv[1], ios::in); // insert file

  int redirection; // int 0 , string 2, float 1

if (!inputFile){
  cout << "issue reading file, try again."<< endl;
  exit(0);
}

do{
  if (inputFile)
  {

    cout << "\nEnter list type (i - int, f - float, s - string): "; // for sorting
    string type_List;
    cin >> type_List;
    cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse (r), swapAlt (s), quit (q)" << endl;
    getline(inputFile, line);
    istringstream iss(line);

    // redirection here, in order to fool-proof the logic even more.

    char integer = 'i';
    char stringer = 's';
    char floater = 'f';
    char tipo = type_List.at(0);

    if (tipo == integer)
    {
      redirection = 0;
    }
    else if (tipo == floater)
    {
      redirection = 1;
    }
    else if (tipo == stringer)
    {
      redirection = 2;
    }

    else
    {
      cout << "Invalid input, try again!" << endl;
    }

    // these will all be used for insertion in their respective location, since this is switch-case, they cannot be declared outside.
    DoublyLinkedList<int> list_int;
    DoublyLinkedList<float> list_float;
    DoublyLinkedList<string> list_string;
    bool delimiter = (line != " "); // this is to check if the line is empty, if it is, it will not be inserted.

    switch (redirection)
    {
    case 0:
      if (delimiter)
      { // if file not empty
        while (getline(iss, convert, ' '))
        {
          int convertedItem = stoi(convert);  // string to integer, since every text is passed as string.
          list_int.insertItem(convertedItem); // added to list
        }
      }
      commandSwitch(list_int);
      break;
    case 1:
      if (delimiter) // delimiter
      {              // if file not empty
        while (getline(iss, convert, ' '))
        {
          float convertedItem = stof(convert);  // string to float, since every text is passed as string.
          list_float.insertItem(convertedItem); // added to list
        }
      }
      commandSwitch(list_float);
      break;
    case 2:
      if (delimiter)
      { // if file not empty
        while (getline(iss, convert, ' '))
        {
          string convertedItem = convert;        // no reason for conversion here.
          list_string.insertItem(convertedItem); // added to list
        }
      }
      commandSwitch(list_string);
      break;
    default:
      cout << "invalid input";
    }
  }
}
while(!inputFile);

}
