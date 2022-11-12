#include "ClassStudent.h"
#include "Files.h"
int main()
{
    setlocale(LC_ALL, "ru");
    bool end = true;
    string PathOfUserFile = "FileAboutUsers.txt"; 
    bool IsAdmin = CheckAdmin(PathOfUserFile); // Определяем Роль для Нашего аккаунта (Администратор или Пользователь) + Авторизация или вход в аккаунт
    student* Member = new student[2]; // Выделение памяти для Студентов
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
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
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