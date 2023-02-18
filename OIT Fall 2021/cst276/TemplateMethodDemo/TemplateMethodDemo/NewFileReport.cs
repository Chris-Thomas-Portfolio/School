using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;

namespace TemplateMethodDemo
{
    class NewFileReport : ReportTemplate
    {
        string dirName;

        public NewFileReport(string directory)
        {
            dirName = directory;
        }
        protected override string GetTitle()
        {
            return string.Format("File Report on directory {0}", dirName);
        }
        protected override string[] GetColumnNames()
        {
            return new string[] { "File Name", "File Size", "Last Modified" };
        }
        protected override List<object[]> GetRows()
        {
            List<object[]> rows = new List<object[]>();
            foreach (FileInfo file in new DirectoryInfo(dirName).GetFiles())
            {
                object[] row = new object[] { file.Name, file.Length, file.LastWriteTime };
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
