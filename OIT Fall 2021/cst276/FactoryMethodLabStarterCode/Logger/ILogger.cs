using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Logger
{
    public interface ILogger
    {
        void Log(string text);
        void Log(LogLevel level, string text);
    }
}
