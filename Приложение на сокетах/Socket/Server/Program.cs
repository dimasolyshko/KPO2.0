using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ServerTCP
{
    class Program
    {
        static void Main(string[] args)
        {
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
        string name;
        int age;
    }
}