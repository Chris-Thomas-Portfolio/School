using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SingletonDemo
{
    class SingletonLogger
    {
        private static SingletonLogger _instance = null;

        private SingletonLogger()
        {
            Console.WriteLine("In SingletonLogger c'tor");
        }

        public static SingletonLogger GetInstance()
        {
            if (_instance == null)
                _instance = new SingletonLogger();

            return _instance;
        }

        public void Logging()
        {
            Console.WriteLine("SingleToneLogger Logging");
        }
    }


}

