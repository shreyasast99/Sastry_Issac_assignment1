#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string fullName;
string firstName;
string lastName;
int projectGrade;
int quizGrade;
int midtermGrade;
int finalGrade;
string username;
string password;
bool login(string username, string password);
string getStudentName();
int getProjectGrade();
int getQuizGrade();
int getMidtermGrade();
int getFinalGrade();
double getOverallGrade();
/*
 *Student constructor
 */
Student::Student(){
    ifstream studentFile;
    studentFile.open("students.txt");
    while(studentFile>>){

    }
}

string getStudentName(){

}
