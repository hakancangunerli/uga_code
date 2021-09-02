#include "Instructor.h"
#include "Student.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc!=3) {
        cout<<"Error: command file argument not equal to two"<<endl;
        return 1;
    } //if two file names are not present

    ifstream file1;
    file1.open(argv[1]);
    if (!file1) {
        cout<<"Error: cannot parse instructors information from file "<<argv[1]<<endl;
        return 2;
    } //instructor file not present
    ifstream file2;
    file2.open(argv[2]);
    if (!file2) {
        cout<<"Error: cannot parse students information from file "<<argv[2]<<endl;
        return 2;
    } //student file not present

    int instructorCount = 0;
    int studentCount = 0;
    string line1;
    string line2;
    while (getline(file1,line1)) {
        instructorCount++;
    } //counts the number of lines in instructors.txt
    while (getline(file2,line2)) {
        studentCount++;
    } //counts the number of lineis in students.txt
    
    Instructor instructors[instructorCount];
    Student students[studentCount];

    ifstream file3;
    file3.open(argv[1]);
    string line;
    int i = 0;
    while (getline(file3,line)) {
        char * chars = new char[line.length()+1];
        strcpy(chars,line.c_str());
        char * token = strtok(chars,"\t");
        instructors[i].setInstructorUsername(token);
        token=strtok(NULL,"\t");
        instructors[i].setInstructorPassword(token);
        token=strtok(NULL,"\t");
        instructors[i].setInstructorName(token);
        delete[] chars;
        i++;
    } //parse info from instructors.txt and initialize values
    
    ifstream file4;
    file4.open(argv[2]);
    string line3;
    int ii = 0;
    while (getline(file4,line3)) {
        char * chars = new char[line3.length()+1];
        strcpy(chars,line3.c_str());
        char * token = strtok(chars,"\t");
        students[ii].setUsername(token);
        token = strtok(NULL,"\t");
        students[ii].setPassword(token);
        token = strtok(NULL,"\t");
        students[ii].setStudentName(token);
        token = strtok(NULL,"\t");
        students[ii].setProjectGrade(atoi(token));
        token = strtok(NULL,"\t");
        students[ii].setQuizGrade(atoi(token));
        token = strtok(NULL,"\t");
        students[ii].setMidtermGrade(atoi(token));
        token = strtok(NULL,"\t");
        students[ii].setFinalGrade(atoi(token));
        delete[] chars;
        ii++;
    } //parse info from students.txt and initialize values

    login:
    
    cout<<"User types,"<<endl;
    cout<<"\t1 - Instructor"<<endl;
    cout<<"\t2 - Student"<<endl;
    cout<<"Select a login user type or enter 3 to exit: ";
    string userInput;
    getline(cin,userInput);

    while(!(userInput.compare("1")==0||userInput.compare("2")==0||userInput.compare("3")==0)) {
        cout<<"Invalid option. Please enter a valid option."<<endl;
        cout<<"User types,"<<endl;
        cout<<"\t1 - Instructor"<<endl;
        cout<<"\t2 - Student"<<endl;
        cout<<"Select a login user type or enter 3 to exit: ";
        getline(cin,userInput);
    } //prompts the user until input is valid

    if(userInput.compare("3")==0) {
        return 0;
    } //program terminates if user input is 3

    if(userInput.compare("1")==0) {
        cout<<"Enter credentials to login,\n\tEnter username: ";
        string userInputUsername;
        string userInputPassword;
        getline(cin,userInputUsername);
        cout<<"\tEnter password: ";
        getline(cin,userInputPassword);

        int instructorLogin = -1;

        for(int i =0;i<instructorCount;i++) {
            if (instructors[i].getInsUsername().compare(userInputUsername)==0) {
                if (instructors[i].getInsPassword().compare(userInputPassword)==0){
                    instructorLogin=i;
                    break;
                }
            } //if both username and password are correct
        }
        if (instructorLogin>=0) {
            bool InstructorLogin = instructors[instructorLogin].login(userInputUsername,userInputPassword);
            cout<<"You are now logged in as instructor "+instructors[instructorLogin].getInstructorName()<<endl;
        } //if login is successful
        else {
            cout<<"Login as instructor failed"<<endl;
            goto login;
        } //if login is unsuccessful
        queryOption:
        cout<<"Query options,"<<endl;
        cout<<"\t1 - view grades of a student"<<endl;
        cout<<"\t2 - view stats"<<endl;
        cout<<"Enter option number: ";
        string temp;
        getline(cin,temp);
        if (!(temp.compare("1")==0||temp.compare("2")==0)){
            cout<<"Invalid option. Please enter a valid option."<<endl;
            goto queryOption;
        } //query option again
        
        if (temp.compare("1")==0) {
            cout<<"Enter student username to view grades: ";
            string studentID;
            getline(cin,studentID);
            
            int studentLogin = -1;
            for(int i = 0;i<studentCount;i++) {
                if (students[i].getUsername().compare(studentID)==0) {
                    studentLogin=i;
                    break;
                } //check if student username is valid
            }
            if (studentLogin>=0) {
                cout<<"Student name: "<<students[studentLogin].getStudentName()<<endl;
                cout<<"\tProject\t"<<students[studentLogin].getProjectGrade()<<"%"<<endl;
                cout<<"\tQuiz\t"<<students[studentLogin].getQuizGrade()<<"%"<<endl;
                cout<<"\tMidterm\t"<<students[studentLogin].getMidtermGrade()<<"%"<<endl;
                cout<<"\tFinal\t"<<students[studentLogin].getFinalGrade()<<"%"<<endl;
                cout<<"\tOverall\t"<<students[studentLogin].getOverallGrade()<<"%"<<endl;
                goto login;
            }
            else{
                cout<<"Student username is not valid"<<endl;
                goto queryOption;
            } //if student username is not valid
        } //if viewing grades of a student
        else if (temp.compare("2")==0) {
            stats:
            cout<<"Grade types,"<<endl;
            cout<<"\t1 - Project grade"<<endl;
            cout<<"\t2 - Quiz grade"<<endl;
            cout<<"\t3 - Midterm grade"<<endl;
            cout<<"\t4 - Final grade"<<endl;
            cout<<"\t5 - Overall grade"<<endl;
            cout<<"Select a grade type to view stats: ";
            
            string viewStats;
            getline(cin,viewStats);
            if (!(viewStats.compare("1")==0||viewStats.compare("2")==0||viewStats.compare("3")==0||viewStats.compare("4")==0||viewStats.compare("5")==0)) {
                cout<<"Invalid option. Please enter a valid option."<<endl;
                goto stats;
            } //invalid input for viewing stats
            
            int minProject=100;
            int maxProject=0;
            double avgProject=0;
            string minProjectStr;
            string maxProjectStr;
            
            int minQuiz=100;
            int maxQuiz=0;
            double avgQuiz=0;
            string minQuizStr;
            string maxQuizStr;
            
            int minMidterm=100;
            int maxMidterm=0;
            double avgMidterm=0;
            string minMidtermStr;
            string maxMidtermStr;
            
            int minFinal=100;
            int maxFinal=0;
            double avgFinal=0;
            string minFinalStr;
            string maxFinalStr;
            
            int minOverall=100;
            int maxOverall=0;
            double avgOverall=0;
            string minOverallStr;
            string maxOverallStr;
            
            for (int i=0;i<studentCount;i++) {
                avgProject+=students[i].getProjectGrade();
                if (students[i].getProjectGrade()<minProject) {
                    minProject=students[i].getProjectGrade();
                    minProjectStr=students[i].getStudentName();
                }
                if (students[i].getProjectGrade()>maxProject) {
                    maxProject=students[i].getProjectGrade();
                    maxProjectStr=students[i].getStudentName();
                }
                avgQuiz+=students[i].getQuizGrade();
                if (students[i].getQuizGrade()<minQuiz) {
                    minQuiz=students[i].getQuizGrade();
                    minQuizStr=students[i].getStudentName();
                }
                if (students[i].getQuizGrade()>maxQuiz) {
                    maxQuiz=students[i].getQuizGrade();
                    maxQuizStr=students[i].getStudentName();
                }
                avgMidterm+=students[i].getMidtermGrade();
                if (students[i].getMidtermGrade()<minMidterm) {
                    minMidterm=students[i].getMidtermGrade();
                    minMidtermStr=students[i].getStudentName();
                }
                if (students[i].getMidtermGrade()>maxMidterm) {
                    maxMidterm=students[i].getMidtermGrade();
                    maxMidtermStr=students[i].getStudentName();
                }
                avgFinal+=students[i].getFinalGrade();
                if (students[i].getFinalGrade()<minFinal) {
                    minFinal=students[i].getFinalGrade();
                    minFinalStr=students[i].getStudentName();
                }
                if (students[i].getFinalGrade()>maxFinal) {
                    maxFinal=students[i].getFinalGrade();
                    maxFinalStr=students[i].getStudentName();
                }
                avgOverall+=students[i].getOverallGrade();
                if (students[i].getOverallGrade()<minOverall) {
                    minOverall=students[i].getOverallGrade();
                    minOverallStr=students[i].getStudentName();
                }
                if (students[i].getOverallGrade()>maxOverall) {
                    maxOverall=students[i].getOverallGrade();
                    maxOverallStr=students[i].getStudentName();
                }
            }
            avgProject/=studentCount;
            avgQuiz/=studentCount;
            avgMidterm/=studentCount;
            avgFinal/=studentCount;
            avgOverall/=studentCount;
            
            if (viewStats.compare("1")==0) {
                cout<<"Project grade stats,"<<endl;
                cout<<"\tmin "<<minProject<<"% "<<"("+minProjectStr+")"<<endl;
                cout<<"\tmax "<<maxProject<<"% "<<"("+maxProjectStr+")"<<endl;
                cout<<"\tavg "<<avgProject<<"% "<<endl;
                goto login;
            }//viewing project grade
            else if (viewStats.compare("2")==0) {
                cout<<"Quiz grade stats,"<<endl;
                cout<<"\tmin "<<minQuiz<<"% "<<"("+minQuizStr+")"<<endl;
                cout<<"\tmax "<<maxQuiz<<"% "<<"("+maxQuizStr+")"<<endl;
                cout<<"\tavg "<<avgQuiz<<"% "<<endl;
                goto login;
            }//viewing Quiz grade
            else if (viewStats.compare("3")==0) {
                cout<<"Midterm grade stats,"<<endl;
                cout<<"\tmin "<<minMidterm<<"% "<<"("+minMidtermStr+")"<<endl;
                cout<<"\tmax "<<maxMidterm<<"% "<<"("+maxMidtermStr+")"<<endl;
                cout<<"\tavg "<<avgMidterm<<"% "<<endl;
                goto login;
            }//viewing midterm grade
            else if (viewStats.compare("4")==0) {
                cout<<"Final grade stats,"<<endl;
                cout<<"\tmin "<<minFinal<<"% "<<"("+minFinalStr+")"<<endl;
                cout<<"\tmax "<<maxFinal<<"% "<<"("+maxFinalStr+")"<<endl;
                cout<<"\tavg "<<avgFinal<<"% "<<endl;
                goto login;
            }//viewing final grade
            else if (viewStats.compare("5")==0) { 
                cout<<"Overall grade stats,"<<endl;
                cout<<"\tmin "<<minOverall<<"% "<<"("+minOverallStr+")"<<endl;
                cout<<"\tmax "<<maxOverall<<"% "<<"("+maxOverallStr+")"<<endl;
                cout<<"\tavg "<<avgOverall<<"% "<<endl;
                goto login;
            }//viewing overall grade
        } //if viewing stats of this class
        
    } //login as an instructor
    else if(userInput.compare("2")==0) {
        cout<<"Enter credentials to login,\n\tEnter username: ";
        string userInputUsername;
        string userInputPassword;
        getline(cin,userInputUsername);
        cout<<"\tEnter password: ";
        getline(cin,userInputPassword);       
        int studentLogin = -1;
        for(int i =0;i<studentCount;i++) {
            if (students[i].getUsername().compare(userInputUsername)==0) {
                if (students[i].getPassword().compare(userInputPassword)==0){
                    studentLogin=i;
                    break;
                }
            } //if both username and password are correct
        }
        if (studentLogin>=0) {
            cout<<"You are now logged in as student "+students[studentLogin].getStudentName()<<endl;
            bool StudentLogin = students[studentLogin].login(userInputUsername,userInputPassword);
        } //if login is successful
        else {
            cout<<"Login as student failed"<<endl;
            goto login;
        } //if login is unsuccessful
        cout<<"Do you want to view grades (y/n)? ";
        string temp;
        getline(cin,temp);
        if (temp.compare("y")!=0) {
            goto login;
        } //if the user input is not y
        
        cout<<"Student name: "<<students[studentLogin].getStudentName()<<endl;
        cout<<"\tProject\t"<<students[studentLogin].getProjectGrade()<<"%"<<endl;
        cout<<"\tQuiz\t"<<students[studentLogin].getQuizGrade()<<"%"<<endl;
        cout<<"\tMidterm\t"<<students[studentLogin].getMidtermGrade()<<"%"<<endl;
        cout<<"\tFinal\t"<<students[studentLogin].getFinalGrade()<<"%"<<endl;
        cout<<"\tOverall\t"<<students[studentLogin].getOverallGrade()<<"%"<<endl;
        goto login;
    } //login as a student



    
    return 0;
}
