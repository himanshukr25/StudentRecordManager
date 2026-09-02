#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <limits>

#include "StudentManager.h"

using namespace std;

void addStudent(vector<Student>& students) {
    Student s;
    cout <<"Enter Name of Student: ";
    cin>> s.name;
    cout<<"Enter Branch :";
    cin>>s.branch;

    //Input for Roll number with edge case validation
     bool duplicate = false;
    do {
        duplicate= false;
    cout<<"Enter Roll Number :";
    cin>> s.rollNumber;
    if(s.rollNumber<=0) {
        cout<<"Invalid input! \nPlease enter a valid Roll Number" << endl;
    }
    
    for(int i=0;i<students.size();i++) {
        if(students[i].rollNumber==s.rollNumber) {
            duplicate = true;
            cout<<"This value is already taken. Please enter different Roll Number"<<endl;
        }
       
    }
    }while(s.rollNumber<=0 || duplicate);
    //Input for CGPA with edge cases validation
    do {
    cout<<"Enter CGPA:";
    cin>> s.cgpa;
    if(s.cgpa < 0 || s.cgpa >10) {
        cout <<"Invalid Input! Please enter value between 0 to 10"<<endl;
    }
    }while(s.cgpa<0 || s.cgpa >10);

    students.push_back(s);
}

void displayStudents(vector<Student>& students) {
    if(students.empty()) {
    cout << "No student records available.\n";
    return;
    }

      cout << setw(10) << "Roll No."
         << setw(20) << "Name"
         << setw(15) << "Branch"
         << setw(10) << "CGPA" << endl;

    cout << "-------------------------------------------------------\n";
    for(int i=0;i<students.size();i++) {
        cout << setw(10) << students[i].rollNumber
             << setw(20) << students[i].name
             << setw(15) << students[i].branch
             << setw(10) << students[i].cgpa
             << endl;
    }
    
    }

    void searchStudent(const vector<Student>&students,int targetRoll) {
        bool recordFound=false;
        for(int i=0;i<students.size();i++) {
            if(students[i].rollNumber==targetRoll) {
            cout << "\n Student Found" << endl;
                cout<<"Name:        "<<students[i].name<<endl;
                cout<<"Branch:      "<<students[i].branch<<endl;
                cout<<"Roll Number: "<<students[i].rollNumber<<endl;
                cout<<"CGPA:        "<<students[i].cgpa<<endl;
                recordFound = true;
                break;
            }
        }
            if(!recordFound){
                cout<<"\nStudent with Roll NUmber"<<targetRoll<<"not found."<<endl;   
        }
    }

void deleteStudent(vector<Student>& students, int targetRoll) {
    bool found = false;
    for(int i=0;i<students.size();i++) {
        if(students[i].rollNumber==targetRoll) {
            students.erase(students.begin()+i);
            cout << "Deleted Successfully" << endl;
            found = true;
            break;

        }
    }
    if(!targetRoll) {
        cout << "Invalid Request!"<< endl;
    }
}

void updateStudent(vector<Student>& students, int targetRoll) {
    bool found = false;

    for(int i = 0; i < students.size(); i++) {
        if(students[i].rollNumber == targetRoll) {

            found = true;

            cout << "Existing Record Found:\n";
            cout << "Name: " << students[i].name
                 << " | Branch: " << students[i].branch
                 << " | Roll Number: " << students[i].rollNumber
                 << " | CGPA: " << students[i].cgpa << "\n";

            cout << "\nEnter new details:\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "New Name: ";
            getline(cin, students[i].name);

            cout << "New Branch: ";
            getline(cin, students[i].branch);

            cout << "New CGPA: ";
            cin >> students[i].cgpa;

            cout << "\nRecords updated successfully!\n";

            break;
        }
    }

    if(!found) {
        cout << "Student with Roll Number "
             << targetRoll << " not found.\n";
    }
}

//Sorting details accordingly
void sortStudents(vector<Student>& students) {

    int choose;
    cout << "\n===== Sort Students =====\n";
    cout << "1. Sort by Roll Number\n";
    cout << "2. Sort by Name\n";
    cout << "3. Sort by CGPA\n";
    cout << "Enter your choice: ";
    cin >> choose;

    switch(choose) {

        case 1:
            sort(students.begin(), students.end(),
                 [](const Student& a, const Student& b) {
                     return a.rollNumber < b.rollNumber;
                 });
            cout << "Sorted by Roll Number.\n";
            break;

        case 2:
            sort(students.begin(), students.end(),
                 [](const Student& a, const Student& b) {
                     return a.name < b.name;
                 });
            cout << "Sorted by Name.\n";
            break;

        case 3:
            sort(students.begin(), students.end(),
                 [](const Student& a, const Student& b) {
                     return a.cgpa > b.cgpa;
                 });
            cout << "Sorted by CGPA (Highest to Lowest).\n";
            break;

        default:
            cout << "Invalid Choice!\n";
    }
}

void saveStudents(const vector<Student>& students) {
    ofstream file("students.txt");

    if(!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    for(int i = 0; i < students.size(); i++) {
        file << students[i].name << " "
             << students[i].branch << " "
             << students[i].rollNumber << " "
             << students[i].cgpa << endl;
    }

    file.close();
}

void loadStudents(vector<Student>& students) {
    ifstream file("students.txt");

    Student s;

    while(file >> s.name >> s.branch >> s.rollNumber >> s.cgpa) {
        students.push_back(s);
    }

    file.close();
}