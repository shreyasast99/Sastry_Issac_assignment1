#include<iostream>
#include<string>
#include "Student.h"
#include "Instructor.h"
string username;
string password;
string firstName;
string lastName;
vector<Instructor> instructorVec;
bool login(string username, string password);
string getInstructorName();
Student getStudent(string username);
Student getMinStudent(int gradeType);
Student getMaxStudent(int gradeType);
double getAvg(int gradeType);

//when the intructor logs in youshould make a instructor object with all instructor info. To check if they are actually an instructor then
Instructor::Instructor(string username, string password,string firstName, string lastName){
  //setting the parsed values into the constructor to make the instructor object
  this.username=username;
  this.password=password;
  this.firstName=firstName;
  this.lastName=lastName;
}
bool Instructor::login(string username, string password){
  //parse files
  ifstream inInstructorFile("instructor.txt",ios::in);
  
  //checking if the ifstream could not open the file
  if(!inInstructorFile){
    cerr<<"File could not be opened"<<endl;
    exit(1);
  }//checking if file could be opened

  while(inInstructorFile >> username >> password >> firstName >> lastName){
    Instructor instructorTemp=new Instructor(); //creating instructor object
    instructorTemp.login(username
  }
}
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




















