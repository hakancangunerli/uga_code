# assignment3
Hakan Gunerli
hcg41790@uga.edu

-- instructions here--- 


`make` to compile

` make clean ` to remove main file 


` ./main <filename>` to run the specific file of your choosing. 


# deleteSubsection pseudocode
```
using T class template
procedure DoublyLinkedList<T>::deleteSubsectionT address of lower bound , T address of upper bound
 
  NodeType<T> *lowerBound 
  NodeType<T> *upperBound 
  NodeType<T> *middleContent  

  bool headUpperBound equals  head point to data more than ub 
  bool tailLowerBound equals  tail point to data less than lb 

  if head equals equals  NULL OR headUpperBound OR tailLowerBound
   
    return  
   
  lowerBound equals  head  
  while lowerBound not equal to NULL && lowerBound point to data less than lb
   
    lowerBound equals  lowerBound point to next  
   
  if lowerBound not equal to NULL
   

    if lowerBound point to back equals equals  NULL
     
      
      head equals  head point to next 
      head point to back equals  NULL 
      delete lowerBound 
      deleteSubsection lb, ub  
      return 
     

    else if lowerBound point to back equals equals  NULL && lowerBound point to next equals equals  NULL
     
      
      head equals  NULL 
      tail equals  NULL 
      delete lowerBound 
      return 
     

    else if lowerBound point to next equals equals  NULL
     
      
      tail equals  tail point to back 
      tail point to next equals  NULL 
      deleteSubsectionlb, ub  
      delete lowerBound 
      return 
     

    else
     
      
      upperBound equals  tail 
      while upperBound not equal to NULL && upperBound point to data more than ub 
       
        upperBound equals  upperBound point to back 
       

      if upperBound point to next equals equals  lowerBound 
       
        return 
       
      else
       
        lowerBound point to back point to next equals  upperBound point to next 

        while lowerBound not equal to upperBound
         
          
          middleContent equals  lowerBound 
          lowerBound equals  lowerBound point to next 
          delete middleContent 
         
       
      return 
     
   
 
```


This entire excerpt will have a O(n) complexity given the lack of nested loops and and simple comparisons and checks. Every while loop is n complexity, and they're not nested so they're added not multiplied. All of the pointer address pointing are 1s. Finally, the recursive deleteSubtraction call is also n but they are never called in a while loop, making it n+x, thus the overall complexity of this function is O(n). 




# Mode pseudocode:
```
using T class template
T DoublyLinkedList<T>::mode
 
  NodeType<T> *temp 
  NodeType<T> *modeNode 
  NodeType<T> *placeH 
  temp equals  head 
  placeH equals  head 

  int bigMode equals  0 

  while placeH point to next not equal to NULL
   
    temp equals  head 
    int iterator equals  0 
    int mode equals  0 
    while temp not equal to NULL 
     
      if placeH point to data equals equals  temp point to data
       
        iterator increase   
        mode equals  iterator 
       
      temp equals  temp point to next 
     

    
    if bigMode less than mode
     
      modeNode equals  placeH 
      bigMode equals  mode 
     
    placeH equals  placeH point to next  
   
  return modeNode point to data 
 
```


The overall complexity of this method where we are iterating through the entire list to find the modes is O(n^2) complexity due to the nested while loops at "while placeH point to next not equal to NULL" and "while temp not equal to NULL".  


# swapAlternate pseudocode: 
```
using T class template
procedure DoublyLinkedList<T>::swapAlternate
 
  NodeType<T> *temp equals  head point to next 
  NodeType<T> *temporaryHead 
  bool HeadEmpty equals  head equals equals  nullptr OR head point to next equals equals  nullptr 
  bool isEven equals  lengthIs % 2 equals equals  0 

  if HeadEmpty 
   
    return 
   

  if lengthIs less than 3
                             
    head point to back equals  temp        
    head point to next equals  temp point to next  
    temp point to next equals  head        
    temporaryHead equals  head 
    temp point to back equals  nullptr 
    head equals  temp 
    temp equals  temporaryHead 
   
  else
   

    head point to back equals  temp        
    head point to next equals  temp point to next  
    temp point to next equals  head        
    temp point to back equals  nullptr 
    head point to next point to back equals  head 

    temporaryHead equals  head 

    head equals  temp           
    temp equals  temporaryHead  

    temp equals  temp point to next point to next 

    if isEven && temp point to next equals equals  NULL
     
      goto DIVISIBLE  
     
    else
     

      while temp not equal to nullptr
       
        

        temp point to next point to back equals  temp point to back  
        temp point to back point to next equals  temp point to next  
        temp point to next equals  temp point to back        

        temp point to back equals  temp point to back point to back  
        temp point to back point to next equals  temp        
        temp point to next point to back equals  temp        

        temp equals  temp point to next point to next point to next  

        if lengthIs % 2 equals equals  0 && temp point to next equals equals  NULL
         
          go to DIVISIBLE LABEL
          
         
DIVISIBLE LABEL :
  if isEven && temp point to next equals equals  NULL
   
    NodeType<T> *tempTail equals  tail point to back 

    tail point to next equals  tempTail  

    tail point to back equals  tempTail point to back  

    tempTail point to back equals  tail     
    tempTail point to next equals  nullptr  

    tail point to back point to next equals  tail  

    tail equals  tail point to next  

    temp equals  nullptr  
   
```

swapAlternate's complexity is O(n). There is no nested while loops of any kind, there are only several if statements that are nested which are all of O(1) complexity. The while loops are not nested, and a goto statement it used to preserve the need for using the same method twice. 