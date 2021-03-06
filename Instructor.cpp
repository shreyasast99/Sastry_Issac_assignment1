#include<iostream>
#include<fstream>
#include<string>
#include "Instructor.h"
#include "Student.h"


/*
string username="";
string password="";
string firstName="";
string lastName="";
string fullName="";
int projectGrade=0;
int quizGrade=0;
int midtermGrade=0;
int finalGrade=0;
int minValue=0;
int maxValue=0;
*/
vector<Student*> StudentVec;
/*
bool login(string username, string password);
bool studentUsername(string username);
string getInstructorName();
Student getStudent(string username);
Student getMinStudent(int gradeType);
Student getMaxStudent(int gradeType);
double getAvg(int gradeType);
double getMin(Student student);
void setMin(double min);
double getMax(Student student);
void setMax(double max);
*/

//when the intructor logs in youshould make a instructor object with all instructor info. To check if they are actually an instructor then
Instructor::Instructor(){
  username="";
  password="";
  fullName="";
  minValue=0;
  maxValue=0;
}
double Instructor::getMin(){
    return minValue;
}
double Instructor::getMax(){
  return maxValue;
}
bool Instructor::studentUsername(string username){
    //bool isFound=false;
  for(unsigned int i=0;i<StudentVec.size();i++){
    if(StudentVec[i]->getUsername().compare(username)==0){
      return true;
    }
  }
  return false;
}
bool Instructor::login(string username, string password){
  //parse files
  ifstream inInstructorFile("instructors.txt",ios::in);
  //checking if the ifstream could not open the file
  if(!inInstructorFile){
    cerr<<"File could not be opened"<<endl;
    exit(1);
  }
  
  //populating student vector
  ifstream inStudentFile("students.txt",ios::in);
  while(inStudentFile >> username >> password >> firstName >> lastName>>projectGrade>>quizGrade>>midtermGrade>>finalGrade){
    Student *temp=new Student();
    temp->setUsername(username);
    temp->setPassword(password);
    temp->setFirstName(firstName);
    temp->setLastName(lastName);
    temp->setProjectGrade(projectGrade);
    temp->setQuizGrade(quizGrade);
    temp->setMidtermGrade(midtermGrade);
    temp->setFinalGrade(finalGrade);
    StudentVec.push_back(temp);   
  }
  //identifying the instructor
  while(inInstructorFile >> username >> password >> firstName >> lastName){
    if((username.compare(username)==0)&&(/*this->getPassword()*/password.compare(password)==0)){
      setInstructorName(firstName,lastName);
      return true;
    }
  }
  return false;
}

void Instructor::setInstructorName(string firstName, string lastName){
    fullName=firstName+ " " + lastName;
}
string Instructor::getInstructorName(){
  return fullName;
}
string Instructor::getUsername(){
    return username;
}
string Instructor::getPassword(){
  return password;
}
Student Instructor::getStudent(string username){
  unsigned int count=0;
  for(unsigned int i=0;i<StudentVec.size();i++){
    if(StudentVec[i]->getUsername().compare(username)==0){
      //return *StudentVec[i];
      //storing the value of index where they are equal
      count=i;
    }
  }
  return *StudentVec[count];
}
Student Instructor::getMinStudent(int gradeType){
  Student *temp=new Student();
  int min;
  //setting what the first min would be
  if(gradeType==1){ 
    min=StudentVec[0]->getProjectGrade();
  }
  if(gradeType==2){ 
    min=StudentVec[0]->getQuizGrade();
  }
  if(gradeType==3){ 
    min=StudentVec[0]->getMidtermGrade();
  }
  if(gradeType==4){ 
    min=StudentVec[0]->getFinalGrade();
  }
  if(gradeType==5){ 
    min=StudentVec[0]->getOverallGrade();
  }
  for(unsigned int i=0;i<StudentVec.size();i++){
    //grade type 1:project
    if(gradeType==1){
      if(StudentVec[i]->getProjectGrade()<min){
	min=StudentVec[i]->getProjectGrade();
	temp=StudentVec[i];
      }
    }
    //grade type 2:quiz
    if(gradeType==2){
      if(StudentVec[i]->getQuizGrade()<min){
	min=StudentVec[i]->getQuizGrade();
	temp=StudentVec[i];
      }
    }
    //grade type 3:midterm
    if(gradeType==3){
      if(StudentVec[i]->getMidtermGrade()<min){
	min=StudentVec[i]->getMidtermGrade();
	temp=StudentVec[i];
      }
    }
    //grade type 4: final
    if(gradeType==4){
      if(StudentVec[i]->getFinalGrade()<min){
	min=StudentVec[i]->getFinalGrade();
	temp=StudentVec[i];
      }
    }
    //grade type 5: overall
    if(gradeType==5){
      if(StudentVec[i]->getOverallGrade()<min){
	min=StudentVec[i]->getOverallGrade();
	temp=StudentVec[i];
      }
    }
  }//end of for loop
  minValue=min;
  return *temp;
}
Student Instructor::getMaxStudent(int gradeType){
  Student * temp=new Student();
  int max;
  //figuing out strating value of max
  if(gradeType==1){ 
    max=StudentVec[0]->getProjectGrade();
  }
  if(gradeType==2){ 
    max=StudentVec[0]->getQuizGrade();
  }
  if(gradeType==3){ 
    max=StudentVec[0]->getMidtermGrade();
  }
  if(gradeType==4){ 
    max=StudentVec[0]->getFinalGrade();
  }
  if(gradeType==5){ 
    max=StudentVec[0]->getOverallGrade();
  }
  for(unsigned int i=0;i<StudentVec.size();i++){
    //grade type 1:project
    if(gradeType==1){
      if(StudentVec[i]->getProjectGrade()>max){
	max=StudentVec[i]->getProjectGrade();
	temp=StudentVec[i];
      }
    }
    //grade type 2:quiz
    if(gradeType==2){
      if(StudentVec[i]->getQuizGrade()>max){
	max=StudentVec[i]->getQuizGrade();
	temp=StudentVec[i];
      }
    }
    //grade type 3:midterm
    if(gradeType==3){
      if(StudentVec[i]->getMidtermGrade()>max){
	max=StudentVec[i]->getMidtermGrade();
	temp=StudentVec[i];
      }
    }
    //grade type 4: final
    if(gradeType==4){
      if(StudentVec[i]->getFinalGrade()>max){
	max=StudentVec[i]->getFinalGrade();
	temp=StudentVec[i];
      }
    }
    //grade type 5: overall
    if(gradeType==5){
      if(StudentVec[i]->getOverallGrade()>max){
	max=StudentVec[i]->getOverallGrade();
	temp=StudentVec[i];
      }
    }
  }//end of for loop
  maxValue=max;
  return *temp;
}
double Instructor::getAvg(int gradeType){
  double sum=0;
  double average=0;
  //iterates through all students and add the overall grade as sum
  for(unsigned int i=0;i<StudentVec.size();i++){
    //gradeType 1: project
    if(gradeType==1){
      sum+=StudentVec[i]->getProjectGrade();
    }
    //gradeType2: quiz
    if(gradeType==2){
      sum+=StudentVec[i]->getQuizGrade();
    }
    //gradeType 3: midterm
    if(gradeType==3){
      sum+=StudentVec[i]->getMidtermGrade();
    }
    //gradeType 4: final
    if(gradeType==4){
      sum+=StudentVec[i]->getFinalGrade();
    }
    //gradeType 5: overall grade
    if(gradeType==5){
      sum+=StudentVec[i]->getOverallGrade();
    }
  }//sum is set
  average=sum/StudentVec.size();
  return average;
}
















