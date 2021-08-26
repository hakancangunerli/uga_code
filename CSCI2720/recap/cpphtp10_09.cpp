// you only need to know what's on the slides. 

// this is the declaration of the header file Time.h 
/* 

this is to prevent multiple inclusions of the same header file 
main shouldn't see the implementation, only the prototype . 
#ifndef TIME_H -> if not defined, use the definition.
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

Time::Time(){ -> constructor that belongs to the class Time. all methods will have a prefix similar to it.
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

/* 
for( i =0; i < 10; i++);
cout << i; 

this will run 10 times.

*/

// passed by reference, objects are usually much larger in size than primitive types. you won't be making a copy of the reference. but that means the method can change the value of the reference, and to prevent that you make it a const.  9.2.13 

// only the data members contribute to the size of the object. depends only on the data members. 

/*
class Student{
    int method1(int,char);
    void method2(char);
    void method3(float);
private:
int x; 
char c; 
}

main{
    Student s1;
}
*/ 
// this will be 5 bytes coming from private members. 

/* 
if you don't wanna do a makefile
gcc -c Time.cpp 
gcc -c main.cpp 
gcc -o main.o Time.o 
*/ 


// explicit can be used once again but if you were to give it default values. 
// ~ -> destructor to release memory. all assignments will include a destructor. check 9.7, figure 9.8

// you cannot call a nonconstant method in your constant method. check figure 9.17 he won't ask it but it's good to remember the concept. 
// class concept, use the Time.h class as an example. 9.1 and 9.2 (template)

// command-line argument 

// figure 17.7 filei/o  this is the easiest way to do it. 

