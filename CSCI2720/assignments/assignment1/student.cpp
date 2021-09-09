#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// 20 students

// Student default constructor
Student::Student()
{
  this->fullName = "";
  this->username = "";
  this->password = ""; // these are string
  this->projectGrade =0;
   this->quizGrade = 0;
   this->midtermGrade = 0;
   this->finalGrade = 0; // these are int 
}

// Student constructor
Student::Student(string username, string password, string firstName, string lastName, int projectGrade, int quizGrade, int midtermGrade, int finalGrade)
{

  this->username = username;
  this->password = password;
  this->fullName = firstName + " " +lastName;
  this->projectGrade = projectGrade;
  this->quizGrade = quizGrade;
  this->midtermGrade = midtermGrade;
  this->finalGrade = finalGrade;
}

// Returns a project grade
int Student::getProjectGrade()
{
  return projectGrade;
}

// Returns true if the username passed as parameter matches the username of the Student calling object
bool Student::match(string username)
{ // match check if the username provided is the same with what the student's username is.
  return this->username == username;
}

// Returns a quiz grade
int Student::getQuizGrade()
{
  return quizGrade;
}

// Returns a midterm exam grade
int Student::getMidtermGrade()
{
  return midtermGrade;
}

// Returns a final exam grade
int Student::getFinalGrade()
{
  return finalGrade;
}

// Returns a student's full name
string Student::getStudentName(){
  return this->fullName; 
}

// Initializes a value to student's full name
void Student::setStudentName(string fullName)
{
  this->fullName = fullName;
}

// Initializes a value to student's project grade
void Student::setProjectGrade(int grade)
{
  this->projectGrade = grade;
}

// Initializes a value to student's quiz grade
void Student::setQuizGrade(int grade)
{
  this->quizGrade = grade;
}
// Initializes a value to student's midterm exam grade
void Student::setMidtermGrade(int grade)
{
  this->midtermGrade = grade;
}
// Initializes a value to student's final exam grade
void Student::setFinalGrade(int grade)
{
  this->finalGrade = grade;
}

/* Returns true if the username and password passed as parameters match
 the username and password of the Student calling object
 */
bool Student::login(string username, string password){
  return this->username ==username && this->password == password; 
}

// Returns a student's overall grade
double Student::getOverallGrade(){
  return (projectGrade + quizGrade + midtermGrade + finalGrade)/4;

}