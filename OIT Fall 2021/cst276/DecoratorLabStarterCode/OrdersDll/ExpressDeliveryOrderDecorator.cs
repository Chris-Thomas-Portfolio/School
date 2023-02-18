using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class ExpressDeliveryOrderDecorator : OrderDecorator
    { 
        public ExpressDeliveryOrderDecorator(AbstractOrderBase order) : base(order)
        { }

        public override double GetTotalCost()
        {
            return 4.00 + inner.GetTotalCost();
        }

        public override void PrintOrderItems()
        {
            Console.WriteLine("A Shipping Cost May Apply");
            inner.PrintOrderItems();
            Console.WriteLine(string.Format("Grand Total with Shipping {0:C}", GetTotalCost()));
        }
    }
}
