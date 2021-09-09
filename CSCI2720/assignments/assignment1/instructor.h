#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Instructor
{
private:
  string fullName;
  string username;
  string password;

public:
  Instructor();
  // username, password, firstName, lastName
  Instructor(string, string, string, string);
  bool login(string username, string password);
  string getInstructorName();
  Student getStudent(string username);
  Student getMinStudent(int gradeType);
  Student getMaxStudent(int gradeType);
  double getAvg(int gradeType);
  void setInstructorName(string);
};
#endif