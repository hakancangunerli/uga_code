#include <iostream>
#include "Student.h"

using namespace std;
//implementation of methods for Student class

Student::Student(){
    this->fullName = "";
    this->username = "";
    this->password = "";
    this->projectGrade = 0;
    this->quizGrade = 0;
    this->midtermGrade = 0;
    this->finalGrade = 0;
}

Student::Student(string fname, string lname, string user, string pass, int proj, int quiz, int mid,
                 int fin){
    this->fullName = fname + " " + lname;
    this->username = user;
    this->password = pass;
    this->projectGrade = proj;
    this->quizGrade = quiz;
    this->midtermGrade = mid;
    this->finalGrade = fin;
}
bool Student::login(string username, string password){
    return (this->username == username && this->password == password);
}

void Student::setStudentName(string fullName){
    this->fullName = fullName;
}

string Student::getStudentName(){
    return this->fullName;
}

void Student::setProjectGrade(int grade){
    this->projectGrade = grade;
}

int Student::getProjectGrade(){
    return this->projectGrade;
}

void Student::setQuizGrade(int grade){
    this->quizGrade = grade;
}

int Student::getQuizGrade(){
    return this->quizGrade;
}

void Student::setMidtermGrade(int grade){
    this->midtermGrade = grade;
}

int Student::getMidtermGrade(){
    return this->midtermGrade;
}

void Student::setFinalGrade(int grade){
    this->finalGrade = grade;
}

int Student::getFinalGrade(){
    return this->finalGrade;
}

bool Student::sameUser(string username){
    return this->username == username;
}
