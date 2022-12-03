using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ClientTCP
{
    class Program
    {
        static void Main(string[] args)
        {
            bool end = true;
            while (end)
                {
                const string ip = "127.0.0.1";
                const int port = 8080;
                var tcpEndPoint = new IPEndPoint(IPAddress.Parse(ip), port);
                var tcpSoket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp); // подключение сокета

                Console.WriteLine("Введите сообщение!");
                var message = Console.ReadLine(); // переменная для сообщения
                if (message == "exit") end = false;

                var data = Encoding.UTF8.GetBytes(message);// перевели сообщение в байты
                tcpSoket.Connect(tcpEndPoint);
                tcpSoket.Send(data);
                // Получение сообщения от сервера!
                var buffer = new byte[256];
                var size = 0; // количество байт
                var answer = new StringBuilder();
                do
                {
                    size = tcpSoket.Receive(buffer); // Записываем количество реально полученных байт
                    answer.Append(Encoding.UTF8.GetString(buffer, 0, size)); // буфер это откуда берём информацию, 0 это начало, size - количество байт
                }
                while (tcpSoket.Available > 0); // до тех пор пока есть данные

                Console.WriteLine(answer.ToString());
                tcpSoket.Shutdown(SocketShutdown.Both);
                tcpSoket.Close(); // закрытие клиента
            }
        }
    }
}
