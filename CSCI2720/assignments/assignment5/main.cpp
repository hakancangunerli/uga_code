#include <iostream>
#include <string>
#include <algorithm>
#include "Sorting.cpp"
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL)); // seed random number generator
    Sorting Sorting;   //creating an object of the class Sorting to access its methods
    ifstream readFile(argv[1]);
    string input_text = "";
    int array[100000];
    int i = 0;

    int value_generate;

    if (argv[1] == NULL) // if there's no file, give an error message
    {
        cout << "Please enter a file name" << endl;
        exit(1);
    }

    if (strcmp(argv[1], "generate") == 0) // if it's generate, generate a example.txt so you can see what it is, and use that array in the algorithms.
    {
        ofstream file("example.txt");
        int input_amount;
        cout << "how many numbers: ";
        cin >> input_amount;
        for (int i = 0; i < input_amount; i++)
        {

            array[i] = rand() % 10000; // randomly generate a number between 0 and 10000
            file << array[i] << " ";   // write that number to the file, so the user can read it
        }
        value_generate = input_amount;
    }

    while (getline(readFile, input_text)) // fill in the readfile if the user enters a file name instead of generate
    {

        istringstream iss(input_text);
        int num;

        // Populate numbers to array
        while (iss >> num)
        {
            array[i] = num;
            i++;
        }
    }

    char algo;
    cout << "selection sort (s) merge-sort (m) heap-sort (h) quick-sort-fp (q) quicksort-rp(r)\n"
         << endl;
    cout << "Enter the algorithm: " << endl;
    cin >> algo;

    if (algo == 's')
    {

        cout << endl; // empty line

        if (strcmp(argv[1], "generate") == 0)
        {
            Sorting.SelectionSort(array, value_generate);
            Sorting.PrintArray(array, value_generate);
            cout << "#Selection sort comparisons:" << Sorting.getComparison();
            cout << endl;
        }
        else
        {
            Sorting.SelectionSort(array, i);
            Sorting.PrintArray(array, i);
            cout << "#Selection sort comparisons: " << Sorting.getComparison() << endl;
            
            cout << endl;
        }
    }
    else if (algo == 'm')
    {

        cout << endl; // empty line
        if (strcmp(argv[1], "generate") == 0)
        {

            Sorting.MergeSort(array, 0, value_generate - 1);
            Sorting.PrintArray(array, value_generate);
            cout << "#Merge sort comparisons: " << Sorting.getComparison() << endl;
            cout << endl;
        }
        else
        {
            Sorting.MergeSort(array, 0, i - 1);
            // Sorting.PrintArray(array, value_generate);
            Sorting.PrintArray(array, i);
            cout << "#Merge sort comparisons: " << Sorting.getComparison() << endl;
            cout << endl;
        }
    }
    else if (algo == 'h')
    {

        cout << endl; // empty line
        if (strcmp(argv[1], "generate") == 0)
        {

            Sorting.HeapSort(array, value_generate);
            Sorting.PrintArray(array, value_generate);
            cout << "#Heap sort comparisons: " << Sorting.getComparison() << endl;
            cout << endl;
        }
        else
        {
            Sorting.HeapSort(array, i);
            Sorting.PrintArray(array, i);
            cout << "#Heap sort comparisons: " << Sorting.getComparison() << endl;
            cout << endl;
        }
    }
    else if (algo == 'q')

    {

        cout << endl; // empty line
        // quick-sort-fp first element as the pivot.
        if (strcmp(argv[1], "generate") == 0)
        {
            
            Sorting.QuickSort(array, 0, value_generate - 1);
            Sorting.PrintArray(array, value_generate);
            cout << "#Quick sort FP comparisons: " << Sorting.getComparison() << endl;
            cout << endl;
        }
        else
        {
            Sorting.QuickSort(array, 0, i - 1); // normal quicksort.
            Sorting.PrintArray(array, i);
            cout << "#Quick sort FP comparisons: " << Sorting.getComparison() << endl;
            cout << endl;
        }
    }
    else if (algo == 'r')
    {
        if (strcmp(argv[1], "generate") == 0)
        {

            Sorting.quickSortRP(array, 0, value_generate - 1);
            Sorting.PrintArray(array, value_generate);
            cout << "#Quick sort RP comparisons: " << Sorting.getComparison() << endl;
            cout << endl;
            
        }
        else
        {
    

            Sorting.quickSortRP(array, 0, i-1); // normal quicksort.
            Sorting.PrintArray(array, i);
            cout << "#Quick sort RP comparisons: " << Sorting.getComparison() << endl;
            cout << endl;
            
        }
    }

    else
    {
        cout << "Invalid input" << endl;
    }
}
