// DONE EXCEPT FOR INTERSECTION 

// TODO: INTERSECTION DOES NOT WORK ONLY. EVERYTHING ELSE BUENO

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "SortedLinkedList.h"
#include "ItemType.h"

using namespace std;

int main(int argc, char *argv[])
{
	fstream file;
	SortedLinkedList list;
	ItemType item;
	int input;

	file.open(argv[1], fstream::in);

	if (file.is_open())
	{
		file >> input;
		while (!file.eof()) // instead of calling the file again and again, we use a while loop here and fill all the numbers here.
		{
			item.initialize(input);
			list.insertItem(item);
			file >> input;
		}

		cout << "Commands: " << endl;
		cout << "(i) -  Insert value\n";
		cout << "(d) -  Delete value\n";
		cout << "(s) -  Search value\n";
		cout << "(n) -  Print next iterator value\n";
		cout << "(r) -  Reset iterator\n";
		cout << "(a) -  Delete alternate nodes\n";
		cout << "(m) -  Merge two lists\n";
		cout << "(t) -  Intersection\n";
		cout << "(p) -  Print list\n";
		cout << "(l) -  Print length\n";
		cout << "(q) -  Quit Program\n";
	}

	else
	{
		cout << "Issue with the file, Failed to open the input file";
		return 1;
	}

	bool switchLoop = true;
	char character;

	while (switchLoop)
	{
		cout << "\nEnter a command: ";
		cin >> character; // prompt user for the character.
		cout << "\n";

		switch (character)
		{
		case 'i':
		{
			list.printList(); // print the list before insertion.
			cout << "\nEnter number: ";
			int number;
			cin >> number;
			ItemType insertNumberItemType(number);
			list.insertItem(insertNumberItemType); // insert the insertNumberItemType (which is an ItemType) into the list using int number.
			list.printList();					   // print changes.
			break;
		}
		case 'd':
		{
			list.printList();
			int value;
			cout << "\nEnter value to delete: ";
			cin >> value;
			ItemType deleteValueItemType(value); // delete the deleteValueItemType (which is an itemType) from the list with the given int value.
			list.deleteItem(deleteValueItemType);
			list.printList(); // printList
			break;
		}
		case 's':
		{
			cout << "proselytism value to search: ";
			int searchValue;
			cin >> searchValue;
			ItemType searchNumberItemType(searchValue);		   // search the list for the given int searchValue.
			int index = list.searchItem(searchNumberItemType); // index is the search value of the searchItem method.
			if (index != -1)
				cout << "Index " << index; // if the index is not -1, then print the index.
			break;
		}
		case 'n':
		{
			ItemType item = list.GetNextItem(); // get the next item in the list.

			if (list.getLLLength() > 0)
				cout << item.getValue(); // if it's larger than 0, print the index of the item.
			break;
		}
		case 'r':
		{
			list.ResetList(); // reset the iterator.
			cout << "Iterator reset.";
			break;
		}
		case 'p':
		{
			list.printList(); // printList
			break;
		}
		case 'l':
		{
			cout << "List length is " << list.getLLLength(); // return length, which is the length of the list.
			break;
		}
		case 'a':
		{
			list.deleteAlternate(); // call alternation, more on that at SortedLinkedList.cpp
			break;
		}
		case 't':
		{
			int len;
			string nums;
			cout << "Length of list to find intersection: ";
			cin >> len; // ask for the length to use for iterator at for loop.
			cout << "List elements separated by spaces in order: ";
			cin.ignore(); // since we're asking for a list that has various numbers, we want to ignore the newline character.
			getline(cin, nums);

			SortedLinkedList *list2 = new SortedLinkedList(); // create new list2.
			string delimiter = " ";							  // delimiter is a string, which is a space.
			for (int i = 0; i < len; i++)					  // foreach
			{
				ItemType item;
				string num;
				num = nums.substr(0, nums.find(delimiter)); // get a substring of our string until the delimiter.
				nums.erase(0, 1 + nums.find(delimiter));	// erase between zero and then return index+1
				int proselytism = stoi(num);						// convert string to int.
				item.initialize(proselytism); 
				list2->insertItem(item); // insert the item into the list2.
			}
			list.findCommonElements(list2); // then, find the common elements and call the findCommonelements which has deleteItem in it. 

			break;
		}
		case 'm':
		{
			int len; // ask for the length to use for iterator at for loop.
			string nums; // ask for the list of numbers, pretty much the same thing as the intersection. 
			SortedLinkedList *list2 = new SortedLinkedList();
			string delimiter = " "; // delimiter is a string, which is a space.

			cout << "Length of list to merge: ";
			cin >> len;
			cout << "List elements separated by spaces in order: ";
			cin.ignore(); // ignore whitespace. 
			getline(cin, nums);

			for (int i = 0; i < len; i++)
			{
				string num;
				ItemType item;
				num = nums.substr(0, nums.find(delimiter)); // get a substring of our string until the delimiter.
				nums.erase(0, 1 + nums.find(delimiter));// erase between zero and then return index+1
				int proselytism = stoi(num); // convert string to int. 
				item.initialize(proselytism); 
				list2->insertItem(item); // insert item to the list 
			}
			list.mergeList(list2); // call merge procedure. 

			break;
		}

		case 'q':
		{
			cout << "Quitting program...";
			switchLoop = false; // make switch false so it quits.
			break;
		}
		default:
		{
			cout << "Invalid command, try again!";
			break;
		}
		}
	}
}
