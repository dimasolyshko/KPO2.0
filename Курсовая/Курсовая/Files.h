#pragma once
#include "ClassStudent.h"
void ReadFromFileAboutUsers(string PathOfUserFile);
bool CheckAdmin(string PathOfUserFile);
void DataAboutStudentsFromFile(string PathOfStudentFile, student* (&Member), int& n);
void WriteInFileInfoAboutStudents(string PathOfStudentFile, student* (&Member), int& n);