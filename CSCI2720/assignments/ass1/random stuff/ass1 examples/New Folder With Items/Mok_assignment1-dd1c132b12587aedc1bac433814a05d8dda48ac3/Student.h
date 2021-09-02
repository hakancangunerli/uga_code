#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

/*
Class that defines a student who has the ability 
to view their own grades
*/

class Student{
public:
  //Default Constructor for the Student Class
  Student();
  
  //Constructor for the Student class
  Student(int row);
  
  //Checks if the login credidentials are valid
  bool login(string username, string password, string fileName, int row);

  //Returns the name of the student
  string getStudentName();

  //Returns the username of the sttudent
  string getUsername();
  
  //Returns the student's project grades
  int getProjectGrade();

  //Returns the student's quiz grade
  int getQuizGrade();

  //Returns the student's midterm grade
  int getMidtermGrade();

  //Returns the students final grade
  int getFinalGrade();

  //Returns the students overall grade
  double getOverallGrade();

  //Setter methods that set the values of the instance variables
  void setStudentName(string firstName, string lastName);
  void setProjectGrade(int grade);
  void setQuizGrade(int grade);
  void setMidtermGrade(int grade);
  void setFinalGrade(int grade);
  void setUsername(string name);
  
  //Prints the grades of the student to standard output
  void printGrades();
  
  //Destructor for the student class
  ~Student();
private:
  //Name of the student
  string fullName;

  //Username of the student
  string username;

  //Project grade
  int projectGrade;

  //Quiz Grade
  int quizGrade;

  //Midterm grade
  int midtermGrade;

  //final grade
  int finalGrade;
 
  //2D array that holds all student information
  string** students;
};
#endif
