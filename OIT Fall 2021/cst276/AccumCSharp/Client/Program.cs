using System;
using Accumulator;

namespace Client
{
    class Program
    {
        static void Main(string[] args)
        {
            Acc a = new Acc();
            Console.WriteLine("The new total is: {0}", a.Accum(5));
            Console.WriteLine("The new total is: {0}", a.Accum(7));
            Console.WriteLine("The new total is: {0}", a.Accum(8));
        }
    }
}
