#include <iostream> 
#include "CreateAndDestroy.h"
using namespace std;

// constructor sets object's ID number and descriptive message 
CreateAndDestroy::CreateAndDestroy(int id, string messageString):
 objectID(id), message(messageString){
     cout << "Object " << objectID << " constructor runs." << message << endl;
 }

 // destructor 
CreateAndDestroy::~CreateAndDestroy(){
    cout << (objectID == 1 || objectID == 6 ? "\n" : "");
cout << "Object" << objectID << " destructor runs." << message << endl;
}


