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
	cout << "������� �������: ";
	Surname = ValidationString();
	cout << "������� ���: ";
	Name = ValidationString();
	cout << "������� ��������: ";
	Otch = ValidationString();
	cout << "������� ����� ������: ";
	cin >> NumberOfGroup;
	cout << "������� ������� ����: ";
	mark = ValidationMark();
	cout << "������� �� �� ����������� �� ���������� �������(� - ���, 1 - ��): ";
	Math = ValidationFaculty();
	cout << "������� �� �� ����������� �� ������ �������(� - ���, 1 - ��): ";
	Physics = ValidationFaculty();
	cout << "������� �� �� ����������� �� ����������������� �������(� - ���, 1 - ��): ";
    Programming = ValidationFaculty();
	cout << "������� �� �� ����������� �� ����������� �������(� - ���, 1 - ��): ";
	English = ValidationFaculty();
	cout << "������� �� �� ����������� �� ����� ������ �������(� - ���, 1 - ��): ";
	Database = ValidationFaculty();
	Member[n-1].SetParametrs(Surname, Name, Otch, NumberOfGroup, mark, Math, Physics, Programming, English, Database);
}
void FindDataAbout(student* (&Member), int& n)
{
	int number;
	cout << "������� �� ����� ������ ������ ������: " <<
		"\n1 - �� �������" <<
		"\n2 - �� �����" <<
		"\n3 - �� ��������" << 
		"\n4 - �� ������ ������" <<
		"\n5 - �� �������� �����" <<endl;	    
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
	case 4:
	{
		int NumberOfGroup;
		cout << "������� ����� ������ ��� ������ ";
		cin >> NumberOfGroup;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetNumberOfGroup() == NumberOfGroup)
			{
				cout << "����� ���������� �������� : " << i + 1 << endl;
				Member[i].Print();
			}
		}
		break;
	}
	case 5:
	{
		double Mark;
		cout << "������� ������� ���� ��� ������ ";
		cin >> Mark;
		for (int i = 0; i < n; i++)
		{
			if (Member[i].GetMark() == Mark)
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
void SortMenu(student* (&Member), int& n)
{
	int number;
	cout << "������� �� ����� ������ ������ c����������: " <<
		"\n1 - �� �������" <<
		"\n2 - �� �����" <<
		"\n3 - �� ��������" <<
		"\n4 - �� ������ ������" <<
		"\n5 - �� �������� �����" << endl;
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
		cout << "���������� ��������� �������!" << endl;
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
		cout << "���������� ��������� �������!" << endl;
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
		cout << "���������� ��������� �������!" << endl;
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
		cout << "���������� ��������� �������!" << endl;
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
		cout << "���������� ��������� �������!" << endl;
		break;
	}
	default:
	{
		cout << "������������ ����� ��������" << endl;
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
	cout << "������� ����� ����������� ��� ����������: ";
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
		cout << "������ ������������ �� ����������" << endl;
	}
}
string ValidationString()
{
	string str;
	bool IsValue = true;
	do
	{
		IsValue = true;
		cin >> str;
		for  (int i = 0; i < str.length(); i++)
		{
			if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123));
			else IsValue = false;
		}
		if (!IsValue) cout << "������ ���������, ���������� �����!" << endl;
	} while (!IsValue);
	return str;
}
double ValidationMark()
{
	double mark;
	bool IsValue = true;
	do
	{
		IsValue = true;
		cin >> mark;
		if (mark < 0 || mark > 10.0)
		{
			IsValue = false;
			cout << "������ ���������, ���������� �����!" << endl;
		}
	} while (!IsValue);
	return mark;
}
char ValidationFaculty()
{
	char x;
	bool IsValue = true;
	do
	{
		IsValue = true;
		cin >> x;
		if (x == '0' || x == '1');
		else
		{
			IsValue = false;
			cout << "������ ���������, ���������� �����!" << endl;
		}
	} while (!IsValue);
	return x;
}