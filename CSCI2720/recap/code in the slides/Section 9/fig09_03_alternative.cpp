// Fig 9.3: fig09_03_alternative.cpp
// program to test class time   
#include <iostream>
#include <stdexcept>
#include "Time-Figure9.1.h"
using namespace std;

void displayTime(const string& message, const Time& time){
    cout << message << "Universal time: " << time.toUniversalString() << "Standard time" << time.toStandardString() << endl;
}

int main(){ 
    Time t; // instantiate object t of class Time 
    displayTime("Initial time: ", t); 
    
    t.setTime(13, 27, 6); // set object t to 13:27:06 universal time

displayTime("After setTime", t);


try{ 
    t.setTime(99, 99, 99); // attempt to set invalid time
}
catch (invalid_argument& e){
    cout << "Exception " << e.what() << " thrown." << endl;
}

displayTime("After attempting invalid time", t);
}