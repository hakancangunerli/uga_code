// Figure 9.8 CreateAndDestroy.h
// CreateAndDestory class definition
// Member functions defined in CreateAndDestroy.cpp
#include <string>

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestroy{
public:
    CreateAndDestroy(int, std::string); // constructor
    ~CreateAndDestroy(); // destructor
private: 
 int objectID;
 std::string message;
}

#endif

