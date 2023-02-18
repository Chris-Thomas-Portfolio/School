using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorFallLibrary2021
{
    public abstract class CompanyComponent
    {
        public virtual void Add(CompanyComponent employee)
        {
            throw new System.Exception("Unsupported Operation");
        }

        public virtual void Remove(CompanyComponent employee)
        {
            throw new System.Exception("Unsupported Operation");
        }

        public virtual List<CompanyComponent> GetCompanyComponents()
        {
            throw new System.Exception("Unsupported Operation");
        }

        public virtual AbstractIterator CreateIterator()
        {
            throw new System.Exception("Unsupported Operation");
        }

        public virtual void Display()
        {
            throw new System.Exception("Unsupported Operation");
        }
        public virtual void NodeDisplay()
        {
            throw new System.Exception();
        }

        public virtual void Accept(IVisitor visitor)
        {
            throw new System.Exception();
        }
    }
}
