#include <string>
#include "Student.h"

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor {
 public:
  Instructor();
  Instructor(std::string username, std::string password, std::string fullName);
  Instructor(Instructor * instructor);

  bool login(std::string username, std::string password, char **argv);
  string getInstructorName();
  string getUsername();
  string getPassword();

  bool getStudent(std::string username, Student students[], int numStudents);
  string getMinStudent(int gradeType, Student students[], int numStudents);
  string getMaxStudent(int gradeType, Student students[], int numStudents);
  string getAvg(int gradeType, Student students[], int numStudents);

  void operator=(Instructor i);

private:
  std::string fullName;
  std::string username;
  std::string password;
}; //Instructor

#endif
