#include <iostream>
#include "CreateAndDestroy.h"
using namespace std; 

void create(); 

CreateAndDestroy first{1, "global before main"}; // global object

int main(){
    cout << "MAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy second{2, "local after main"}; // global object
    static CreateAndDestroy third{3, "local static in main"}; // global object
create(); 

 cout << "MAIN FUNCTION: EXECUTION RESUMES" << endl;
 CreateAndDestroy fourth{4, "local after create"}; // global object
 cout << "MAIN FUNCTION: EXECUTION ENDS" << endl;

}

void create(){
    cout << "CREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy fifth{5, "local in create"}; // global object
    static CreateAndDestroy sixth{6, "local static in create"}; // global object
    static CreateAndDestroy seventh{7, "local static in create"}; // global object
    cout << "CREATE FUNCTION: EXECUTION ENDS" << endl;
}

