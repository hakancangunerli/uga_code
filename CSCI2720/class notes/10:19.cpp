/*

 slide 55: recursive function: some of the terms are computed multiple times 

for this specific example: 
iterative O(n) 
recursive O(n^n)

linkedlist: (slide 24) 
basecase when the list is empty 
recursive case:


within this context, base case is implicit and base cases do nothing. 
RevPrint(listdata)
if (listdata != NULL )
{
    RevPrint(listdata->next)
    cout << listdata.info() << endl;
}



you'd need an activation record to keep track of the x,y,z and use that in the runtime stack back in the day (this is also what a compiler does)

Activation Record:
x=10
y=5
count =15 
check slide 44



it's because of the activation record that the recursive complexity is bad on storage, not time. 


tail recursion where the last call is the recursive call. you pretty much replace it with a for loop. some best cases will become a case 


printReverse is not a tail recursive function.

*/

