﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateAccounts
{
     public class TaxFreeSavings : AccountTemplate
    {
        protected override double GetInterestRate()
        {
            double interestRate = .06;
            return interestRate;
        }

        protected override double GetTaxRate()
        {
            double taxRate = 0;
            return taxRate;
        }

    }
}

