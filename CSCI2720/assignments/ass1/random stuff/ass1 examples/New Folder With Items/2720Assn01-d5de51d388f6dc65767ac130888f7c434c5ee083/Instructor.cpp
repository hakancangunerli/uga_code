#include "Instructor.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

//Sets up default constructor for Instructor
Instructor::Instructor() {
  username = "";
  password = "";
  fullName = "";
} //constructor

//Sets up fully initialized Instructor constructor
Instructor::Instructor(std::string username, std::string password, std::string fullName) {
  this->username = username;
  this->password = password;
  this->fullName = fullName;
} //constructor

//Sets up Instructor copy constructor
Instructor::Instructor(Instructor * instructor) {
  this->username = instructor->username;
  this->password = instructor->password;
  this->fullName = instructor->fullName;
} //constructor

//Login functionality
bool Instructor::login(std::string username, std::string password, char **argv) {
  //Defines file as first command line arg
  ifstream instructorFile(argv[1]);
  string fileReader;

  //initially sets login capabilities to false
  bool succesfulLogin{false};

  string s;

  //parses through instructor file for username, password, full name
  while (getline(instructorFile, fileReader)) {
    istringstream tempString{fileReader};
    //parses through each line of file
    while (getline(tempString, s, '\t')) {
      //checks for proper username
      if (s.compare(username) == 0) {
        getline(tempString, s, '\t');
        //given proper username, checks for proper password
        if (s.compare(password) == 0) {
          succesfulLogin = true;
        } //if
      } //if
    } //while
  } //while
  return succesfulLogin;
} //login

//simple getter method for full name
string Instructor::getInstructorName() {
  return this->fullName;
} //getInstructorName

//simple getter method for username
string Instructor::getUsername() {
  return this->username;
} //getUserName

//simple getter method for password
string Instructor::getPassword() {
  return this->password;
} //getPassword

//returns all student info
bool Instructor::getStudent(std::string username, Student students[], int numStudents) {
  //iterates through all students
  for (int i = 0; i < numStudents; i++) {
    //checks for proper student based on username
    if (students[i].getUsername() == username) {
      //prints student information
      std::cout << endl;
      std::cout << "Student name: " << students[i].getStudentName() << std::endl;
      std::cout << "\t Project " << students[i].getProjectGrade() << "%" << std::endl;
      std::cout << "\t Quiz " << students[i].getQuizGrade() << "%" << std::endl;
      std::cout << "\t Midterm " << students[i].getMidtermGrade() << "%" << std::endl;
      std::cout << "\t Final " << students[i].getFinalGrade() << "%" << std::endl;
      std::cout << "\t Overall " << students[i].getOverallGrade() << "%" << std::endl;
      return true;
    } //if
  } //for
  //handles exceptions
  std::cout << "Student username is not valid" << std::endl;
  return false;
} //getStudent

//Returns min grade in a set and its reciever
string Instructor::getMinStudent(int gradeType, Student students[], int numStudents) {
  //var declaration, initialization
  double min {100};
  Student minStudent{students[0]};

  //checks for gradetype
  if (gradeType == 1) {
    //iterates through all students
    for (int i = 0; i < numStudents; i++) {
      //checks for min grade
      if (students[i].getProjectGrade() < min) {
        //identifies min student and min grade
        minStudent = students[i];
        min = minStudent.getProjectGrade();
      } //if
    } //for
    //gradetype checking
  } else if (gradeType == 2) {
    //iterates through all elements
    for (int i = 0; i < numStudents; i++) {
      //checks for min grade
      if (students[i].getQuizGrade() < min) {
        //identifies min student and min grade
        minStudent = students[i];
        min = minStudent.getQuizGrade();
      } //if
    } //for
  //checks for gradetype
  } else if (gradeType == 3) {
    //iterates through all students
    for (int i = 0; i < numStudents; i++) {
      //checks for min grade
      if (students[i].getMidtermGrade() < min) {
        //identifies min student and min grade
        minStudent = students[i];
        min = minStudent.getMidtermGrade();
      } //if
    } //for
  // gradetype checking
  } else if (gradeType == 4) {
    //iterates through all elements
    for (int i = 0; i < numStudents; i++) {
      //checks for min grade
      if (students[i].getFinalGrade() < min) {
        //identifies min student and min grade
        minStudent = students[i];
        min = minStudent.getFinalGrade();
      } //if
    } //for
  //checks for gradetype
  } else if (gradeType == 5) {
    //iterates through all elements
    for (int i = 0; i < numStudents; i++) {
      //checks for min grade
      if (students[i].getOverallGrade() < min) {
        //identifies min student and min grade
        minStudent = students[i];
        min = minStudent.getOverallGrade();
      } //if
    } //for
  } //if

  //prints proper output
  std::cout << "\t min \t" << min << "% (" << minStudent.getStudentName() << ")" << endl;
  //arbitrary return
  return "";
} //getMinStudent

