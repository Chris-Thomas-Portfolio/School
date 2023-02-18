using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GOFObserver
{
    interface IStudentObserver
    {
        void StartedWork();
        void Working();
        void FinishedWork();
    }
}
