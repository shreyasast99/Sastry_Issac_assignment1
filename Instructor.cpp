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
  }
  
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
  }
  //identifying the instructor
  while(inInstructorFile >> username >> password >> firstName >> lastName){
    if((this.username.compare(username)==0)&&(this.password.compare(password)==0)){
      setInstructorName(firstName,lastName);
      return true;
    }
  }
  return false;
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
      //grade type 1:project
      if(gradeType==1){
	if(StudentVec[i]->getProjectGrade()<min){
	  min=StudentVec[i]->getProjectGrade();
	}
      }
      //grade type 2:quiz
      if(gradeType==2){
	if(StudentVec[i]->getQuizGrade()<min){
	  min=StudentVec[i]->getQuizGrade();
	}
      }
      //grade type 3:midterm
      if(gradeType==3){
	if(StudentVec[i]->getMidtermGrade()<min){
	  min=StudentVec[i]->getMidtermGrade();
	}
      }
      //grade type 4: final
      if(gradeType==4){
	if(StudentVec[i]->getFinalGrade()<min){
	  min=StudentVec[i]->getFinalGrade();
	}
      }
      //grade type 5: overall
      if(gradeType==5){
	if(StudentVec[i]->getOverallGrade()<min){
	  min=StudentVec[i]->getOverallGrade();
	}
      }
    }//end of for loop
    return min;
}
Student getMaxStudent(int gradeType){
    int min=StudentVec[0]->getProjectGrade();
    for(int i=0;i<StudentVec.size();i++){
      //grade type 1:project
      if(gradeType==1){
	if(StudentVec[i]->getProjectGrade()<min){
	  max=StudentVec[i]->getProjectGrade();
	}
      }
      //grade type 2:quiz
      if(gradeType==2){
	if(StudentVec[i]->getQuizGrade()<min){
	  max=StudentVec[i]->getQuizGrade();
	}
      }
      //grade type 3:midterm
      if(gradeType==3){
	if(StudentVec[i]->getMidtermGrade()<min){
	  max=StudentVec[i]->getMidtermGrade();
	}
      }
      //grade type 4: final
      if(gradeType==4){
	if(StudentVec[i]->getFinalGrade()<min){
	  max=StudentVec[i]->getFinalGrade();
	}
      }
      //grade type 5: overall
      if(gradeType==5){
	if(StudentVec[i]->getOverallGrade()<min){
	  max=StudentVec[i]->getOverallGrade();
	}
      }
    }//end of for loop
    return max;
}
double getAvg(int gradeType){
  double sum=0;
  double average=0;
  //iterates through all students and add the overall grade as sum
  for(int i=0;i<StudentVec.size();i++){
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




















