#include "Instructor.h"

int main() {

	char userType;
	char choice;
	string username, password;
	while (true) {

		// displaying option
		cout << "\n\nUser types," << endl;
		cout << "\t1 - Instructor" << endl;
		cout << "\t2 - Student" << endl;
		cout << "Select a login user type or enter 3 to exit: ";
		cin >> userType;

		// if instructor or student option is selected then get credentials
		if (userType == '1' || userType == '2') {
			cout << "\nEnter credentials to login," << endl;
			cout << "\tEnter username: ";
			cin >> username;
			cout << "\tEnter password: ";
			cin >> password;
		}

		// if instructor option is selected
		if (userType == '1') {

			// instatiating instructor object
			Instructor* instructor = new Instructor();

			// if instructor login successful
			if (instructor->login(username, password)) {

				// displaying prompt of login
				cout << "\nYou are now logged in as instructor " << instructor->getInstructorName() << endl;

				// until instructor chooses a correct option
				while (true) {

					// getting choice from student to view grades
					cout << "\nQuery options," << endl;
					cout << "\t1 - view grades of a student" << endl;
					cout << "\t2 - view stats" << endl;
					cout << "Enter option number: ";
					cin >> choice;

					// if the instructor wants to view the grades of student
					if (choice == '1') {

						// until instructor enters a correct username
						while (true) {

							// getting username of student from instructor
							string username;
							cout << "\nEnter student username to view grades: ";
							cin >> username;

							// getting record of student against the given username
							Student student = instructor->getStudent(username);

							// if record of student with the given username is found
							if (student.getStudentName().compare("") != 0) {

								// printing grade details of student
								cout << "\nStudent name: " << student.getStudentName() << endl;
								cout << "\tProject\t" << student.getProjectGrade() << "%" << endl;
								cout << "\tQuiz\t" << student.getQuizGrade() << "%" << endl;
								cout << "\tMidterm\t" << student.getMidtermGrade() << "%" << endl;
								cout << "\tFinal\t" << student.getFinalGrade() << "%" << endl;
								cout << "\tOverall\t" << student.getOverallGrade() << "%" << endl;
								break;
							}

							// if record of student with the given username is not found
							else
								cout << "\nStudent username is not valid" << endl;
						}
						break;
					}

					// if the instructor wants to view the stats
					else if (choice == '2') {

						// until instructor chooses a correct grade type
						while (true) {

							// getting grade type from instructor
							char gradeType;
							cout << "\nGrade types," << endl;
							cout << "\t1 - Project grade" << endl;
							cout << "\t2 - Quiz grade" << endl;
							cout << "\t3 - Midterm grade" << endl;
							cout << "\t4 - Final grade" << endl;
							cout << "\t5 - Overall grade" << endl;
							cout << "Select a grade type to view stats: ";
							cin >> gradeType;

							// if grade type is between 1-5 inclusive
							if (gradeType == '1' || gradeType == '2' || gradeType == '3' || gradeType == '4' || gradeType == '5') {

								// getting student with minimum grade in grade type
								Student minGradeStudent = instructor->getMinStudent(gradeType - 48);

								// getting student with maximum grade in grade type
								Student maxGradeStudent = instructor->getMaxStudent(gradeType - 48);

								// printing grade stats
								cout << "\nOverall grade stats," << endl;
								cout << "\tmin " << minGradeStudent.getFinalGrade() << "% (" << minGradeStudent.getStudentName() << ")" << endl;
								cout << "\tmax " << maxGradeStudent.getFinalGrade() << "% (" << maxGradeStudent.getStudentName() << ")" << endl;
								cout << "\tavg " << instructor->getAvg(gradeType - 48) << "%" << endl;
								break;
							}

							// if invalid grade type is selected
							else
								cout << "\nInvalid option. Please enter a valid option." << endl;
						}
						break;
					}

					// if invalid option is selected
					else
						cout << "\nInvalid option. Please enter a valid option." << endl;
				}
			}

			// if instructor login failed
			else
				cout << "\nLogin as instructor failed." << endl;
		}

		// if student option is selected
		else if (userType == '2') {

			// instatiating instructor object
			Student* student = new Student();

			// if instructor login successful
			if (student->login(username, password)) {

				// displaying prompt of login
				cout << "\nYou are now logged in as student " << student->getStudentName() << endl;

				// getting choice from student to view grades
				cout << "\nDo you want to view grades (y/n)? ";
				cin >> choice;

				// if student enters 'y'
				if (choice == 'y') {

					// printing grade details of student
					cout << "\nStudent name: " << student->getStudentName() << endl;
					cout << "\tProject\t" << student->getProjectGrade() << "%" << endl;
					cout << "\tQuiz\t" << student->getQuizGrade() << "%" << endl;
					cout << "\tMidterm\t" << student->getMidtermGrade() << "%" << endl;
					cout << "\tFinal\t" << student->getFinalGrade() << "%" << endl;
					cout << "\tOverall\t" << student->getOverallGrade() << "%" << endl;
				}

				// deleting student object
				delete student;
			}

			// if instructor login failed
			else
				cout << "\nLogin as student failed." << endl;
		}

		// if exit option is enetered
		else if (userType == '3')
			break;

		// if invalid option enetered
		else
			cout << "\nInvalid option. Please enter a valid option." << endl;
	}

	return EXIT_SUCCESS;
}