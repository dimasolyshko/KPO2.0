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