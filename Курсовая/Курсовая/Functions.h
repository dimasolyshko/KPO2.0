#pragma once
#include "ClassStudent.h"
#include "Files.h"
string Hash(string line);
void AddStudent(string PathOfStudentFile, student* (&Member), int& n);
void FindDataAbout(student* (&Member), int& n);
void ITask1(student* (&Member), int& n);
void ITask2(student* (&Member), int& n);
void SortMenu(student* (&Member), int& n);
void DeleteStudent(student* (&Member), int& n, int index);
void DeleteUser(User* (&user), int& n, int index);
string ValidationString();
double ValidationMark();
char ValidationFaculty();
