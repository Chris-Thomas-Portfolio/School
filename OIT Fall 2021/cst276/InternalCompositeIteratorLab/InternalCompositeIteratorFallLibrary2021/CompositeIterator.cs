using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternalCompositeIteratorFallLibrary2021
{
   public class CompositeIterator : AbstractIterator
    {
        Stack<AbstractIterator> stack = new Stack<AbstractIterator>();

        public CompositeIterator(CompanyComponent component)
        {
            inner = component;
            stack.Push(inner.CreateIterator());
            current = 0;
        }
        public override void First()
        {
            stack.Peek().First();
        }

        public override CompanyComponent GetCurrent()
        {
            if (IsDone())
                throw new InvalidOperationException();
            return stack.Peek().GetCurrent();
        }

        public override bool IsDone()
        {
            if (stack.Count == 0)
            {
                return true;
            }
            else
            {
                if (stack.Peek().IsDone())
                {
                    stack.Pop();

                    if (stack.Count != 0)
                    {
                        stack.Peek().MoveNext();
                    }
                    return IsDone();
                }
                else
                    return false;
            }
        }

        public override void MoveNext()
        {
            if (stack.Peek().GetCurrent() is CompanyComposite)
            {
                stack.Push(stack.Peek().GetCurrent().CreateIterator());
            }
            else
            {
                stack.Peek().MoveNext();
            }
        }
    }
}
