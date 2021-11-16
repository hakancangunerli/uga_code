/* 
hashing 
you have to find the position of the element in the array,
 always it'd involved search for linkedlist

 what happens with hashing is that you make the search constant. you'd need a unique identifier to do sth like this ofc. 


let's say we have 100 employees, we assign them a number between 0 to 99. 

this 6 digit number will be the key.

in this case, we'd say it's hash function= key % 100.
what happens if we have a collision? (same key) 


linear probing: check slide 10, you start searching linearly for a free space. the first free space is the one you'd like to use. you'd put it to five in this case. 
 
if you have too many collissions, you'll basically end up with the linear search. 
if we had something like 03,04,05,06,07, it'll cluster the elements together. compared to index 9, index 8 has a higher chance of being filled. 

in linear probing you should make it circular to search top and bottom to find wherever free possible.



rehashing:

hash = key % 100 
rehash = (hash + 3) % 100
because of this jumping around, you'd have less clustering and less collisions.

the %100 and 3 should be numbers that are prime when you pick your rehashing value. 


 */ 