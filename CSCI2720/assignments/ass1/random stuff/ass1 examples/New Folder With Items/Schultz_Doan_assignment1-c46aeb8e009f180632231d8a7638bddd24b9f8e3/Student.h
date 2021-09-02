#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
 public:
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

 private:
    string fullName;
    int projectGrade;
    int quizGrade;
    int midtermGrade;
    int finalGrade;

    vector<string> matchUser(string filename, string username, string password);
};

#endif
