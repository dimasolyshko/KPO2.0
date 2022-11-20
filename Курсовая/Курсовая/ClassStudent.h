#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
class student
{
private:
    string Surname, Name, Otch; //ФИО студента
    int NumberOfGroup; // Номер группы студента
    double mark; //Средний балл студента
    char Math, Physics, Programming, English, Database; // Факультативы
public:
    student(); // Конструктор без параметров
    student(string Fam, string Name, string Otch, int NumberOfGroup, double mark, char Math, char Physics, char Programming, char English, char Database);
    void SetParametrs(string Surname, string Name, string Otch, int NumberOfGroup, double mark, char Math, char Physics, char Programming, char English, char Database);
    string GetSurName() { return Surname; } // геттер для фамилии
    string GetName() { return Name; } // геттер для Имени
    string GetOtch() { return Otch; } // геттер для Отчества
    int GetNumberOfGroup() { return NumberOfGroup; } // геттер для номера группы
    double GetMark() { return mark; }// геттер для среднего балла
    char GetMath() { return Math; } //геттер для факультатива по математике
    char GetPhysics() { return Physics; } //геттер для факультатива по физике
    char GetProgramming() { return Programming; } //геттер для факультатива по программированию
    char GetEnglish() { return English; } //геттер для факультатива по английскому
    char GetDataBase() { return Database; } //геттер для факультатива по БД
    void Print(); //Вывод Информации о студенте
    ~student() {}; //Деструктор
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