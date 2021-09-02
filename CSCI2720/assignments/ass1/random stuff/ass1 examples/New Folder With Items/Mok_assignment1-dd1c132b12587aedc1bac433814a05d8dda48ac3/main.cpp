#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Student.h"
#include "Instructor.h"

using namespace std;

int main(int argc, char * argv[]){
  bool running = true;
  int stuRow = 0, insRow = 0;
  string line, line2;
  string **classArray;

  //Test to see if the input files are valid
  if(argc !=  3){
    cout << "Usage: main [instructor_file] [student_file]" << endl;
  }
  ifstream test(argv[1]);
  if(!test){
    cout << "Error: cannot parse instructor information from file " << argv[1] << endl;
    return 1;
  }
  else{
    while(getline(test, line)){
      insRow++;
    }
  }
  test.close();
  ifstream test2(argv[2]);
  if(!test2){
    cout << "Error: cannot parse student information from file " << argv[2] << endl;
    return 1;
  }
  else{
    while(getline(test2, line)){
      stuRow++;
    }
  }
  test2.close();
  ifstream test3(argv[2]);
  if(test3.is_open()){
    classArray = new string *[stuRow];
    for(int i = 0; i < stuRow; i++){
      classArray[i] = new string[8];
    }
    for(int i = 0; i < stuRow; i++){
      for(int j = 0; j < 8; j++){
        test3 >> classArray[i][j];
      }
    } 
  }
  test3.close();

  
  
  while(running){
    string input;
    bool loggedIn = false;
    cout << "User types, " << endl;
    cout << "   1 - Instructor" << endl;
    cout << "   2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit:" << endl;
    cin >> input;

    if(input.compare("1") == 0){
      Instructor * instructor1 = new Instructor(insRow);
      string username, password;
      cout << "Enter credidentials to login, " << endl;
      cout <<         "Enter username: ";
      cin >> username;
      cin.clear(); fflush(stdin);
      cout <<         "Enter password: ";
      cin >> password;
      cin.clear(); fflush(stdin);

      loggedIn = instructor1 -> login(username, password, argv[1]);
      if(loggedIn){
        bool looper = true;
        while(looper){
          cout << "Query Options, " << endl;
          cout << "     1 - view the grades of a student" << endl;
          cout << "     2 - view stats" << endl;
          int answer;
          cin >> answer;
          cin.clear();
          fflush(stdin);
          if(answer == 1){
            bool looper3 = true;
            while(looper3){
              cout << "Enter a student username to view grades: ";
              cin >> username; cout << endl;
              cin.clear(); fflush(stdin);
              if(instructor1 -> getStudent(username, stuRow, classArray) != NULL){
                looper3 = false;
                looper = false;
              }
            }
          }
          else if(answer == 2){
            bool looper2 = true;
            while(looper2){
            cout << "Grade Types," << endl;
            cout << "        1 - Project grade" << endl;
            cout << "        2 - Quiz grade" << endl;
            cout << "        3 - Midterm grade" << endl;
            cout << "        4 - Final grade" << endl;
            cout << "        5 - Overall grade" << endl;
            cout << "Select a grade type to view stats: ";
            cin >> answer; cout << endl;
            cin.clear(); fflush(stdin);
            if(answer < 6 && answer > 0){
              instructor1 -> getMinStudent(answer, stuRow, classArray);
              instructor1 -> getMaxStudent(answer, stuRow, classArray);
              cout << "        avg     " << instructor1 -> getAvg(answer, stuRow, classArray)
                   << "%" << endl;
              looper2 = false;
              looper = false;
            }
            else{
              cout << "Invalid option. Please enter a valid option" << endl;
            }
            }
          }
          else{
            cout << "Invalid option. Please enter a valid option." << endl;
          }
        }
      }
      delete instructor1;
    }
    else if(input.compare("2") == 0){
      Student * student1 = new Student(stuRow);
      string username, password;
      cout << "Enter credidentials to login, " << endl;
      cout <<         "Enter username: ";
      cin >> username;
      cin.clear(); fflush(stdin);
      cout <<         "Enter password: ";
      cin >> password;
      cin.clear(); fflush(stdin);
      loggedIn = student1 -> login(username, password, argv[2], stuRow);
      if(loggedIn){
        string answer;
        bool looper = true;
        while(looper){
          cout << "Do you want to view grades (y/n) ";
          cin >> answer; cout << endl;
          cin.clear(); fflush(stdin);
          if(answer.compare("y") == 0){
            student1 -> printGrades();
            looper = false;
          }
          else if(answer.compare("n") == 0){
            looper = false;
          }
        }
      }
      delete student1;
    }
    else if(input.compare("3") == 0){
      running = false;
    }
    else{
      cout << "Invalid option. Please enter a valid option" << endl;
    }
  }
  for(int i = 0; i < stuRow; i++){
    delete[] classArray[i];
  }
  delete[] classArray;
}
