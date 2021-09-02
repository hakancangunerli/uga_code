#include "Student.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Student::Student() {
  // Set default values
  fullName = "";
  username = "";
  password = "";
  // Set defualt grade values
  projectGrade = 0;
  quizGrade = 0;
  midtermGrade = 0;
  finalGrade = 0.0;

} // Student

Student::Student(Student * student) {
  // copy string values over
  this->fullName = student->fullName;
  this->username = student->username;
  this->password = student->password;
  // Copy grade values over
  this->projectGrade = student->projectGrade;
  this->quizGrade = student->quizGrade;
  this->midtermGrade = student->midtermGrade;
  this->finalGrade = student->finalGrade;
} // Student

Student::Student(string name, string username, string password, int projectGrade, int quizGrade, int midtermGrade, int finalGrade, string studentFile) {
  // Copy all respective values over
  fullName = name;
  this->username = username;
  this->password = password;
  
  this->projectGrade = projectGrade;
  this->quizGrade = quizGrade;
  this->midtermGrade = midtermGrade;
  this->finalGrade = finalGrade;

} // Student

bool Student::login(string username, string password, char **argv) {
  // OPen file based on proper space in command line arguments
  ifstream studentFile(argv[2]);
  string fileReader;
  // defualt succes rate to false
  bool succesfulLogin{false};
  //Dummy variables to help check for equality
  string s;
  string studentusername;
  string studentpassword;
  
  while (getline(studentFile, fileReader)) { // Read each line
    istringstream tempString{fileReader}; // Create string stream of each line
    while (getline(tempString, s, '\t')) { // Iterate through each string stream
      if (s.compare(username) == 0) { // if the username position is equal
	studentusername = s;
        getline(tempString, s, '\t'); // go to next item in the line
        if (s.compare(password) == 0) { // is password is equal to input
          succesfulLogin = true; // set succesful login to true
	  studentpassword = s;
        } //if
      } //if
    } //while
  } //while
  return succesfulLogin;
} // login

string Student::getStudentName() {
  return this->fullName;
} // getStudentName

int Student::getProjectGrade() {
  return this->projectGrade;
} // getProjectGrade

int Student::getQuizGrade() {
  return this->quizGrade;
} // getQuizGrade

int Student::getMidtermGrade() {
  return this->midtermGrade;
} // getMidtermGrade

int Student::getFinalGrade() {
  return this->finalGrade;
} //getFinalGrade

double Student::getOverallGrade() {
  return ((0.3 * getProjectGrade()) + (0.1 * getQuizGrade()) + (0.2 * getMidtermGrade()) + (0.4 * getFinalGrade()));
} // getOverallGrade

string Student::getUsername() {
  return this->username;
} // getUsername

string Student::getPassword() {
  return this->password;
} // getPassword

void Student::operator=(Student s) {
  // Set all values to the same as student S just like copy constructor
  this->fullName = s.getStudentName();
  this->username = s.getUsername();
  this->password = s.getPassword();
  
  this->projectGrade = s.getProjectGrade();
  this->quizGrade = s.getQuizGrade();
  this->midtermGrade = s.getMidtermGrade();
  this->finalGrade = s.getFinalGrade();
} // operator=

