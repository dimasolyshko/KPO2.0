#pragma once
#include "ClassStudent.h"
#include "Files.h"
string Hash(string line);
void AddStudent(string PathOfStudentFile, student* (&Member), int& n);
void FindDataAbout(student* (&Member), int& n);
void ITask(student* (&Member), int& n);
void SortMenu(student* (&Member), int& n);
string ValidationString();
double ValidationMark();
char ValidationFaculty();
