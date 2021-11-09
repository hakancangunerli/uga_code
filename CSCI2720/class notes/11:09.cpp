/* 
Merge sort uses more memory
Heap sort has the cost of constructing a heap (O(n) cost )
Quicksort: if the data is sorted, it's going to be very bad 


there are algorithms that are better than nlogn 
radixsort is O(n), no comparison 

n : number of elements
d: number of digits

800
157 
001
034 
268
009
530 


you check for the first digit 
800 
530
001
034
157
268
009
then you sort on the second digit
800 
001
009
530 
034 
157
268
then you sort on the third digit
001 
009 
034 
157
268
530
800 


you've a "bucket" 

0 800, 530 
1 001 
4  034
5 
6 
7  157
8 268 
9 009
0

step 2 :

0 800 001 009 
1
2
3 530 034 
4
5 157 
6 268
7
8
9


finally it'd be like this: 

0 001 009 034 
1 157 
2 268 
3
4
5 530 
6
7
8 800 
9


N cost since you go through numbers and put them in a bucket 

AVL trees:

         5
       /   \
      2     10 


balance factor: height of left subtree - height of right subtree

in this case it's 0. 
      5 
   2 

balance factor 1-0 = 1 


AVL tree:

   30 
 20 
10 

when the balance factor is not -1 or 1, it will perform rotation 
4 types or rotation
1. left rotation
2. right rotation
3. left-right rotation
4. right-left rotation
 
 a right rotation would make this 

   20 
  10 30  


    30
  20 
10  25 

if we want to balance this tree due to the order property, we'd have to move things around (generalized case)


   20 
10   30 
    25 


Multiple nodes can also be unbalanced 
first unbalanced node is the first one you do the rotation on.  that's when you do double rotation 

check slide 17 for more info LR rotation 

*/ 