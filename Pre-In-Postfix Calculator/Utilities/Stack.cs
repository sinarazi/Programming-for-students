using System;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    class Stack<T>
    {
        private T[] stackArray;
        private int lastIndex = -1;

        /// <summary>
        /// Count of items in the stack.
        /// </summary>
        public int Count 
        {
            get => this.lastIndex + 1;
        }
        public bool IsEmpety 
        { 
            get => this.lastIndex == -1;
        }

        public Stack()
        {
            // the default capicity is 10.
            this.stackArray = new T[10];
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="capicity">Capicity of stack</param>
        public Stack(int capicity)
        {
            // set the stack capicity
            this.stackArray = new T[capicity];
        }

        /// <summary>
        /// Removes and returns the object at the top of the Stack.
        /// </summary>
        /// <returns>object at the top of the Stack</returns>
        public T Pop()
        {
            // check the stack array.
            if(lastIndex <= -1)
            {
                throw new Exception("The Stack is empety!!!");
            }
            else
            {
                T lastItem = this.stackArray[this.lastIndex];
                // set the removed index to null, the GC auto maticly free the ram.
                this.stackArray[this.lastIndex--] = default;
                return lastItem;
            }
        }

        /// <summary>
        /// Inserts an object at the top of the Stack.
        /// </summary>
        /// <param name="item"></param>
        public void Push(T item)
        {
            // check the stack array.
            if(lastIndex >= stackArray.Length)
            {
                throw new Exception("Stack over flow!!!!");
            } 
            else
            {
                this.stackArray[++this.lastIndex] = item;
            }
        }

        /// <summary>
        /// Returns the object at the top of the Stack without removing it.
        /// </summary>
        /// <returns></returns>
        public T Peek()
        {
            if(this.lastIndex == -1)
            {
                //Console.WriteLine("The Stack is empety");
                return default;
            }
            else
            {
                return this.stackArray[this.lastIndex];
            }
        }

        public override string ToString()
        {
            string temp = "";
            for (int i = 0; i <= this.lastIndex; i++)
            {
                temp += this.stackArray[i].ToString();
                temp += " ";
            }

            return temp;
        }
    }
}
