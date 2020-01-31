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
          
}

bool Student::login(string username, string password){
    //parse files
    ifstream inStudentFile("students.txt",ios::in);
    
    //checking if the ifstream could not open the file
    if(!inStudentFile){
       cerr<<"File could not be opened"<<endl;
       exit(1);
    }//checking if file could be opened
    
    while(inStudentFile >> username >> password >> firstName >> lastName>>projectGrade>>quizGrade>>midtermGrade>>finalGrade){
        if(this.username==username&&this.password==password){
           
           return true;
        }
        
    }
    return false;
    
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

void Student::setUsername(string username){
    this.username=username;
}
void Student::setPassword(string password){
    this.password=password;
}
void Student::setFirstName(string firstName){
    this.firstName=firstName;
}
void Student::setLastName(string lastName){
    this.lastName=lastName;
}
//Student::~Student(){}
//};
