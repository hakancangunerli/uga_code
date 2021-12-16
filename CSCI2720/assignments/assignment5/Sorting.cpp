#include "sorting.h"
using namespace std;
#include <iostream>
#include <ctime>

int Sorting::getComparison()
{
    return comparisons; // we need this for returning the amount of comparisons.
}
// Author: Hakan Gunerli
void Sorting::Swap(int &a, int &b) // Swap is basically a Swap.
{
    // if this was python i could've just a,b = b,a. :(
    int temporaryValue = a;
    a = b;
    b = temporaryValue;
}
// Author: Hakan Gunerli
void Sorting::Split(int values[], int first, int last, int &splitPoint)
{
    int splitVal = values[first];
    int saveFirst = first;
    bool onCorrectSide;

    first++;

    do
    {
        onCorrectSide = true;

        while (onCorrectSide)
        {
            comparisons++;

            if (values[first] > splitVal) // if first is bigger than split val, we're not on the correct side.
            {
                onCorrectSide = false;
            }
            else
            {
                first++;
                onCorrectSide = (first <= last); // check if we're still on the correct side.
            }
        }

        onCorrectSide = (first <= last);

        while (onCorrectSide)
        {
            comparisons++;
            if (values[last] <= splitVal) // if last is smaller than splitval, we're at the wrong place again.
            {
                onCorrectSide = false;
            }
            else
            {
                last--;
                onCorrectSide = (first <= last); // check if we're still on the correct side.
            }
        }

        if (first < last)
        {
            Swap(values[first], values[last]); // Swap the values.
            first++;
            last--;
        }
    } while (first <= last); // while we haven't reached the end of the valuesay.
    splitPoint = last;
    Swap(values[saveFirst], values[splitPoint]); // Swap the split point with the first value.
}
// Anjiya Kazani
int Sorting::MinIndex(int values[], int start, int end)
{
    int indexOfMin = start;
    // Iterate through numbers
    for (int index = start + 1; index <= end; index++)
    {
        comparisons++;
        if (values[index] < values[indexOfMin]) // smaller than current minimum, minimumindex is index.
        {
            indexOfMin = index;
        }
    }
    return indexOfMin;
}

// Selection Sort
// Author : Anjiya Kazani
void Sorting::SelectionSort(int values[], int numValues)
{
    int endIndex = numValues - 1;
    for (int current = 0; current < endIndex; current++)
        Swap(values[current], values[MinIndex(values, current, endIndex)]);
}

// mergesort
// Author : Anjiya Kazani
void Sorting::Merge(int values[], int LeftFirst, int LeftLast, int RightFirst, int RightLast)
{
    int size = RightLast - LeftFirst + 1;
    int *temp = new int[size];
    int leftIndex = LeftFirst;
    int rightIndex = RightFirst;
    int tempIndex = 0;
    // until left index is less than right index and right index is less than right last
    while (leftIndex <= LeftLast && rightIndex <= RightLast)
    {

        comparisons++;
        if (values[leftIndex] < values[rightIndex]) // if left is less than right
            temp[tempIndex++] = values[leftIndex++];
        else // otherwise
            temp[tempIndex++] = values[rightIndex++];
    }
    while (leftIndex <= LeftLast) // if left index is less than left last
        temp[tempIndex++] = values[leftIndex++];
    while (rightIndex <= RightLast) // if right index is less than right last
        temp[tempIndex++] = values[rightIndex++];
    for (int index = 0; index < size; index++) // copy temp back into values
        values[LeftFirst + index] = temp[index];
    delete[] temp; // no need to keep temp
}
// Author: Anjiya Kazani
void Sorting::MergeSort(int values[], int first, int last)
{
    // mergesort is the same as quicksort, except that it uses the merge function and cuts into perfect two.
    if (first < last)
    {
        int mid = (first + last) / 2;             // cut it in half
        MergeSort(values, first, mid);            // sort the left half
        MergeSort(values, mid + 1, last);         // sort the right half
        Merge(values, first, mid, mid + 1, last); // merge them
    }
}
// Author : Hakan Gunerli
void Sorting::QuickSort(int values[], int first, int last)
{
    if (first < last)
    {
        int splitPoint;
        Split(values, first, last, splitPoint);   // split into two parts
        QuickSort(values, first, splitPoint - 1); // sort the left part
        QuickSort(values, splitPoint + 1, last);  // sort the right part
    }
}
// Author : Hakan Gunerli
void Sorting::HeapSort(int values[], int numValues)
{
    int index;
    for (index = numValues / 2 - 1; index >= 0; index--) // build heap
        ReheapDown(values, index, numValues - 1);
    for (index = numValues - 1; index >= 1; index--) // Swap root and last element, do a reheap down recursively.
    {
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1);
    }
}
// Author : Hakan Gunerli && Anjiya Kazani
void Sorting::PrintArray(int *values, int numValues)
{ // print valuesay based on the number of values.
    for (int i = 0; i < numValues; i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

// Author : Hakan Gunerli
void Sorting::ReheapDown(int values[], int root, int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;  // left child
    rightChild = root * 2 + 2; // right child

    comparisons++;

    if (leftChild <= bottom)
    {

        comparisons++;

        if (leftChild == bottom) // if leftchild is the same as the bottom, maxchild is the leftchild.
        {
            maxChild = leftChild;
        }
        else
        {
            if (values[leftChild] <= values[rightChild]) // if the
            {
                maxChild = rightChild; // if the left child is less than the right child, the maxchild is the right child.
            }
            else
            {
                maxChild = leftChild; // otherwise it's the left.
            }
        }
        // if the root is smaller than the maxchild, Swap and reheap down again.
        if (values[root] < values[maxChild])
        {
            Swap(values[root], values[maxChild]);
            ReheapDown(values, maxChild, bottom);
        }
    }
}
// Author : Hakan Gunerli  && Anjiya Kazani
void Sorting::randomNumberGenerator(int values[], int numValues)
{
    for (int i = 0; i < numValues; i++)
    {
        values[i] = rand() % 1000000; // random values are between 0 and 1000000.
        // assignment doesn't specify what numbers it should be between in.
    }
}

// this is Lomuto partitioning scheme.

int Sorting::SplitRandom(int values[], int first, int last)
{

    int pivot = values[last]; // start with the last element as our pivot point.

    int i = (first - 1); // start from the first element

    for (int j = first; j <= last - 1; j++) // for the entirety of the array 
    {
        
        if (values[j] <= pivot) // if the values we have for j is less than the pivot (aka if the current element is small or equal to the pivot)
        {
            comparisons++;
            i++; // icnrement the element 
            Swap(values[i], values[j]); // perform swap 
        }
    }
    Swap(values[i + 1], values[last]); // swap the pivot with the last element.
    return (i + 1); // return the index of the pivot.
}

int Sorting::partition_random(int values[], int first, int last) // COMPLETELY RANDOMLY GENERATED NUMBER
{

    srand(time(NULL));                            // randomly generate a number
    int random = first + rand() % (last - first); // random number between first and last.

    Swap(values[random], values[last]); // swap that with the last element.

    return SplitRandom(values, first, last); // call SplitRandom function.
}

void Sorting::quickSortRP(int values[], int first, int last)
{
    if (first < last) // until we reach the end, make partitions using the pivot point we have obtained through the random partition. 
    {

        int pivot_point = partition_random(values, first, last);

        quickSortRP(values, first, pivot_point - 1);
        quickSortRP(values, pivot_point + 1, last);

    }
}