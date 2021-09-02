#include<unistd.h>

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<sstream>

#include "Student.h"
#include "Instructor.h"

using namespace std;

int main(int argc, char **argv) {

  if (argc != 3) {
    cout << "Usage: main [instructors_file] [students_file]" << endl;
    return 1;
  }

  ifstream instructorFile(argv[1]);
  ifstream studentFile(argv[2]);
  string fileReader;
  int numInstructors{0};
  int numStudents{0};
  Student * students;

  while(getline(instructorFile, fileReader)) {
    numInstructors++;
  }
  while(getline(studentFile, fileReader)) {
    numStudents++;
  }

  //instructors = new Instructor [numInstructors];
  students = new Student [numStudents];
  studentFile.clear();
  studentFile.seekg(0);

  string studIdentifier[3];
  int studGrades[4];
  int i{0};
  int j{0};
  string s;


    cout << "User Types," << endl << "\t 1- Instructor" << endl << "\t 2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit: ";

    string input;
    string inputUsername;
    string inputPassword;
    bool incorrectInput = true;

    cin >> input;
    while (incorrectInput) {
      if (input == "1" || input == "2" || input == "3") {
        incorrectInput = false;
      } else {
        cout << "Invalid option. Please enter a valid option." << endl;
        cin >> input;
      }
    }

    cout << endl;

    cout << "Enter credentials to login, \n\t Enter Username: ";;
    cin >> inputUsername;
    cout << "\t Enter Password: ";
    cin >> inputPassword;

  while (getline(studentFile, fileReader)) {
    istringstream tempString{fileReader};
    i = 0;
    while (getline(tempString, s, '\t')) {
      if (i < 3) {
        studIdentifier[i] = s;
      } else {
        studGrades[i-3] = stoi(s, nullptr, 10);
      } //if
      i++;
    }

    Student temp{studIdentifier[2], studIdentifier[0], studIdentifier[1], studGrades[0], studGrades[1], studGrades[2], studGrades[3], argv[2]};
    students[j] = temp;
    j++;
  }
  


  if (input == "1") {
    Instructor temp{};
    cout << temp.login(inputUsername,inputPassword,argv);
  } else if (input == "2") {
    Student test{};
    if (test.login(inputUsername, inputPassword, argv)) {
      for (int i = 0; i < numStudents; i++) {
	if (students[i].getUsername() == inputUsername) {
	  cout << students[i].getUsername() << endl;
	  cout << students[i].getPassword() << endl;
	  cout << students[i].getStudentName() << endl;
	  cout << students[i].getProjectGrade() << endl;
	  cout << students[i].getQuizGrade() << endl;
	  cout << students[i].getMidtermGrade() << endl;
	  cout << students[i].getFinalGrade() << endl;
	  test = students[i];
	}
      }
      string gradeInput;
      cout << "You are now logged in as student " << test.getStudentName() << endl;
      cout << "Do you want to view grades (y/n)?";
      cin >> gradeInput;
      if(gradeInput == "y") {
	std::cout << "Student name: " << test.getStudentName() << std::endl;
	std::cout << "\t Project " <<test.getProjectGrade() << std::endl;
	std::cout << "\t Quiz " << test.getQuizGrade() << std::endl;
	std::cout << "\t Midterm " << test.getMidtermGrade() << std::endl;
	std::cout << "\t Final " << test.getFinalGrade() << std::endl;
	std::cout << "\t Overall " << test.getOverallGrade() << std::endl;
      } else {
	
      }
    } else {
      cout << "Login as student failed" << endl;
    }
  }
  
}

  void getCredentials() {

  } //getCredentials
