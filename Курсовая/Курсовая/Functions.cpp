#include "Functions.h"
string Hash(string line) {
	unsigned long hash = 0, degree = 176;
	for (char c : line) {
		hash = degree * hash + (unsigned long)c;
	}
	return to_string(hash);
}
void AddStudent(string PathOfStudentFile, student* (&Member), int& n)
{

	string Surname, Name, Otch;
	int NumberOfGroup;
	double mark;
	char Math, Physics, Programming, English, Database;
	n++;
	Member = new student[n];
	OldDataAboutStudentsFromFile(PathOfStudentFile, Member, n - 1); // После выделения памяти считываем Данные про прошлых студентов
	cout << "Введите фамилию: ";
	Surname = ValidationString();
	cout << "Введите имя: ";
	Name = ValidationString();
	cout << "Введите отчество: ";
	Otch = ValidationString();
	cout << "Введите Номар группы: ";
	cin >> NumberOfGroup;
	cout << "Введите средний балл: ";
	mark = ValidationMark();
	cout << "Записан ли на факультатив по математике студент(о - нет, 1 - да): ";
	Math = ValidationFaculty();
	cout << "Записан ли на факультатив по физике студент(о - нет, 1 - да): ";
	Physics = ValidationFaculty();
	cout << "Записан ли на факультатив по программмированию студент(о - нет, 1 - да): ";
    Programming = ValidationFaculty();
	cout << "Записан ли на факультатив по английскому студент(о - нет, 1 - да): ";
	English = ValidationFaculty();
	cout << "Записан ли на факультатив по Базам данных студент(о - нет, 1 - да): ";
	Database = ValidationFaculty();
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
void ITask1(student* (&Member), int& n)
{
	setlocale(LC_ALL, "ru");
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (Member[j].GetMark() > Member[j + 1].GetMark()) swap(Member[j], Member[j + 1]);
		}
	}
	int count = 0;
    string x;
	cout << "Введите Какой факультатив вас интересует (На английском языке) > ";
	cin >> x;
	if(x == "Maths" || x == "maths")
	{
		for (int i = n-1; i >=0; i--)
		{
			if (Member[i].GetMath() == '1')
			{
				if (count < 15) Member[i].Print();
				count++;
			}
		}
		cout << "\nобщее число желающих прослушать математику > " << count << endl;
	}
	else if (x == "Physics" || x == "physics")
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int count = 0;
			if (Member[i].GetPhysics() == '1')
			{
				if (count < 15) Member[i].Print();
				count++;
			}
		}
		cout << "\nобщее число желающих прослушать физику > " << count << endl;
	}
	else if (x == "Programming" || x == "programming")
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (Member[i].GetProgramming() == '1')
			{
				if (count < 15) Member[i].Print();
				count++;
			}
		}
		cout << "\nобщее число желающих прослушать программирование > " << count << endl;
	}
	else if (x == "English" || x == "english")
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (Member[i].GetEnglish() == '1')
			{
				if (count < 15) Member[i].Print();
				count++;
			}
		}
		cout << "\nобщее число желающих прослушать английский язык > " << count << endl;
	}
	else if (x == "Database" || x == "database")
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (Member[i].GetDataBase() == '1')
			{
				if (count < 15) Member[i].Print();
				count++;
			}
		}
		cout << "\nобщее число желающих прослушать факультатив по Базам Данных > " << count << endl;
	}
	else
	{
		cout << "Такого факультатива не существует" << endl;
	}
}
void ITask2(student* (&Member), int& n)
{
	string Faculties[5] = { "Математика","Физика","Программирование","Английский язык","База Данных" };
	int Count[5] = {0,0,0,0,0};
	for (int i = 0; i < n; i++)
	{
		if (Member[i].GetMath() == '1')	Count[0]++;
		if (Member[i].GetPhysics() == '1')	Count[1]++;
		if (Member[i].GetProgramming() == '1')	Count[2]++;
		if (Member[i].GetEnglish() == '1')	Count[3]++;
		if (Member[i].GetDataBase() == '1')	Count[4]++;
	}
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (Count[j] > Count[j + 1])
			{
				swap(Count[j], Count[j + 1]);
				swap(Faculties[j], Faculties[j + 1]);
			}
		}
	}
	for (int i = 4; i >= 0; i--)
	{
		cout << endl << Faculties[i] << " > " << Count[i] << endl;
	}
}
void DeleteStudent(student* (&Member), int& n, int index)
{
	index--;
	student* Buffer = new student[n];
	for (size_t i = 0; i < n; i++)
	{
		Buffer[i] = Member[i];
	}
	n--;
	Member = new student[n];
	for (size_t i = 0; i < n; i++)
	{
		if (i < index) Member[i] = Buffer[i];
		else if (i >= index) Member[i] = Buffer[i + 1];
	}
	cout << "Данный студент удалён:" << endl;
	Buffer[index].Print();
}
void DeleteUser(User* (&user), int& n, int index)
{
	User* Buffer = new User[n];
	for (size_t i = 0; i < n; i++)
	{
		Buffer[i] = user[i];
	}
	n--;
	user = new User[n];
	for (size_t i = 0; i < n; i++)
	{
		if (i < index) user[i] = Buffer[i];
		else if (i >= index) user[i] = Buffer[i + 1];
	}
	cout << "Данный пользователь удалён:" << endl;
	Buffer[index].Print();
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
		if (!IsValue) cout << "Ошибка валидации, попробуйте снова!" << endl;
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
			cout << "Ошибка валидации, попробуйте снова!" << endl;
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
			cout << "Ошибка валидации, попробуйте снова!" << endl;
		}
	} while (!IsValue);
	return x;
}
