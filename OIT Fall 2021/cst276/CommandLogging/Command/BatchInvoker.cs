using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Command
{
    public class BatchInvoker
    {
        private List<ICommand> commands = new List<ICommand>();

        public void Execute(ICommand command)
        {
            commands.Add(command);
            if (commands.Count == 5)
            {
                foreach (ICommand comm in commands)
                {
                    comm.Execute();
                }
                commands.Clear();
                Thread.Sleep(500);
            }
        }
    }
}
