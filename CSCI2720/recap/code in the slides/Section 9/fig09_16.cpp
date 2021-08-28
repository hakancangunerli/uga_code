// fig09_16.cpp
#include <iostream>
#include "Date.h"
using namespace std;

int main(){
    Date date1{7,4,2004};
    Date date2;  // date2 defaults to 1/1/2000
cout << "date1: " << date1.toString() << "date2=" << date2.toString() << endl;

date2 = date1; 

cout << "After default memberwise assignment, date2 = " << date2.toString() << endl;
}
