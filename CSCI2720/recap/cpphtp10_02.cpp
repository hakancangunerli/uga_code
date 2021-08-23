// programming, i/o and operators. 

#include <iostream> // preprocessor directive, they don't end with a semicolon


// int main()
// {
//     std::cout << "Hello, world!\n" ;  // cout is an object from the standard library (iostream).
//   
// return 0 ; 
// }

// << is called the stream insertion operator.     
// in c there's no class concept, c++ has classes. 
// operator overloading 

// int main(){
//     this initialization is called list initialization, introducted in C++11. 

//     int number1{0};
//     int number2{0};
//     int sum{0}; 
// he's okay with both, doesn't matter. 


//     int number1 = 0; 
//      int number2 = 0;
//      int sum =0 ; 
//     std::cout << "Enter a number: ";
//     std::cin >> number1; // cin is the read operator. >> is called a stream extraction operator.
//     std::cout << "Enter another number: ";
//     std::cin >> number2;
//     sum = number1 + number2;
//     std::cout << "The sum of " << number1 << " and " << number2 << " is " << sum << std::endl; 
//      endl is the end of line operator, reserved keyword. 
// endl is similar to \n, but endl will flush the buffer.
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