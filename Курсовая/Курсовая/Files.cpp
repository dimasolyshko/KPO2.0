#include "Files.h"
void ReadFromFileAboutUsers(string PathOfUserFile)
{
    ifstream fin;
    fin.open(PathOfUserFile);
    if (!fin.is_open())
    {
        cout << "���� �� ������!" << endl;
    }
    else
    {
        cout << "���� ������!" << endl;
        string str = "";
        fin >> str;
        while (!fin.eof())
        {
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            fin >> str;
            cout << "�����:  |" << str << endl;
            fin >> str;
            cout << "������:|" << str << endl;
            fin >> str;
            cout << "����: |" << str << endl;
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
        cout << "���� �� ������!" << endl;
    }
    else
    {
        string login, Pass, CorrectLogin, CorrectPass;
        cout << "������� �����: ";
        cin >> login;
        cout << "������� ������: ";
        cin >> Pass;
        bool end = true;
        while (!fin.eof() && end)
        {
            fin >> CorrectLogin;
            fin >> CorrectPass;
            fin >> Role;
            if (login == CorrectLogin && Pass == CorrectPass)
            {
                cout << "�� ������� ����� � �������!" << endl;
                end = false;
            }
        }
    }
    fin.close();
    return Role;
}
