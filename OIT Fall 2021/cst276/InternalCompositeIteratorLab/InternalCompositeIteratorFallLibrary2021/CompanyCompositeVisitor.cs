using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorFallLibrary2021
{
    public class CompanyCompositeVisitor : IVisitor
    {
        public CompanyCompositeVisitor(CompanyComponent component)
        {
            component.Accept(this);
        }

        public void Visit(Employee employee)
        {
            
        }

        public void Visit(CompanyComposite company)
        {
            Console.WriteLine("I am at composite node");
        }
    }
}
