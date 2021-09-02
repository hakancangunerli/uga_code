#include "Instructor.h"

bool Instructor::login(string username, string password) {

	// opening the file
	ifstream inputFile("instructors.txt");

	// if file not found
	if (!inputFile.is_open()) {
		cout << "instructors.txt File not found!" << endl;
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
		if (oUsername.compare(username.c_str()) == 0 && oPassword.compare(password.c_str()) == 0) {

			// getting full name of instructor
			getline(dataLine, fullName, '\n');

			// closing file
			inputFile.close();

			// instructor was found
			return true;
		}
	}

	// closing file
	inputFile.close();

	// if credentials wasn't found
	return false;
}

string Instructor::getInstructorName() {
	return fullName;
}

Student Instructor::getStudent(string username) {

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

		// if student was found
		if (oUsername.compare(username.c_str()) == 0) {

			// for storing student details
			Student student;

			// getting full name of student
			string fullName;
			getline(dataLine, fullName, '\t');
			student.setStudentName(fullName);

			// getting project grade of student
			string data;
			getline(dataLine, data, '\t');
			student.setProjectGrade(atoi(data.c_str()));

			// getting quiz grade of student
			getline(dataLine, data, '\t');
			student.setQuizGrade(atoi(data.c_str()));

			// getting midterm grade of student
			getline(dataLine, data, '\t');
			student.setMidtermGrade(atoi(data.c_str()));

			// getting final grade of student
			getline(dataLine, data, '\n');
			student.setFinalGrade(atoi(data.c_str()));

			// closing file
			inputFile.close();

			// student was found
			return student;
		}
	}

	// closing file
	inputFile.close();

	return Student();
}

Student Instructor::getMinStudent(int gradeType) {

	// for storing student details having minimum grade in the given grade type
	Student minGradeStudent;

	// opening the file
	ifstream inputFile("students.txt");

	// if file not found
	if (!inputFile.is_open()) {
		cout << "student.txt File not found!" << endl;
		exit(EXIT_FAILURE);
	}

	// reading data from file line by line
	string line;
	bool first = true;
	while (getline(inputFile, line)) {

		// coverting the line into a stream of data
		stringstream dataLine(line);

		// getting username and password
		string oUsername, oPassword;
		getline(dataLine, oUsername, '\t');
		getline(dataLine, oPassword, '\t');

		// for storing student details
		Student student;

		// getting full name of student
		string fullName;
		getline(dataLine, fullName, '\t');
		student.setStudentName(fullName);

		// getting project grade of student
		string data;
		getline(dataLine, data, '\t');
		student.setProjectGrade(atoi(data.c_str()));

		// getting quiz grade of student
		getline(dataLine, data, '\t');
		student.setQuizGrade(atoi(data.c_str()));

		// getting midterm grade of student
		getline(dataLine, data, '\t');
		student.setMidtermGrade(atoi(data.c_str()));

		// getting final grade of student
		getline(dataLine, data, '\n');
		student.setFinalGrade(atoi(data.c_str()));

		// if it's the first student record
		if (first) {
			minGradeStudent = student;
			first = false;
			continue;
		}

		// if grade type is project grade
		if (gradeType == 1) {
			if (student.getProjectGrade() < minGradeStudent.getProjectGrade())
				minGradeStudent = student;
		}

		// if grade type is quiz grade
		else if (gradeType == 2) {
			if (student.getQuizGrade() < minGradeStudent.getQuizGrade())
				minGradeStudent = student;
		}

		// if grade type is mid term grade
		else if (gradeType == 3) {
			if (student.getMidtermGrade() < minGradeStudent.getMidtermGrade())
				minGradeStudent = student;
		}

		// if grade type is final grade
		else if (gradeType == 4) {
			if (student.getFinalGrade() < minGradeStudent.getFinalGrade())
				minGradeStudent = student;
		}

		// if grade type is overall grade
		else {
			if (student.getOverallGrade() < minGradeStudent.getOverallGrade())
				minGradeStudent = student;
		}
	}

	// closing file
	inputFile.close();

	// returning the student details having minimum grade in the given grade type
	return minGradeStudent;
}

