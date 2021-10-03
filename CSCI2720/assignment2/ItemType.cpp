// DONE
#include <iostream>
#include <fstream>
#include "ItemType.h"

using namespace std;

ItemType::ItemType() {
    value = 0;
}

ItemType::ItemType(int value) {
    this -> value = value;
}

Comparison ItemType::compareTo(ItemType item) {
    if (this -> value > item.getValue()) { // if the getValue which returns a const value is greater than the value of the item passed in, return GREATER
	return GREATER;
    }

    else if (this -> value < item.getValue()) { // if the getValue which returns a const value is less than the value of the item passed in, return LESS
	return LESS;
    }

    else { // if both of these are false, assume equality. 
	return EQUAL;
    }
}

int ItemType::getValue() const { // returns the value of the item
    return value;
}

void ItemType::initialize(int num) { // sets the value of the item to the value of num
    this -> value = num;
}

