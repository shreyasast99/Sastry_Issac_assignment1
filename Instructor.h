#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "Instructor.h" //just added this 
using namespace std;
/*
 *Used for implementing the Instructor class. This class has different
 *properities.
 */
class Instructor{
public:
  Instructor();
  bool login(string username, string password);
  bool studentUsername(string username);
  string getInstructorName();
  string getUsername();
  string getPassword();
  string setInstructorName(string firstName,string lastName);
  Student getStudent(string username);
  Student getMinStudent(int gradeType);
  double getMin();
  Student getMaxStudent(int gradeType);
  double getMax();
  double getAvg(int gradeType);
  //void setInstructorName(string fullName);
//private:
    
  string fullName="";
  string firstName;
  string lastName;
    string username;
    string password;
    int projectGrade;
    int quizGrade;
    int midtermGrade;
    int finalGrade;
    int minValue;
    int maxValue;
    
};
#endif
