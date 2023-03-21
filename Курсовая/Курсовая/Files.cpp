#include "Files.h"
#include "Functions.h"
bool Authorization(string PathOfUserFile)
{
    while (true)
    {
        cout << "Вам необходимо Зарегистрироваться, или войти в аккаунт!\nЕсли хотите Зарегистрироваться напишите 0, если хотите войти в аккаунт напишите 1: ";
        int number;
        cin >> number;
        if (number == 0)
        {
            Registration(PathOfUserFile);
            return false;
        }
        else if (number == 1)
        {
            bool roll = SignIn(PathOfUserFile);
            return roll;
        }
        else cout << "Ошибка!Вы не ввели 1 либо 0\nПопробуйте снова!" << endl;
    }
}
void DataAboutStudentsFromFile(string PathOfStudentFile, student *(&Member), int &n)
{
    setlocale(LC_ALL, "ru");
    ifstream fin;
    fin.open(PathOfStudentFile);
    if (!fin.is_open())
    {
        cout << "Файл не открыт!" << endl;
    }
    else
    {
        fin >> n;
        string Surname, Name, Otch;
        int NumberOfGroup;
        double mark;
        char Math, Physics, Programming, English, Database;
        Member = new student[n];
        for (int i = 0; i < n; i++)
        {
            fin >> Surname >> Name >> Otch;
            fin >> NumberOfGroup;
            fin >> mark;
            fin >> Math;
            fin >> Physics;
            fin >> Programming;
            fin >> English;
            fin >> Database;
            Member[i].SetParametrs(Surname, Name, Otch, NumberOfGroup, mark, Math, Physics, Programming, English, Database);
        }
    }
    fin.close();
}
void DataAboutUsersFromFile(string PathOfUsersFile, User* (&Account), int& n)
{
    setlocale(LC_ALL, "ru");
    ifstream fin;
    fin.open(PathOfUsersFile);
    if (!fin.is_open())
    {
        cout << "Файл не открыт!" << endl;
    }
    else
    {
        n = CheckCountOfUsers(PathOfUsersFile);
        Account = new User[n];
        for (int i = 0; i < n; i++)
        {
            fin >> Account[i].Login;
            fin >> Account[i].Pass;
            fin >> Account[i].Role;
        }
    }
    fin.close();
}
void OldDataAboutStudentsFromFile(string PathOfStudentFile, student* (&Member), int n)
{
    setlocale(LC_ALL, "ru");
    ifstream fin;
    fin.open(PathOfStudentFile);
    if (!fin.is_open())
    {
        cout << "Файл не открыт!" << endl;
    }
    else
    {
        fin >> n;
        string Surname, Name, Otch;
        int NumberOfGroup;
        double mark;
        char Math, Physics, Programming, English, Database;
        for (int i = 0; i < n; i++)
        {
            fin >> Surname >> Name >> Otch;
            fin >> NumberOfGroup;
            fin >> mark;
            fin >> Math;
            fin >> Physics;
            fin >> Programming;
            fin >> English;
            fin >> Database;
            Member[i].SetParametrs(Surname, Name, Otch, NumberOfGroup, mark, Math, Physics, Programming, English, Database);
        }
    }
    fin.close();
}
void WriteInFileInfoAboutStudents(string PathOfStudentFile, student* (&Member), int& n)
{
    ofstream fout;
    fout.open(PathOfStudentFile);
    if (!fout.is_open())
    {
        cout << "Файл не открыт!" << endl;
    }
    else
    {
        fout << n << endl;
        for (int i = 0; i < n; i++)
        {
            fout << Member[i].GetSurName() << " " << Member[i].GetName() << " " << Member[i].GetOtch() << endl;
            fout << Member[i].GetNumberOfGroup() << endl;
            fout << Member[i].GetMark() << endl;
            fout << Member[i].GetMath() << endl;
            fout << Member[i].GetPhysics() << endl;
            fout << Member[i].GetProgramming() << endl;
            fout << Member[i].GetEnglish() << endl;
            fout << Member[i].GetDataBase() << endl;
        }
    }
}
int CheckCountOfUsers(string PathOfUserFile)
{
    int n = 0;
    ifstream fin;
    fin.open(PathOfUserFile);
    if (!fin.is_open())
    {
        cout << "Файл не открыт!" << endl;
    }
    else
    {
        string str = "";
        while (!fin.eof())
        {
            fin >> str;
            n++;
        }
    }
    fin.close();
    return (n / 3);
}
void RedactUsers(string PathOfUsersFile, User* (&Account), int& n)
{
    bool Correct = true;
    while(Correct)
    {
        string login;
        cout << "Введите логин учётной записи которую хотите редактировать: ";
        cin >> login;
        if (login == "Admin") cout << "Учётную запись Админа редактировать запрещено!" << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (Account[i].Login == login)
                {
                    Correct = false;
                    cout << "Искомый редактированный аккаунт:\n" << "Логин: " << Account[i].Login << endl << "Пароль: " << Account[i].Pass << endl;
                    if (Account[i].Role == '0') cout << "Пользователь" << endl;
                    else if (Account[i].Role == '1') cout << "Администратор" << endl;
                    bool end = false;
                    do
                    {
                        end = false;
                        string newlogin;
                        cout << "Введите новый логин данной учётной записи: ";
                        cin >> newlogin;
                        for (int j = 0; j < n; j++)
                        {
                            if (Account[j].Login == newlogin)
                            {
                                cout << "Увы! Такой логин существует... Попробуйте снова!";
                                end = true;
                            }
                        }
                        if (end == false)
                        {
                            string newPass;
                            cout << "Введите новый пароль данной учётной записи: ";
                            cin >> newPass;
                            newPass = Hash(newPass);
                            Account[i].Login = newlogin;
                            Account[i].Pass = newPass;
                        }
                    } while (end);
                }
            }
            if (Correct) cout << "Данного Логина не существует... Попробуйте снова" << endl;
        }
    }
}
void WriteInFileInfoAboutUsers(string PathOfUsersFile, User* (&Account), int& n)
{
    ofstream fout;
    fout.open(PathOfUsersFile);
    if (!fout.is_open())
    {
        cout << "Файл не открыт!" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fout << Account[i].Login << endl;
            fout << Account[i].Pass << endl;
            fout << Account[i].Role << endl;
        }
    }
}
void OpenFile(string Path)
{
    ifstream fin;
    fin.open(Path);
    if (!fin.is_open())
    {
        cout << "Файл не открыт, он не существует" << endl;
    }
    else
    {
        cout << "файл открыт " << endl;
        char ch;
        while (fin.get(ch))
        {
            cout << ch;
        }
    }
    fin.close();
}

