Hakan Can Gunerli #811727237 hcg41790 

Anjiya Kazani #811921000 afk01397 

## To run: 
compile using 

    make 

delete using 

    make clean

to run the code, use:


    ./main [filename]

to run the code with the generator 

    ./main generate
    type in the amount of numbers you want to generate
    the numbers will both be generated in example.txt as well as in the terminal

## who did what

Hakan did:

    Quicksort 
    HeapSort
    Reheapdown
    Swap
    Split
    printArray
Anjiya did: 

    Selection sort 
    MergeSort 
    Merge
    MinIndex 
    getComparison
Collectively:

    randomizer
    bug fixes

We've used these books to create the algorithms: 
    
    C++ Plus Data Structures, Nell Dale
    Introduction to Algorithms, CLRS
    Slides 
    GeeksforGeeks
    Stackoverflow (for bugs and issues in the code)


Generator working system:
The generator works as follows:

A seed number is generated, and the number is used to generate a random number.
then, if no txt file is provided in the argv, the generator will automatically will generate numbers and put the resulting numbers into example.txt (THIS FILE        IS NOT USED TO BE READ AGAIN, IT IS SO THAT THE USER CAN SEE WHAT NUMBERS ARE BEING GENERATED. )
This array and the amount of numbers generated is then passed into the wanted algorithm. Each algorithm has 2 functions called since we can either have selection sort based on random numbers or just from the file that's passed into our argv. 
