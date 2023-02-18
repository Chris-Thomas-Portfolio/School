using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateAccounts
{
    public abstract class AccountTemplate
    {
        private double balance = 0.0;
        public double GetBalance()
        {
            return balance;
        }

        public void SetDeposit(double deposit)
        {
            balance += deposit;
        }

        public void PayYearlyInterest()
        {
            double grossInterestPayment = balance * GetInterestRate();
            double netInterestPayment = grossInterestPayment - grossInterestPayment * GetTaxRate();
            balance += netInterestPayment;
        }

        protected abstract double GetTaxRate();


        protected abstract double GetInterestRate();

    }
}
