// you won't need a set method if you get a constructor for the assignment. 
// just assume they type in an integer. 1->instructor 2-> student 


// you can make an array if you want for each student and pass the array between the methods [static array maybe], you can also ask to input again and again too idk 

// we're csci-2720c 

// time v n graph 

/*


f(n) = f(n-1) +2 -> recursively 

f(n) = 3n^2 + 5n+1 
O(f)= n^2 

complexity is the growth of the f(n)


monotonic increasing functions:
c(1) = 1 
log(n) 
n 
n*log(n) 
n^2 
n^3
n^10 
2^n  -> exponential
n! -> factorial

Big O notation:

f(n) <= c* g(n)
c>0, n0 >0, n > n0

we're trying to find the bound, since f(n) will never surpass c*g(n), that's the upper boundary

Big Omega notation:

f(n) => c* g(n)

 since c*g(n) will never surpass f(n), that's the lower boundary


big theta is:
c*g(n) <= f(n) <= c2*g(n)

lower bound and upper bound we're know them 

the theta of this function is theta (n)

Sk(n) = 1^k + 2^k +...+n^k

Sk(n) = theta(n^(k+1))

S= 1+2+...+n
S= n*(n+1)/2 
θ(n^2) k=1 

θ(n^1+1)

if Sk(n) belongs to O(n^k+1) and Sk(n) belongs to omega (n^k+1) then Sk(n^k+1) belongs to theta(n^k+1)

f(n)<= c*g(n)
f(n) is Sk(n)

coming from Sk(n) = 1^k + 2^k +...+n^k , we can say that Sk(n) <= n^k + n^k +... + n^k 

Sk(n) = n*n^k
Sk(n) = n^k+1
Sk(n) <= n^k+1 what is c? 1 k is k so

Sk(n) belongs to O(n^k+1) 

we need to show that Sk(n) belongs to omega(n^k+1)

f(n) => c*g(n)

Sk(n) = n summa i=1  of i^k

Sk(n) = n summa i=1 (n-(i-1))^k

2* Sk(n) = n summa i=1  of i^k  + n summa i=1 (n-(i-1))^k


at i=1, you get 1+n^k  so 1+n^k => (n/2)^k
i= n/2 , you get (n/2)^k + (n/2 + 1)^k => (n/2)^k 
n^k+1 => (n/2)^k
this means that each term on the left it's always bigger than (n/2)^k thus it will be all bigger than the n summa i=1 , (n/2)^k

2Sk(n)=> n summa i =1 , (n/2)^k 

so Sk(n) >= n^k+1 / (2^(k+1))
c= 1/2 k+1
Sk(n) => (n^k+1)/(2^(k+1)) elements of omega n^k+1

x
*/
