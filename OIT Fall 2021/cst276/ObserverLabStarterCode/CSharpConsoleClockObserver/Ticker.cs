using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace CSharpConsoleClockObserver
{
    delegate void OnSecondsDelegate();
    delegate void OnTenthsDelegate();
    delegate void OnHundredthsDelegate();
    class Ticker
    {

        public event OnSecondsDelegate OnSecondsTick;
        public event OnTenthsDelegate OnTenthsTick;
        public event OnHundredthsDelegate OnHundredthsTick;

        private bool done;
        public bool Done
        {
            get { return done; }
            set { done = value; }
        }

        public Ticker()
        {
            OnSecondsTick += NullHandler;
            OnTenthsTick += NullHandler;
            OnHundredthsTick += NullHandler;
        }
        public void NullHandler()
        { }
        public void Run()
        {
            int count = 0;
            while (!done)
            {
                Interlocked.Increment(ref count);

                OnHundredthsTick();
                if (count % 100 == 0)
                {
                    OnSecondsTick();
                }
                if (count % 10 == 0)
                {
                    OnTenthsTick();
                }
              
            }
        }       
    }
}
