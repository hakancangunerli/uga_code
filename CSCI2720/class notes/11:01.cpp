
/* 
   10
 7    5
 2 3 

 when you dequeue, 10 will be removed because of the FIFO order of the queue operation 

10
7
5
2
3
would be stored like this in an array 
finding maximum is constant time


Dequeue:
1. make a copy of the root 
2. remove it from the heap
3. put last element in the root (at index 0 )
4. reheapdown


in a heap, all the levels are full except the last levels, which ensures the log(n) balance, it'd never be more than log(n) 

                DQ  EQ
Unsorted List  O(N) O(1)
Sorted List  o(1)   o(n)
BST        log(n)**   log(n)
Heap        log(n)    log(n)

** not guaranteed to be log(n) because we can't guarantee the tree is balanced

order property of the heap ensures that the tree is always balanced, so we can always do log(n) operations



Sorting Algorithms: 



6 sorting algorithms: -> Comparison based algorithms
3 of them have a complexity of O(n^2) -> number of data element comparison the algorithm has to make

bubblesort n^2 
insertion 
selection

3 of them have a complexity of O(n log n) -> number of data element comparison the algorithm has to make 
mergesort 
quicksort
heapsort

1. num of swaps, use of memory etc are also parts of analysis 

you cannot go below nlog(n) for any comparison based algorithms


the sorting needs to be done in ascending order, if it's descending order that means it's not "sorted"



 */ 