#include <iostream>
#include <string>
#include "student.h"
#include "instructor.h"
#include <cstring>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: ./main [instructors_file] [students_file]" << endl;
        exit(1);
    }
    else if (strcmp(argv[2], "students.txt"))
    {
        cout << "Error: cannot parse students' information from " << argv[2] << endl;
        exit(1);
    }
    else if (strcmp(argv[1], "instructors.txt"))
    {
        cout << "Error: cannot parse instructors' information from " << argv[1] << endl;
        exit(1);

    } // if
    // file i/o
    ifstream studentFile(argv[2], ios::in);
    // ifstream studentFile(argc[1]);
    if (!studentFile)
    {
        cout << "Error opening student file" << endl;
        exit(1);
    }

    // 20 students in array
    // values we want entered to be to our array
    // 8 values that go here, username, password, firstName, lastName , projectGrade, quizGrade, midtermGrade, finalGrade,
    int studentCounter = 0;
    string inputUsername, inputPassword, inputFirstName, inputLastName;
    int inputProjectGrade, inputQuizGrade, inputMidtermGrade, inputFinalGrade;
    Student studentArray[20];
    bool logic = false;
    // @hakancangunerli i don't understand what this variable does

    // fill in the student_arrays
    while (studentFile >> inputUsername >> inputPassword >> inputFirstName >> inputLastName >> inputProjectGrade >> inputQuizGrade >> inputMidtermGrade >> inputFinalGrade)
    {
        Student temporaryStudent(inputUsername, inputPassword, inputFirstName, inputLastName, inputProjectGrade, inputQuizGrade, inputMidtermGrade, inputFinalGrade);
        studentArray[studentCounter] = temporaryStudent;
        studentCounter++;
    } // while
    studentFile.close();
    // @hakancangunerli we need to close the file stream
    // also, i think we should flush the input stream as well
    Instructor instructorArray[3];
    ifstream instructorFile(argv[1], ios::in);

    // ifstream instructorFile(argc[0]);
    if (!instructorFile)
    {
        cout << "Instructor file cannot be opened." << endl;
        exit(1);
    } // if

    int instructorCounter = 0;
    while (instructorFile >> inputUsername >> inputPassword >> inputFirstName >> inputLastName)
    {
        Instructor temporaryInstructor(inputFirstName, inputLastName, inputUsername, inputPassword);
        instructorArray[instructorCounter] = temporaryInstructor;
        instructorCounter++;
    }                       // while
    instructorFile.close(); // we should flush the input stream here too
