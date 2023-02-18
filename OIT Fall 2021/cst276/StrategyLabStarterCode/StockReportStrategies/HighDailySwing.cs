using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StockReportStrategies
{
    public class HighDailySwing : IFilterStrategy
    {
        public bool FilterStrategy(TradingDay day)
        {
            //logic before the "if" inside the "foreach"
            double swing = day.Open - day.Close;
            double percentageSwing = Math.Abs(swing / day.Open);

            if (percentageSwing > 0.1)
            {
                return true;
            }
            return false;
        }
    }


}
