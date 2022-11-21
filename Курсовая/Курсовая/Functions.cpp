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
		"\n3 - По отчеству" << 
		"\n4 - По Номеру группы" <<
		"\n5 - По Среднему баллу" <<endl;	    
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
	case 4:
	{
		int NumberOfGroup;
		cout << "Введите номер группы для поиска ";
		cin >> NumberOfGroup;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetNumberOfGroup() == NumberOfGroup)
			{
				cout << "Номер найденного студента : " << i + 1 << endl;
				Member[i].Print();
			}
		}
		break;
	}
	case 5:
	{
		double Mark;
		cout << "Введите Средний балл для поиска ";
		cin >> Mark;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetMark() == Mark)
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
void SortMenu(student* (&Member), int& n)
{
	int number;
	cout << "Введите по каким данных хотите cортировать: " <<
		"\n1 - По фамилии" <<
		"\n2 - По имени" <<
		"\n3 - По отчеству" <<
		"\n4 - По Номеру группы" <<
		"\n5 - По Среднему баллу" << endl;
	cin >> number;
	switch (number)
	{
	case 1:
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (Member[j].GetSurName() > Member[j+1].GetSurName()) swap(Member[j], Member[j + 1]);
			}
		}
		cout << "Сортировка выполнена успешно!" << endl;
		break;
	}
	case 2:
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (Member[j].GetName() > Member[j + 1].GetName()) swap(Member[j], Member[j + 1]);
			}
		}
		cout << "Сортировка выполнена успешно!" << endl;
		break;
	}
	case 3:
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (Member[j].GetOtch() > Member[j + 1].GetOtch()) swap(Member[j], Member[j + 1]);
			}
		}
		cout << "Сортировка выполнена успешно!" << endl;
		break;
	}
	case 4:
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (Member[j].GetNumberOfGroup() > Member[j + 1].GetNumberOfGroup()) swap(Member[j], Member[j + 1]);
			}
		}
		cout << "Сортировка выполнена успешно!" << endl;
		break;
	}
	case 5:
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (Member[j].GetMark() > Member[j + 1].GetMark()) swap(Member[j], Member[j + 1]);
			}
		}
		cout << "Сортировка выполнена успешно!" << endl;
		break;
	}
	default:
	{
		cout << "Неправильный номер операции" << endl;
		break;
	}
	}
}
void ITask(student* (&Member), int& n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (Member[j].GetMark() > Member[j + 1].GetMark()) swap(Member[j], Member[j + 1]);
		}
	}
	int count = 0;
    string x;
	cout << "Введите Какой факультатив вас интересует: ";
	cin >> x;
	if(x == "Maths" || x == "maths")
	{
		for (int i = n-1; i >=0; i--)
		{
			if (Member[i].GetMath() == '1' && count < 15)
			{
				Member[i].Print();
				count++;
			}
		}
	}
	else if (x == "Physics" || x == "physics")
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int count = 0;
			if (Member[i].GetPhysics() == '1' && count < 15)
			{
				Member[i].Print();
				count++;
			}
		}
	}
	else if (x == "Programming" || x == "programming")
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int count = 0;
			if (Member[i].GetProgramming() == '1' && count < 15)
			{
				Member[i].Print();
				count++;
			}
		}
	}
	else if (x == "English" || x == "english")
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int count = 0;
			if (Member[i].GetEnglish() == '1' && count < 15)
			{
				Member[i].Print();
				count++;
			}
		}
	}
	else if (x == "Database" || x == "database")
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int count = 0;
			if (Member[i].GetDataBase() == '1' && count < 15)
			{
				Member[i].Print();
				count++;
			}
		}
	}
	else
	{
		cout << "Такого факультатива не существует" << endl;
	}
}