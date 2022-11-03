#pragma once
#include <iostream>
#include <fstream>
#include <string>
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
    string GetSurName(string Surname) { return Surname; } // ������ ��� �������
    string GetName(string Name) { return Name; } // ������ ��� �����
    string GetOtch(string Otch) { return Otch; } // ������ ��� ��������
    int GetNumberOfGroup(int Number) { return Number; } // ������ ��� ������ ������
    double GetMark(double mark) { return mark; }// ������ ��� �������� �����
    char GetMath(char Math) { return Math; } //������ ��� ������������ �� ����������
    char GetPhysics(char Physics) { return Physics; } //������ ��� ������������ �� ������
    char GetProgramming(char Programming) { return Programming; } //������ ��� ������������ �� ����������������
    char GetEnglish(char English) { return English; } //������ ��� ������������ �� �����������
    char GetDataBase(char db) { return db; } //������ ��� ������������ �� ��
    void Print(); //����� ���������� � ��������
    ~student() {}; //����������
};