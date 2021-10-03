// DONE
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison
{
    GREATER,
    LESS,
    EQUAL
}; // enumeration

class ItemType
{

public:
    ItemType(); // constructor 
    ItemType(int value);
    Comparison compareTo(ItemType item); // comparison 
    int getValue() const; // return the value instance variable 
    void initialize(int num); // initialize the data member num

private:
    int value;
};

#endif
