using System;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    class Evaluate
    {
        private static Stack<double> operands;
        private static Stack<char> operators;

        public static double PreFix(string input)
        {
            var items = input.Split(',');
            //var items = inputList.ToArray();

            // initialize the stacks.
            operands = new Stack<double>(input.Length);
            operators = new Stack<char>(input.Length);

            for (int i = items.Length - 1; i >= 0; i--)
            {
                string temp = items[i];

                // check the item type
                bool isoperand = IsOperand(temp);
                double operand = isoperand ? double.Parse(temp) : 0;

                if (!isoperand)
                {
                    bool pushed = false;

                    for (int j = temp.Length - 1; j >= 0; j--)
                    {
                        if (!(Char.IsDigit(temp[j]) || temp[j] == '.'))
                        {
                            if (!pushed)
                            {
                                operands.Push(double.Parse(temp.Substring(j + 1)));
                                pushed = !pushed;
                            }

                            operators.Push(temp[j]);
                            EvaluateStack();
                        }
                    }

                }
                else
                    operands.Push(operand);
            }

            return operands.Pop();
        }

        public static double PostFix(string input)
        {
            var items = input.Split(',');
            //var items = inputList.ToArray();

            // initialize the stacks.
            operands = new Stack<double>(input.Length);
            operators = new Stack<char>(input.Length);

            foreach (string item in items)
            {
                // check the item type
                bool isoperand = IsOperand(item);
                double operand = isoperand ? double.Parse(item) : 0;

                if (!isoperand)
                {
                    string temp = String.Empty;
                    foreach (char ch in item)
                    {
                        if (!Char.IsDigit(ch))
                        {
                            if (!string.IsNullOrEmpty(temp))
                            {
                                operands.Push(double.Parse(temp));
                                temp = String.Empty;
                            }

                            operators.Push(ch);
                            EvaluateStack(true);
                        }
                        else
                            temp += ch;
                    }
                }
                else
                    operands.Push(operand);
            }

            return operands.Pop();
        }

        private static bool IsOperand(string item)
        {
            if (!Double.TryParse(item, out double nothong))
                return false;
            else if (item.Contains("+") || item.Contains("-"))
                return false;
            else
                return true;
        }

        private static void EvaluateStack(bool reverse= false)
        {
            while (operators.Peek() != default && operators.Peek() != ')')
            {
                double itemA = operands.Pop();
                double itemB = operands.Pop();

                operands.Push(reverse ? DoOperation(itemB, itemA, operators.Pop()) : DoOperation(itemA, itemB, operators.Pop()));
            }
        }

        private static double DoOperation(double itemA, double itemB, char _operator)
        {
            double result = 0.0;

            switch (_operator)
            {
                case '+':
                    result = itemA + itemB;
                    break;
                case '-':
                    result = itemA - itemB;
                    break;
                case '*':
                    result = itemA * itemB;
                    break;
                case '/':
                    result = itemA / itemB;
                    break;
                case '^':
                    result = Math.Pow(itemA, itemB);
                    break;
                default:
                    throw new Exception("Unknown operator!!");
            }

            return result;
        }
    }
}
