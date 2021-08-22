// this is the declaration of the header file Time.h 
/* 

this is to prevent multiple inclusions of the same header file 
#ifndef TIME_H
#define TIME_H

class Time{
    public: 
    Time();
    void setTime(int h, int m, int s);
    void printUniversal();
    void printStandard();
    private:
    int hour;
    int minute;
    int second;
};

}
#endif


*/
// time class definition is made here. , the source-code (.cpp) is where the member functions are defined. this way we can reuse the class as necessary.


// Time.cpp 
/* 
#include <iostream> 
#include "Time.h"
using namespace std;

Time::Time(){
    hour = minute = second = 0;
} // this is the time constructor


void Time::setTime(int h, int m, int s){
    hour = (h >=0 && h < 24) ? h : 0;
    minute = (m >=0 && m < 60) ? m : 0;
    second = (s >=0 && s < 60) ? s : 0;
} // this is the setTime function

void Time::printUniversal(){
   cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second;
} // this is the printUniversal function


void Time::printStandard(){
    cout << (( hour == 0 || hour == 12) ? 12: (hour % 12)) << ":" << setfill('0') << setw(2) << minute << ":" << setw(2) << second << ((hour < 12) ? " AM":" PM");
} // printStandard 

*/ 


// finally this is the driver/tester code

/* 
#include <iostream>
#include "Time.h" 
using namespace std;

int main(){
    Time t; 
    cout << "Enter the time in universal format: ";
     t.printUniversal();
     cout << "the initial standard time is";
     t.printStandard();

     t.setTime(13,27,6);


 check page 19 for the rest of the code, not really matters anyway. 




}

 ~ -> is a destructor, opposite to a constructor. 
*/ 
