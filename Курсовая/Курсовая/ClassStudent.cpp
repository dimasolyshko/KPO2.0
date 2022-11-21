#include "ClassStudent.h"
student::student()// ����������� ��� ����������
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
//����������� � �����������
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
//������ ��� ���� ����������
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
// ����� ��� ������ ���������� �� �����
void student::Print()
{
    cout << "--------------------------------------------------------------------" << endl;
    cout << "��� ��������: " << Surname << "  " << Name << "  " << Otch << endl;
    cout << "����� ������: " << NumberOfGroup << endl;
    cout << "������� ���� ��������: " << mark << endl;
    cout << "����������� �� ���������� (0 - �� �������, 1 - �������) - " << Math << endl;
    cout << "����������� �� ������ (0 - �� �������, 1 - �������) - " << Physics << endl;
    cout << "����������� �� ���������������� (0 - �� �������, 1 - �������) - " << Programming << endl;
    cout << "����������� �� ����������� ����� (0 - �� �������, 1 - �������) - " << English << endl;
    cout << "����������� �� ����� ������ (0 - �� �������, 1 - �������) - " << Database << endl;
}
User::User()// ����������� ��� ����������
{
    this->Login = "";
    this->Pass = "";
    this->Role = '0';
}
void User::Print()
{
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "�����:  |" << Login << endl;
    cout << "������:|" << Pass << endl;
    cout << "����: |" << Role << endl;
}

