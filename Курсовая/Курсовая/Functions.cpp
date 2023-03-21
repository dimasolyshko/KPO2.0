#include "Functions.h"
void Registration(string PathOfUserFile)
{
	bool NewUser = true;
	int number;
	string login, Pass, CorrectLogin, str;
	while (NewUser) // Цикл, который будет проходить пока не будет успешно проверен логин на уникальность будущего аккаунта!
	{
		NewUser = false;
		cout << "Введите логин вашего аккаунта: ";
		cin >> login;
		ifstream fin;
		fin.open(PathOfUserFile);
		if (!fin.is_open()) cout << "Файл не открыт!" << endl;
		else
		{
			while (!fin.eof())
			{
				fin >> CorrectLogin;
				fin >> str;
				fin >> str;
				if (CorrectLogin == login) // Проверка на уникальность введённого логина
				{
					cout << "Такой логин уже существует попробуйте другой" << endl;
					NewUser = true;
					CorrectLogin = "";
				}
			}
		}
		fin.close();
	}
	cout << "Введите пароль вашего аккаунта: ";
	cin >> Pass;
	Pass = Hash(Pass);
	ofstream fout;
	fout.open(PathOfUserFile, ios::app);
	if (!fout.is_open()) cout << "Файл не открыт!" << endl;
	else // Запись данных об аккаунте в файл
	{
		fout << login << endl;
		fout << Pass << endl;
		fout << "0" << endl;
	}
	cout << "Вы успешно зарегистрировались, Ваш логин " << login << endl;
	fout.close();
}
bool SignIn(string PathOfUserFile)
{
	bool end = true, Role = false;
	while (end) //Добавляем цикл, который будет проходить пока мы не войдём в аккаунт успешно!
	{
		end = true;
		ifstream fin;
		fin.open(PathOfUserFile);
		if (!fin.is_open())
		{
			cout << "Файл не открыт!" << endl;
		}
		else
		{
			string login, Pass, CorrectLogin, CorrectPass;
			cout << "Введите Логин: ";
			cin >> login;
			cout << "Введите Пароль: ";
			cin >> Pass;
			Pass = Hash(Pass);
			while (!fin.eof() && end) // Проходим по файлу до конца или до совпадения логина или пароля
			{
				fin >> CorrectLogin;
				fin >> CorrectPass;
				fin >> Role;
				if (login == CorrectLogin && Pass == CorrectPass) // Проверка на совпадение пароля и логина
				{
					cout << "Вы успешно вошли в аккаунт!" << endl;
					end = false;
				}
			}
			if (end) cout << "Вы неправильно ввели Пароль или Логин!\nПопробуйте снова" << endl;
		}
		fin.close();
	}
	return Role; // Возвращаем роль
}
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
void AddUser(string PathOfUserFile)
{
	string login, Pass, CorrectLogin,str;
	bool NewUser = true;
		while (NewUser) // Цикл, который будет проходить пока не будет успешно проверен логин на уникальность будущего аккаунта!
		{
			NewUser = false;
			cout << "Введите логин аккаунта: ";
			cin >> login;
			ifstream fin;
			fin.open(PathOfUserFile);
			if (!fin.is_open()) cout << "Файл не открыт!" << endl;
			else
			{
				while (!fin.eof())
				{
					fin >> CorrectLogin;
					fin >> str;
					fin >> str;
					if (CorrectLogin == login) // Проверка на уникальность введённого логина
					{
						cout << "Такой логин уже существует попробуйте другой" << endl;
						NewUser = true;
						CorrectLogin = "";
					}
				}
			}
			fin.close();
		}
	cout << "Введите пароль аккаунта: ";
	cin >> Pass;
	Pass = Hash(Pass);
	ofstream fout;
	fout.open(PathOfUserFile, ios::app);
	if (!fout.is_open()) cout << "Файл не открыт!" << endl;
	else // Запись данных об аккаунте в файл
	{
		fout << login << endl;
		fout << Pass << endl;
		fout << "0" << endl;
	}
	cout << "Вы успешно Добавили пользователя" << endl;
	fout.close();
}
void SortMark(student* (&Member), int& n)
{
	cout << "Выполнение сортировки по Среднему баллу" << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (Member[j].GetMark() > Member[j + 1].GetMark()) swap(Member[j], Member[j + 1]);
		}
	}
	cout << "Сортировка выполнена успешно!" << endl;
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
		for (int i = 0; i < str.length(); i++)
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
void FindDataAboutStudent(student* (&Member), int& n)
{
	system("cls");
	cout << "Поиск по фамилии" << endl;
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
}
void ITask1(student* (&Member), int& n)
{
	setlocale(LC_ALL, "ru");
	SortMark(Member, n);
	system("cls");
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

