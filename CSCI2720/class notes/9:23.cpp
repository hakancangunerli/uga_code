/* 
Search -> linear search
Insert -> O(1) 
Delete -> O(1)+ O(n) [else is where you search]
Special case where the first node O(1) 
General case -> two pointers, one for location and the predloc 




Sorted link-list: Insert will change, Search will change 
Sorted and unsorted link-list delete is the same 


bool Search(item){
    NodeType *temp = listdata; 
    while(temp != NULL){
        if(item.compareto(temp->info) == EQUAL){
            return true;
        }
        if (item.compareto(temp->info)  == LESS){
            return false; 
            }
            temp = temp->next;

}

sorted link-list:
insert where you have to add in the very first one , empty case is a special case too 

/\ i think this is how it should look like /\
if (listdata == NULL){
    listdata = new NodeType;
    listdata->info = item;
    listdata->next = NULL;
    return true;
    }

Nodetype *predloc; 
Nodetype *location = listdata;
while (location != NULL){
   
    if (item.compareto(location->info) == LESS){
        break; 
    }
prodloc = location;
location = location->next;

prodloc->next = node; 
node->next = location;
length++;


/// NOT IN QUIZ /// 
Stack and Queue:

STACK LIFO 
operations: slide 5 
no insert and delete for this, we say push/pop 
you never search a stack 

QUEUE FIFO



*/ 
