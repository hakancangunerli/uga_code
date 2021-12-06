// last class:

/*
stack, stack adt operations 

you're not doing search while push and pop (because you get it from the top of the stack or the bottom of the stack)

top points to the top of the stack

when you push, you can call the isFull method to see if it's full yet, if it's you can just call an exception 
when you pop , you can call the isEmpty method to see if it's empty yet, if it's you can just call an exception

all constant type 
if ( isEmpty()){
    throw "Stack is empty";
}else{
    return--; 
}

ItemType top(){
    if ( isEmpty()){
        throw "Stack is empty";
    }else{
        return info[top];
}

slide 40, there'll be a pointer but it's still an array-based implementation 

Queue: 
dequeue: remove the first item in the queue
eqnqueue : add the item to the rear of the queue


LECTURE NOTES:


we talked about unsorted array-based list. 

†
5,3,7 where these numbers are itemType object with length of 3. 

Complexity of Unsorted List : Search for -> O(n), Insertion -> O(1), Deletion -> O(N) [delete will always involve a search]

Slide 28: currentPosition is -1 because we are starting at the beginning of the list. currentPosition is only updated by getNextItem()

Within a sorted array-based list :
data is in order, 
2,5,7,9.... 
putItem, deleteItem 


look at slide 37: the insertion is O(n) since the loops are not nested. for and while [2N+1] 
slide 40: deleteItem is O(n) because the loops are not nested. for and while. [2N+1]
since the data is sorted, you can do binary search to find the item. for unsorted, you'd have to check the entire array, you just skip some here. 

slide 44: 
LESS: last = midPoint -1; 
GREATER : first = midPoint + 1;

check slide 45 for the complete code. 



created by the compiler, pointer will take more space than the variable , store the address of an int variable. 

let's say int is at address 4000, and int x=5;
int *ptr; 
ptr = &x;  // the ptr is now pointing to 4000.

cout << *ptr; will print out 5.
if you don't use *, you'll get the address of the variable.


pointer can only store the address. 

int *ptr; 
ptr = new int;  --> this will return an address. 
*ptr = 15; --> 15 will be stored at the address
delete ptr; to deallocate memory 

if it's not an address, you cannot deallocate it.


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
/*

you never delete anything from the array, you override the value at the index

for array based is length=0 where O(1) 

O(N)
for makeEmpty function
Nodetype *temp;
while (listdata != NULL){
    temp = listdata;
    listdata = listdata->next; 
    delete temp;
}
    length = 0;
     
/\/\/\/\/\

call this makeEmpty function for destructor 
 
Search -> linear search
Insert -> O(1) 
Delete -> O(1)+ O(n) [else is where you search]
Special case where the first node O(1) 
General case -> two pointers, one for location and the predloc 




Sorted link-list: Insert will change, Search will change 
Sorted and unsorted link-list delete is the same 


bool Search(item){
    NodeType *temp = listdata; 
    while(temp != NULL){
        if(item.compareto(temp->info) == EQUAL){
            return true;
        }
        if (item.compareto(temp->info)  == LESS){
            return false; 
            }
            temp = temp->next;

}

sorted link-list:
insert where you have to add in the very first one , empty case is a special case too 

/\ i think this is how it should look like /\
if (listdata == NULL){
    listdata = new NodeType;
    listdata->info = item;
    listdata->next = NULL;
    return true;
    }

Nodetype *predloc; 
Nodetype *location = listdata;
while (location != NULL){
   
    if (item.compareto(location->info) == LESS){
        break; 
    }
prodloc = location;
location = location->next;

prodloc->next = node; 
node->next = location;
length++;




*/

