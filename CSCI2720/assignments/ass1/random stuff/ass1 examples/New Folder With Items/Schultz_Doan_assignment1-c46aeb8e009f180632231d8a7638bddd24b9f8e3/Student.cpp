#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Student.h"

using namespace std;

bool Student::login(string username, string password) {
    vector<string> studentInfo = matchUser("students.txt", username, password);

    if(!studentInfo.empty()) {
	fullName = studentInfo.at(2);
	projectGrade = stoi(studentInfo.at(3));
	quizGrade = stoi(studentInfo.at(4));
	midtermGrade = stoi(studentInfo.at(5));
	finalGrade = stoi(studentInfo.at(6));

	return true;
    }

    else {
	cout << "Login failed" << endl;
	
	return false;
    }
}

vector<string> Student::matchUser(string filename, string username, string password) {
    vector<string> userInfo;
    
    string line;
    bool matchFound = false;
    
    ifstream file(filename);

    if(file.is_open()) {
	while(getline(file, line)) {
	    if(username.compare(line.substr(0, line.find("\t"))) == 0) {
		matchFound = true;
		break;
	    }
	}
	
	file.close();
    }

    else
	cout << "Error opening students.txt" << endl;

    if(matchFound) {
	int firstTabLoc = line.find("\t");
	int secondTabLoc = line.find("\t", firstTabLoc+1);
	
	if(password.compare(line.substr(firstTabLoc+1, (secondTabLoc-firstTabLoc)-1)) == 0) {
	    size_t current = line.find("\t");
	    unsigned int prev = 0;
	    
	    while(current != string::npos) {
		userInfo.push_back(line.substr(prev, current - prev));
		prev = current + 1;
		current = line.find("\t", prev);
	    }
	    userInfo.push_back(line.substr(prev));
	}
    }

    return userInfo;
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
    // all weights are in percent (%)
    double projectWeight = 0.30;
    double quizWeight = 0.10;
    double midtermWeight = 0.20;
    double finalWeight = 0.40;

    return (projectGrade * projectWeight) + (quizGrade * quizWeight)
	+ (midtermGrade * midtermWeight) + (finalGrade * finalWeight);
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

