#include "ItemType.h"

using namespace std;

ItemType::ItemType() {
    value = 0;
} // default constructor

Comparison ItemType::compareTo(ItemType item) {
    if (item.value > this->value) {
        return LESS;
    }
    else if (item.value < this->value) {
        return GREATER;
    }
    else {
        return EQUAL;
    }
} //comparison

int ItemType::getValue() const {
    return value;
} //returns value as an int

void ItemType::initialize(int num) {
    value=num;
} // initializing value


