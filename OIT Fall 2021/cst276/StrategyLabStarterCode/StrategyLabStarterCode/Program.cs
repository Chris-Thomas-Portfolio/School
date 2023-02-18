using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using StockReportStrategies;



namespace StrategyLabStarterCode
{
    class Program
    {
        private static void ReportTradingDays(StockMarket tradingDays, IFilterStrategy strategy)
        {
            foreach (TradingDay day in tradingDays.GetTradingDays())
            {
                if (strategy.FilterStrategy(day) == true)
                {
                    Console.WriteLine(day.ToString());
                }
            }
        }

        static void Main(string[] args)
        {
            StockMarket tradingDays = new StockMarket(@"..\..\stockData.csv");
            //HighDailySwing swing = new HighDailySwing();
            HighVolume volume = new HighVolume();
            ReportTradingDays(tradingDays, volume);
        }        
    }
}