//checks for max grade for a gradetype and its recipient
string Instructor::getMaxStudent(int gradeType, Student students[], int numStudents) {
  //var declaration, initialization
  double max {0};
  Student maxStudent{students[0]};

  //checks gradetype
  if (gradeType == 1) {
    //iterates through all elements
    for (int i = 0; i < numStudents; i++) {
      //checks for max
      if (students[i].getProjectGrade() > max) {
        //identifies max student and grade
        maxStudent = students[i];
        max = maxStudent.getProjectGrade();
      } //if
    } //for
  //checks gradetype
  } else if (gradeType == 2) {
    //iterates through all elements
    for (int i = 0; i < numStudents; i++) {
      //checks for max grade
      if (students[i].getQuizGrade() > max) {
        //identifies max grade and student
        maxStudent = students[i];
        max = maxStudent.getQuizGrade();
      } //if
    } //for
  } else if (gradeType == 3) {
    //iterates through all elements
    for (int i = 0; i < numStudents; i++) {
      //checks for max grade
      if (students[i].getMidtermGrade() > max) {
        //identifies max grade and student
        maxStudent = students[i];
        max = maxStudent.getMidtermGrade();
      } //if
    } //for
  } else if (gradeType == 4) {
    //iterates through elements
    for (int i = 0; i < numStudents; i++) {
      //checks for max grade
      if (students[i].getFinalGrade() > max) {
        //identifies max grade and student
        maxStudent = students[i];
        max = maxStudent.getFinalGrade();
      } //if
    } //for
  //gradetype checking
  } else if (gradeType == 5) {
    //iterates through all elements
    for (int i = 0; i < numStudents; i++) {
      //checks for max grade
      if (students[i].getOverallGrade() > max) {
        //identifies max grade and student
        maxStudent = students[i];
        max = maxStudent.getOverallGrade();
      } //if
    } //for
  } //if
  //outputs properly formatted information
  std::cout << "\t max \t" << max << "% (" << maxStudent.getStudentName() << ")" << endl;
  //arbitrary return output
  return "";
} //getMaxStudent

//returns the average grade of a particular gradetype
string Instructor::getAvg(int gradeType, Student students[], int numStudents) {
  //variable declaration, initialization
  double avg{0};
  double sum{0};

  //gradetype checking
  if (gradeType == 1) {
    //summing vars
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getProjectGrade();
    } //for
    //divides by number of students
    avg = sum / numStudents;
  //gradetype checking
  } else if (gradeType == 2) {
    //sums over all grades
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getQuizGrade();
    } //for
    //divides by number of students
    avg = sum / numStudents;
  //gradetype checking
  } else if (gradeType == 3) {
    //sums over all grades
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getMidtermGrade();
    } //for
      //divides by number of students
      avg = sum / numStudents;
  //gradetype checking
  } else if (gradeType == 4) {
    //sums over all grades
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getFinalGrade();
    } //for
    //divides by number of students
    avg = sum / numStudents;
  //gradetype checking
  } else if (gradeType == 5) {
    //sums over all grades
    for (int i = 0; i < numStudents; i++) {
      sum += students[i].getOverallGrade();
    } //for
    //divides by number of students
    avg = sum / numStudents;
  } //if

  //prints out correctly formatted output
  std::cout << "\t avg \t" << avg << "%" << endl;
  //returns arbitrary output
  return "";
} //getAvg

void Instructor::operator=(Instructor i) {
  this->fullName = i.getInstructorName();
  this->username = i.getUsername();
  this->password = i.getPassword();
} //copy
