/*

you never delete anything from the array, you override the value at the index

for array based is length=0 where O(1) 

O(N)
for makeEmpty function
Nodetype *temp;
while (listdata != NULL){
    temp = listdata;
    listdata = listdata->next; 
    delete temp;
}
    length = 0;
     
/\/\/\/\/\

call this makeEmpty function for destructor 



*/ 