#include<iostream>
#include<string>
#include "Student.h"
#include "Instructor.h"
string username;
string password;
string firstName;
string lastName;
string fullName;
int projectGrade;
int quizGrade;
int midtermGrade;
int finalGrade;

vector<Student> StudentVec;
bool login(string username, string password);
string getInstructorName();
Student getStudent(string username);
Student getMinStudent(int gradeType);
Student getMaxStudent(int gradeType);
double getAvg(int gradeType);

//when the intructor logs in youshould make a instructor object with all instructor info. To check if they are actually an instructor then
Instructor::Instructor(/*string username, string password,string firstName, string lastName*/){
  //setting the parsed values into the constructor to make the instructor object
  //this.username=username;
  //this.password=password;
  //this.firstName=firstName;
  //this.lastName=lastName; 
}
bool Instructor::login(string username, string password){
  //parse files
  ifstream inInstructorFile("instructors.txt",ios::in);
  
  //checking if the ifstream could not open the file
  if(!inInstructorFile){
    cerr<<"File could not be opened"<<endl;
    exit(1);
  }//checking if file could be opened
//populating student vector
  ifstream inStudentFile("students.txt",ios::in);
  while(inStudentFile >> username >> password >> firstName >> lastName>>projectGrade>>quizGrade>>midtermGrade>>finalGrade){
      Student *temp=new Student();
      temp->setUsername(username);
      temp->setPassword(password);
      temp->setFirstName(firstName);
      temp->setLastName(lastName);
      temp->setProjetGrade(projectGrade);
      temp->setQuizGrade(quizGrade);
      temp->setMidtermGrade(midtermGrade);
      temp->setFinalGrade(finalGrade);
      StudentVec.push_back(new Student());   
  }//student vector
  while(inInstructorFile >> username >> password >> firstName >> lastName){
      if((this.username.compare(username)==0)&&(this.password.compare(password)==0)){
          setInstructorName(firstName,lastName);
          return true;
      }
    
  }
  return false;
}

}
void setInstructorName(string firstName, string lastName){
    fullName=firstName+ " " + lastName;
}
string Instructor::getInstructorName(){
    return fullName;
}
Student getStudent(string username){
    for(int i=0;i<StudentVec.size();i++){
        if(StudentVec[i]->getUsername().compare(username)){
            return *StudentVec[i];
        }
    }
}
Student getMinStudent(int gradeType){
    int min=StudentVec[0]->getProjectGrade();
    for(int i=0;i<StudentVec.size();i++){
        if(gradeType==1){//project
            if(StudentVec[i]->getProjectGrade()<min){
                min=StudentVec[i]->getProjectGrade();
            }
        }
    }
    return min;
}
Student getMaxStudent(int gradeType){
    Student *student=new Student();
    return student;
}
double getAvg(int gradeType){
    return 0;
}




















