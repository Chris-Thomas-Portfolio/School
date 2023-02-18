using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollectionFall2021
{
    public class Employee
    {
        private string _name;
        private string _social;
        private double _salary;

        public double Salary
        {
            get { return _salary; }
        }
        public Employee(string name, string social, double salary)
        {
            _name = name;
            _social = social;
            _salary = salary;
        }
        public void DisplayEmployee()
        {
            Console.WriteLine(" {0}, {1}, {2} ",
                _name, _social, _salary);
        }
    }
}
