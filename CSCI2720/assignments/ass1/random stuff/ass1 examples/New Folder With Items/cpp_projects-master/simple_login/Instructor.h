#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "Student.h"
#include <string.h>

using namespace std;

class Instructor {

    
public:

    bool login(string username,string password);
    string getInstructorName();
    Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    double getAvg(int gradeType);

    void setInstructorName(string fullName);
    void setInstructorUsername(string username);
    void setInstructorPassword(string password);

    string getInsUsername();
    string getInsPassword();

private:

    string fullName;

    string username;
    string password;

};

#endif
