#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
    private:
        string fullName;
        int projectGrade;
        int quizGrade;
        int midtermGrade;
        int finalGrade;    
        string username; 
        string password; 
    public:
        Student();  // default constructor
        // member variables username, password, firstName, lastName , projectGrade, quizGrade, midtermGrade, finalGrade, 
        
        Student(string,string, string, string, int, int, int, int); // constructor
        bool login(string username, string password);
        string getStudentName();
        int getProjectGrade();
        int getQuizGrade();
        int getMidtermGrade();
        int getFinalGrade();
        void setStudentName(string fullName);
        void setProjectGrade(int grade);
        void setQuizGrade(int grade);
        void setMidtermGrade(int grade);
        void setFinalGrade(int grade);
        bool match(string username);
        double getOverallGrade();
};
#endif