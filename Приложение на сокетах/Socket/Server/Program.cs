using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ServerTCP
{
    class Program
    {
        static void Main(string[] args)
        {
            void ReadInfoAboutDataBase(ref database [] Db, ref int row)
            {
                string path = "DataBase.txt";   // путь к файлу
                // чтение из файла
                using (StreamReader reader = new StreamReader(path))
                {
                    int count = 0;
                    string[] words;
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        if (count != 0)
                        {
                            Array.Resize(ref Db, ++row);
                            words = line.Split(' ');
                            Db[row - 1] = new database(words[0], Convert.ToInt32(words[1]));
                        }
                        count++;
                    }
                }
                for (int i = 0; i < row; i++) Db[i].Print();
            }
            int row = 0;
            database[] Db = new database[row];
            ReadInfoAboutDataBase(ref Db, ref row);
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
                Listener.Send(Encoding.UTF8.GetBytes("Всё хорошо! Сообщение отправлено!"));
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