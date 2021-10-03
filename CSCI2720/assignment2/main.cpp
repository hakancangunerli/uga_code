#include <iostream>
#include <fstream>
#include <string>
#include "SortedLinkedList.h"
#include "ItemType.h"

using namespace std;

int main(int argc, char *argv[])
{
	SortedLinkedList list;

	ItemType item;
	int input;
	fstream fs;

	fs.open(argv[1], fstream::in); // reads input file

	if (fs.is_open())
	{
		fs >> input;
		while (!fs.eof())
		{
			item.initialize(input);
			list.insertItem(item);
			fs >> input;
		}

		cout << "Commands: " << endl;
		cout << "(i) -  Insert value" << endl; // done
		cout << "(d) -  Delete value" << endl; // done
		cout << "(s) -  Search value" << endl; // done
		cout << "(n) -  Print next iterator value" << endl;
		cout << "(r) -  Reset iterator" << endl;
		cout << "(a) -  Delete alternate nodes" << endl;
		cout << "(m) -  Merge two lists" << endl;
		cout << "(t) -  Intersection" << endl;
		cout << "(p) -  Print list" << endl;
		cout << "(l) -  Print length" << endl;
		cout << "(q) -  Quit Program" << endl;
	}

	else
	{
		cout << "Failed to open the input file";
		return 0;
	}

	bool loop = true;
	char character; // character input when entering a command

	while (loop)
	{
		cout << "\nEnter a command: ";
		cin >> character;
		cout << "\n";

		switch (character)
		{
		case 'i':
		{ // insert command that inserts a node in the linked list
			list.printList();
			cout << "\nEnter number: ";
			int number;
			cin >> number;
			ItemType numType(number);
			list.insertItem(numType);
			list.printList();
			break;
		}
		case 'd':
		{ // delete command that deletes a node in the linked list
			list.printList();
			int value;
			cout << "\nEnter value to delete: ";
			cin >> value;
			ItemType valueType(value);
			list.deleteItem(valueType);
			list.printList();
			break;
		}
		case 's':
		{ // search command that searches for a node in the linked list
			cout << "Enter value to search: ";
			int searchNum;
			cin >> searchNum;
			ItemType searchNumType(searchNum);

			int index = list.searchItem(searchNumType);

			if (index != -1)
				cout << "Index " << index;
			break;
		}
		case 'n':
		{ // next command that gets the next node in the linked list
			ItemType item = list.GetNextItem();

			if (list.getLength() > 0)
				cout << item.getValue();
			break;
		}
		case 'r':
		{ // reset command that restarts the linked list back to the first position and element
			list.ResetList();
			cout << "Iterator reset.";
			break;
		}
		case 'p':
		{ // print command that prints the linked list
			list.printList();
			break;
		}
		case 'l':
		{ // getLength command that returns the getLength of the linked list
			cout << "List length is " << list.getLength();
			break;
		}
		case 'a':{
			list.deleteAlternate();
      break;
		}
		case 'b':
		{ // reverse command that reverses the list
			cout << "Before";

			list.printList();

			list.reverse();

			cout << "After";

			list.printList();
			break;
		}
		case 't':
		{
			int len;
			string nums;
			cout << "Length of list to find intersection: ";
			cin >> len;
			cout << "List elements separated by spaces in order: ";
			cin.ignore();
			getline(cin, nums);

			SortedLinkedList *list2 = new SortedLinkedList();
			string delimiter = " ";
			for (int i = 0; i < len; i++)
			{
				string num;
				num = nums.substr(0, nums.find(delimiter));
				nums.erase(0, 1 + nums.find(delimiter));
				int enter = stoi(num);
				ItemType item;
				item.initialize(enter);
				list2->insertItem(item);
			}
			list.findCommonElements(list2);

			// this was a -> changed it to . 
			break;
		}
		case 'm':
		{
			int len;
			string nums;
			cout << "Length of list to merge: ";
			cin >> len;
			cout << "List elements separated by spaces in order: ";
			cin.ignore();
			getline(cin, nums);

			SortedLinkedList *list2 = new SortedLinkedList();
			string delimiter = " ";
			for (int i = 0; i < len; i++)
			{
				string num;
				num = nums.substr(0, nums.find(delimiter));
				nums.erase(0, 1 + nums.find(delimiter));
				int enter = stoi(num);
				ItemType item;
				item.initialize(enter);
				list2->insertItem(item);
			}
			list.mergeList(list2);
			// changed this from ->
			break;
		}

		case 'q':
		{ // quit command that stops the while loop and exits the program
			cout << "Quitting program...";
			loop = false;
			break;
		}
		default:
		{ // this will print when the command is invalid
			cout << "Invalid command, try again!";
			break;
		}
		}
	}
}
