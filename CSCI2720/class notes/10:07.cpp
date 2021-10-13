// Sorted Array-based list
item is 6

list 2, 5, 7, 10  // 10 is info, 2 is itemType, getLength(), 
// we want 
list1= 2,5 
list2 = 9, 10
SplitLists(ListType& list1, ListType& list2, ItemType item){

}

list1.makeEmpty();
list2.makeEmpty();
for (i=0; i<length; i++){
    if (info[i].compareTo(item)== GREATER){
        list2.insert(info[i]);
    }
    else{
        list1.insert(info[i]);
    }
}



// how in linkedlist?

// you'd use a while loop

// NodeType *temp;
// temp = listdata;

// while(temp != NULL){
//     if (temp->info.compareTo(item)== GREATER){
//         list2.insert(listdata->info);
//     }
//     else{
//         list1.insert(listdata->info);
//     }
//     listdata = listdata->next;
// }


if you want to do a for loop
in this case, we'd make list1 = 2,5,7,10, list2 = 9,10 list3= 9,10

list2.makeEmpty();
list3.makeEmpty();
for (i=0; i<list1.getLength(); i++){
    item2= list1.getNextItem();

    if (info[i].compareTo(item)== GREATER){
        list2.insert(info[i]);
    }
    else if (info[i].compareTo(item)== LESS){
        list3.insert(item2);
    }
    else{
        list1.insert(item2);
    }
}

// deleteItem slide from photos

int location =0;
int index; 
bool moreToSearch;
moreToSearch = true; // location < length; 
bool found = false; 
while (!found && moreToSearch){
    switch (item.CompareTo(info[location])){
        case LESS:
            location++;
            moreToSearch= 
            break; 
        case GREATER:
            location++;
            moreToSearch= 
            break;
        case EQUAL:
            found = true;
            break;
    }
} 
}

if(found){
    info[location] = info[inflength-1];
    length--;
}
}


///



//1  0
//2 length -1 
//3 first <= last 
//4 midPoint + 1;
//5 midPoint + 1; 
//6  info[midPoint]; 
// https://sites.cs.ucsb.edu/~mikec/cs24/misc/DaleCode/Chapter4/Array/sorted.cpp

// stack 
3
5
16
1
0
item =5 

*q = new int; // invalid  *q is an integer since it's dereferences, new int is an address q= new int would be correct  

a yes
b no
c no 
d yes
e no
f yes 
g yes 
h no // can't put a start before integer 
i no 
j yes
k yes 
l no 
m no // asterisk wrong side, *q = NULL is also wrong since null is not possible like that for this 
n yes 
o no 
p = 2q // you can't? 
int **p; // has to be double pointer 