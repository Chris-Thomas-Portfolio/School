using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateMethodDemo
{
    class Program
    {
        private static void OutputReport(ReportTemplate report, IReportOutputStrategy strategy)
        {
            report.ProduceReport(strategy);
        }
        static void Main(string[] args)
        {
            // FileReport report = new FileReport(@"c:\windows");
            //NewFileReport report = new NewFileReport(@"c:\windows");
             DirectoryReport report = new DirectoryReport(@"c:\windows");
            // ConsoleOutputStrategy strategy = new ConsoleOutputStrategy();
            HTMLOutputReportStrategy strategy = new HTMLOutputReportStrategy("HTMLReport.html");
            OutputReport(report, strategy);
        }
    }
}
