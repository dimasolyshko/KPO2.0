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
    while (true)
    {
        cout << "��� ���������� ��������������, ��� ����� � �������!\n���� ������ �������������� �������� 0, ���� ������ ����� � ������� �������� 1: ";
        bool NewUser = true;
        int number;
        string login, Pass, CorrectLogin, str;
        cin >> number;
        if (number == 0)
        {
            while (NewUser) // ����, ������� ����� ��������� ���� �� ����� ������� �������� ����� �� ������������ �������� ��������!
            {
                NewUser = false;
                cout << "������� ����� ������ ��������: ";
                cin >> login;
                ifstream fin;
                fin.open(PathOfUserFile);
                if (!fin.is_open()) cout << "���� �� ������!" << endl;
                else
                {
                    while (!fin.eof())
                    {
                        fin >> CorrectLogin;
                        fin >> str;
                        fin >> str;
                        if (CorrectLogin == login) // �������� �� ������������ ��������� ������
                        {
                            cout << "����� ����� ��� ���������� ���������� ������" << endl;
                            NewUser = true;
                            CorrectLogin = "";
                        }
                    }
                }
                fin.close();
            }
            cout << "������� ������ ������ ��������: ";
            cin >> Pass;
            ofstream fout;
            fout.open(PathOfUserFile, ios::app);
            if (!fout.is_open()) cout << "���� �� ������!" << endl;
            else // ������ ������ �� �������� � ����
            {
                fout << login << endl;
                fout << Pass << endl;
                fout << "0" << endl;
            }
            cout << "�� ������� ������������������, ��� ����� " << login << endl;
            fout.close();
            return false; // ���������� ���� ������������, ��� ��� ������� ��� ������ �������������!
        }
        else if (number == 1)
        {
            bool end = true,Role = false;
            while(end) //��������� ����, ������� ����� ��������� ���� �� �� ����� � ������� �������!
            {
                end = true;
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
                    while (!fin.eof() && end) // �������� �� ����� �� ����� ��� �� ���������� ������ ��� ������
                    {
                        fin >> CorrectLogin;
                        fin >> CorrectPass;
                        fin >> Role;
                        if (login == CorrectLogin && Pass == CorrectPass) // �������� �� ���������� ������ � ������
                        {
                            cout << "�� ������� ����� � �������!" << endl;
                            end = false;
                        }
                    }
                    if (end) cout << "�� ����������� ����� ������ ��� �����!\n���������� �����" << endl; 
                }
                fin.close();
            }
            return Role; // ���������� ����
        }
        else cout << "������!�� �� ����� 1 ���� 0\n���������� �����!" << endl;
    }
}
