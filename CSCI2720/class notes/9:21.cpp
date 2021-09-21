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


to insert you do,

void Insert(itemtype item){
    node-> info = item;
    node->next = listdata;
    listdata = node;
    length++;
}
complexity of this is constant

Search will not change, just linear search only just the syntax changes 


bool Search( itemtype item){
    Nodetype *temp = listdata;

    while (temp != NULL){
        if ( item compareto(temp->info == EQUAL )){
            return true;
        }
        temp = temp->next;
    }
    return false;

    
    }


special case where the first node is the one you want to delete

void delete(itemtype item){
Nodetype *temp;
if(item compareto(listdata->info == EQUAL)){
temp = listdata;
listdata = listdata->next;
delete temp;
length--; 
}else{
    Nodetype *predloc; 
    Nodetype *location= listdata; 

    the general case (all the other ones basically) 
while (location != NULL)
{
    if (item compareto(location->info == EQUAL))
    {
        break;
    }

    predloc = location;
    location = location->next;
    }
    predloc->next = location->next;    
    delete location;
    length--;

}
}
}
check slide 84;



* /

