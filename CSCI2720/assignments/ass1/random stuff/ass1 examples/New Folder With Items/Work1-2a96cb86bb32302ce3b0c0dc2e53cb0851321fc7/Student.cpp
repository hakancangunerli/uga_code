#include "Student.h"

bool Student::login(string username, string password) {

	// opening the file
	ifstream inputFile("students.txt");

	// if file not found
	if (!inputFile.is_open()) {
		cout << "student.txt File not found!" << endl;
		exit(EXIT_FAILURE);
	}

	// reading data from file line by line
	string line;
	while (getline(inputFile, line)) {

		// coverting the line into a stream of data
		stringstream dataLine(line);

		// getting username and password
		string oUsername, oPassword;
		getline(dataLine, oUsername, '\t');
		getline(dataLine, oPassword, '\t');

		// if credentails were found
		if(oUsername.compare(username.c_str()) == 0 && oPassword.compare(password.c_str()) == 0) {

			// getting full name of student
			getline(dataLine, fullName, '\t');

			// getting project grade of student
			string data;
			getline(dataLine, data, '\t');
			setProjectGrade(atoi(data.c_str()));

			// getting quiz grade of student
			getline(dataLine, data, '\t');
			setQuizGrade(atoi(data.c_str()));

			// getting midterm grade of student
			getline(dataLine, data, '\t');
			setMidtermGrade(atoi(data.c_str()));

			// getting final grade of student
			getline(dataLine, data, '\n');
			setFinalGrade(atoi(data.c_str()));

			// closing file
			inputFile.close();

			// student was found
			return true;
		}
	}

	// closing file
	inputFile.close();

	// if credentials wasn't found
	return false;
}

string Student::getStudentName() {
	return fullName;
}

int Student::getProjectGrade() {
	return projectGrade;
}

int Student::getQuizGrade() {
	return quizGrade;
}

int Student::getMidtermGrade() {
	return midtermGrade;
}

int Student::getFinalGrade() {
	return finalGrade;
}

double Student::getOverallGrade() {
	return ((projectGrade * 0.3) + (quizGrade * 0.1) + (midtermGrade * 0.2) + (finalGrade * 0.4));
}

void Student::setStudentName(string fullName) {
	this->fullName = fullName;
}

void Student::setProjectGrade(int grade) {
	this->projectGrade = grade;
}

void Student::setQuizGrade(int grade) {
	this->quizGrade = grade;
}

void Student::setMidtermGrade(int grade) {
	this->midtermGrade = grade;
}

void Student::setFinalGrade(int grade) {
	this->finalGrade = grade;
}
