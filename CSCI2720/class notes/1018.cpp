/*


factorial(n){
    if(n==0){ // can have many base cases 
        return 1 
    }else{ // general case is always recursive 
        return n*factorial(n-1)
    }
    }
}

you are always solving a smaller problem 

usually they are less efficient, iterative and recursive are pretty much similar on the complexity level. but it's heavy on memory. 
stores more variable than iterative 

you can switch an iterative to a recursive, and a recursive to an iterative 

complexity depends on the amount of recursion you call 


recurrence relationship and then apply the master theorem or backwards substitution












Recursive search(list, value, startIndex){

}




*/

// linear search recursively 

LinearSearch(list, value, startIndex){
    if(startIndex == list.length){
        return -1
    }
    if(list[startIndex] == value){
        return startIndex
    }
    return LinearSearch(list, value, startIndex+1)
}

