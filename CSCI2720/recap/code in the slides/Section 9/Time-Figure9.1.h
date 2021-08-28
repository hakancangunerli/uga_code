// Figure 9.1: Time.h

// Time class definition 

#include <string>
#ifndef TIME_H
#define TIME_H

// Time class definition
class Time
{
public:
 void setTime( int, int, int ); // set hour, minute, second
 std::string toUniversalString() const; // 24 hr time 
 std::string toStandardString() const; // 12hr time 
private:
unsigned int hour{0}; // 0,23 (24-hour clock)
unsigned int minute{0}; // 0,59
unsigned int second{0}; // 0,59 
};
 
#endif 