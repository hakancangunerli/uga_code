/*

templates for doubly-linked list

everything until circular-list (including circular-list)

circular-linked list will point back to the first item. the only thing is that the last node is pointing to the first node 

you no longer check for null 

insertion operation in the beginning and the end : O(n) (since you have to traverse the entire list)

listdata node at the last node not the first (for efficiency)


findItem(&predloc, &location, &found, item, listdata)



predloc = listdata;
location = listdata->next; 
do{
    if(item.compareTo(location->info) == LESS){
        break
    }
    predloc = location ;
    location = location->next;
}while(location != listdata->next)

insert at the end is also a special case 
insert empty list also a special case 


void Insert(item){
    
if (listdata == NULL){
    NodeType *n = new NodeType;
    node->info = item;
    node->next = node;
    listdata = node;
}
else{
    findItem(&predloc, &location, &found, item, listdata);
  if(){

  }else{
      general case
  }
}
}


*/ 

