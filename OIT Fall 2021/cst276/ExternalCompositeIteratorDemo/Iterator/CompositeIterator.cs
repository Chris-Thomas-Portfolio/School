using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Iterator
{
    class CompositeIterator : AbstractIterator
    {
        Stack<AbstractIterator> stack = new Stack<AbstractIterator>();

        public CompositeIterator(OITComponent component)
        {
            inner = component;
           // inner.NodeDisplay();  //optional
            stack.Push(inner.CreateIterator()); //creates ReturnAllIterator
            current = 0;
        }

        public override void First()
        {            
            stack.Peek().First(); //on ReturnAllIterator
        }

        public override void MoveNext()
        {
            if (stack.Peek().GetCurrent() is OITComposite)
            {
                stack.Push(stack.Peek().GetCurrent().CreateIterator()); //pushes ReturnAllIterator
            }
            else
            {
                stack.Peek().MoveNext(); //on ReturnAllIterator
            }
        }

        public override bool IsDone()
        {
            if (stack.Count == 0)
            {
                return true;
            }
            else
            {
                if (stack.Peek().IsDone()) //on ReturnAllIterator
                {
                    stack.Pop();

                    if (stack.Count != 0)
                    {
                        stack.Peek().MoveNext(); //on ReturnAllIterator
                    }
                    return IsDone(); //recursive call on CompositeIterator
                }
                else
                    return false;
            }
        }

        public override OITComponent GetCurrent()
        {
            if (IsDone())
                throw new InvalidOperationException();
            return stack.Peek().GetCurrent(); //on ReturnAllIterator
        }
    }
}
