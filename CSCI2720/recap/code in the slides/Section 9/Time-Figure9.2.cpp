// Time-Figure9.2.cpp

#include <iomanip>
#include <stdexcept>
#include <sstream> 
#include <string>
#include "Time-Figure9.1.h"

using namespace std;

void Time::setTime(int h, int m, int s){
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)){
        hour = h;
        minute = m;
        second = s;
    }else{
        throw invalid_argument("Invalid Time");   
    }
}

// return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const{
    ostringstream output;
    output << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
    return output.str(); // returns formatted string 
} 

string Time::toStandardString() const{
    ostringstream output;
    output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setfill('0') << setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM");
    return output.str(); // returns formatted string
} 