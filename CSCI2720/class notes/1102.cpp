/* 
selection sort:

find minimum and swap it with the top of the list 

36 -     6     6 
24      24-    10
10      10-    24-
6 -     36     36
12      12     12-


some factors to consider for analysis: 
1. num of comparison
2. num of swaps
3. memory


this is a n^2 
finding a minima  (for n elements, we'd iterate through the list n-1 times for first iteration, second would be n-2 etc) 
 basically n(n-1)/2 which is n^2/2 -> n^2 

check slide 14, slide 16 

Bubble sort:
36                36        6
24                24        36
10                i-1=10    i-1= 24
i-1= 6            i= 6      i= 10
i= 12             12        12
you compare i with i-1, if they're out of order, swap 
6,12 is in order 

first second  third  forth  
(n-1)  (n-2)   1    (n-1) .... n(n-1)/2 


the bubblesort2 would not do the (n-1) action at the very end. 
comparison after inserting sorted again O(n) time to detect whether it's sorted or not. 


Insertion sort:
like a deck of cards, pick a number and put it between the other numbers

single card 

36-   24  10
24-   36  24
10    10  36
6     6   6 
12    12  12         very last one 
(0)   (1)  (2)   ... (n-1)

n(n-1)/2 

comparison after inserting the sorted: less comparison O(n)

sorted or partially sorted: use insertion
!! bubblesort performance is not linear


divide and conquer family: 
625 - 437 
256 -  347
then merge 

o^2 

(n1+n2) if it's size 50 for each, it's 100 
since this is o^2,

50^2 + 50^2 + 100 = 5100 



(divide and conquer)  mergesort:

mergesort follows the same structure as the divide and conquer mentality above; 


(divide and conquer) quicksort:   


 heapsort:

 
*/ 