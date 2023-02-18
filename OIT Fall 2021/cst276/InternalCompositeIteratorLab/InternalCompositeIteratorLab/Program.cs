using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using InternalCompositeIteratorFallLibrary2021;

namespace InternalCompositeIteratorLab
{
    class Program
    {
        static void Main(string[] args)
        {
            CompanyComponent company1 = new CompanyComposite("Oil Tech", "Oil Technologies");

            company1.Add(new Employee("Sally", "365-12-9871", 100000));
            company1.Add(new Employee("Sage", "846-32-9822", 30000));
            company1.Add(new Employee("Dave", "455-18-8743", 400000));

            CompanyComponent company2 = new CompanyComposite("Tech Tech", "Tech Technologies");

            company2.Add(new Employee("Illy", "365-22-4874", 10023000));
            company2.Add(new Employee("Rage", "846-32-1825", 100434));
            company2.Add(new Employee("Dan", "455-185-8746", 1340000));

            CompanyComponent tech = new CompanyComposite("Tech", "Technologies");

            tech.Add(company1);
            tech.Add(company2);

            CompanyComponent soda = new CompanyComposite("Soda", "Soda Pop");

            soda.Add(new Employee("Borg", "000-00-0001", 7584864));

            CompanyComponent allcompany = new CompanyComposite("Coke", "Coca Cola");

            allcompany.Add(tech);
            allcompany.Add(soda);

            //allcompany.Display();

            //AbstractIterator iter = new CompositeIterator(allcompany);

            //for (iter.First(); !iter.IsDone(); iter.MoveNext())
            //{
            //    iter.GetCurrent().NodeDisplay();
            //}

            //IVisitor Visitor = new CompanyCompositeVisitor(allcompany);
            IVisitor Visitor = new EmployeeVisitor(allcompany);
            
        }
    }
}
