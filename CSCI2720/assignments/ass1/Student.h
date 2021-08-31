#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;
class Student
{

public:
    bool login(string username, string password);
    string getStudentName();
    int getProjectGrade();
    int getQuizGrade();
    int getMidtermGrade();
    int getFinalGrade();
    double getOverallGrade();
     int getStudent(string username);
    int getMinStudent(int gradeType);
    int getMaxStudent(int gradeType);
    double getAvg(int gradeType);

private:
    string fullName;
    int projectGrade;
    int quizGrade;
    int midtermGrade;
    int finalGrade;
};

#endif // INSTRUCTOR_H
