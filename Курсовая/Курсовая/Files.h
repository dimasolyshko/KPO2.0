#pragma once
#include "ClassStudent.h"
bool CheckAdmin(string PathOfUserFile);
void DataAboutStudentsFromFile(string PathOfStudentFile, student* (&Member), int& n);
void OldDataAboutStudentsFromFile(string PathOfStudentFile, student* (&Member), int n);
void WriteInFileInfoAboutStudents(string PathOfStudentFile, student* (&Member), int& n);
void WriteInFileInfoAboutUsers(string PathOfUsersFile, User* (&Account), int& n);
void DataAboutUsersFromFile(string PathOfUsersFile, User* (&Account), int& n);
int CheckCountOfUsers(string PathOfUserFile);
void RedactUsers(string PathOfUsersFile, User* (&Account), int& n);
void OpenFile(string Path);