#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <vector>
#include "Student.h"

void addStudent(std::vector<Student>& students);
void displayStudents( std::vector<Student>& students);
void searchStudent(const std::vector<Student>& students, int targetRoll);
void deleteStudent(std::vector<Student>& students, int targetRoll);
void updateStudent(std::vector<Student>& students, int targetRoll);
void sortStudents(std::vector<Student>& students);

void saveStudents(const std::vector<Student>& students);
void loadStudents(std::vector<Student>& students);

#endif