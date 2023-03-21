#pragma once
#include "ClassStudent.h"
#include "Files.h"
void Registration(string PathOfUserFile);
bool SignIn(string PathOfUserFile);
void AddStudent(string PathOfStudentFile, student* (&Member), int& n);
void AddUser(string PathOfUserFile);
void FindDataAboutStudent(student* (&Member), int& n);
void ITask1(student* (&Member), int& n);
void ITask2(student* (&Member), int& n);
void SortMark(student* (&Member), int& n);
void DeleteStudent(student* (&Member), int& n, int index);
void DeleteUser(User* (&user), int& n, int index);
string ValidationString();
double ValidationMark();
char ValidationFaculty();
string Hash(string line);
