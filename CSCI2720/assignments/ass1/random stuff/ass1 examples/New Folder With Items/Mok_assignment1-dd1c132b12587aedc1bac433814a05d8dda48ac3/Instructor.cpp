#include "Instructor.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Instructor::Instructor(int row){
  instructors = new string*[row];
  for(int i = 0; i < row; i++){
    instructors[i] = new string [4];
  }
}

bool Instructor::login(string username, string password,
                       string fileNameInstructor){
  
  ifstream instructorFile(fileNameInstructor);
  if(instructorFile.is_open()){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 4; j++){
        instructorFile >> instructors[i][j]; 
      }
    }
  }

  instructorFile.close();

  for(int i = 0; i < 3; i++){
    if(instructors[i][0].compare(username) == 0){
      if(instructors[i][1].compare(password) == 0){
        setName(instructors[i][2], instructors[i][3]);
        cout << "You are now logged in as instructor " << getInstructorName() << endl;
        return true;
      }
    }
  }
  cout << "Login as instructor failed." << endl;
  return false;
}

string Instructor::getInstructorName(){
  return fullName;
}

Student* Instructor::getStudent(string username, int size, string ** array){
  for(int i = 0; i < size; i++){
    if(array[i][0].compare(username) == 0){
      Student *stu1 = new Student();
      stu1->setStudentName(array[i][2],array[i][3]);
      stu1->setProjectGrade(stoi(array[i][4]));
      stu1->setQuizGrade(stoi(array[i][5]));
      stu1->setMidtermGrade(stoi(array[i][6]));
      stu1->setFinalGrade(stoi(array[i][7]));
      cout << "Student name: " << stu1->getStudentName() << endl;
      cout << "Project " << stu1->getProjectGrade() << "%" << endl;
      cout << "Quiz " << stu1->getQuizGrade() << "%" << endl;
      cout << "Midterm " << stu1->getMidtermGrade() << "%" << endl;
      cout << "Final " << stu1->getFinalGrade() << "%" << endl;
      cout << "Overall " << stu1->getOverallGrade() << "%" << endl;
      cout << endl;
      return stu1;
    }
  }
  cout << "Student username is not valid" << endl;
  return NULL;
}

Student* Instructor::getMinStudent(int gradeType, int size, string ** array){
  int minStudent = 0;
  Student* minStud = new Student(20);
  if(gradeType == 1){
    for(int i = 1; i < size; i++){
      if(stoi(array[minStudent][4]) > stoi(array[i][4])){
        minStudent = i;
      }
    }
    minStud -> setStudentName(array[minStudent][2], array[minStudent][3]);
    minStud -> setProjectGrade(stoi(array[minStudent][4]));
    cout << "Project Grade Stats, " << endl;
    cout << "        min     " << minStud -> getProjectGrade()
         << "%  (" << minStud -> getStudentName() << ")" << endl;
    return minStud;
  }
  else if(gradeType == 2){
    for(int i = 1; i < size; i++){
      if(stoi(array[minStudent][5]) > stoi(array[i][5])){
        minStudent = i;
      }
    }
    minStud -> setStudentName(array[minStudent][2], array[minStudent][3]);
    minStud -> setQuizGrade(stoi(array[minStudent][5]));
    cout << "Quiz Grade Stats, " << endl;
    cout << "        min     " << minStud -> getQuizGrade()
         << "%  (" << minStud -> getStudentName() << ")" << endl;
    return minStud;
  }
  else if(gradeType == 3){
    for(int i = 1; i < size; i++){
      if(stoi(array[minStudent][6]) > stoi(array[i][6])){
        minStudent = i;
      }
    }
    minStud -> setStudentName(array[minStudent][2], array[minStudent][3]);
    minStud -> setMidtermGrade(stoi(array[minStudent][6]));
    cout << "Midterm Grade Stats, " << endl;
    cout << "        min     " << minStud -> getMidtermGrade()
         << "%  (" << minStud -> getStudentName() << ")" << endl;
    return minStud;
  }
  else if(gradeType == 4){
    for(int i = 1; i < size; i++){
      if(stoi(array[minStudent][7]) > stoi(array[i][7])){
        minStudent = i;
      }
    }
    minStud -> setStudentName(array[minStudent][2], array[minStudent][3]);
    minStud -> setFinalGrade(stoi(array[minStudent][7]));
    cout << "Final Grade Stats, " << endl;
    cout << "        min     " << minStud -> getFinalGrade()
         << "%  (" << minStud -> getStudentName() << ")" << endl;
    return minStud;
  }
  else if(gradeType == 5){
    for(int i = 1; i < size; i++){
      if(((stoi(array[minStudent][4])*0.3) + (stoi(array[minStudent][5])*0.1) +
          (stoi(array[minStudent][6])*0.2) + (stoi(array[minStudent][7])*0.4))
         >((stoi(array[i][4])*0.3) + (stoi(array[i][5])*0.1) +
           (stoi(array[i][6])*0.2) + (stoi(array[i][7])*0.4))){
        minStudent = i;
      }
    }
    minStud -> setStudentName(array[minStudent][2], array[minStudent][3]);
    cout << "Overall Grade Stats, " << endl;
    cout << "        min     " << (stoi(array[minStudent][4])*0.3) + (stoi(array[minStudent][5])*0.1)
      + (stoi(array[minStudent][6])*0.2) + (stoi(array[minStudent][7])*0.4)
         << "%  (" << minStud -> getStudentName() << ")" << endl;
    return minStud;
  }
  return NULL;
}

