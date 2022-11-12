#include "ClassStudent.h"
#include "Files.h"
int main()
{
    setlocale(LC_ALL, "ru");
    bool end = true;
    string PathOfUserFile = "FileAboutUsers.txt";
    bool IsAdmin = CheckAdmin(PathOfUserFile);
    student* Member = new student[2];
    while (end)
    {
        if (IsAdmin)
        {
            cout << "\nУ вас есть права администратора\n\nВыберите что хотите сделать!\n\n1 - Посмотреть все учётные записи пользователей" <<
                "\n2 - Отредактировать учётную запись" <<
                "\n3 - Удалить учётную запись" <<
                "\n4 - Создать файл" <<
                "\n5 - Открыть файл" <<
                "\n6 - Удалить файл" <<
                "\n7 - Посмотреть все данные" <<
                "\n8 - Добавить запись" <<
                "\n9 - Удалить запись" <<
                "\n10 - Вывести студентов желающих записаться на факультатив: " <<
                "\n11 - Выполнить поиск данных" <<
                "\n12 - Выполнить сортировку" <<
                "\n13 - Выход из программы! " << endl;
            int number;
            cin >> number;
            switch (number)
            {
            case 1:
            {
                ReadFromFileAboutUsers(PathOfUserFile);
                break;
            }
            case 2:
            {
                // Info(Participant, count, path); 
                break;
            }
            case 3:
            {
                //SortAge(Participant, count, path); 
                break;
            }
            case 4:
            {
                // Delete(Participant, count); 
                // New_file(Participant, count, path); 
                break;
            }
            case 5:
            {
                // Molodie(Participant, count); 
                break;
            }
            case 6:
            {
                end = false;
                break;
            }
            case 7:
            {

            }
            case 8:
            {

            }
            case 9:
            {

            }
            case 10:
            {

            }
            case 11:
            {

            }
            case 12:
            {

            }
            case 13:
            {
                end = false;
                break;
            }
            default:
            {
                cout << "Неправильный номер операции" << endl;
                break;
            }
            }
        }
        else
        {
            cout << "Права Пользователя:" << endl;
        }
    }
    return 0;
}
/*
void New_file(student Participant[], int count, string path);
void SortAge(student Participant[], int count, string path);
void AddPArticipant(student Participant[], int* count, string path);
void New_file(student Participant[], int count, string path)
{
    ofstream fout;
    fout.open(path);
    for (int i = 0; i < count; i++)
    {
        fout << "_________________________________" << endl << endl;
        fout << "Страна участника - " << Participant[i].Country << endl;
        fout << "Команда участника - " << Participant[i].Team << endl;
        fout << "ФИО участника - " << Participant[i].Fam << " " << Participant[i].Name << " " << Participant[i].Otch << endl;
        fout << "Номер участника - " << Participant[i].Number << endl;
        fout << "Возраст участника - " << Participant[i].Year << endl;
        fout << "Рост участника - " << Participant[i].Rost << endl;
        fout << "Вес участника - " << Participant[i].Ves << endl;
    }
    fout.close();
}
void SortAge(student Participant[], int count, string path)
{
    for (int i = count - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (Participant[j].Year > Participant[j + 1].Year)
            {
                student tmp = Participant[j];
                Participant[j] = Participant[j + 1];
                Participant[j + 1] = tmp;
            }
        }
    }
    cout << "Сортировка по возрасту: " << endl;
    New_file(Participant, count, path);
    Info(Participant, count, path);
}
void AddPArticipant(student Participant[], int* count, string path)
{
    cout << "Страна участника - ";
    cin >> Participant[*count].Country;
    cout << "Команда участника -  ";
    cin >> Participant[*count].Team;
    cout << "ФИО участника - ";
    cin >> Participant[*count].Fam >> Participant[*count].Name >> Participant[*count].Otch;
    cout << "Номер участника - ";
    cin >> Participant[*count].Number;
    cout << "Возраст участника - ";
    cin >> Participant[*count].Year;
    cout << "Рост участника - ";
    cin >> Participant[*count].Rost;
    cout << "Вес участника - ";
    cin >> Participant[*count].Ves;
    (*count)++;
    New_file(Participant, *count, path);
}
*/