// DONE 

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum class Comparison{LESS, GREATER, EQUAL}; // the enum class for the comparison

class ItemType
{
public:
    ItemType();
    ~ItemType();
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);
private:
    int value; 
};
#endif 