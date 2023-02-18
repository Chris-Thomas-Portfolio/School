using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.IO;

namespace SingletonDll
{
    public class SingletonLogger
    {
        private object _filelock = new object();
        private StreamWriter streamwriter;
        static SingletonLogger _instance = null;
        private static object _lock = new object();

        SingletonLogger()
        {
            streamwriter = new StreamWriter(File.Create("log"));
        }

        public void LogMsg(String a)
        {
            lock (_filelock)
            {
                streamwriter.WriteLine("{0} {1}", DateTime.Now, a);
                Thread.Sleep(10);
            }
        }

        public void Close()
        {
            streamwriter.Close();
        }
        public static SingletonLogger GetInstance()
        {
            if (_instance == null)
            {
                lock (_lock)
                {
                    if (_instance == null)
                    {
                        _instance = new SingletonLogger();
                    }
                }
            }

            return _instance;
        }
    }
}