Student* Instructor::getMaxStudent(int gradeType, int size, string ** array){
  int maxStudent = 0;
  Student* maxStud = new Student(20);
  if(gradeType == 1){
    for(int i = 1; i < size; i++){
      if(stoi(array[maxStudent][4]) < stoi(array[i][4])){
        maxStudent = i;
      }
    }
    maxStud -> setStudentName(array[maxStudent][2], array[maxStudent][3]);
    maxStud -> setProjectGrade(stoi(array[maxStudent][4]));
    cout << "        max     " << maxStud -> getProjectGrade()
         << "%  (" << maxStud -> getStudentName() << ")" << endl;
    return maxStud;
  }
  else if(gradeType == 2){
    for(int i = 1; i < size; i++){
      if(stoi(array[maxStudent][5]) < stoi(array[i][5])){
        maxStudent = i;
      }
    }
    maxStud -> setStudentName(array[maxStudent][2], array[maxStudent][3]);
    maxStud -> setQuizGrade(stoi(array[maxStudent][5]));
    cout << "        max     " << maxStud -> getQuizGrade()
         << "%  (" << maxStud -> getStudentName() << ")" << endl;
    return maxStud;
  }
  else if(gradeType == 3){
    for(int i = 1; i < size; i++){
      if(stoi(array[maxStudent][6]) < stoi(array[i][6])){
        maxStudent = i;
      }
    }
    maxStud -> setStudentName(array[maxStudent][2], array[maxStudent][3]);
    maxStud -> setMidtermGrade(stoi(array[maxStudent][6]));
    cout << "        max     " << maxStud -> getMidtermGrade()
         << "%  (" << maxStud -> getStudentName() << ")" << endl;
    return maxStud;
  }
  else if(gradeType == 4){
    for(int i = 1; i < size; i++){
      if(stoi(array[maxStudent][7]) < stoi(array[i][7])){
        maxStudent = i;
      }
    }
    maxStud -> setStudentName(array[maxStudent][2], array[maxStudent][3]);
    maxStud -> setFinalGrade(stoi(array[maxStudent][7]));
    cout << "        max     " << maxStud -> getFinalGrade()
         << "%  (" << maxStud -> getStudentName() << ")" << endl;
    return maxStud;
  }
  else if(gradeType == 5){
    for(int i = 1; i < size; i++){
      if(((stoi(array[maxStudent][4])*0.3) + (stoi(array[maxStudent][5])*0.1) +
          (stoi(array[maxStudent][6])*0.2) + (stoi(array[maxStudent][7])*0.4))
         <((stoi(array[i][4])*0.3) + (stoi(array[i][5])*0.1) +
           (stoi(array[i][6])*0.2) + (stoi(array[i][7])*0.4))){
        maxStudent = i;
      }
    }
    maxStud -> setStudentName(array[maxStudent][2], array[maxStudent][3]);
    cout << "        max     " << (stoi(array[maxStudent][4])*0.3) + (stoi(array[maxStudent][5])*0.1)
      + (stoi(array[maxStudent][6])*0.2) + (stoi(array[maxStudent][7])*0.4)
         << "%  (" << maxStud -> getStudentName() << ")" << endl;
    return maxStud;
  }
  return NULL;
 
}

double Instructor::getAvg(int gradeType, int size, string ** array){
  double total = 0.0;
  if(gradeType == 1){
    for(int i = 0; i < size; i++){
      total += stoi(array[i][4]);
    }
    return total / size;
  }
  else if(gradeType == 2){
    for(int i = 0; i < size; i++){
      total += stoi(array[i][5]);
    }
    return total / size;
  }
  else if(gradeType == 3){
    for(int i = 0; i < size; i++){
      total += stoi(array[i][6]);
    }
    return total / size;
  }
  else if(gradeType == 4){
    for(int i = 0; i < size; i++){
      total += stoi(array[i][7]);
    }
    return total / size;
  }
  else if(gradeType == 5){
    for(int i = 0; i < size; i++){
      total += ( stoi(array[i][4])*0.3) + (stoi(array[i][5])*0.1)
        + (stoi(array[i][6])*0.2) + (stoi(array[i][7])*0.4);
    }
    return total / size;
  }
  return 0.0;
}

void Instructor::setName(string firstName, string lastName){
  fullName = firstName + " " + lastName;
}



Instructor::~Instructor(){
  for(int i = 0; i < 3; i++){
    delete[] instructors[i];
  }
  delete[] instructors;


}
