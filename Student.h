#infdef STUDENT_H
#define STUDENT-H
#include <iostream>
#include <vector>
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
 
 private:
  string fullName;
  string firstName;
  string lastName;
  int projectGrade;
  int quizGrade;
  int midtermGrade;
  int finalGrade;
  string username;
  string password;
};
#endif
