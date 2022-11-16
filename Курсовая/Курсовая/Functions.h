#pragma once
#include "ClassStudent.h"
#include "Files.h"
void AddStudent(string PathOfStudentFile, student* (&Member), int& n);
void FindDataAbout(student* (&Member), int& n);
