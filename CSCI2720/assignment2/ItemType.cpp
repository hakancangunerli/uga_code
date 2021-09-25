// DONE 

#include "ItemType.h"
using namespace std; 

ItemType::ItemType() {
}    // kurucu konstruktor 


Comparison ItemType::compareTo(ItemType item)  {
//  la comparaison von les items ici using l'enum palabras GREATER, LESS y finalmente EQUAL
if (item.getValue () > value){
    return Comparison::GREATER;
}else if (item.getValue () < value){
    return Comparison::LESS;
}  else {
    return Comparison::EQUAL;
}
// che cazzo aq it's correct!!!! 

}// compareTo

int ItemType::getValue() const {
    return value;
}// getValue 

void ItemType::initialize(int num) {
 value = num; 
}// initialize
