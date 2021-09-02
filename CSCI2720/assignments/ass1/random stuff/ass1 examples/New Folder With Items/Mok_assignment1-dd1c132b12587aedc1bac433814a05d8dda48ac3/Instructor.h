#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

/*
Class that defines an instructor who can look up
any students grades given the name of the student
*/

class Instructor{
public:
  //Constructor for the Instructor class
  Instructor(int row);
  
  //Checks if the credidentials are valid for log in
  bool login(string username, string password,
             string fileNameInstructors);

  //Returns the name of the instructor
  string getInstructorName();

  //Returns a student
  Student* getStudent(string username, int size, string ** array);

  //Returns the student with the min grade of
  //a certain grade type
  Student* getMinStudent(int gradeType, int size, string ** array);

  //Returns the student with the max grade of
  //a certain grade type
  Student* getMaxStudent(int gradeType, int size, string ** array);

  //Returns the average grade of a certain grade tyoe
  double getAvg(int gradeType, int size, string ** array);

  //Sets the instructors name
  void setName(string firstName, string lastName);

  //Creates a data base of Students from the file input
  //void fillStudents(string fileName, int size);

    
  //Destructor for the instructor class
  ~Instructor();

private:
  //Full name of the instructor
  string fullName;

  //1D array holding all the students in the class
  //Student *students[20];

  //2D array holding all the information for the instructors
  string** instructors;
};
#endif
