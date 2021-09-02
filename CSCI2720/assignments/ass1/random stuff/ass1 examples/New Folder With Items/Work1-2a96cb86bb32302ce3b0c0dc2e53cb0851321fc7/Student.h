#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Student {
private:
	string fullName;
	int projectGrade;
	int quizGrade;
	int midtermGrade;
	int finalGrade;

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
};