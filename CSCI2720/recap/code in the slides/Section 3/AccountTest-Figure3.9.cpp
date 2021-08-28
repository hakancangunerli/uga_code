#include <iostream> 
#include "Account-Figure3.8.h"
using namespace std;

int main() {
    Account account1{"Jane Green", 50};
    Account account2{"John Blue", -7};

// display initial balance of each object

cout << "account1: " << account1.getName() << " balance: $" << account1.getBalance() << endl;
cout << "account2: " << account2.getName() << " balance: $" << account2.getBalance() << endl;


cout << "Enter deposit amount for account1: ";
int depositAmount;
cin >> depositAmount;
cout << "adding " << depositAmount << " to account1 balance\n";
account1.deposit(depositAmount);


cout << "account1:" << account1.getName() << " balance: $" << account1.getBalance() << endl;
cout << "account2:" << account2.getName() << " balance: $" << account2.getBalance() << endl;

cout << "Enter deposit amount for account2: ";
cin >> depositAmount;
cout << "adding " << depositAmount << " to account2 balance\n";
account2.deposit(depositAmount);

cout << "account1:" << account1.getName() << " balance: $" << account1.getBalance() << endl;
cout << "account2:" << account2.getName() << " balance: $" << account2.getBalance() << endl;
}