usertypes:
    cout << "User types," << endl;
    cout << "\t1 - Instructor " << endl;
    cout << "\t2 - Student " << endl;
    cout << "Select a login user type or enter 3 to exit: ";
    int loginType = 0;
    cin >> loginType;
    cout << "" << endl;
    if (loginType != 1 && loginType != 2 && loginType != 3)
    {
        cout << "Invalid option, please enter a valid option.\n";
        goto usertypes;
    }

    //count = 0;
    instructorCounter = 0;

    // this would allow for a simpler exit
    /*if (loginType == 3) {
        cout << "Exiting..." endl;
        exit(0);

    }*/

    while (loginType != 3)
    {

        if (loginType == 1)
        {

            cout << "Enter credentials to login, \n\tEnter username: ";
            string username = "";
            string password = "";
            cin >> username;
            cout << "\tEnter password: ";
            cin >> password;
            cout << "" << endl;
            bool attemptToLogin = false;
            int instructorOption = 0;

            for (int i = 0; i < 3; i++)
            {
                attemptToLogin = instructorArray[i].login(username, password);
                if (attemptToLogin == true)
                {
                    cout << "You are now logged in as instructor " + instructorArray[i].getInstructorName() + ".\n"
                         << endl;
                    do
                    {
                    query:
                        cout << "Query options, " << endl;
                        cout << "\t1 - view grades of a student" << endl;
                        cout << "\t2 - view stats" << endl;
                        cout << "Enter option number: ";
                        cin >> instructorOption;
                        cout << "" << endl;
                        if (instructorOption != 1 && instructorOption != 2)
                        {
                            cout << "Invalid option. Please enter a valid option. \n"
                                 << endl;
                        } // if
                    } while (instructorOption != 1 && instructorOption != 2);

                    if (instructorOption == 1)
                    {
                        // view specific student's grades
                        cout << "Enter student username to view grades: ";
                        string studentUsername;
                        cin >> studentUsername;
                        cout << "" << endl;
                        for (int i = 0; i < 20; i++)
                        {
                            if (studentArray[i].match(studentUsername) == true)
                            {
                                // project, quiz, midterm, final, overall
                                cout << "Student name: " << studentArray[i].getStudentName() << endl;
                                cout << "Project grade: " << studentArray[i].getProjectGrade() << endl;
                                cout << "Quiz grade: " << studentArray[i].getQuizGrade() << endl;
                                cout << "Midterm grade: " << studentArray[i].getMidtermGrade() << endl;
                                cout << "Final grade: " << studentArray[i].getFinalGrade() << endl;
                                cout << "Overall grade: " << studentArray[i].getOverallGrade() << endl;
                                goto usertypes;
                            } // if
                           

                        } // for
                        if (studentArray[i].match(studentUsername) == false)
                            {
                                cout << "Student not found." << endl;
                                goto query;
                            } // else if
                    }
                    else if (instructorOption == 2)
                    {
                        // view stats
                        int gradeType = 0;
                        do
                        {
                            cout << "Grade types," << endl;
                            cout << "1- Project \n 2- Quiz \n 3- Midterm \n 4- Final\n 5-Overall Grade" << endl;
                            cout << "Select a grade type to view stats: ";
                            cin >> gradeType;
                            cout << "" << endl;
                            if (gradeType < 1 || gradeType > 5)
                            {
                                cout << "Invalid option, please enter a valid option" << endl;
                            } // if

                            if (gradeType == 1)
                            {
                                int min = 0;
                                int average_stat = 0;
                                int max = 0;
                                string minName = "";
                                string maxName = "";
                                min = studentArray[0].getProjectGrade();
                                max = studentArray[0].getProjectGrade();
                                minName = studentArray[0].getStudentName();
                                maxName = studentArray[0].getStudentName();

                                int sum = 0;
                                for (int i = 0; i < 20; i++)
                                {
                                    if (min > studentArray[i].getProjectGrade())
                                    {
                                        min = studentArray[i].getProjectGrade();
                                        minName = studentArray[i].getStudentName();
                                    } // if
                                    if (max < studentArray[i].getProjectGrade())
                                    {
                                        max = studentArray[i].getProjectGrade();
                                        maxName = studentArray[i].getStudentName();
                                    } // if
                                    sum += studentArray[i].getProjectGrade();
                                } // for

                                average_stat = sum / 20;
                                cout << "Project grade statistics" << endl;
                                cout << "Min grade: " << min << " " << minName << endl;
                                cout << "Max grade: " << max << " " << maxName << endl;
                                cout << "Average grade: " << average_stat << endl;
                                goto usertypes;
                                break;

                                /* 
                                    for each student,(for i in 20), we compare min variable with the current
                                    student's project/midterm/final grade, if the current student's project/midterm/final grade is less than
                                    the min, we set the min to the current student's project/midterm/final grade.
                                */
                            }
                            else if (gradeType == 2)
                            {
                                // quiz
                                int min = 0;
                                int average_stat = 0;
                                int max = 0;
                                string minName = "";
                                string maxName = "";
                                min = studentArray[0].getQuizGrade();
                                max = studentArray[0].getQuizGrade();
                                minName = studentArray[0].getStudentName();
                                maxName = studentArray[0].getStudentName();
                                int sum = 0;
                                for (int i = 0; i < 20; i++)
                                {
                                    if (min > studentArray[i].getQuizGrade())
                                    {
                                        min = studentArray[i].getQuizGrade();
                                        minName = studentArray[i].getStudentName();
                                    } // if
                                    if (max < studentArray[i].getQuizGrade())
                                    {
                                        max = studentArray[i].getQuizGrade();
                                        maxName = studentArray[i].getStudentName();
                                    } // if
                                    sum += studentArray[i].getQuizGrade();
                                } // for

                                average_stat = sum / 20;
                                cout << "Quiz grade statistics" << endl;
                                cout << "Min grade: " << min << " " << minName << endl;
                                cout << "Max grade: " << max << " " << maxName << endl;
                                cout << "Average grade: " << average_stat << endl;
                                goto usertypes;
                            }
                            else if (gradeType == 3)
                            {
                                // midterm
                                int min = 0;
                                int average_stat = 0;
                                int max = 0;
                                string minName = "";
                                string maxName = "";
                                min = studentArray[0].getMidtermGrade();
                                max = studentArray[0].getMidtermGrade();
                                minName = studentArray[0].getStudentName();
                                maxName = studentArray[0].getStudentName();

                                int sum = 0;
                                for (int i = 0; i < 20; i++)
                                {
                                    if (min > studentArray[i].getMidtermGrade())
                                    {
                                        min = studentArray[i].getMidtermGrade();
                                        minName = studentArray[i].getStudentName();
                                    } // if
                                    if (max < studentArray[i].getMidtermGrade())
                                    {
                                        max = studentArray[i].getMidtermGrade();
                                        maxName = studentArray[i].getStudentName();
                                    } // if
                                    sum += studentArray[i].getMidtermGrade();
                                } // for

                                average_stat = sum / 20;
                                cout << "Midterm grade statistics" << endl;
                                cout << "Min grade: " << min << " " << minName << endl;
                                cout << "Max grade: " << max << " " << maxName << endl;
                                cout << "Average grade: " << average_stat << endl;
                                goto usertypes;
                            }
                            else if (gradeType == 4)
                            {
                                // final grade
                                int min = 0;
                                int average_stat = 0;
                                int max = 0;
                                string minName = "";
                                string maxName = "";
                                min = studentArray[0].getFinalGrade();
                                max = studentArray[0].getFinalGrade();
                                minName = studentArray[0].getStudentName();
                                maxName = studentArray[0].getStudentName();
                                int sum = 0;
                                for (int i = 0; i < 20; i++)
                                {
                                    if (min > studentArray[i].getFinalGrade())
                                    {
                                        min = studentArray[i].getFinalGrade();
                                        minName = studentArray[i].getStudentName();
                                    } // if
                                    if (max < studentArray[i].getFinalGrade())
                                    {
                                        max = studentArray[i].getFinalGrade();
                                        maxName = studentArray[i].getStudentName();
                                    } // if
                                    sum += studentArray[i].getProjectGrade();
                                } // for
                                average_stat = sum / 20;
                                cout << "Final grade statistics" << endl;
                                cout << "Min grade: " << min << " " << minName << endl;
                                cout << "Max grade: " << max << " " << maxName << endl;
                                cout << "Average grade: " << average_stat << endl;
                                goto usertypes;
                                break;
                            }
                            else if (gradeType == 5)
                            {
                                // overall grade
                                // this is an overall one, different from the other 4.
                                double overall = 0;
                                double overall_sum = 0;
                                int min = 0;
                                int max = 0;
                                int average_stat = 0;
                                string minName = "";
                                string maxName = "";
                                for (int i = 0; i < 20; i++) // for the list of students, keep comparing the grades, for base case where i=0, best overall is zero
                                {
                                    overall = (studentArray[i].getProjectGrade() * .3 + studentArray[i].getQuizGrade() * .1 + studentArray[i].getMidtermGrade() * .2 + studentArray[i].getFinalGrade() * .4);

                                    if (i == 0)
                                    {
                                        min = overall;
                                        max = overall;
                                        minName = studentArray[i].getStudentName();
                                        maxName = studentArray[i].getStudentName();
                                    }                  // if
                                    if (min > overall) // if min is higher than the overall, min becomes the overall
                                    {
                                        min = overall;
                                        minName = studentArray[i].getStudentName();
                                    }                  // if
                                    if (max < overall) // if max is less than the overall, then max becomes the new overall.
                                    {
                                        max = overall;
                                        maxName = studentArray[i].getStudentName();
                                    } // if
                                    overall_sum += overall;
                                } // for
                                average_stat = overall_sum / 20;
                                cout << "Overall grade statistics" << endl;
                                cout << "Min grade: " << min << " " << minName << endl;
                                cout << "Max grade: " << max << " " << maxName << endl;
                                cout << "Average grade: " << average_stat << endl;
                                goto usertypes;
                                break;
                            } // if
                        } while (gradeType > 1 && gradeType < 5);
                    } // if
                    while (loginType != 3)
                    {
                        /* as mentioned on line 342, we could remove this while loop() by handling loginType == 3 
                        first
                        */

                        if (loginType == 3)
                        {
                            /* @hakancangunerli input or loginType? because if input = 3, loginType = input, and 
                        the enclosing if statement (line 85) is only true when loginType == 1, this code
                        is dead code and will never be reached. a solution to this would be to check that the user wants
                        to exit then call exit(0) before handling other input
                        */
                            cout << "exiting";
                            logic = true;
                        } // if
                    }     // while
                    // @hakancangunerli where is the code for when attemptToLogin is false?
                    // added the code below
                }
                else if (i == 2 && !attemptToLogin)
                {
                    cout << "Login as instructor failed.\n"
                         << endl;
                } // if
            }     // for

        } // if

        if (loginType == 2)
        {

            cout << "Enter credentials to login, \n\tEnter username: ";
            string username = "";
            string password = "";
            cin >> username;
            cout << "\tEnter password: ";
            cin >> password;
            cout << "" << endl;
            //bool attemptToLogin = false;
            //int instructorOption = 0;

            bool testAttemptToLogin = false;
            for (int i = 0; i < 20; i++)
            {

                testAttemptToLogin = studentArray[i].login(username, password);

                if (testAttemptToLogin == true)
                {
                    testAttemptToLogin = studentArray[i].login(username, password);
                    if (testAttemptToLogin == true)
                    {
                        cout << "You are now logged in as student " + studentArray[i].getStudentName() + ".\n"
                             << endl;
                        cout << "Do you want to view your grades (y/n)? ";
                        string reply;
                        cin >> reply;
                        if (reply != "y" && reply != "n")
                        {
                            cout << "Please enter \'y\' or \'n'\'.";
                        } // if
                        if (reply == "n")
                        {
                            goto usertypes;
                        }

                        if (reply == "y")
                        {
                            cout << "Student name: " + studentArray[i].getStudentName() << endl;
                            cout << "Project " << studentArray[i].getProjectGrade() << "%" << endl;
                            cout << "Quiz " << studentArray[i].getQuizGrade() << "%" << endl;
                            cout << "Midterm " << studentArray[i].getMidtermGrade() << "%" << endl;
                            cout << "Final " << studentArray[i].getFinalGrade() << "%" << endl;
                            double overall = 0;
                            overall = studentArray[i].getProjectGrade() * .3 + studentArray[i].getQuizGrade() * .1 +
                                      studentArray[i].getMidtermGrade() * .2 + studentArray[i].getFinalGrade() * .4;
                            cout << "Your Overall grade is " << overall << "%" << endl;
                            goto usertypes;
                            // program hangs after printing this
                        } // if
                    }     // if
                }         // if

                

            } // for()
           

            while (logic == false)
                ;
        } // while
        if (loginType == 3)
        {
            cout << "exiting";
        } // if

    } // while

    return 0;

} // main()