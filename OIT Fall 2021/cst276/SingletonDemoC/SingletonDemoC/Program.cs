using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SingletonDemo
{
    class GlobalLogger
    {
        public static Logger logger = new Logger();
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("In Main");

            SingletonLogger s1 = SingletonLogger.GetInstance();
            SingletonLogger s2 = SingletonLogger.GetInstance();
        }
    }
}
