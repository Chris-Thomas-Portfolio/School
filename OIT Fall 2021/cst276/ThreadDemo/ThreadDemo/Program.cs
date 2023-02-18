using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ThreadDemo
{
    class ExerciseThreads
    {
        private static object _lock = new object();
        public static void ThreadLogger()
        {
            lock (_lock)
            {
                for (int i = 0; i < 100; i++)
                {
                    Console.WriteLine("{0} {1}", Thread.CurrentThread.ManagedThreadId, i);
                }
            }
        }

        static void Main(string[] args)
        {
            List<Thread> threadList = new List<Thread>();

            for(int nThread = 0; nThread < 5; nThread++)
            {
                threadList.Add(new Thread(ExerciseThreads.ThreadLogger));
                threadList[nThread].Start();
            }

            foreach (Thread t in threadList)
            {
                t.Join();
            }

            Console.WriteLine("End Main");
        }
    }
}
