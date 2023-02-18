using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpConsoleClockObserver
{
    class SecondClock : Clock, IDisposable
    {

        private Ticker _tick;
        public SecondClock(int originalColumn, int originalRow, ConsoleColor? color, Ticker tick)
            : base(originalColumn, originalRow, color)
        {
            _tick = tick;
            _tick.OnSecondsTick += Second;
        }

        public void Dispose()
        {
            _tick.OnSecondsTick -= Second;
        }

        private void Second()
        {
            DateTime dt = DateTime.Now;

            WriteAt(dt.Hour, 0, 0, 2);
            WriteAt(":", 2, 0);
            WriteAt(dt.Minute, 3, 0, 2);
            WriteAt(":", 5, 0);
            WriteAt(dt.Second, 6, 0, 2);
        }   
    }

    class HundredthSecondClock : Clock, IDisposable
    {
        private Ticker _tick;
        public HundredthSecondClock(int originalColumn, int originalRow, ConsoleColor? color, Ticker tick)
            : base(originalColumn, originalRow, color)
        {
            _tick = tick;
            _tick.OnHundredthsTick += HundredthSecond;
        }

        public void Dispose()
        {
            _tick.OnHundredthsTick -= HundredthSecond;
        }

        private void HundredthSecond()
        {
            DateTime dt = DateTime.Now;

            WriteAt(dt.Hour, 0, 0, 2);
            WriteAt(":", 2, 0);
            WriteAt(dt.Minute, 3, 0, 2);
            WriteAt(":", 5, 0);
            WriteAt(dt.Second, 6, 0, 2);
            WriteAt(".", 8, 0);
            WriteAt(dt.Millisecond / 10, 9, 0, 2);
        }
    }

    class TenthSecondClock : Clock, IDisposable
    {
        private Ticker _tick;
        public TenthSecondClock(int originalColumn, int originalRow, ConsoleColor? color, Ticker tick)
            : base(originalColumn, originalRow, color)
        {
            _tick = tick;
            _tick.OnTenthsTick += TenthSecond;
        }

        public void Dispose()
        {
            _tick.OnTenthsTick -= TenthSecond;
        }

        private void TenthSecond()
        {
            DateTime dt = DateTime.Now;

            WriteAt(dt.Hour, 0, 0, 2);
            WriteAt(":", 2, 0);
            WriteAt(dt.Minute, 3, 0, 2);
            WriteAt(":", 5, 0);
            WriteAt(dt.Second, 6, 0, 2);
            WriteAt(".", 8, 0);
            WriteAt(dt.Millisecond / 100, 9, 0, 1);
        }
    }
}
