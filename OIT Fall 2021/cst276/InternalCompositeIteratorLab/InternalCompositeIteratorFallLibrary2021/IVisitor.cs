using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorFallLibrary2021
{
    public interface IVisitor
    {
        void Visit(CompanyComposite composite);
        void Visit(Employee employee);
    }
}
