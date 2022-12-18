#include "ClassStudent.h"
#include "Functions.h"
#include "Files.h"
int main()
{
    setlocale(LC_ALL, "ru");
    int NumberOfStudents = 0, NumberOfUsers = 0;
    bool end = true;
    string PathOfUserFile = "FileAboutUsers.txt", PathOfStudentFile = "FileAboutStudents.txt";
    bool IsAdmin = CheckAdmin(PathOfUserFile); // Определяем Роль для Нашего аккаунта (Администратор или Пользователь) + Авторизация или вход в аккаунт
    student* Member = new student [NumberOfStudents]; // Выделение памяти для Студентов
    User* Account = new User[NumberOfUsers];
    DataAboutStudentsFromFile(PathOfStudentFile, Member, NumberOfStudents);
    DataAboutUsersFromFile(PathOfUserFile, Account, NumberOfUsers);
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
                for (int i = 0; i < NumberOfUsers; i++) Account[i].Print();
                break;
            }
            case 2:
            {
                cout << "вы точно хотите отредактировать учётную запись?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {
                    RedactUsers(PathOfUserFile, Account, NumberOfUsers);
                    WriteInFileInfoAboutUsers(PathOfUserFile, Account, NumberOfUsers);
                    break;
                }
                else
                {
                    break;
                }
            }
            case 3:
            {
                cout << "вы точно хотите удалить учётную запись?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {

                }
                else
                {
                    break;
                }
            }
            case 4:
            {
                cout << "вы точно хотите открыть файл?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {
                    string Path;
                    cout << "Введите название нового файла" << endl;
                    cin >> Path;
                    Path += ".txt";
                    WriteInFileInfoAboutStudents(Path, Member, NumberOfStudents);
                    break;
                }
                else
                {
                    break;
                }
            }
            case 5:
            {
                cout << "вы точно хотите удалить учётную запись?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {

                }
                else
                {
                    break;
                }
                break;
            }
            case 6:
            {
                cout << "вы точно хотите удалить файл?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {
                    string Path;
                    cout << "Введите имя файла: ";
                    cin >> Path;
                    Path += ".txt";
                    if (remove(Path.c_str()) == 0) cout << "Файл успешно удалён!" << endl;
                    else cout << "Такого файла не существует!" << endl;
                    break;
                }
                else
                {
                    break;
                }
            }
            case 7:
            {
                for (int i = 0; i < NumberOfStudents; i++) Member[i].Print();   
                break;
            }
            case 8:
            {
                cout << "вы точно хотите добавить участника?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {
                    AddStudent(PathOfStudentFile, Member, NumberOfStudents);
                    WriteInFileInfoAboutStudents(PathOfStudentFile, Member, NumberOfStudents);
                    break;
                }
                else
                {
                    break;
                }
            }
            case 9:
            {
                cout << "вы точно хотите удалить участника?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {

                }
                else
                {
                    break;
                }
            }
            case 10:
            {
                ITask(Member, NumberOfStudents);
                break;
            }
            case 11:
            {
                FindDataAbout(Member, NumberOfStudents);
                break;
            }
            case 12:
            {
                SortMenu(Member, NumberOfStudents);
                break;
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
            end = false;
        }
    }
    return 0;
}