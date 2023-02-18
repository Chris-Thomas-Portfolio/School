using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeCollectionFall2021
{
    public class Company
    {
        string _name = "Oil Tech";
        string _description = "Oil Technology";
        List<Employee> employees = new List<Employee>();

        public string Name
        {
            get { return _name; }
        }

        public List<Employee> GetEmployee()
        {
            return employees;
        }

        public void Add(Employee employee)
        {
            employees.Add(employee);
        }

        public void Remove(Employee employee)
        {
            employees.Remove(employee);
        }
    }
}
