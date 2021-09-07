#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include "Student.h"
//header file including all prototypes for methods for Instructor
using namespace std;

class Instructor {
    string fullName;
    string username;
    string password;
public:
    Instructor();
    Instructor(string fname, string lname, string user, string pass);
    bool login(string username, string password);
    string getInstructorName();
    Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    double getAvg(int gradeType);
    void setInstructorName(string fullName);
};
#endif
