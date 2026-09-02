#include <iostream>
#include <vector>

#include "StudentManager.h"

using namespace std;


int main() {
   vector<Student> students;
    loadStudents(students);
    
   int choice;
   do {
   cout<<"Student Record Manager" << endl;
   cout <<"1. Add Student" << endl;
   cout <<"2. Display Student"<<endl;
   cout <<"3. Search Student"<<endl;
   cout <<"4. Delete Student"<<endl;
   cout <<"5. Update Details"<<endl;
   cout <<"6. Sort students"<< endl;
   cout <<"7. Save Students"<< endl;
   cout <<"8. Exit"<<endl;
   cout << "\nEnter your choice : ";
   cin >> choice;

   switch(choice) 
   {
    case 1 :
    addStudent(students);
    break;

    case 2 :
        displayStudents(students);
        break;

    case 3 : {
        int rollNo;
        cout <<"Enter roll number"<<endl;
        cin >> rollNo;
        searchStudent(students,rollNo);
        break;
        }
    
    case 4 : {
        int roll;
        cout << "Enter Roll Number" << endl;
        cin >> roll;
        deleteStudent(students,roll);
        break;
    }

    case 5 : {
        int rollNo;
        cout<<"Enter roll Number:" <<endl;
        cin >> rollNo; 
        updateStudent(students,rollNo);
        break;
    }

    case 6 :
        sortStudents(students);
        break;

    case 7 :
        saveStudents(students);
        break;
    
     case 8 : {
        saveStudents(students);
        cout << "\nRecords saved successfully!";
         cout << "\nExiting..." <<endl;
         break;
        }
    
    default : 
        cout <<"\nInvalid Choice!" << endl;

   }
    
    }while(choice !=8); 


    
     return 0;
 }