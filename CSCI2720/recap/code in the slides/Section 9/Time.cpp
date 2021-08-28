// Fig 9.2 Time.cpp
// Member-function definitions for class Time.
#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;

// time constructor initializes each data member to zero
// ensures all Time objects start in a consistent state
Time::Time(){
    hour = minute =second = 0;
 } // end time default constructor

 // set new time value using universal time; ensure that
 // the data remains consistent by setting invalid values to zero
 void Time::setTime(int h, int m, int s){
     hour = (h >= 0 && h < 24) ? h : 0; // validate hour
     minute = (m >= 0 && m < 60) ? m : 0; // validate minute
     second = (s >= 0 && s < 60) ? s : 0; // validate second 
     // ternary operations
 } // end function setTime

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal(){
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":" << setw(2) << second;
} // end function printUniversal

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard(){
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << setfill('0') << setw(2) << minute << ":" << setw(2)
        << second << (hour < 12 ? " AM" : " PM");
} // end function printStandard
