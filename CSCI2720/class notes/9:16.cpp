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





*/ 