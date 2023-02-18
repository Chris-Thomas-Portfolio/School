using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorFallLibrary2021
{
    public abstract class AbstractIterator
    {
        protected int current;
        protected CompanyComponent inner;

        public abstract void First();
        public abstract void MoveNext();
        public abstract bool IsDone();
        public abstract CompanyComponent GetCurrent();

    }
}
