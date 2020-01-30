#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
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
//class Student{
/*
 *Student constructor
 */
Student::Student(){
  
    ifstream studentFile;
    studentFile.open("students.txt",ios::in);
    while(studentFile>>username>>password>>firstName>>lastName>>projectGrade>>quizGrade>>midtermGrade>>finalGrade){
        
    }
  
}

bool Student::login(string username, string password){
    return true;
}
/*
 *concatenates the first and last name and returns full name
 */
string Student::getStudentName(){
  fullName=firstName+" "+lastName;
  return fullName;
}
/*
 *returns project grade
 */
int Student::getProjectGrade(){
  return projectGrade;
}
/*
 *returns quiz Grade
 */
int Student::getQuizGrade(){
  return quizGrade;
}
/*
 *returns Midterm grade
 */
int Student::getMidtermGrade(){
  return midtermGrade;
}
/*
 *returns final grade
 */
int Student::getFinalGrade(){
  return finalGrade;
}
/*
 *does calculation and returns the overall grade
 */
double Student::getOverallGrade(){
  double overallGrade;
  overallGrade=(0.30*getProjectGrade())+(0.10*getQuizGrade());
  overallGrade+=(0.20*getMidtermGrade())+(0.40*getFinalGrade());
  return overallGrade;
}

/*
void Student::setStudentName(string fullName){
}
*/

/*
 *changing the porject grade value
 */
void Student::setProjectGrade(int grade){
  projectGrade=grade;
}
/*
 *setting the quiz grade value
 */
void Student::setQuizGrade(int grade){
  quizGrade=grade;
}
/*
 *setting midterm grade
 */
void Student::setMidtermGrade(int grade){
  midtermGrade=grade;
}
/*
 *setting the final grade
 */
void Student::setFinalGrade(int grade){
  finalGrade=grade;
}
//Student::~Student(){}
//};
