/*

FOR HW: 
part a) 

n*log(n^2+1) + n^2 log(n)
n log(n^2) = 2nlog(n)
= 2nlog(n) + n^2*log(n)

O(n^2*log(n))


question 4) 

T(n)= T(n-1)+ T(n-2)+ 1 ---- > T(n-2) will always be at T(n-1) 

T(n-2)  approximately T(n-1)
= 2T(n-1)+ 1 

LECTURE NOTES:


we talked about unsorted array-based list. 


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




*/ 