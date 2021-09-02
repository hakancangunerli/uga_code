#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student {

 private:
  // declare all the member variables that pertain to a Student class
  // the identification variables
  string fullName;
  string username;
  string password;

  // the grade member variables
  int projectGrade;
  int quizGrade;
  int midtermGrade;
  int finalGrade;

  
 public:

  //Constructors
  Student();
  // Copy Constructor
  Student(Student * student);
  // Constructor with every parameter
  Student(string name, string username, string password, int projectGrade, int quizGrade, int midtermGrade, int finalGrade, string studentFile);

  
  bool login(string username, string password, char **argv);
  string getStudentName();

  int getProjectGrade();
  int getQuizGrade();
  int getMidtermGrade();
  int getFinalGrade();
  double getOverallGrade();
  string getUsername();
  string getPassword();

  // assignment operator for greater functionality
  void operator=(Student s);
  //string printStats();
};

#endif
  
