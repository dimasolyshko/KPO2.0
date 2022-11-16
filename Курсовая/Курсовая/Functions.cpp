#include "Functions.h"
void AddStudent(string PathOfStudentFile, student* (&Member), int& n)
{

	string Surname, Name, Otch;
	int NumberOfGroup;
	double mark;
	char Math, Physics, Programming, English, Database;
	n++;
	Member = new student[n];
	OldDataAboutStudentsFromFile(PathOfStudentFile, Member, n - 1); // После выделения памяти считываем Данные про прошлых студентов
	cout << "Введите ФИО: ";
	cin >> Surname >> Name >> Otch;
	cout << "Введите Номар группы: ";
	cin >> NumberOfGroup;
	cout << "Введите средний балл: ";
	cin >> mark;
	cout << "Записан ли на факультатив по математике студент(о - нет, 1 - да): ";
	cin >> Math;
	cout << "Записан ли на факультатив по физике студент(о - нет, 1 - да): ";
	cin >> Physics;
	cout << "Записан ли на факультатив по программмированию студент(о - нет, 1 - да): ";
	cin >> Programming;
	cout << "Записан ли на факультатив по английскому студент(о - нет, 1 - да): ";
	cin >> English;
	cout << "Записан ли на факультатив по Базам данных студент(о - нет, 1 - да): ";
	cin >> Database;
	Member[n-1].SetParametrs(Surname, Name, Otch, NumberOfGroup, mark, Math, Physics, Programming, English, Database);
}
void FindDataAbout(student* (&Member), int& n)
{
	int number;
	cout << "Введите по каким данных хотите искать: " <<
		"\n1 - По фамилии" <<
		"\n2 - По имени" <<
		"\n3 - По отчеству" << endl;
	cin >> number;
	switch (number)
	{
	case 1:
	{
		string Surname;
		cout << "Введите фамилию для поиска ";
		cin >> Surname;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetSurName() == Surname)
			{
				cout << "Номер найденного студента : " << i + 1 << endl;
				Member[i].Print();
			}
		}
		break;
	}
	case 2:
	{
		string Name;
		cout << "Введите фамилию для поиска ";
		cin >> Name;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetSurName() == Name)
			{
				cout << "Номер найденного студента : " << i + 1 << endl;
				Member[i].Print();
			}
		}
		break;
	}
	case 3:
	{
		string Otch;
		cout << "Введите фамилию для поиска ";
		cin >> Otch;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetSurName() == Otch)
			{
				cout << "Номер найденного студента : " << i + 1 << endl;
				Member[i].Print();
			}
		}
		break;
	}
	default:
	{
		cout << "Неправильный номер операции" << endl;
		break;
	}
	}
}