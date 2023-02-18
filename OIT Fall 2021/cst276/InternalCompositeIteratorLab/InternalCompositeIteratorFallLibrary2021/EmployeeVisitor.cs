using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorFallLibrary2021
{
    public class EmployeeVisitor : IVisitor
    {
        int employeeCount = 0;
        double totalSalary = 0;
        public EmployeeVisitor(CompanyComponent component)
        {
            component.Accept(this);
        }

        public void Visit(Employee employee)
        {
            totalSalary += employee.Salary;
            employeeCount++;
            Console.WriteLine("The average employee salary is {0}", totalSalary / employeeCount);
        }

        public void Visit(CompanyComposite company)
        {
            
        }
    }
}
