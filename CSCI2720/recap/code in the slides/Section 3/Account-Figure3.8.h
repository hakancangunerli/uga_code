// Figure 3.8: Account-Figure3.8.h
// Account class with name and balance data members, and a constructor and deposit function that each perform validation


#include <string> 
class Account{
public:
    Account(std::string name, double initialBalance):
    name{AccountName}{
        if(initialBalance > 0){
            balance = initialBalance;
    }
}

// function that deposits (adds) only a valid amount to the balance
void deposit(double depositAmount){
    if(depositAmount > 0){ // if the deposit amount is valid
        balance = balance + depositAmount; // add it to the balance 
    }
}
// returns the balance 
int getBalance() const{
 return balance; 
}
// sets the name 
void setName(std::string accountName){
name = accountName;
}
// returns the name 
std::string getName() const{
return name; 
}

private: 
    std::string name;
    int balance{0} ;

};