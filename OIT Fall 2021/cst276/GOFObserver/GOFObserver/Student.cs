using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace GOFObserver
{
    class Student
    {
        List<IStudentObserver> observers = new List<IStudentObserver>();

        public void Attach(IStudentObserver obs)
        {
            observers.Add(obs);
        }

        public void Detach(IStudentObserver obs)
        {
            observers.Remove(obs);
        }

        public void DoWork()
        {
            foreach (IStudentObserver observer in observers)
            {
                observer.StartedWork();

                for (int i = 0; i < 10; i++)
                {
                    observer.Working();
                    Thread.Sleep(100);
                }

                observer.FinishedWork();
            }
        }
    }
}
