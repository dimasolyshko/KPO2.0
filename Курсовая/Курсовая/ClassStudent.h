#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
class student
{
private:
    string Surname, Name, Otch; //��� ��������
    int NumberOfGroup; // ����� ������ ��������
    double mark; //������� ���� ��������
    char Math, Physics, Programming, English, Database; // ������������
public:
    student(); // ����������� ��� ����������
    student(string Fam, string Name, string Otch, int NumberOfGroup, double mark, char Math, char Physics, char Programming, char English, char Database);
    void SetParametrs(string Surname, string Name, string Otch, int NumberOfGroup, double mark, char Math, char Physics, char Programming, char English, char Database);
    string GetSurName() { return Surname; } // ������ ��� �������
    string GetName() { return Name; } // ������ ��� �����
    string GetOtch() { return Otch; } // ������ ��� ��������
    int GetNumberOfGroup() { return NumberOfGroup; } // ������ ��� ������ ������
    double GetMark() { return mark; }// ������ ��� �������� �����
    char GetMath() { return Math; } //������ ��� ������������ �� ����������
    char GetPhysics() { return Physics; } //������ ��� ������������ �� ������
    char GetProgramming() { return Programming; } //������ ��� ������������ �� ����������������
    char GetEnglish() { return English; } //������ ��� ������������ �� �����������
    char GetDataBase() { return Database; } //������ ��� ������������ �� ��
    void Print(); //����� ���������� � ��������
    ~student() {}; //����������
};
class User
{
public:
    string Login;
    string Pass;
    char Role;
    User();
    ~User() {};
    
};