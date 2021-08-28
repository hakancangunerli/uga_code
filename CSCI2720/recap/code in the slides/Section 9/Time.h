// Fig 9.1 Time.h
// Declaration of class Time
// Member functions defined in Time.cpp

// prevent multiple inclusions of the header file
#ifndef TIME_H
#define TIME_H 

// Time class definition
class Time{
public:
    Time();
    void setTime(int, int, int); // set hour, minute, second
    void printUniversal(); // print universal-time
    void printStandard(); // print standard-time 
private:
    int hour;
    int minute;
    int second;
};
#endif 