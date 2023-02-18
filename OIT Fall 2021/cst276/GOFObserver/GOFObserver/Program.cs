using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GOFObserver
{
    class Program
    {
        static void Main(string[] args)
        {
            Professor Breedlove = new Professor();
            Spouse JimBo = new Spouse();

            Student Sally = new Student();

            Sally.Attach(Breedlove);
            Sally.Attach(JimBo);

            Sally.DoWork();
        }
    }
}
