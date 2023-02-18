using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdersDll
{
    public class OrderDecorator : AbstractOrderBase
    {
        protected AbstractOrderBase inner;

        protected OrderDecorator(AbstractOrderBase order)
        {
            inner = order;
        }
        public override void AddItem(string productCode, int quantity, double cost, double weight)
        {
            inner.AddItem(productCode, quantity, cost, weight);
        }

        public override double GetTotalCost()
        {
            return inner.GetTotalCost();
        }

        public override void PrintOrderItems()
        {
            inner.PrintOrderItems();
        }
    }
}
