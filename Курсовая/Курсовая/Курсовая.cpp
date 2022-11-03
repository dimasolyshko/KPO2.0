#include <string> 
#include <iostream> 
#include <fstream> 
using namespace std;
class student
{
private:
    string Surname, Name, Otch;
    int NumberOfGroup;
    double mark;
    char Math, Physics, Programming, English, Database;
public:
    student()
    {
        this->Surname = "";
        this->Name = "";
        this->Otch = "";
        this->NumberOfGroup = 0;
        this->mark = 0.00;
        this->Math = 0;
        this->Physics = 0;
        this->Programming = 0;
        this->English = 0;
        this->Database = 0;
    }

    student(string Fam, string Name, string Otch, int NumberOfGroup, double mark, char Math, char Physics, char Programming, char English, char Database)
    {
        this->Surname = Fam;
        this->Name = Name;
        this->Otch = Otch;
        this->NumberOfGroup = NumberOfGroup;
        this->mark = mark;
        this->Math = Math;
        this->Physics = Physics;
        this->Programming = Programming;
        this->English = English;
        this->Database = Database;
    }
    void SetParametrs(string Surname, string Name, string Otch, int NumberOfGroup, double mark, char Math, char Physics, char Programming, char English, char Database)
    {
        this->Surname = Surname;
        this->Name = Name;
        this->Otch = Otch;
        this->NumberOfGroup = NumberOfGroup;
        this->mark = mark;
        this->Math = Math;
        this->Physics = Physics;
        this->Programming = Programming;
        this->English = English;
        this->Database = Database;
    }
    void Print()
    {
        cout << "ФИО студента: " << Surname << "  " << Name << "  " << Otch << endl;
        cout << "Номер Группы: " << NumberOfGroup << endl;
        cout << "Средний Балл студента: " << mark << endl;
        cout << "Факультатив по Математике (0 - Не записан, 1 - Записан) - " << Math << endl;
        cout << "Факультатив по Физике (0 - Не записан, 1 - Записан) - " << Physics << endl;
        cout << "Факультатив по Программированию (0 - Не записан, 1 - Записан) - " << Programming << endl;
        cout << "Факультатив по Английскому языку (0 - Не записан, 1 - Записан) - " << English << endl;
        cout << "Факультатив по Базам Данных (0 - Не записан, 1 - Записан) - " << Database << endl;
    }
    ~student()
    {
    }

};
void New_file(student Participant[], int count, string path);
void SortAge(student Participant[], int count, string path);
void AddPArticipant(student Participant[], int* count, string path);
int main()
{
    setlocale(LC_ALL, "ru");
    bool end = true;
    student* Member = new student[100];
    Member[0].SetParametrs("a", "b", "c", 5, 5.11, '0', '1', '0', '1', '0');
    Member[0].Print();
}
/*    while (end)
    {
        cout << "Выберите что хотите сделать!\n\n1 - Добавить участника" << 
            "\n2 - Вывести информацию об участниках " << 
            "\n3 - Сортировка по возрасту участников" << 
            "\n4 - Удалить информацию об участнике" << 
            "\n5 - Вывести участников старше 20 лет" << 
            "\n6 - Конец программы " << endl;
        int number;
        cin >> number;
        switch (number)
        {
        case 1:
        {
            AddPArticipant(Participant, &count, path);
            break;
        }
        case 2:
        {
            Info(Participant, count, path);
            break;
        }
        case 3:
        {
            SortAge(Participant, count, path);
            break;
        }
        case 4:
        {
            Delete(Participant, count);
            New_file(Participant, count, path);
            break;
        }
        case 5:
        {
            Molodie(Participant, count);
            break;
        }
        case 6:
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
    delete[] Participant;
    return 0;
}
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
}*/