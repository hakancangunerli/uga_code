#include <string.h>
#include "Student.h"
#include "Instructor.h"

using namespace std;

bool Instructor::login(string name, string pass) {
    if ((username.compare(name)==0)&&(password.compare(pass))) {
        return true;
    } //if username and password are correct
    else {
        return false;
    }
} //returns true if login is successful

void Instructor::setInstructorName(string name) {
    fullName=name;
} //sets instructor name

void Instructor::setInstructorUsername(string name) {
    username=name;
} //sets instructor username

void Instructor::setInstructorPassword(string pass) {
    password=pass;
} //sets instructor password

string Instructor::getInstructorName() {
    return fullName;
} //returns instructor name

string Instructor::getInsUsername() {
    return username;
} //returns username

string Instructor::getInsPassword() {
    return password;
} //returns password


Student Instructor::getStudent(string username) {
//not yet implemented
} //returns student according the username

Student Instructor::getMinStudent(int gradeType) {
//not yet implemented
} //returns the student with the minimum score

Student Instructor::getMaxStudent(int gradeType) {
//not yet implemented
} //returns the student with the maximum score

double getAvg(int gradeType) {
//not yet implemented
} //returns the average grade 
