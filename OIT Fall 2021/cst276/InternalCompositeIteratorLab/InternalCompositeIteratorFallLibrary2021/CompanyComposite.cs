using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorFallLibrary2021
{
    public class CompanyComposite : CompanyComponent
    {
        string _name;
        string _description;
        List<CompanyComponent> employees = new List<CompanyComponent>();

        
        public string Name
        {
            get { return _name; }
        }

        public CompanyComposite(string name, string description)
        {
            _name = name;
            _description = description;
        }
        public override List<CompanyComponent> GetCompanyComponents()
        {
            return employees;
        }

        public override void Add(CompanyComponent employee)
        {
            employees.Add(employee);
        }

        public override void Remove(CompanyComponent employee)
        {
            employees.Remove(employee);
        }
        public override AbstractIterator CreateIterator()
        {
            return new InternalReturnAllIterator(this);
        }

        public override void Display()
        {
            Console.WriteLine(_name + " " + _description);

            AbstractIterator iter = CreateIterator();
            for(iter.First(); !iter.IsDone(); iter.MoveNext())
            {
                iter.GetCurrent().Display();
            }
        }

        public override void NodeDisplay()
        {
            Console.WriteLine("**********     " + _name + "    *************");
        }

        public override void Accept(IVisitor visitor)
        {
            visitor.Visit(this);

            AbstractIterator iter = CreateIterator();
            for (iter.First(); !iter.IsDone(); iter.MoveNext())
            {
                iter.GetCurrent().Accept(visitor);
            }
        }
    }
}
