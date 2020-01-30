#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 *Used for implementing the Instructor class. This class has different
 *properities.
 */
class Instructor{
public:
    bool login(string username, string password);
    string getInstructorName();
    string setInstructorNAme(string firstName,string lastName);
    Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudetn(int gradeType);
    double getAvg(int gradeType);
    //void setInstructorName(string fullName);
private:
    string fullName;
    string firstName;
    string lastName;
};
#endif
