using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollectionFall2021
{
    public class InternalFatCatsIterator : AbstractIterator
    {
        private double fatCat;
        public InternalFatCatsIterator(Company company, double salary)
        {
            current = 0;
            inner = company;
            fatCat = salary;
        }
        public override void First()
        {
            current = 0;
            while (!IsDone() && inner.GetEmployee()[current].Salary < fatCat)
                ++current;
        }

        public override Employee GetCurrent()
        {
            if (IsDone())
                Console.WriteLine("Maybe throw exception?");
            return inner.GetEmployee()[current];
        }

        public override bool IsDone()
        {
            return current > inner.GetEmployee().Count - 1;
        }

        public override void MoveNext()
        {
            ++current;
            while (!IsDone() && inner.GetEmployee()[current].Salary < fatCat)
                ++current;
        }
    }
}
