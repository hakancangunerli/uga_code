#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
//header file including all protype methods for Student
using namespace std;

class Student{
    string username;
    string password;
    string fullName;
    int projectGrade;
    int quizGrade;
    int midtermGrade;
    int finalGrade;
public:
    Student();
    Student(string fname, string lname, string user, string pass, int proj, int quiz, int mid,
            int fin);
    bool login(string username, string password);
    string getStudentName();
    int getProjectGrade();
    int getQuizGrade();
    int getMidtermGrade();
    int getFinalGrade();
    double getOverallGrade();

    void setStudentName(string fullName);
    void setProjectGrade(int grade);
    void setQuizGrade(int grade);
    void setMidtermGrade(int grade);
    void setFinalGrade(int grade);
    bool sameUser(string username);
};
#endif
