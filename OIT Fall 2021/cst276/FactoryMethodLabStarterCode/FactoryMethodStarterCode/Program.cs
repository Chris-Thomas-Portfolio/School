using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Logger;
using System.Configuration;

namespace FactoryMethodStarterCode
{
    class Program
    {
        private static ILoggerFactory LoadFactory(string factoryName)
        {
            string factoryTypeAsString = ConfigurationManager.AppSettings[factoryName];
            Type factoryType = Type.GetType(factoryTypeAsString);
            return (ILoggerFactory)Activator.CreateInstance(factoryType);
        }
        static void Main(string[] args)
        {
            ILoggerFactory factory = LoadFactory("ConsoleFactory");
            ILogger logger1 = factory.CreateLogger();
            logger1.Log("Log message");

            ILoggerFactory factory1 = LoadFactory("ConsoleFactory");
            ILogger logger2 = factory.CreateLogger(LogLevel.ERROR);
            logger2.Log(LogLevel.WARN, "Should not see this");
            logger2.Log(LogLevel.ERROR, "Error Message");
            logger2.Log(LogLevel.FATAL, "Fatal Message");

            ILoggerFactory factory2 = LoadFactory("FileFactory");
            ILogger flogger1 = factory2.CreateLogger();
            flogger1.Log("Log message");

            ILoggerFactory factory3 = LoadFactory("FileFactory");
            ILogger flogger2 = factory3.CreateLogger(LogLevel.ERROR);
            flogger2.Log(LogLevel.WARN, "Should not see this");
            flogger2.Log(LogLevel.ERROR, "Error Message");
            flogger2.Log(LogLevel.FATAL, "Fatal Message");
        }
    }
}
