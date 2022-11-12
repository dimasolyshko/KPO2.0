#include "Files.h"
void ReadFromFileAboutUsers(string PathOfUserFile)
{
    ifstream fin;
    fin.open(PathOfUserFile);
    if (!fin.is_open())
    {
        cout << "Файл не открыт!" << endl;
    }
    else
    {
        cout << "Файл открыт!" << endl;
        string str = "";
        fin >> str;
        while (!fin.eof())
        {
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            fin >> str;
            cout << "Логин:  |" << str << endl;
            fin >> str;
            cout << "Пароль:|" << str << endl;
            fin >> str;
            cout << "Роль: |" << str << endl;
        }
    }
    fin.close();
}
bool CheckAdmin(string PathOfUserFile)
{
    while (true)
    {
        cout << "Вам необходимо авторизоваться, или войти в аккаунт!\nЕсли хотите авторизоваться напишите 0, если хотите войти в аккаунт напишите 1: ";
        bool NewUser = true;
        int number;
        string login, Pass, CorrectLogin, str;
        cin >> number;
        if (number == 0)
        {
            while (NewUser)
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
                        if (CorrectLogin == login)
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
            ofstream fout;
            fout.open(PathOfUserFile, ios::app);
            if (!fout.is_open()) cout << "Файл не открыт!" << endl;
            else
            {
                fout << login << endl;
                fout << Pass << endl;
                fout << "0" << endl;
            }
            cout << "Вы успешно зарегистрировались, Ваш логин " << login << endl;
            fout.close();
            return false;
        }
        else if (number == 1)
        {
            bool end = true,Role = false;
            while(end)
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
                    while (!fin.eof() && end)
                    {
                        fin >> CorrectLogin;
                        fin >> CorrectPass;
                        fin >> Role;
                        if (login == CorrectLogin && Pass == CorrectPass)
                        {
                            cout << "Вы успешно вошли в аккаунт!" << endl;
                            end = false;
                        }
                    }
                    if (end) cout << "Вы неправильно ввели Пароль или Логин!\nПопробуйте снова" << endl;
                }
                fin.close();
            }
            return Role;
        }
        else cout << "Ошибка!Вы не ввели 1 либо 0\nПопробуйте снова!" << endl;
    }
}
