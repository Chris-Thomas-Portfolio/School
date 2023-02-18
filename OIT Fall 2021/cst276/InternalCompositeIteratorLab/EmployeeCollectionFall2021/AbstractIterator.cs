using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollectionFall2021
{
    public abstract class AbstractIterator
    {
        protected int current;
        protected Company inner;

        public abstract void First();
        public abstract void MoveNext();
        public abstract bool IsDone();
        public abstract Employee GetCurrent();

    }
}
