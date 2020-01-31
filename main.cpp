#include <iostream>
#include <string>
#include "Student.h"
#include "Instructor.h"
using namespace std;
int person=0;
string username;
string pass;
int query;
string viewGrades;
string studentUser;
int gradeType;
int main(){
    while(person!=3){
        cout<<"User types,\n 1 - Instructor\n 2 - Student\n select a login user type or enter 3 to exit:\n"<<endl;
        cin>>person;
        //checks if you are instructor(1) or student(2)
        if(person==1){
            //do instructor stuff
            cout<<"Enter credentials to login, Enter username:\n"<<endl;
            cin>>username;
            cout<<"Enter password: \n"<<endl;
            cin>>pass;
            Instructor *instructor= new Instructor();
            if(instructor->login(username,pass)==true){
                cout<<"You are now logged in as instructor "<< instructor->getInstructorName()<< "."<<endl;
                cout<<"Query options,\n1 - view grades of a student\n2 - view stats\nEnter option number:"<<endl;
                cin>>query;
                //checks the query option(view grades or view stats)
                int queryValid=0;
                
                while(queryValid==0){//checks if user input is valid
                    cout<<"Query options,\n1 - view grades of a student\n2 - view stats\nEnter option number:"<<endl;
                    cin>>query;
                    if(query!=1&&query!=2){
                        queryValid=0;
                    }
                    userValid=1;
                    if(query==1){
                        cout<<"Enter student username to view grades: "<<endl;
                        cin>>studentUser;
                        //checking if username is in file COME BACK HERE
                        if(student.getUsername(studentUser).compare("")){
                            cout<<"Student username is not valid."<<endl;
                            userValid=0;
                        }
                        cout<<"Student name:"<<instructor->getStudent(studentUser).getStudentName()<<endl;
                        cout<<"Project   "<<instructor->getStudent(studentUser).getProjectGrade()<<endl;
                        cout<<"Quiz   "<<instructor->getStudent(studentUser).getQuizGrade()<<endl;
                        cout<<"Midterm   "<<instructor->getStudent(studentUser).getMidtermGrade()<<endl;
                        cout<<"Final   "<<instructor->getStudent(studentUser).getFinalGrade()<<endl;
                        cout<<"Overall   "<<instructor->getStudent(studentUser).getOverallGrade()<<endl;
                    }
                    else if(query==2){
                        int wrongType=0;
                        while(wrongType==0){
                            
                            cout<<"Grade types, \n 1 - Project grade \n2 - Quiz grade\n3 - Midterm grade\n4 - Final grade\n5 - Overall grade"<<endl;
                            cout<<"Select a grade type to view stats: "<<endl;
                            cin>>gradeType;
                            if(gradeType!=1||gradeType!=2||gradeType!=3||gradeType!=4||gradeType!=5){
                                cout<<"Invalid option. Please select a valid option."<<endl;
                            }
                            else{
                                if(gradeType==1){
                                    cout<<"Overall grade stats, "<<endl;
                                    cout<<"min "<< instructor->getStudent(studentUser).getStudentName()<<endl;
                                }
                                wrongType=1;
                            }
                        }
                    }
                    else{
                        cout<<"Invalid option. Please enter a valid option."<<endl;
                    }
                }//userValid while loop
            }
            else{
                cout<<"Login as instructor failed"<<endl;
            }
        }//Person is 1 (Instructor)
        else if(person==2){
            //do student stuff
            cout<<"Enter credentials to login, Enter username:"<<endl;
            cin>>username;
            cout<<"Enter password: "<<endl;
            cin>>pass;
            Student *student=new Student();;
            student->login(username,pass);
            //checks if login attempt is valid
            if(student->login(username,pass)==true){
                cout<<"You are now logged in as student "<< student->getStudentName()<< "."<<endl;
                cout<<"Do you want to view grades (y/n)?"<<endl;
                cin>>viewGrades;
                if(viewGrades=="y"){
                    cout<<"Student name: "<<student->getStudentName()<<endl;
                    cout<<"Project"<<student->getProjectGrade()<<endl;
                    cout<<"Quiz"<<student->getQuizGrade()<<endl;
                    cout<<"Midterm"<<student->getMidtermGrade()<<endl;
                    cout<<"Final"<<student->getFinalGrade()<<endl;
                    cout<<"Overall"<<student->getOverallGrade()<<endl;
                }
                else{
                    delete student;
                }
            }
            else{
                cout<<"Login as student failed."<<endl;
            }
        }//if person 2 (Student)
        else{
            cout<<"Invalid option. Please enter a valid option."<<endl;
        }//if they did not input 1 or 2
    }//end of while lop
    if(person==3){
		  exit(0);
    }//exiting the loop
}//main method end loop
