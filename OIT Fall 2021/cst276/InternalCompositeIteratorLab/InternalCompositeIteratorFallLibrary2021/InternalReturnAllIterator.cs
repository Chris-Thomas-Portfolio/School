using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorFallLibrary2021
{
    class InternalReturnAllIterator : AbstractIterator
    {
        public InternalReturnAllIterator(CompanyComposite company)
        {
            current = 0;
            inner = company;
        }
        public override void First()
        {
            current = 0; ;
        }

        public override CompanyComponent GetCurrent()
        {
            if (IsDone())
                Console.WriteLine( "Maybe throw exception?");
            return inner.GetCompanyComponents()[current];
        }

        public override bool IsDone()
        {
            return current > inner.GetCompanyComponents().Count - 1;
        }

        public override void MoveNext()
        {
            ++current;
        }
    }
}
