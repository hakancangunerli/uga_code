Hakan Gunerli
#811727237

to compile:

$ `make compile`:

to run:

$ ` make run`

to remove main:

$ `make clean`

Merge is a O(n) since the while loop iterates through the list and the rest is O(1), or constant. Since the loop goes until the length of the list, the most efficient way to conduct this would be such way. Could also do a nested loop here with worse complexity. 


Merge pseudocode:
position equal to the head of the list 
whileSearching is not position null, 
print lists to the user

while the whileSearching condition exists

if the position of the item is a duplicate
    do not let insert duplicate item. 
otherwise, insertItem at the position.
make position point to the next 
and set whileSearching to the position not equal to null again 
print the new list 

finding common elements' pseudocode is as follows: 

print the lists to the user
set our position to equal to the head of the list 
while the whileSearching condition exists 
the location should be the head of the list 
set our null checker untilNull to position not being equal to null, like whileSearching 
commonElement should be false initally 
while untilNull exists, 
write a switch comparison to check for cases one by one

- Greater being the location pointing to the next of the location
and untilNull still being location not being equal to null and break. 

- Equal being the commonElement being achieved and untilNull being false 
- Less being that untilNull is false, not a common element, like greater. only equal has the commonElement found.


if we were not able to find a commonElement then we should delete the item of the position 
make position equal to position next 
and whileSearching equal to position not being null
and finally print the list. 

Since there are two while loops nested here, where first loop iterates the length and second loop likewise does the same. For this purpose, the most efficient way of achieving such result would be O(n^2), or quadratic complexity. 
