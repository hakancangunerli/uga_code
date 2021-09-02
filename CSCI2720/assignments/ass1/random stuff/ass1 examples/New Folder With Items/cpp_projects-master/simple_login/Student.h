#ifndef STUDENT_H
#define STUDENT_H
#include <string.h>
#include <string>

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

    void setUsername(string username);
    void setPassword(string password);

    string getUsername();
    string getPassword();

private:

    string fullName;
    int projectGrade;
    int quizGrade;
    int midtermGrade;
    int finalGrade;

    string username;
    string password;

};

#endif
