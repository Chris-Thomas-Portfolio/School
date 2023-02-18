using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateAccounts
{
    public class VariableInterestAccount : AccountTemplate
    {
        protected override double GetInterestRate()
        {
            if (GetBalance() < 1000)
            {
                double interestRate = .05;
                return interestRate;
            }
            else if (GetBalance() < 6000)
            {
                double interestRate = 0.6;
                return interestRate;
            }
            else
            {
                double interestRate = .08;
                return interestRate;
            }
            
        }

        protected override double GetTaxRate()
        {
            double taxRate = .25;
            return taxRate;
        }
    }
}
