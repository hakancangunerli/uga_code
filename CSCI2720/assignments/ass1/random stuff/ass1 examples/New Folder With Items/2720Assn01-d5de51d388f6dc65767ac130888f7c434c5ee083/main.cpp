#include<unistd.h>

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<stdlib.h>

#include "Student.h"
#include "Instructor.h"

using namespace std;

int main(int argc, char **argv) {

  if (argc != 3) { // Check to see if the argument number is correct
    cout << "Usage: main [instructors_file] [students_file]" << endl; // throw error message
    return 1;
  } // if

  // open up file streams for both argument types
  ifstream instructorFile(argv[1]);
  if (!(instructorFile.is_open())){ // check if instructor file cannot be opened
    cout << "Error: cannot parse instructors information from file" << argv[1] << endl;
    return 1;
  } // if
  ifstream studentFile(argv[2]); 
  if (!(studentFile.is_open())) { // check if student file cannot be opened
    cout << "Error: cannot parse students information from file" << argv[2] << endl;
    return 1;
  } // if
  string fileReader;
  int numInstructors{0};
  int numStudents{0};
  // Create arrays for students and instructors
  Student * students;
  Instructor * instructors;

  // COunt number of instructors
  while(getline(instructorFile, fileReader)) {
    numInstructors++;
  } // while
  // Count number of students
  while(getline(studentFile, fileReader)) {
    numStudents++;
  } // while

  //instructors = new Instructor [numInstructors];
  //Clear student file and initialize student array
  students = new Student [numStudents];
  studentFile.clear();
  studentFile.seekg(0);

  // Clear instructor file and initialize instructor array
  instructors = new Instructor [numInstructors];
  instructorFile.clear();
  instructorFile.seekg(0);

  // establish constants because there are only 3/4 identifiers for each person
  string instIdentifier[3];
  string studIdentifier[3];
  int studGrades[4];
  int i{0};
  int j{0};
  string s;

  while (getline(studentFile, fileReader)) { // Read each line in studentfile
    istringstream tempString{fileReader}; // convert string to string stream
    i = 0;
    while (getline(tempString, s, '\t')) { // read each word split by tab in line
      if (i < 3) {
	studIdentifier[i] = s; // put first three identifiers in identifier array
      } else {
	studGrades[i-3] = stoi(s, nullptr, 10); // put next grades in grad array
      } //if
      i++; // increment
    } // while

    //Create student with info and add to array
    Student temp{studIdentifier[2], studIdentifier[0], studIdentifier[1], studGrades[0], studGrades[1], studGrades[2], studGrades[3], argv[2]};
    students[j] = temp;
    j++;
  } //while

  j=0;
  while (getline(instructorFile, fileReader)) { //Read each line in instructor file
    istringstream tempString{fileReader}; // convert string to string stream
    i = 0;
    while (getline(tempString, s, '\t')) { // reac each word split by tab in line
      instIdentifier[i] = s; // put identifiers into array
      i++;
    } //while
    // Create instructor objects and add to array
    Instructor temp{instIdentifier[0],instIdentifier[1],instIdentifier[2]};
    instructors[j] = temp;
    j++;
  } //while

  // Create while condition
  bool wantToQuit{true};
  while (wantToQuit) { // while the user does not want to quit
    cout << "User Types," << endl << "\t 1- Instructor" << endl << "\t 2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit: ";

    string input;
    string inputUsername;
    string inputPassword;
    bool incorrectInput = true;

    cin >> input;
    while (incorrectInput) { // Check for incorrect input
      if (input == "1" || input == "2") {
	incorrectInput = false; // if input is correct do not repeat the loop
      } else if (input == "3") { // if input is correct but 3
	delete [] students;
	delete [] instructors;
	exit(1); // exit
      } else { //if input is incorrect
	cout << "Invalid option. Please enter a valid option." << endl;
	cout << "User Types," << endl << "\t 1- Instructor" << endl << "\t 2 - Student" << endl;
	cout << "Select a login user type or enter 3 to exit: ";
	cin >> input; // print error message and reprint info
      } // if
    } // while

    cout << endl;
    // Ask for credentials
    cout << "Enter credentials to login, \n\t Enter Username: ";;
    cin >> inputUsername;
    cout << "\t Enter Password: ";
    cin >> inputPassword;

    
    if (input == "1") { // If instructor logs in
      for (int i = 0; i < numInstructors; i++) {
      } //for
      Instructor temp{}; //create temp instructor
      if(temp.login(inputUsername,inputPassword,argv)) { // if log in is succesful
	for (int i = 0; i < numInstructors; i++) {
	  if (inputUsername == instructors[i].getUsername()) { //find correct instructor
	    temp = instructors[i]; // copy that instructor to temp instructor
	  } //if
	} //for
	// Print success mesage and next question
	cout << "\n You are now logged in as instructor " << temp.getInstructorName() << endl;
	cout << "\n Query options, \n\t 1 - view grades of a student \n\t 2 - view stats" << endl;
	cout << "Enter option number: ";
	cin >> input;
	// Create while loop condition
	bool invalidInput{true};
	while (invalidInput) {
	  if (input == "1" || input == "2") { // if the input is valid
	    invalidInput = false;
	  } else { // if the input is not valid
	    cout << "Invalid option. Please enter a valid option." << endl;
	    cout << "\n Query options, \n\t 1 - view grades of a student \n\t 2 - view stats" << endl;
	    cout << "Enter option number: ";
	    cin >> input; //reprint query options and error message
	  } //if
	} //while
	// if instructor wants to see student grades
	if (input == "1") {
	  bool properUsername{true};
	  while (properUsername) { // while the username is incorrect
	    cout << "Enter student username to view grades: ";
	    string studentName;
	    cin >> studentName;
	    if (temp.getStudent(studentName,students,numStudents)) { // if the username is correct
	      properUsername = false; // break out of loop
	    } else { // if username is correct
	      continue; // keep going
	      //cout << "Student username is not valid" << endl;
	    } //if
	  } // while
	} else if (input == "2") { // if instructor wants to see min,max,avg
	  cout << endl; // Print all options
	  cout << "Grade types," << endl;
	  cout << "\t 1 - Project grade \n\t 2 - Quiz grade";
	  cout << "\n\t 3 - Midterm grade \n\t 4 - Final grade \n\t 5 - Overall grade" << endl;
	  cout << "Select a grade type to view stats: ";
	  cin >> input;

	  // Look for invalid input 
	  invalidInput = true;
	  while (invalidInput) {
	    if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5") {
	      invalidInput = false; // if input is valid break out of loop
	    } else { // if input is invalid
	      cout << "Invalid option. Please enter a valid option.";
	      cout << endl;
	      cout << "Grade types," << endl;
	      cout << "\t 1 - Project grade \n\t 2 - Quiz grade";
	      cout << "\n\t 3 - Midterm grade \n\t 4 - Final grade \n\t 5 - Overall grade" << endl;
	      cout << "Select a grade type to view stats: ";
	      cin >> input; // Throw error message and break out of loop
	    } // if
	  } //while
	  if (input == "1") { // if instructor asks for project grade
	    cout << endl;
	    cout << "Project grade stats," << endl;
	    cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents); // calculate min for projects
	    cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents); // calculate max for projects
	    cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents); // calculate avg for projects
	  } else if (input == "2") { // if instructor asks for quiz grade
	    cout << endl;
	    cout << "Quiz grade stats," << endl;
	    cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents); //calculate min for quizzes
	    cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents); // calculate max for quizzes
	    cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents); // calculate avg for quizzes
	  } else if (input == "3") { // if instructor wants to see midterm grade 
	    cout << endl;
	    cout << "Midterm grade stats," << endl;
	    cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents); // Calculate min for midterms
	    cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents); // calculate max for midterms
	    cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents); // Calculate avg for midterms
	  } else if (input == "4") { // If instructor wants to see final grades
	    cout << endl;
	    cout << "Final grade stats," << endl;
	    cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents); // Caluclate min for finals
	    cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents); // Calculate max for finals
	    cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents); // Calculate avg for finals
	  } else if (input == "5") { // If instructor wants to see overall grade stats
	    cout << endl;
	    cout << "Overall grade stats," << endl;
	    cout << temp.getMinStudent(stoi (input,nullptr,10),students,numStudents); // calculate min for overall
	    cout << temp.getMaxStudent(stoi (input,nullptr,10),students,numStudents); // Calculate max for overall
	    cout << temp.getAvg(stoi (input,nullptr,10),students,numStudents); // Calculate avg for overall
	  } // if
	} // while

      } else {
	cout << "Login as instructor failed." << endl;
	continue; // print failure message and reset loop
      } //if



    } else if (input == "2") { // if student logs in 
      Student test{}; // create temp student object
      if (test.login(inputUsername, inputPassword, argv)) { // if login is successful
	for (int i = 0; i < numStudents; i++) {
	  if (students[i].getUsername() == inputUsername) { // find correct student
	    test = students[i]; // copy correct student to test student
	  } // if
	} // for
	string gradeInput; // Ask for grade input
	cout << "You are now logged in as student " << test.getStudentName() << endl;
	cout << "Do you want to view grades (y/n)?";
	cin >> gradeInput;
	if(gradeInput == "y") { // if student wants grades print grades
	  std::cout << "Student name: " << test.getStudentName() << std::endl;
	  std::cout << "\t Project " <<test.getProjectGrade() << "%" << std::endl;
	  std::cout << "\t Quiz \t " << test.getQuizGrade() << "%" << std::endl;
	  std::cout << "\t Midterm " << test.getMidtermGrade() << "%" << std::endl;
	  std::cout << "\t Final \t " << test.getFinalGrade() << "%" << std::endl;
	  std::cout << "\t Overall " << test.getOverallGrade() << "%" <<std::endl;
	} else { // otherwise reset loop
	  continue;
	} // if
      } else { // if student login fails 
	cout << "Login as student failed" << endl;
	continue;
      } // if
    } //if
  } // while
} //main
