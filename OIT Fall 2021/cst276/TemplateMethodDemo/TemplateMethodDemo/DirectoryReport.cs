using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Principal;

namespace TemplateMethodDemo
{
    class DirectoryReport : ReportTemplate
    {
        string dirName;

        public DirectoryReport(string directory)
        {
            dirName = directory;
        }
        protected override string GetTitle()
        {
            return string.Format("Directory Report on directory {0}", dirName);
        }
        protected override string[] GetColumnNames()
        {
            return new string[] { "File Name", "Last Modified" };
        }
        protected override List<object[]> GetRows()
        {
            List<object[]> rows = new List<object[]>();
            foreach (DirectoryInfo dir in new DirectoryInfo(dirName).GetDirectories())
            {
                object[] row = new object[] { dir.Name, dir.LastWriteTime };
                rows.Add(row);
            }

            return rows;
        }
        protected override string GetFooter()
        {
            return string.Format("Report ran on {0} by {1}", DateTime.Now, WindowsIdentity.GetCurrent().Name);
        }
    }
}
