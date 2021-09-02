#include "Sorting.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int Sorting::comparisonCount =0;

void Sorting::swap(int &x, int &y){
    int temp;
    temp = x;
    x=y;
    y=temp;
} //swaps two ints

void Sorting::display(int *array, int size){
    for(int i=0; i<size; i++) {
        cout<<array[i]<< " ";
    }
    cout<<endl;
} //displays array to standard output

void Sorting::selectionSort(int *array, int size){
    int i;
    int j;
    int min;
    for (i=0;i<size-1;i++) {
        min=i;
        for(j=i+1;j<size;j++) {
            comparisonCount++;
            if(array[j]<array[min]){
                min=j;
                //places min in correct position
            }//if
        } //for
        swap(array[i],array[min]);
    }//for
} //selectionsort

void Sorting::mergeSort(int *array, int l, int r) {
    int m;
    if (l<r){
        int m=l+(r-l)/2;
        mergeSort(array,l,m);
        mergeSort(array,m+1,r);
        merge(array,l,m,r);
    }
} //mergesort

void Sorting::merge(int *array, int l, int m, int r){
    int i;
    int j;
    int k;
    int nl;  //size of left array
    int nr;  //size of right array
    nl=m-l+1;
    nr=r-m;
    int larr[nl];
    int rarr[nr];
    for (i=0;i<nl;i++) {
        larr[i]=array[l+i];
    }//for
    for(j=0;j<nr;j++){
        rarr[j]=array[m+1+j];
    }//for
    i=0;
    j=0;
    k=l;
    //merge temp array with real array
    while(i<nl&&j<nr){
        if(larr[i]<=rarr[j]) {
            array[k]=larr[i];
            i++;
        }//if
        else{
            array[k]=rarr[j];
            j++;
        }//else
        comparisonCount++;
        k++;
    }//while
    while(i<nl){
        array[k]=larr[i];
        i++;
        k++;
    }//one more element in left array
    while(j<nr){
        array[k]=rarr[j];
        j++;
        k++;
    }//one more element in right array
} //helping function for mergesort

void Sorting::heapSort(int *arr, int n) {
    //heap building
    for (int i =n/2-1;i>=0;i--){
        reheap(arr,n,i);
    }//for
    for (int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        reheap(arr,i,0);
    }//for
} //heapsort

void Sorting::reheap(int arr[], int n, int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    //if left is greater than root
    if (l<n&&arr[l]>arr[largest]){
        largest=l;
    }
    comparisonCount++;
    //if right is greater than root
    if (r<n&&arr[r]>arr[largest]) {
        largest=r;
    }
    comparisonCount++;
    //if root is not largest
    if (largest!=i) {
        swap(arr[i],arr[largest]);
        reheap(arr,n,largest);
    }   
} //healping function for heapsort

void Sorting::quickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
  
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void Sorting::quickSortRandom(int arr[], int low, int high) 
{ 
    if (low < high) { 
  
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partitionRandom(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


int Sorting::partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 
  
    for (int j = low; j <= high - 1; j++) { 
  
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) { 
  
            i++; // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
        comparisonCount++;
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

int Sorting::partitionRandom(int arr[], int low, int high) 
{ 
    // Generate a random number in between 
    // low .. high 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    // Swap A[random] with A[high] 
    swap(arr[random], arr[high]); 
  
    return partition(arr, low, high); 
} 
