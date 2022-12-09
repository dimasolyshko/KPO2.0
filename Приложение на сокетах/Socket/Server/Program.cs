using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace ServerTCP
{
    class Program
    {
        const string table = "People";
        const string Name = "name";
        const string Age = "age";
        const string path = "DataBase.txt";
        static async Task Main(string[] args)
        {
            void ReadInfoAboutDataBase(ref database [] Db, ref int row)
            {
                // чтение из файла
                using (StreamReader reader = new StreamReader(path))
                {
                    row = 0;
                    int count = 0;
                    string[] words;
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        if (count != 0)
                        {
                            Array.Resize(ref Db, ++row);
                            words = line.Split("    ");
                            Db[row - 1] = new database(words[0], Convert.ToInt32(words[1]));
                        }
                        count++;
                    }
                }
                for (int i = 0; i < row; i++) Db[i].Print();
            }
            void SortName(ref database[] Db,ref int row)
            {
                for (int j = 0; j < row; j++)
                    for (int i = 0; i < row - 1; i++)
                    {
                        database temp;
                        if (string.Compare(Db[i].name, Db[i + 1].name) > 0)
                        {
                            temp = Db[i];
                            Db[i] = Db[i + 1];
                            Db[i + 1] = temp;
                        }
                    }
            }
            void SortNameReverse(ref database[] Db, ref int row)
            {
                for (int j = 0; j < row; j++)
                    for (int i = 0; i < row - 1; i++)
                    {
                        database temp;
                        if (string.Compare(Db[i].name, Db[i + 1].name) < 0)
                        {
                            temp = Db[i];
                            Db[i] = Db[i + 1];
                            Db[i + 1] = temp;
                        }
                    }
            }
            void SortAge(ref database[] Db, ref int row)
            {
                for (int j = 0; j < row; j++)
                    for (int i = 0; i < row - 1; i++)
                    {
                        database temp;
                        if (Db[i].age > Db[i + 1].age)
                        {
                            temp = Db[i];
                            Db[i] = Db[i + 1];
                            Db[i + 1] = temp;
                        }
                    }
            }
            void SortAgeReverse(ref database[] Db, ref int row)
            {
                for (int j = 0; j < row; j++)
                    for (int i = 0; i < row - 1; i++)
                    {
                        database temp;
                        if (Db[i].age < Db[i + 1].age)
                        {
                            temp = Db[i];
                            Db[i] = Db[i + 1];
                            Db[i + 1] = temp;
                        }
                    }
            }
            void CheckOrderBy(string [] words, ref database[] Db, ref int row, ref bool IsCommand, int j, int length)
            {
                if (words.Length == length) ;
                else if (words[j] == "ORDER" && words[j + 1] == "BY" && words[j + 2] == Age)// SELECT * FROM People WHERE age > n ORDER BY age DESC
                {
                    if (words.Length == length + 3) SortAge(ref Db, ref row);
                    else if (words[j + 3] == "DESC" && words.Length == length + 4) SortAgeReverse(ref Db, ref row);
                    else if (words[j + 3] == "ASC" && words.Length == length + 4) SortAge(ref Db, ref row);
                    else IsCommand = false;
                }
                else if (words[j] == "ORDER" && words[j + 1] == "BY" && words[j + 2] == Name)// SELECT * FROM People WHERE age > n ORDER BY name ASC
                {
                    if (words.Length == length + 3) SortName(ref Db, ref row);
                    else if (words[j + 3] == "DESC" && words.Length == length + 4) SortNameReverse(ref Db, ref row);
                    else if (words[j + 3] == "ASC" && words.Length == length + 4) SortName(ref Db, ref row);
                    else IsCommand = false;
                }
                else IsCommand = false;
            }
            void Command(ref database[] Db, ref int row, string str, ref bool IsCommand, ref string message)
            {
                string[] words = str.Split(' '); //сплитим строку для проверки по каждому слову
                switch (words[0])
                {
                    case "SELECT":
                        {
                            int i = 1;
                            if (words.Length < 4) IsCommand = false;
                            else if ((words[i] == "*" || words[i] == "name,age" || words[i] == "age,name") && words[i + 1] == "FROM" && words[i + 2] == table)
                            {
                                int j = i + 3;
                                message = "name   age\n";
                                if (words.Length == 4)
                                {
                                    for (int l = 0; l < Db.Length; l++) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                }
                                else if (words[j] == "WHERE")
                                {
                                    if (words.Length < 8) IsCommand = false;
                                    else if (words[j + 1] == Age && words[j + 2] == "=")// SELECT * FROM People WHERE age = 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Convert.ToInt32(words[j + 3]) == Db[l].age) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == ">")// SELECT * FROM People WHERE age > 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age > Convert.ToInt32(words[j + 3])) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == "<")// SELECT * FROM People WHERE age <
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age < Convert.ToInt32(words[j + 3])) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == "<=")// SELECT * FROM People WHERE age <=
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age < Convert.ToInt32(words[j + 3]) || Db[l].age == Convert.ToInt32(words[j + 3])) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == ">=")// SELECT * FROM People WHERE age >=
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age > Convert.ToInt32(words[j + 3]) || Db[l].age == Convert.ToInt32(words[j + 3])) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "=") // SELECT * FROM People WHERE name = 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (words[j + 3] == Db[l].name) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">")// SELECT * FROM People WHERE name >
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "<")// SELECT * FROM People WHERE name < 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) < 0) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "<=")// SELECT * FROM People WHERE name <= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) < 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">=")// SELECT * FROM People WHERE name >= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">=")// SELECT * FROM People WHERE name >= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].name + "   " + Db[l].age + "\n";
                                        }
                                    }
                                    else IsCommand = false;
                                }
                                else if (words[j] == "ORDER") CheckOrderBy(words, ref Db, ref row, ref IsCommand, j, 4);
                                else IsCommand = false;
                            } // SELECT * FROM People
                            else if (words[i] == Name && words[i + 1] == "FROM" && words[i + 2] == table)// SELECT name FROM People
                            {
                                int j = i + 3;
                                message = "Name\n";
                                if (words.Length == 4)
                                {
                                    for (int l = 0; l < Db.Length; l++) message = message + Db[l].name + "\n";
                                }
                                else if (words[j] == "WHERE")
                                {
                                    if (words.Length < 8) IsCommand = false;
                                    else if (words[j + 1] == Age && words[j + 2] == "=")// SELECT * FROM People WHERE age = 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Convert.ToInt32(words[j + 3]) == Db[l].age) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == ">")// SELECT * FROM People WHERE age > 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age > Convert.ToInt32(words[j + 3])) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == "<")// SELECT * FROM People WHERE age <
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age < Convert.ToInt32(words[j + 3])) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == "<=")// SELECT * FROM People WHERE age <=
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age < Convert.ToInt32(words[j + 3]) || Db[l].age == Convert.ToInt32(words[j + 3])) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == ">=")// SELECT * FROM People WHERE age >=
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age > Convert.ToInt32(words[j + 3]) || Db[l].age == Convert.ToInt32(words[j + 3])) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "=") // SELECT * FROM People WHERE name = 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (words[j + 3] == Db[l].name) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">")// SELECT * FROM People WHERE name >
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "<")// SELECT * FROM People WHERE name < 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) < 0) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "<=")// SELECT * FROM People WHERE name <= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) < 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">=")// SELECT * FROM People WHERE name >= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">=")// SELECT * FROM People WHERE name >= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].name + "\n";
                                        }
                                    }
                                    else IsCommand = false;
                                }
                                else if (words[j] == "ORDER")
                                {
                                    CheckOrderBy(words, ref Db, ref row, ref IsCommand, j, 4);
                                    for (int l = 0; l < Db.Length; l++)
                                    {
                                        message = message + Db[l].name + "\n";
                                    }
                                }
                                else IsCommand = false;
                            }
                            else if (words[i] == Age && words[i + 1] == "FROM" && words[i + 2] == table)
                            {
                                int j = i + 3;
                                message = "age\n";
                                if (words.Length == 4)
                                {
                                    for (int l = 0; l < Db.Length; l++) message = message + Db[l].age + "\n";
                                }
                                else if (words[j] == "WHERE")
                                {
                                    if (words.Length < 8) IsCommand = false;
                                    else if (words[j + 1] == Age && words[j + 2] == "=")// SELECT * FROM People WHERE age = 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Convert.ToInt32(words[j + 3]) == Db[l].age) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == ">")// SELECT * FROM People WHERE age > 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age > Convert.ToInt32(words[j + 3])) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == "<")// SELECT * FROM People WHERE age <
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age < Convert.ToInt32(words[j + 3])) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == "<=")// SELECT * FROM People WHERE age <=
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age < Convert.ToInt32(words[j + 3]) || Db[l].age == Convert.ToInt32(words[j + 3])) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Age && words[j + 2] == ">=")// SELECT * FROM People WHERE age >=
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (Db[l].age > Convert.ToInt32(words[j + 3]) || Db[l].age == Convert.ToInt32(words[j + 3])) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "=") // SELECT * FROM People WHERE name = 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (words[j + 3] == Db[l].name) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">")// SELECT * FROM People WHERE name >
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "<")// SELECT * FROM People WHERE name < 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) < 0) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == "<=")// SELECT * FROM People WHERE name <= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) < 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">=")// SELECT * FROM People WHERE name >= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else if (words[j + 1] == Name && words[j + 2] == ">=")// SELECT * FROM People WHERE name >= 
                                    {
                                        CheckOrderBy(words, ref Db, ref row, ref IsCommand, j + 4, 8);
                                        for (int l = 0; l < Db.Length; l++)
                                        {
                                            if (string.Compare(words[j + 3], Db[l].name) > 0 || string.Compare(words[j + 3], Db[l].name) == 0) message = message + Db[l].age + "\n";
                                        }
                                    }
                                    else IsCommand = false;
                                }
                                else if (words[j] == "ORDER") CheckOrderBy(words, ref Db, ref row, ref IsCommand, j, 4);
                                else IsCommand = false;
                            } // SELECT age FROM People
                            else IsCommand = false;
                            break;
                        }
                    case "INSERT":
                        break;
                    case "DELETE":
                        break;
                    case "UPDATE":
                        break;
                    default:
                        IsCommand = false;
                        break;
                }
            }
            int row = 0;
            database[] Db = new database[row];
            ReadInfoAboutDataBase(ref Db, ref row) ;
            Console.WriteLine(row);

            const string ip = "127.0.0.1";
            const int port = 8080;

            var tcpEndPoint = new IPEndPoint(IPAddress.Parse(ip), port);

            var tcpSoket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp); // подключение сокета

            tcpSoket.Bind(tcpEndPoint); // Прослушивание
            tcpSoket.Listen(5);

            while (true)
            {
                var Listener = tcpSoket.Accept(); // новый слушатель для каждого нового клиента
                var buffer = new byte[256];
                var size = 0; // количество байт
                var data = new StringBuilder();
                do
                {
                    size = Listener.Receive(buffer); // Записываем количество реально полученных байт
                    data.Append(Encoding.UTF8.GetString(buffer, 0, size)); // буфер это откуда берём информацию, 0 это начало, size - количество байт
                }
                while (Listener.Available > 0); // до тех пор пока есть данные
                Console.WriteLine(data); // проверка строки
                string str = data.ToString();
                string message = "";
                bool IsCommand = true;
                Command(ref Db, ref row, str, ref IsCommand,ref message);
                if (!IsCommand) Listener.Send(Encoding.UTF8.GetBytes("Неверно введена команда!\n"));
                else
                {
                    //string fileText = await File.ReadAllTextAsync(path);
                    Listener.Send(Encoding.UTF8.GetBytes("\n       База данных \n"));
                    Listener.Send(Encoding.UTF8.GetBytes(message));
                    //Listener.Send(Encoding.UTF8.GetBytes(fileText));
                }
                Listener.Shutdown(SocketShutdown.Both);
                Listener.Close(); // закрытие клиента
            }
        }
        
    }
    class database
    {
        public string name;
        public int age;
        public database()
        {
            age = 0;
            name = "Неизвестно";
        }
        public database(string name, int age)
        {
            this.age = age;
            this.name = name;
        }
        public void Print()
        {
            Console.WriteLine($"{name} {age}");
        }
    }
}