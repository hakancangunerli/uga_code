#include <fstream>
#include <iostream>
#include "Sorting.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    Sorting myList;
    int input;
    fstream fs;
    int numbers=0;
    fs.open(argv[1], fstream::in);

    if (fs.is_open()) {
        fs >> input;
        while (!fs.eof()) {
            numbers++;
            fs >> input;
        }
    }
    else {
        cout << "Failed to open the input file" << endl;
        return 0;
    } //input file error

    int list[numbers]; 
    fstream fs2;
    fs2.open(argv[1], fstream::in);
    int numberCounter=0;
    if (fs2.is_open()) {
        fs2 >> input;
        while (!fs2.eof()){
            list[numberCounter]=input;
            numberCounter++;
            fs2 >>input;
        } //creates array
    }
    cout << "selection-sort (s)\tmerge-sort (m)\theap-sort (h)\tquick-sort-fp(q)\tquick-sort-rp (r)\n";
    cout << "Enter the algorithm: ";
    char userInput;
    cin >> userInput;
    if (userInput=='s') {
        myList.selectionSort(list,numbers);
        myList.display(list,numbers);
        cout << "#Selection-sort comparisons: " << myList.comparisonCount<<endl;
    } //selection sort
    else if (userInput=='m') {
        myList.mergeSort(list,0,numbers-1);
        myList.display(list,numbers);
        cout << "#Merge-sort comparisons: " << myList.comparisonCount<<endl;
    } //merge sort
    else if (userInput=='h') {
        myList.heapSort(list,numbers);
        myList.display(list,numbers);
        cout << "#Heap-sort comparisons: " << myList.comparisonCount<<endl;
    } //heap sort
    else if (userInput=='q') {
        myList.quickSort(list,0,numbers-1);
        myList.display(list,numbers);
        cout << "#Quick-sort-fq comparisons: " << myList.comparisonCount<<endl;
    } //quick sort with first element as pivot
    else if (userInput=='r') {
        myList.quickSortRandom(list,0,numbers-1);
        myList.display(list,numbers);
        cout << "#Quick-sort-rp comparisons: " << myList.comparisonCount<<endl;
    } //quick sort with random element as pivot
    return 0;  //terminates program after one sort is done
}//main
