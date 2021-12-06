// heap chapter and sorting chapter 18th 
/*
Split is the function to split the array in like Slide 49 into two parts. 

then you call the Quicksort on the left and right part. 

the comparison is O(nlog(n))


when you split the array 

it'd be n/2 level 
n/4 and n/4 

      O(N)
  n/2    n/2     -> O(n)
n/4 n/4 n/4 n/4   -> O(n)


for quicksort, if the data is sorted 

2 5 7 11 13 15 17 

first value is the split value split function will be producing the same list  n-1 
then it'll sort still 5 the split will have n-2 

size of the split will be  n levels of split 
how many comparisons? n amount of comaparisons 


number of comparisons would be n^2 for this case

if you want to overcome that, you can randomly pick an index instead. 
when you randomize, it should be nlogn


heapsort:

70 -> max value is here 
60
12
40
30
8
10 

you swap 70 with 10, 70 is sorted now 


     10
   60  12 
  / \  /
40 30  8   

you reheap the 10 so the tree looks like this:
    60 
  40     12
  / \    / 
10  30  8  

so 60 is a part of 70's sorted list 


continue doing this stuff until you have sorted the whole list

cost of constructing heap is linear O(n)


all the algorithms recap:

3 algos that are n^2 , three algos that are nlogn
mergesort (uses more memory)
quicksort 
heapsort nlogn (addiotional order n cost at constructing it)


*/ 