#include <iostream>
#include "Instructor.h"
#include "Student.h"

using namespace std;
//implementation of all methods for Instructor class
Instructor::Instructor(){
    this->fullName = "";
    this->username = "";
    this->password = "";
}

Instructor::Instructor(string fname, string lname, string user, string pass){
    this->fullName = fname + " " + lname;
    this->username = user;
    this->password = pass;
}

bool Instructor::login(string username, string password){
    return (this->username == username && this->password == password);
}

string Instructor::getInstructorName(){
    return this->fullName;
}

Student Instructor::getStudent(string username){
    Student temp;
    return temp;
}

Student Instructor::getMinStudent(int gradeType){
    Student temp;
    return temp;
}

Student Instructor::getMaxStudent(int gradeType){
    Student temp;
    return temp;
}

double Instructor::getAvg(int gradeType){
    return 0;
}
