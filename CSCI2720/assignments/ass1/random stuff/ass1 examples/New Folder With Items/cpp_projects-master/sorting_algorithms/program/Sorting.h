#ifndef SORTING_H
#define SORTING_H

class Sorting {

public:
    static int comparisonCount;
    void swap(int &a, int &b);
    void display(int *array, int size);
    void selectionSort(int *array, int size);
    void mergeSort(int *array, int l, int r);
    void merge(int *array, int l, int m, int r);
    void heapSort(int *array, int size);
    void reheap(int arr[], int n, int i);
    void quickSort(int arr[], int low, int high);
    void quickSortRandom(int arr[], int low, int high);
    int partition (int arr[], int low, int high);
    int partitionRandom (int arr[], int low, int high);

};

#endif 