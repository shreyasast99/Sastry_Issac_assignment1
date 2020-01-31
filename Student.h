#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;
/*
 *creates a student class
 */
class Student{
public:
  Student();
  bool login(string username, string password);
  string getStudentName();
  string getUsername();
  int getProjectGrade();
  int getQuizGrade();
  int getMidtermGrade();
  int getFinalGrade();
  double getOverallGrade();
  
  // void setStudentName(string fullName);
  void setProjectGrade(int grade);
  void setQuizGrade(int grade);
  void setMidtermGrade(int grade);
  void setFinalGrade(int grade);
  void setUsername(string username);
  void setPassword(string password);
  void setFirstName(string firstName);
  void setLastName(string lastName);
  
//private:
    
  string fullName="";
  string firstName;
  string lastName;
  int projectGrade=0;
  int quizGrade=0;
  int midtermGrade=0;
  int finalGrade=0;
  string username="";
  string password;
    
};
#endif
