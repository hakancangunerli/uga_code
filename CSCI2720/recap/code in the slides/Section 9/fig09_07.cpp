#include <iostream> 
#include <stdexcept>
#include "Time-Figure9.5.h"
using namespace std; 
void displayTime(const string& message, const Time& time){
    cout << message << ": " << time.toUniversalString() << ":" << "Standard Time: " << time.toStandardString(); 
}
int main(){
    Time t1; 
    Time t2{2};
    Time t3{21, 34};
    Time t4{12,25,42};

    cout << "Constructed with";
    displayTime("t1", t1);
    displayTime("t2", t2);
    displayTime("t3", t3);
    displayTime("t4", t4);
    
    try{ 
        Time t5{25, 74, 99};
    }
    catch (invalid_argument& e) { 
        cerr << "exception while initializing t5" << e.what() << endl;
    }
    }
