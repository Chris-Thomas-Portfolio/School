using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateLabStarterCode
{
    class BankAccount
    {
        double interestRate;
        double taxRate;
        double balance;

        public BankAccount()
        {
            interestRate = 0.06;
            taxRate = 0.25;
            balance = 0.0;
        }

        public void SetDeposit(double value)
        {
            balance += value;
        }

        public void PayYearlyInterest()
        {
            double grossInterestPayment = balance * interestRate;
            double netInterestPayment = grossInterestPayment - grossInterestPayment * taxRate;
            balance += netInterestPayment;
        }

        public double GetBalance()
        {
            return balance;
        }
    }
}
