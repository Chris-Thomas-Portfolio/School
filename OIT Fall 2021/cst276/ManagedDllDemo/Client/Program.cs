using System;
using CalcDll;

namespace Client
{
    class Program
    {
        static void Main(string[] args)
        {
            Calc c = new Calc();
            Console.WriteLine(c.Add(6, 7));
            Console.WriteLine(c.Sub(6, 7));
        }
    }
}
