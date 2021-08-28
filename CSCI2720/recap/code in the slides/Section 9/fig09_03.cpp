// fig09_03.cpp
// Program to test class Time
// NOTE: This file must be compiled with Time.cpp 
#include <iostream>
#include "Time.h" // include definition of class Time from Time.h
using namespace std;
int main(){
    Time t; // instantiate object t of class Time
    cout << "The initial universal time is "; 
    t.printUniversal(); // print universal time
    cout << "The initial standard time is";
    t.printStandard(); // print standard time

t.setTime(13,27,6); // set time to 13:27:06

// output Time object t's new values 
cout << "\nUniversal time after setTime is ";
t.printUniversal();
cout << "Standard time after setTime is ";
t.printStandard();

t.setTime(99,99,99); // set invalid time
// output t's values after specifying invalid time
cout << "Universal time ";
t.printUniversal();
cout << "Standard time ";
t.printStandard();
cout << endl; 
} // end main
