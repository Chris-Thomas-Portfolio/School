using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace CSharpConsoleClockObserver
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.CursorVisible = false;

            Ticker ticker = new Ticker() ;
            using (SecondClock seconds = new SecondClock(0, 1, ConsoleColor.Yellow, ticker))
            using (TenthSecondClock tenth = new TenthSecondClock(0, 2, ConsoleColor.Green, ticker))
            using (HundredthSecondClock hundredth = new HundredthSecondClock(0, 3, ConsoleColor.Red, ticker))
            {

                Thread thread = new Thread(ticker.Run);
                thread.Start();

                Console.ReadLine();

                ticker.Done = true;
                thread.Join();
            }
        }
    }
}
