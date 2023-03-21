#include "ClassStudent.h"
#include "Functions.h"
#include "Files.h"
int main()
{
    setlocale(LC_ALL, "ru");
    int NumberOfStudents = 0, NumberOfUsers = 0;
    bool end = true;
    string PathOfUserFile = "FileAboutUsers.txt", PathOfStudentFile = "FileAboutStudents.txt";
    bool IsAdmin = Authorization(PathOfUserFile); // Определяем Роль для Нашего аккаунта (Администратор или Пользователь) + Авторизация или вход в аккаунт
    student* Member = new student [NumberOfStudents]; // Выделение памяти для Студентов
    User* Account = new User[NumberOfUsers];
    DataAboutStudentsFromFile(PathOfStudentFile, Member, NumberOfStudents);
    DataAboutUsersFromFile(PathOfUserFile, Account, NumberOfUsers);
    while (end)
    {
        if (IsAdmin)
        {
            cout << "\nУ вас есть права администратора\n\nВыберите что хотите сделать!\n\n0 - Посмотреть все учётные записи пользователей" <<
                "\n1 - Добавить учётную запись" <<
                "\n2 - Отредактировать учётную запись" <<
                "\n3 - Удалить учётную запись" <<
                "\n4 - Создать файл" <<
                "\n5 - Открыть файл" <<
                "\n6 - Удалить файл" <<
                "\n7 - Посмотреть все данные" <<
                "\n8 - Добавить запись" <<
                "\n9 - Удалить запись" <<
                "\n10 - Выполнить индивидуальное задание!" <<
                "\n11 - Выполнить поиск данных" <<
                "\n12 - Выполнить сортировку по среднему баллу" <<
                "\n13 - Выход из программы! " << endl;
            int number;
            cin >> number;
            switch (number)
            {
            case 0:
            {
                for (int i = 0; i < NumberOfUsers; i++) Account[i].Print();
                break;
            }
            case 1:
            {
                AddUser(PathOfUserFile);
                DataAboutUsersFromFile(PathOfUserFile, Account, NumberOfUsers);
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
                    for (int i = 1; i < NumberOfUsers; i++)
                    {
                        Account[i].Print();
                        cout << i << "-й" << " пользователь" << endl;
                    }
                    cout << "Введите Номер пользователя которого хотите удалить > ";
                    int index;
                    cin >> index;
                    DeleteUser(Account, NumberOfUsers, index);
                    WriteInFileInfoAboutUsers(PathOfUserFile, Account, NumberOfUsers);
                    break;
                }
                else
                {
                    break;
                }
            }
            case 4:
            {
                cout << "вы точно хотите создать файл?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
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
                cout << "вы точно хотите открыть файл?\n" << "1 - да, точно!\n" << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {
                    string Path;
                    cout << "Введите название файла, который хотите открыть" << endl;
                    cin >> Path;
                    Path += ".txt";
                    OpenFile(Path);
                    break;
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
                    if (Path == PathOfUserFile) cout << "\nУвы! Данный файл удалить нельзя, т.к. там хранятся данные о пользователях и администраторе!\n";
                    else if (Path == PathOfStudentFile) cout << "\nУвы! Данный файл удалить нельзя, т.к. там хранятся важные данные о студентах!\n";
                    else
                    {
                        if (remove(Path.c_str()) == 0) cout << "Файл успешно удалён!" << endl;
                        else cout << "Такого файла не существует!" << endl;
                    }
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
                    for (int i = 0; i < NumberOfStudents; i++)
                    {
                        Member[i].Print();
                        cout << i + 1 << "-й" << " cтудент" << endl;
                    }
                    cout << "Введите Номер студента которого хотите удалить > ";
                    int index;
                    cin >> index;
                    DeleteStudent(Member, NumberOfStudents, index);
                    WriteInFileInfoAboutStudents(PathOfStudentFile, Member, NumberOfStudents);
                    break;

                }
                else
                {
                    break;
                }
            }
            case 10:
            {
                cout << "Какое индивидуальное задание вы хотите выполнить?\n" 
                     << "1 - Вывысти список и общее количество студентов, желающих прослушать дисциплину x!\n" 
                     << "2 - Вывести предлагаемые дисциплины в порядке убывания популярности с указанием общего числа записавшихся на каждую из них!\n"
                     << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {
                    ITask1(Member, NumberOfStudents);
                    break;
                }
                else if(j == 2)
                {
                    ITask2(Member, NumberOfStudents);
                    break;
                }
                else
                {
                    break;
                }
            }
            case 11:
            {
                FindDataAboutStudent(Member, NumberOfStudents);
                break;
            }
            case 12:
            {
                SortMark(Member, NumberOfStudents);
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
            cout << "\nУ вас есть права пользователя\n\nВыберите что хотите сделать!\n\n" <<
            "\n1 - Посмотреть все данные" <<
            "\n2 - Выполнить индивидуальное задание!" <<
            "\n3 - Выполнить поиск данных" <<
            "\n4 - Выполнить сортировку по среднему баллу" <<
            "\n0 - Выход из программы! " << endl;
            int number;
            cin >> number;
            switch (number)
            {
            case 1:
            {
                for (int i = 0; i < NumberOfStudents; i++) Member[i].Print();
                break;
            }
            case 2:
            {
                cout << "Какое индивидуальное задание вы хотите выполнить?\n"
                    << "1 - Вывысти список и общее количество студентов, желающих прослушать дисциплину x!\n"
                    << "2 - Вывести предлагаемые дисциплины в порядке убывания популярности с указанием общего числа записавшихся на каждую из них!\n"
                    << "Другая цифра - Нет, Обратно в меню!" << endl;
                int j;
                cin >> j;
                if (j == 1)
                {
                    ITask1(Member, NumberOfStudents);
                    break;
                }
                else if (j == 2)
                {
                    ITask2(Member, NumberOfStudents);
                    break;
                }
                else
                {
                    break;
                }
            }
            case 3:
            {
                FindDataAboutStudent(Member, NumberOfStudents);
                break;
            }
            case 4:
            {
                SortMark(Member, NumberOfStudents);
                break;
            }
            case 0:
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
    }
    return 0;
}