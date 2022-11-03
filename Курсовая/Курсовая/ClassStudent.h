#pragma once
#include <iostream>
#include <fstream>
#include <string>
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
    string GetSurName(string Surname) { return Surname; } // геттер для фамилии
    string GetName(string Name) { return Name; } // геттер для Имени
    string GetOtch(string Otch) { return Otch; } // геттер для Отчества
    int GetNumberOfGroup(int Number) { return Number; } // геттер для номера группы
    double GetMark(double mark) { return mark; }// геттер для среднего балла
    char GetMath(char Math) { return Math; } //геттер для факультатива по математике
    char GetPhysics(char Physics) { return Physics; } //геттер для факультатива по физике
    char GetProgramming(char Programming) { return Programming; } //геттер для факультатива по программированию
    char GetEnglish(char English) { return English; } //геттер для факультатива по английскому
    char GetDataBase(char db) { return db; } //геттер для факультатива по БД
    void Print(); //Вывод Информации о студенте
    ~student() {}; //Деструктор
};