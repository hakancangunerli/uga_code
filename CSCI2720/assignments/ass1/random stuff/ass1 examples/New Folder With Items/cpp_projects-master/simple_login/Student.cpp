#include "Student.h"
#include <string.h>

using namespace std;

void Student::setStudentName(string name) {
    fullName=name;
} //sets student name

void Student::setProjectGrade(int grade) {
    projectGrade=grade;
} //sets student project grade

void Student::setQuizGrade(int grade) {
    quizGrade=grade;
} //sets student quiz grade

void Student::setMidtermGrade(int grade) {
    midtermGrade=grade;
} //sets student midterm grade

void Student::setFinalGrade(int grade) {
    finalGrade=grade;
} //sets student final grade

string Student::getStudentName() {
    return fullName;
} //returns student name

int Student::getProjectGrade() {
    return projectGrade;
} //returns student project grade

int Student::getQuizGrade() {
    return quizGrade;
} //returns student quiz grade

int Student::getMidtermGrade() {
    return midtermGrade;
} //returns student midterm grade

int Student::getFinalGrade() {
    return finalGrade;
} //returns student final grade

double Student::getOverallGrade() {
    return projectGrade*0.3+quizGrade*0.1+midtermGrade*0.2+finalGrade*0.4;
} //returns student overall grade

void Student::setUsername(string name) {
    username=name;
} //sets the student username

void Student::setPassword(string pass) {
    password=pass;
} //sets the student password

string Student::getUsername() {
    return username;
} //returns username

string Student::getPassword() {
    return password;
} //returns password

bool Student::login(string name, string pass) {
    if ((username.compare(name)==0)&&(password.compare(pass)==0)) {
        return true;
    } //if username and password are correct
    else {
        return false;
    }
} //returns true if login is successful

