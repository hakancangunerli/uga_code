#include <iostream>
#include <string>
#include "instructor.h"

using namespace std;

// Instructor default constructor
Instructor::Instructor()
{
    this->fullName = "";
    this->username = "";
    this->password = "";
}

// Instructor constructor
Instructor::Instructor(string firstName, string lastName, string username, string password)
{
    this->fullName = firstName + " " + lastName;
    this->username = username;
    this->password = password;
}

/* Returns true if the username and password passed as parameters match
the username and password of the Instructor calling object
*/
bool Instructor::login(string username, string password)
{
    return (this->username == username && this->password == password); 
}

// Returns a instructor's full name
string Instructor::getInstructorName()
{
    return this->fullName;
}

// Returns the student associated with the username passed as parameter
Student Instructor::getStudent(string username) // defined within student realm 
{
    Student student;
    return student;
}

/* Returns the student with the lowest grade in the grade category indicated 
by the grade type passed as parameter
*/
Student Instructor::getMinStudent(int gradeType) // defined within student realm 
{
    Student minStudent;
    return minStudent;
}

/* Returns the student with the highest grade in the grade category indicated 
by the grade type passed as parameter
*/
Student Instructor::getMaxStudent(int gradeType)  // defined within student realm 
{
    Student maxStudent;
    // if (gradeType == 1) {   
    //     //project

    // } else if (gradeType == 2) {
    //     //quiz

    // } else if (gradeType == 3) {
    //     //midterm

    // } else if (gradeType == 4) {
    //     //final

    // } else if (gradeType == 5) {
    //     //overall

    // }
    return maxStudent;
}

/* Returns the class average of all the grades in the grade category indicated 
by the grade type passed as parameter
*/
double Instructor::getAvg(int gradeType)
{
    return 0; // since this is calculated in main
}

