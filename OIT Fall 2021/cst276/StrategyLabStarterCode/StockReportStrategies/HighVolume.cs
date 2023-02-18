using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StockReportStrategies
{
    public class HighVolume : IFilterStrategy
    {
        public bool FilterStrategy(TradingDay day)
        {
            if (day.Volume > 20000000)
            {
                return true;
            }
            return false;
        }
    }
}
