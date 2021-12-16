#ifndef SORTING_H
#define SORTING_H

class Sorting
{
private:
    int comparisons;

public:
    void PrintArray(int *values, int numValues);
    int getComparison();
    void Swap(int &a, int &b);
    int MinIndex(int values[], int start, int end);
    void ReheapDown(int values[], int root, int bottom);
    void Split(int values[], int first, int last, int &splitPoint);
    void Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast);
    void randomNumberGenerator(int values[], int numValues);
    // Sort Functions
    void SelectionSort(int values[], int n);
    void MergeSort(int values[], int first, int last);
    void HeapSort(int values[], int numValues);
    void QuickSort(int values[], int first, int last);
    void quickSortRP(int values[], int first, int last);
    int partition_random(int values[], int first, int last);
    int SplitRandom(int values[], int first, int last);
};
#endif