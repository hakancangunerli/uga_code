#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Student::Student(){
  students = new string*[20];
  for(int i = 0; i < 20; i++){
    students[i] = new string [8];
  }

  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 8; j++){
      students[i][j] = "a";
    }
  }
}

Student::Student(int row){
  students = new string*[row];
  for(int i = 0; i < row; i++){
    students[i] = new string [8];
  }

  for(int i = 0; i < row; i++){
    for(int j = 0; j < 8; j++){
      students[i][j] = "a";
    }
  }
}

bool Student::login(string username, string password, string fileName, int row){
 ifstream studentFile(fileName);
  if(studentFile.is_open()){
    for(int i = 0; i < row; i++){
      for(int j = 0; j < 8; j++){
        studentFile >> students[i][j];
       }
    }
  }

  studentFile.close();
  for(int i = 0; i < row; i++){
    if(username.compare(students[i][0]) == 0
       && password.compare(students[i][1]) == 0){

      setStudentName(students[i][2],students[i][3]);
      setProjectGrade(stoi(students[i][4]));
      setQuizGrade(stoi(students[i][5]));
      setMidtermGrade(stoi(students[i][6]));
      setFinalGrade(stoi(students[i][7]));

      cout << "You are now logged in as student " << getStudentName() << endl;
      return true;
    }
  }
  cout << "Login as student failed." << endl;
  return false;
}

string Student::getStudentName(){
  return fullName;
}

int Student::getProjectGrade(){
  return projectGrade;
}

int Student::getQuizGrade(){
  return quizGrade;
}

int Student::getMidtermGrade(){
  return midtermGrade;
}

int Student::getFinalGrade(){
  return finalGrade;
}

double Student::getOverallGrade(){
  return (projectGrade*0.3) + (quizGrade*0.1) + (midtermGrade*0.2) + (finalGrade*0.4);
}

string Student::getUsername(){
  return username;
}

void Student::setStudentName(string firstName, string lastName){
  fullName = firstName + " " + lastName;
}

void Student::setProjectGrade(int grade){
  projectGrade = grade;
}

void Student::setQuizGrade(int grade){
  quizGrade = grade;
}

void Student::setMidtermGrade(int grade){
  midtermGrade = grade;
}

void Student::setFinalGrade(int grade){
  finalGrade = grade;
}

void Student::setUsername(string name){
  username = name;
}

void Student::printGrades(){
  cout << "Student name: " << getStudentName() << endl;
  cout << "     Project " << getProjectGrade() << "%" << endl;
  cout << "     Quiz    " << getQuizGrade() << "%" << endl;
  cout << "     Midterm " << getMidtermGrade() << "%" << endl;
  cout << "     Final   " << getFinalGrade() << "%" << endl;
  cout << "     Overall " << getOverallGrade() << "%" << endl;
  cout << endl;
}

Student::~Student(){
  for(unsigned int i = 0; i < 20; i++){
    delete[] students[i];
  }
  delete[] students;
  
}

