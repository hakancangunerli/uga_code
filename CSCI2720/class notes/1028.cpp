/*
i = index of parent 

2i+1 left child 
2i+2 right child 
i = index of the child 

(i-1)/2 = index of the parent


let's say we got this list of values
0 50 
1 30 
2 70  let's say this is the case LC = 2*2+1 =5  RC = 2*2 +2 = 6 
3 10    
4 -1 
5 -1
6 80 
7 -1 (-1 to indicate that the node is empty)
8 15 

parent of 80 is : (6-1)/2 = 5/2 = 2 70
in an array based representation you can traverse in both directions 

Heaps 
Full tree: every non-leaf node has two children 
Complete tree: All the levels except the last level is full, the last level is partially filled, and is filled from left. 

Complete 
     x 
    / \
    y   z
    / \
    a   b

NOT COMPLETE:

     x 
    / \
    y   z
        / \
        a   b    

check slide 3 



every full also be complete. 


Heap: a binary tree that satisfies a special shape and order of properties. 
shape property:must be a complete binary tree. 
order property: the key of each node is greater than or equal to the keys of its children.


slide 6: the one of the left is not a heap, the one on the right is heap 
slide 7: also heap, complete and parent always bigger than children. 

similarly to bst, you can create different types of heap using multiple heaps.

min heap: parent always smaller than children (we'll not talk about this stuff)

max heap: parent is always bigger than children ( root is the largest value represented)

70
60
12
40
30
8
(there'll be no node with value -1 because the shape property shows that there'll be no -1 on this) 
    70
    /  \
    60   12 
    / \   \ 
   40  30  8 

priority queue: a data structure that satisfies the heap property.
2,5,10,3,1 
[2,5,10,3,1]
FIFO 

one with the largest value will have the largest priority
10, 5, 2, 3, 1
[10,5,2,3,1]

let's say we make a change to the leaf, we'd have to compare it with the parent, and if it's bigger than the parent, we'd have to swap it with the parent.
reheap-up 



*/ 

