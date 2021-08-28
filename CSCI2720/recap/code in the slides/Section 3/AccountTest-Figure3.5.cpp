// Figure 3.5 AccountTest.cpp 
// Using the Account constructor to initialize the name data 
// member at the time each Account object is created.
#include <iostream>
#include "Account-Figure3.4.h""

using namespace std;

int main(){
    Account account1{"Jane Green"};
    Account account2{"John Blue"};
cout << "account1: " << account1.getName() << endl;
cout << "account2: " << account2.getName() << endl;

}