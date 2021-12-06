// Master theorem will directly give you the answer 

/*
you can directly compute it by the formula 

the one in the slides is the simplest way to compute the answer

f(n) element of  O(n^k)

T(n) = T(n-1) +1 
let's say a=1, b=1, f(n)=1 
f(n) = n^0
k=0 

T(n) element O(n^k+1)
element of O(n^1+0)
T(n) element of O(n) 

example, 
T(n) = 1(n-1)+ n^2 , element O(n^3)

another one, 
T(n) = 2*T(n-1)+n , a =2 , b=1, f(n)=n , k=1 
then, T(n) would be O(n^ka^n/b)

element of T(n) element of n*2^n 

can't do this with a linkedlist 



// 


T(n) = T(n/2)+ 1 
+1 is always for constants. 


applying master formula
a is 1, b is 2 and d= 0 
b^d 
b^d = 2^0 
b^d =1 
a= b^d
second case, 
T(n) theta (n^d * log(n))= theta (n^0 log(n)) = theta (log(n))




Master theorem for dividing functions:


T(n)= theta(n^d) if a< b^d 
Theta (n^d*log(n)) if a = h^d 
theta (n^(log base b  (a) )) if a > b^d



CH3_CH4_LIST ADT Unsorted List:

list adt : unsorted list and sorted list
in unsorted list: there's array based and linkedlist based


in array-based unsorted list: the order in which the elements are stored is not important.
no duplicate elements allowed (although in the assignment it is allowed)

ADT Operations: resetList is not an iterator operation
operations
Constructor
Transformations
Observer
Iterator

slide 9 
unsorted array based list:
3,7,5..
within this example, 3 is not an integer, it's an object of ItemType. within this case, your implementation is not based on a data type. 


*/
