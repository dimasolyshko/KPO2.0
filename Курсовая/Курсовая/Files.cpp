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
    bool Role = false;
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
        bool end = true;
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
    }
    fin.close();
    return Role;
}
