// tail recursion, remove the recursive, make a for loop or iterative loop 

// slide 29, just make it everything into a stack rev print is like 2,5,7 input would become 7,5,2 

/*
stack 
RevPrint(7)
RevPrint(5)
RevPrint(2)

LIFO WAY 

( this is also what the compiler pretty much does)
slide 53 

some rec functions are naturally inefficient , they're more elegant tho 


----- Binary tree---- 

Array-based list -> fixed size              binary tree 
Linked-List -> dynamic size             it'd be dynamic
Search Insert Delete -> O(n)            we 'd like it to be log(n)



binary tree-> node and a data 
can have upto 2 children 

     [15] -> root 
    /    \
[10]    [20] -> children
        /   \
    [5]  [12] -> children
leaf nodes are the ones who do not have any children 
5,12,10 would be leaf 

right subtree would be 20,5,12 

[if you look, recursive is the whole point of this thing ]


level zero would be 15  (level is the distance from the root)
level one would be 10,20 
level two 5,12
3 levels here. 

height of the tree: distance from the root to the furthest leaf 
height of this tree is 2 


binary search tree: slide 25 

the ones on the left subtree, the ones on the right subtree will be larger than the root

          40 
        /   \
    20       70 
    /  \     /  \   
   10   25  65  80
 /      /    \
 5     22     67 

we're not going to get a question about a binary tree, we talk about binary search tree (not BT)

node would be a struct

Struct Nodetype{
    ItemType info; 
    NodeType *left;
    NodeType *right;
}

70 30 45 90 85 15 100 91 

        [70]
        /    \
    [30]    [90]
    /  \    /  \
[15] [45] [85] [100]
               /
               [91]
                             
changing the order of the tree changes the tree shape [shape of the tree depends on the data]

when the binary tree is balanced, the height will be in proportional to log(n) 
we want a balanced tree, so we want the height to be log(n)

the balanced tree will not be checking to avoid unbalanced trees
you should randomize the data to make it balanced as supposed to be like a linkedlist because if you sort the data it'd be like
15 30 45 90 85 100 91



*/