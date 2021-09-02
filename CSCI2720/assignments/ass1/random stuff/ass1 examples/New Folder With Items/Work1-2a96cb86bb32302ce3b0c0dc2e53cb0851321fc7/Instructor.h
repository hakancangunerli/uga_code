#include "Student.h"

class Instructor {
private:
	string fullName;

public:
	bool login(string username, string password);
	string getInstructorName();
	Student getStudent(string username);
	Student getMinStudent(int gradeType);
	Student getMaxStudent(int gradeType);
	double getAvg(int gradeType);
	void setInstructorName(string fullName);
};