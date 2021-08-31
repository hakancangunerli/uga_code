#include <string>

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "Student.h"
using namespace std;

class Instructor
{
public:
    bool login(string username, string password);
    string getInstructorName();
    Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    Student getAvg(int gradeType);
};


#endif // INSTRUCTOR_H