Student Instructor::getMaxStudent(int gradeType) {
	
	// for storing student details having maximum grade in the given grade type
	Student maxGradeStudent;

	// opening the file
	ifstream inputFile("students.txt");

	// if file not found
	if (!inputFile.is_open()) {
		cout << "student.txt File not found!" << endl;
		exit(EXIT_FAILURE);
	}

	// reading data from file line by line
	string line;
	bool first = true;
	while (getline(inputFile, line)) {

		// coverting the line into a stream of data
		stringstream dataLine(line);

		// getting username and password
		string oUsername, oPassword;
		getline(dataLine, oUsername, '\t');
		getline(dataLine, oPassword, '\t');

		// for storing student details
		Student student;

		// getting full name of student
		string fullName;
		getline(dataLine, fullName, '\t');
		student.setStudentName(fullName);

		// getting project grade of student
		string data;
		getline(dataLine, data, '\t');
		student.setProjectGrade(atoi(data.c_str()));

		// getting quiz grade of student
		getline(dataLine, data, '\t');
		student.setQuizGrade(atoi(data.c_str()));

		// getting midterm grade of student
		getline(dataLine, data, '\t');
		student.setMidtermGrade(atoi(data.c_str()));

		// getting final grade of student
		getline(dataLine, data, '\n');
		student.setFinalGrade(atoi(data.c_str()));

		// if it's the first student record
		if (first) {
			maxGradeStudent = student;
			first = false;
			continue;
		}

		// if grade type is project grade
		if (gradeType == 1) {
			if (student.getProjectGrade() > maxGradeStudent.getProjectGrade())
				maxGradeStudent = student;
		}

		// if grade type is quiz grade
		else if (gradeType == 2) {
			if (student.getQuizGrade() > maxGradeStudent.getQuizGrade())
				maxGradeStudent = student;
		}

		// if grade type is mid term grade
		else if (gradeType == 3) {
			if (student.getMidtermGrade() > maxGradeStudent.getMidtermGrade())
				maxGradeStudent = student;
		}

		// if grade type is final grade
		else if (gradeType == 4) {
			if (student.getFinalGrade() > maxGradeStudent.getFinalGrade())
				maxGradeStudent = student;
		}

		// if grade type is overall grade
		else {
			if (student.getOverallGrade() > maxGradeStudent.getOverallGrade())
				maxGradeStudent = student;
		}
	}

	// closing file
	inputFile.close();

	// returning the student details having maximum grade in the given grade type
	return maxGradeStudent;
}

double Instructor::getAvg(int gradeType) {

	// for storing student grades of all students in the given grade type
	double total = 0;

	// opening the file
	ifstream inputFile("students.txt");

	// if file not found
	if (!inputFile.is_open()) {
		cout << "student.txt File not found!" << endl;
		exit(EXIT_FAILURE);
	}

	// reading data from file line by line
	string line;
	int count = 0;
	while (getline(inputFile, line)) {

		// coverting the line into a stream of data
		stringstream dataLine(line);

		// getting username and password
		string oUsername, oPassword;
		getline(dataLine, oUsername, '\t');
		getline(dataLine, oPassword, '\t');

		// for storing student details
		Student student;

		// getting full name of student
		string fullName;
		getline(dataLine, fullName, '\t');
		student.setStudentName(fullName);

		// getting project grade of student
		string data;
		getline(dataLine, data, '\t');
		student.setProjectGrade(atoi(data.c_str()));

		// getting quiz grade of student
		getline(dataLine, data, '\t');
		student.setQuizGrade(atoi(data.c_str()));

		// getting midterm grade of student
		getline(dataLine, data, '\t');
		student.setMidtermGrade(atoi(data.c_str()));

		// getting final grade of student
		getline(dataLine, data, '\n');
		student.setFinalGrade(atoi(data.c_str()));

		// incrementing the record count
		count++;

		// if grade type is project grade
		if (gradeType == 1)
			total += student.getProjectGrade();

		// if grade type is quiz grade
		else if (gradeType == 2)
			total += student.getQuizGrade();

		// if grade type is mid term grade
		else if (gradeType == 3)
			total += student.getMidtermGrade();

		// if grade type is final grade
		else if (gradeType == 4)
			total += student.getFinalGrade();

		// if grade type is overall grade
		else
			total += student.getOverallGrade();
	}

	// closing file
	inputFile.close();

	// returning the student details having minimum grade in the given grade type
	return (total / count);
}

void Instructor::setInstructorName(string fullName) {
	this->fullName = fullName;
}