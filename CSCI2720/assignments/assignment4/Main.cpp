#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "BinaryTree.cpp"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Error, requires one file input.";
        exit(0);
    }
    string txt = argv[1]; // file name

    bool found; // boolean for if the word is found
    cout << "Enter tree type (i - int, f - float, s - std:string): ";
    string listType;  // type of tree
    cin >> listType;  // user input
    ifstream is(txt); // input stream
    int fill = 0;     // number of words in the file
    int counter = 0;  // counter for the words
    

    //// our fillers ( where our tree will be filled below using fstream )
    NodeType<int> *rootInteger = new NodeType<int>();
    BinaryTree<int> integerBST = BinaryTree<int>();
    NodeType<float> *rootFloat = new NodeType<float>();
    BinaryTree<float> floatBST = BinaryTree<float>();
    NodeType<string> *rootString = new NodeType<string>();
    BinaryTree<string> stringBST = BinaryTree<string>();

    if (listType == "i")
    {
  
        while (is >> fill)
        {
            counter++;
            if (counter == 1)
            {
                integerBST.insertionFirst(rootInteger, fill);
            }
            else
            {
                integerBST.insert(fill);
            }
        }
        is.close();
        goto INTEGER;
    }
    if (listType == "f")
    {

        ifstream floatFile(txt, ios::in); 
        vector<float> pushingVector; // size of the vector needed thus we called a vector here. 
        float num = 0.0;
        
        while (floatFile >> num)
        {
            pushingVector.push_back(num);
        }
        counter = 0;
        for (int i = 0; i < (int)pushingVector.size() ; i++) 
        {
            counter++;
            float fill = pushingVector[i];
            if (counter == 1)
            {
              floatBST.insertionFirst(rootFloat, fill);
            }
            else
            {
                floatBST.insert(fill);
            }
        }
        is.close();
       goto FLOAT;
    }
    if (listType == "s")
    {

        string fillstr;
        while (is >> fillstr)
        {

            counter++;
            if (counter == 1)
            {
                stringBST.insertionFirst(rootString, fillstr);
            }
            else
            {
                stringBST.insert(fillstr);
            }
        }
        is.close();
        goto STRING;
    }
    cout << "Commands:\n";
    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes (f), getSumofSubtrees (t), quit (q)";


INTEGER:
    found = false;
    int retrieveItem;
    if (listType == "i")
    {
        while (true)
        {
            cout << "\nEnter a command: ";
            char integerCommandInput;
            cin >> integerCommandInput;

            switch (integerCommandInput)
            {


            case 'i':
                cout << "Item to insert: ";
                int insertInput;
                cin >> insertInput;
                found = false;
                integerBST.retrieve(insertInput, found);
                if (found == false)
                {
                    integerBST.insert(insertInput);
                }
                else
                {
                    cout << "Item already in tree.\n";
                }
                cout << "In-Order: ";
                integerBST.inOrder();
                cout << "\n";
                break;
            case 'd':
                cout << "Item to delete: ";
                int deleteInput;
                cin >> deleteInput;
                found = false;
                integerBST.retrieve(deleteInput, found);
                if (found == false)
                {
                    cout << "Item not in tree.\n";
                }
                else
                {
                    integerBST.del(deleteInput);
                }
                cout << "In-Order: ";
                integerBST.inOrder();
                cout << "\n";
                break;
            case 'r':
                cout << "Item to be retrieved: ";

                cin >> retrieveItem;
                found = false;
                integerBST.retrieve(retrieveItem, found);
                if (found == false)
                {
                    cout << "Item not in tree.";
                }
                else
                {
                    cout << "Item found in tree.";
                }
                cout << "\n";
                break;
            case 'p':
                cout << "Pre-Order: ";
                integerBST.preOrder();
                cout << "\n";
                break;
            case 'o':
                cout << "Post-Order: ";
                integerBST.postOrder();
                cout << "\n";
                break;
            case 'n':
                cout << "In-Order: ";
                integerBST.inOrder();
                cout << "\n";
                break;
            case 'l':
                cout << "Tree Length: " << integerBST.getLength();
                cout << "\n";
                break;
            case 's':
                cout << "Number of Single Parents: ";
                cout << integerBST.getNumSingleParent(rootInteger);
                cout << "\n";
                break;
            case 'f':
                cout << "Number of leaf nodes: ";
                cout << integerBST.getNumLeafNodes(rootInteger);
                cout << "\n";
                break;
            case 't':
                cout << "Item to get sum of subtrees: ";
                int retrieveItem;
                cin >> retrieveItem;
                found = false;
                integerBST.retrieve(retrieveItem, found);
                if (found == false)
                {
                    cout << "Item not in tree.";
                }
                else
                {
                    cout << "Sum of Subtrees: " << integerBST.getSumOfSubtrees(rootInteger, retrieveItem);
                }
                cout << "\n";
                break;
            case 'q':
                cout << "Quitting program...\n";
                exit(0);
                break;
            default:
                cout << "Command not recognized. Try again.";
                cout << "\n";

                break;
            }
        }
    }
