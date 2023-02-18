using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Logger
{
    class FileLoggerFactory : ILoggerFactory
    {
        public ILogger CreateLogger()
        {
            return new FileLogger();
        }

        public ILogger CreateLogger(LogLevel logLevel)
        {
            return new FileLogger(logLevel);
        }
    }
}
