// programming, i/o and operators. 

#include <iostream> // preprocessor directive, they don't end with a semicolon


// int main()
// {
//     std::cout << "Hello, world!\n" ; 
//     // << is called the stream insertion operator.     
// return 0 ; 
// }


// int main(){
//     // this initialization is called list initialization, introducted in C++11. 

//     int number1{0};
//     int number2{0};
//     int sum{0}; 


//     // int number1 = 0; 
//     // int number2 = 0;
//     // int sum =0 ; 
//     std::cout << "Enter a number: ";
//     std::cin >> number1; // cin is the read operator. >> is called a stream extraction operator.
//     std::cout << "Enter another number: ";
//     std::cin >> number2;
//     sum = number1 + number2;
//     std::cout << "The sum of " << number1 << " and " << number2 << " is " << sum << std::endl; 
//     // endl is the end of line operator, reserved keyword. 
     
// }


// what you can also do, to output and input, is to declare them using the keyword "using"

using std::cout; 
using std::cin;
using std::endl;
 
int main(){
int number1{0};
int number2{0};

cout << "Enter a number: ";
cin >> number1 >> number2; 

cout << number1 << " " << number2 << endl; 

    }