/* 
quiz only on CH3_CH4

pointers will be on the quiz 


recap:
array-based list: 
-unsorted list 
search O(n) 
insert O(1)
delete O(n)
-sorted list 
search O(n) or binary search O(log(n))
insert (O(n))
delete O(n)
the structure is exactly the same


allocate a space, you use a pointer: int *p = new int; 
somewhere in the program, there should be a delete p;
recap end,

we'll use structs instead of class in assignment2 

if we know the size of our operation, array based list is better than linked list. bc of its dynamic nature. linkedlist uses pointers. 


data members of a linkedlist:

struct NodeType{
    itemType info; // itemtype object 
    NodeType *next;  // pointer to the next node

};
 data members ->
there needs to be a listData pointer that points to the first node.
int length -> length of the list
nodeType *currentPos -> pointer to the current position of the list
Slide 58: 
public methods are the same from the previous slides 



how the main would look like:

Itemtype item;
item.initialize(15);
UnsortedList L1; 
L1.insert(item);


getLength would just be return length;

isFull would check if allocation of memory is successful. check slide 71. 

function allocates memory and see if you create a new node or not. 
*/ 