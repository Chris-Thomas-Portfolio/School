using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace TemplateMethodDemo
{
    abstract class ReportTemplate
    {
        protected abstract string GetTitle();

        protected abstract string[] GetColumnNames();

        protected abstract List<object[]> GetRows();

        protected abstract string GetFooter();
        public void ProduceReport(IReportOutputStrategy OutputBehavior)
        {
            // Console.WriteLine(GetTitle());
            OutputBehavior.OutputTitle(GetTitle());

            OutputBehavior.OutputHeadings(GetColumnNames());

            //bool first = true;
            //foreach (string column in GetColumnNames())
            //{
            //    if (first)
            //    {
            //        Console.Write(column);
            //        first = false;
            //    }
            //    else
            //    {
            //        Console.Write(", ");
            //        Console.Write(column);
            //    }
            //}
            //Console.WriteLine();

            foreach (object[] row in GetRows())
            {
                //Console.WriteLine(row.Aggregate((accumstr, nextstr) => accumstr.ToString() +
                //", " + nextstr.ToString()).ToString());
                OutputBehavior.OutputRow(row);
            }

            // Console.WriteLine(GetFooter());
            OutputBehavior.OutputFooter(GetFooter());
        }
    }
}
