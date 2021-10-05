/*

circular list -> special case insert in the empty, when you insert at the end
general case ->insert in the beginning , reverse from linkedlist 

search -> o(n)
insert -> o(n)
delete

special cases for deletions: 
deleting from the end
deleting the last node 


doubly linked-list

struct Nodetype{
    ItemType info;
    Nodetype *next;
    Nodetype *back;
}

no need to change the algorithms, you're just changing the amount of pointers you're updating 
the special cases are the same as singly linked list

preloc->next=node;
node->back=preloc;
node->next=location;
location->back=node;

in theory you don't need a predloc 

give a situation, pick an advantage of what you want to do
doubly you can go back and forth
circular you can come back to the beginning


header and trailer node


let's assume we got no class, then we can do it using struct

struct NodeType{
    char c;
    int next; where the second item is
}

struct List{
    NodeType node[10];
    int first; will tell you where the first item is
}

List L1; 

char next
0 C | 2 
1 D  | -1 
2 E  | 4 
3 A  | 0 
4 B | 1
first 3 

-1 is like a null 


don't study shallow copy

slide 35

what are the elements in list 1 john nell susan and sussanne 
list 2: mark naomi and robert 


NUL - -1 
NULL is null, you know that already 
*/ 