using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class AmericanExpressDecorator : OrderDecorator
    {
        public AmericanExpressDecorator(AbstractOrderBase card) : base(card)
        { }
        public override double GetTotalCost()
        {
            return 5.00 + inner.GetTotalCost();
        }

        public override void PrintOrderItems()
        {
            Console.WriteLine("A Charge Cost May Apply");
            inner.PrintOrderItems();
            Console.WriteLine(string.Format("Grand Total with Card Charge {0:C}", GetTotalCost()));
        }
    }
}