//////////////////////////////////////////////////////////////////////// FLOATING //////////////////////////////////////////////////////////
FLOAT:
    found = false;
    float retrieveFItem;
    if (listType == "f")
    {
        while (true)
        {
            cout << "\nEnter a command: ";
            char integerCommandInput;
            cin >> integerCommandInput;

            switch (integerCommandInput)
            {

            case 'i':
                cout << "Item to insert: ";
                float insertInput;
                cin >> insertInput;
                found = false;
                floatBST.retrieve(insertInput, found);
                if (found == false)
                {
                    floatBST.insert(insertInput);
                }
                else
                {
                    cout << "Item already in tree.\n";
                }
                cout << "In-Order: ";
                floatBST.inOrder();
                cout << "\n";
                break;
            case 'd':
                cout << "Item to delete: ";
                float deleteInput;
                cin >> deleteInput;
                found = false;
                floatBST.retrieve(deleteInput, found);
                if (found == false)
                {
                    cout << "Item not in tree.\n";
                }
                else
                {
                    floatBST.del(deleteInput);
                }
                cout << "In-Order: ";
                floatBST.inOrder();
                cout << "\n";
                break;
            case 'r':
                cout << "Item to be retrieved: ";
                cin >> retrieveFItem;
                found = false;
                floatBST.retrieve(retrieveFItem, found);
                if (found == false)
                {
                    cout << "Item not in tree.";
                }
                else
                {
                    cout << "Item found in tree.";
                }
                cout << "\n";
                break;
            case 'p':
                cout << "Pre-Order: ";
                floatBST.preOrder();
                cout << "\n";
                break;
            case 'o':
                cout << "Post-Order: ";
                floatBST.postOrder();
                cout << "\n";
                break;
            case 'n':
                cout << "In-Order: ";
                floatBST.inOrder();
                cout << "\n";
                break;
            case 'l':
                cout << "Tree Length: " << floatBST.getLength();
                cout << "\n";
                break;
            case 's':
                cout << "Number of Single Parents: ";
                cout << floatBST.getNumSingleParent(rootFloat);
                cout << "\n";
                break;
            case 'f':
                cout << "Number of leaf nodes: ";
                cout << floatBST.getNumLeafNodes(rootFloat);
                cout << "\n";
                break;
            case 't':
                cout << "Item to get sum of subtrees: ";
                cin >> retrieveItem;
                found = false;
                floatBST.retrieve(retrieveFItem, found);
                if (found == false)
                {
                    cout << "Item not in tree.";
                }
                else
                {
                    cout << "Sum of Subtrees: " << floatBST.getSumOfSubtrees(rootFloat, retrieveFItem);
                }
                cout << "\n";
                break;
            case 'q':
                cout << "Quitting program...\n";
                exit(0);
                break;
            default:
                cout << "Command not recognized. Try again.";
                cout << "\n";

                break;
            }
        }
    }


STRING:
    found = false;
    string retrieveSItem;
    if (listType == "s")
    {
        while (true)
        {
            cout << "\nEnter a command: ";
            char stringCommandInput;
            cin >> stringCommandInput;
            string insertInput;
            string deleteInput; 

            switch (stringCommandInput)
            {
            case 'i':
                cout << "Item to insert: ";
                cin >> insertInput;
                found = false;
                stringBST.retrieve(insertInput, found);
                if (found == false)
                {
                    stringBST.insert(insertInput);
                }
                else
                {
                    cout << "Item already in tree.\n";
                }
                cout << "In-Order: ";
                stringBST.inOrder();
                cout << "\n";
                break;
            case 'd':
                cout << "Item to delete: ";
                cin >> deleteInput;
                found = false;
                stringBST.retrieve(deleteInput, found);
                if (found == false)
                {
                    cout << "Item not in tree.\n";
                }
                else
                {
                    stringBST.del(deleteInput);
                }
                cout << "In-Order: ";
                stringBST.inOrder();
                cout << "\n";
                break;
            case 'r':
                cout << "Item to be retrieved: ";
                cin >> retrieveSItem;
                found = false;
                stringBST.retrieve(retrieveSItem, found);
                if (found == false)
                {
                    cout << "Item not in tree.";
                }
                else
                {
                    cout << "Item found in tree.";
                }
                cout << "\n";
                break;
            case 'p':
                cout << "Pre-Order: ";
                stringBST.preOrder();
                cout << "\n";
                break;
            case 'o':
                cout << "Post-Order: ";
                stringBST.postOrder();
                cout << "\n";
                break;
            case 'n':
                cout << "In-Order: ";
                stringBST.inOrder();
                cout << "\n";
                break;
            case 'l':
                cout << "Tree Length: " << stringBST.getLength();
                cout << "\n";
                break;
            case 's':
                cout << "Number of Single Parents: ";
                cout << stringBST.getNumSingleParent(rootString);
                cout << "\n";
                break;
            case 'f':
                cout << "Number of leaf nodes: ";
                cout << stringBST.getNumLeafNodes(rootString);
                cout << "\n";
                break;
            case 't':
                cout << "Item to get sum of subtrees: ";
                cin >> retrieveItem;
                found = false;
                stringBST.retrieve(retrieveSItem, found);
                if (found == false)
                {
                    cout << "Item not in tree.";
                }
                else
                {
                    cout << "Sum of Subtrees: " << stringBST.getSumOfSubtrees(rootString, retrieveSItem);
                }
                cout << "\n";
                break;
            case 'q':
                cout << "Quitting program...\n";
                exit(0);
                break;
            default:
                cout << "Command not recognized. Try again.";
                cout << "\n";

                break;
            }
        }
    }
}



