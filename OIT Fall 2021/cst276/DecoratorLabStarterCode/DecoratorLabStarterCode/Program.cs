using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OrdersDll;

namespace DecoratorLabStarterCode
{
    class Program
    {
        static void Main(string[] args)
        {
            Order order = new Order();
            ExpressDeliveryOrderDecorator exp = new ExpressDeliveryOrderDecorator(order);
            //AmericanExpressDecorator card = new AmericanExpressDecorator(order);
            VisaDecorator card = new VisaDecorator(exp);
            order.AddItem("BroncoHats", 2, 1.5, 0.2);
            order.AddItem("BroncoGloves", 1, 3.0, 0.5);
            order.AddItem("BroncoSocks", 6, 1.9, 0.1);
            order.AddItem("BroncoBanners", 3, 8.0, 1.5);
            order.AddItem("BroncoFootBalls", 4, 5.6, 0.6);
            order.AddItem("BroncoJerseys", 2, 2.3, 0.4);
            

            card.PrintOrderItems();
            
            Console.ReadLine();
        }
    }
}
