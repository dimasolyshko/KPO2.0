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