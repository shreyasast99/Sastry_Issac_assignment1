#include<iostream>
#include<string>
#include "Student.h"
#include "Instructor.h"
string firstName;
string lastName;
bool login(string username, string password);
string getInstructorName();
Student getStudent(string username);
Student getMinStudent(int gradeType);
Student getMaxStudent(int gradeType);
double getAvg(int gradeType);

//when the intructor logs in youshould make a instructor object with all instructor info. To check if they are actually an instructor then
Instructor::Instructor(){

}
bool Instructor::login(string username, string password){
    return true;
}
string Instructor::getInstructorName(){
    return firstName+" "+lastName;
}
Student getStudent(string username){
//go through file and create student objects for every student then return the object with that username
    Student student=new Student();
    return student;
}
Student getMinStudent(int gradeType){
    Student *student=new Student();
    return student;
}
Student getMaxStudent(int gradeType){
    Student *student=new Student();
    return student;
}
double getAvg(int gradeType){
    return 0;
}




















