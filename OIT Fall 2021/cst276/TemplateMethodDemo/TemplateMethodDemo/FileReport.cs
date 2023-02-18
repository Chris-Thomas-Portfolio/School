using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Principal;
using System.Text;
using System.Threading.Tasks;

namespace TemplateMethodDemo
{
    class FileReport
    {
        string dirName;

        public FileReport(string dir)
        {
            dirName = dir;
        }

        public void ProduceReport()
        {
            Console.WriteLine("File Report on directory {0}: ", dirName);
            Console.WriteLine("File Name, File Size, Last Modified");

            DirectoryInfo dir = new DirectoryInfo(dirName);

            foreach (FileInfo file in dir.GetFiles())
            {
                Console.Write(file.Name);
                Console.Write(",");
                Console.Write(file.Length);
                Console.Write(", ");
                Console.WriteLine(file.LastWriteTime); ;
            }

            Console.WriteLine("Report ran on {0} by {1}", DateTime.Now, WindowsIdentity.GetCurrent().Name);
        }
    }
}
