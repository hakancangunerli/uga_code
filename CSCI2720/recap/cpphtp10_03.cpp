#include <iostream> 
using namespace std;

// It’s customary to place a reusable class definition in a file known as a header with a.h filename extension. these ones should have a "", not <> like iostream. #include "Account.h" for example. 
// the class name string belongs to std, like cout. 
// if you're going to get a multiline input, you can't use cin, you gotta use getline() 
/* 
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
*/ 

// class definition needs a ; at the end. 


//  A constructor in C++ is a special method that is automatically called when an object of a class is created.

 
// example from w3schools,


#include <iostream>
using namespace std;

class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z); // Constructor declaration
};

// Constructor definition outside the class
Car::Car(string x, string y, int z) {
  brand = x;
  model = y;
  year = z;
}

int main() {
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  // Print values
  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  return 0;
}

 