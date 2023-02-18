using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Logger
{
    public class FileLogger : ILogger
    {
        private string logFile;
        private LogLevel logLevel;


        internal FileLogger()
        {
            logLevel = LogLevel.INFO;
            logFile = "logging.txt";
        }       

        internal FileLogger(LogLevel level)
        {
            logLevel = level;
            logFile = "logging.txt";
        }
       

        public void Log(string text)
        {
            StreamWriter writer = new StreamWriter(logFile, true);
            writer.WriteLine(text);
            writer.Close();
        }

        public void Log(LogLevel level, string text)
        {
            if (level >= logLevel)
            {
                Log(text);
            }
        }
    }
}
