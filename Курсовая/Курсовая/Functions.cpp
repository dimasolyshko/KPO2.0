#include "Functions.h"
void AddStudent(string PathOfStudentFile, student* (&Member), int& n)
{

	string Surname, Name, Otch;
	int NumberOfGroup;
	double mark;
	char Math, Physics, Programming, English, Database;
	n++;
	Member = new student[n];
	OldDataAboutStudentsFromFile(PathOfStudentFile, Member, n - 1); // ����� ��������� ������ ��������� ������ ��� ������� ���������
	cout << "������� ���: ";
	cin >> Surname >> Name >> Otch;
	cout << "������� ����� ������: ";
	cin >> NumberOfGroup;
	cout << "������� ������� ����: ";
	cin >> mark;
	cout << "������� �� �� ����������� �� ���������� �������(� - ���, 1 - ��): ";
	cin >> Math;
	cout << "������� �� �� ����������� �� ������ �������(� - ���, 1 - ��): ";
	cin >> Physics;
	cout << "������� �� �� ����������� �� ����������������� �������(� - ���, 1 - ��): ";
	cin >> Programming;
	cout << "������� �� �� ����������� �� ����������� �������(� - ���, 1 - ��): ";
	cin >> English;
	cout << "������� �� �� ����������� �� ����� ������ �������(� - ���, 1 - ��): ";
	cin >> Database;
	Member[n-1].SetParametrs(Surname, Name, Otch, NumberOfGroup, mark, Math, Physics, Programming, English, Database);
}
void FindDataAbout(student* (&Member), int& n)
{
	int number;
	cout << "������� �� ����� ������ ������ ������: " <<
		"\n1 - �� �������" <<
		"\n2 - �� �����" <<
		"\n3 - �� ��������" << endl;
	cin >> number;
	switch (number)
	{
	case 1:
	{
		string Surname;
		cout << "������� ������� ��� ������ ";
		cin >> Surname;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetSurName() == Surname)
			{
				cout << "����� ���������� �������� : " << i + 1 << endl;
				Member[i].Print();
			}
		}
		break;
	}
	case 2:
	{
		string Name;
		cout << "������� ������� ��� ������ ";
		cin >> Name;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetSurName() == Name)
			{
				cout << "����� ���������� �������� : " << i + 1 << endl;
				Member[i].Print();
			}
		}
		break;
	}
	case 3:
	{
		string Otch;
		cout << "������� ������� ��� ������ ";
		cin >> Otch;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetSurName() == Otch)
			{
				cout << "����� ���������� �������� : " << i + 1 << endl;
				Member[i].Print();
			}
		}
		break;
	}
	default:
	{
		cout << "������������ ����� ��������" << endl;
		break;
	}
	}
}