#include "ClassStudent.h"
student::student()// Конструктор без параметров
{
    this->Surname = "";
    this->Name = "";
    this->Otch = "";
    this->NumberOfGroup = 0;
    this->mark = 0.00;
    this->Math = 0;
    this->Physics = 0;
    this->Programming = 0;
    this->English = 0;
    this->Database = 0;
}
//Конструктор с параметрами
student::student(string Fam, string Name, string Otch, int NumberOfGroup, double mark, char Math, char Physics, char Programming, char English, char Database)
{
    this->Surname = Fam;
    this->Name = Name;
    this->Otch = Otch;
    this->NumberOfGroup = NumberOfGroup;
    this->mark = mark;
    this->Math = Math;
    this->Physics = Physics;
    this->Programming = Programming;
    this->English = English;
    this->Database = Database;
}
//Сеттер для всех параметров
void student::SetParametrs(string Surname, string Name, string Otch, int NumberOfGroup, double mark, char Math, char Physics, char Programming, char English, char Database)
{
    this->Surname = Surname;
    this->Name = Name;
    this->Otch = Otch;
    this->NumberOfGroup = NumberOfGroup;
    this->mark = mark;
    this->Math = Math;
    this->Physics = Physics;
    this->Programming = Programming;
    this->English = English;
    this->Database = Database;
}
// Метод для вывода информации на экран
void student::Print()
{
    cout << "--------------------------------------------------------------------" << endl;
    cout << "ФИО студента: " << Surname << "  " << Name << "  " << Otch << endl;
    cout << "Номер Группы: " << NumberOfGroup << endl;
    cout << "Средний Балл студента: " << mark << endl;
    cout << "Факультатив по Математике (0 - Не записан, 1 - Записан) - " << Math << endl;
    cout << "Факультатив по Физике (0 - Не записан, 1 - Записан) - " << Physics << endl;
    cout << "Факультатив по Программированию (0 - Не записан, 1 - Записан) - " << Programming << endl;
    cout << "Факультатив по Английскому языку (0 - Не записан, 1 - Записан) - " << English << endl;
    cout << "Факультатив по Базам Данных (0 - Не записан, 1 - Записан) - " << Database << endl;
}
User::User()// Конструктор без параметров
{
    this->Login = "";
    this->Pass = "";
    this->Role = '0';
}
void User::Print()
{
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Логин:  |" << Login << endl;
    cout << "Пароль:|" << Pass << endl;
    cout << "Роль: |" << Role << endl;
}

