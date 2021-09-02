#ifndef ITEMTYPE_H
#define ITEMTYPE_H

using namespace std;

enum Comparison {GREATER, LESS, EQUAL};

class ItemType {
    
public:
    ItemType();
    void print();
    void initialize(int number);
    Comparison compareTo(ItemType item);
    int getValue() const;
    
private:
    int value;

};
#endif
