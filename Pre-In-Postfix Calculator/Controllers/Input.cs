using System;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    class Input
    {
        private string input;
        private List<string> highPriority = new List<string> { };
        private List<string> mediumPriority = new List<string> { "*", "/", "^" };
        private List<string> lowPriority = new List<string> { "+", "-" };

        public Input(string input)
        {
            this.input = input;
        }

        public string GetPreFix()
        {
            Stack<string> operators = new Stack<string>(input.Length);
            Stack<string> operands = new Stack<string>(input.Length);

            for (int i = 0; i < input.Length; i++)
            {
                // Check the item is digit or not!
                if (Char.IsDigit(input[i]) || input[i] == '.' || input[i] == 'e')
                {
                    // handle desimal types.
                    bool haveDot = input[i] == '.';
                    string temp = haveDot ? "0." : input[i].ToString();

                    while (((i + 1) < input.Length) &&
                        (Char.IsDigit(input[i + 1]) || input[i + 1] == '.'))
                    {
                        if (input[i] == '.')
                        {
                            if (haveDot)
                                throw new Exception("bad number :(");

                            haveDot = true;
                        }

                        i++;
                        temp += input[i].ToString();
                    }

                    operands.Push(temp);
                }
                else
                {
                    var lastOperator = operators.Peek();


                    if (input[i] == ')')
                    {
                        // handle ( in input
                        while (!operators.Peek().Contains("("))
                        {
                            HandleStack(operators, operands);
                        }

                        operands.Push($"{operators.Pop()}{operands.Pop()})");
                    }
                    else if (!mediumPriority.Contains(input[i].ToString()) && !lowPriority.Contains(input[i].ToString()))
                    {
                        string temp = "";
                        bool condition;
                        do
                        {
                            temp += input[i];
                            i++;
                            condition = !mediumPriority.Contains(input[i].ToString()) && !lowPriority.Contains(input[i].ToString());
                        } while (condition && !Char.IsDigit(input[i]));

                        i--;
                        operators.Push(temp);
                    }
                    // If last item is null dont do any thing.
                    else if (lastOperator == default || lastOperator.Contains("("))
                    {
                        operators.Push(input[i].ToString());
                    }
                    /*else if (input[i] == '^')
                    {
                        HandleStack(operators, operands);
                        operators.Push(input[i].ToString());
                    }*/
                    else if (CheckPriority(lastOperator.ToString(), input[i].ToString()) == Priority.low)
                    {
                        HandleStack(operators, operands);
                        operators.Push(input[i].ToString());
                    }
                    else
                        operators.Push(input[i].ToString());
                }
            }

            HandleStack(operators, operands);
            return operands.Peek();
        }

        private Priority CheckPriority(string itemOne, string itemTwo)
        {
            if (itemOne == "(")
                return Priority.low;
            if (itemTwo == ")")
                return Priority.High;
            /*if (highPriority.Contains(itemTwo))
                return Priority.High;*/
            if (mediumPriority.Contains(itemTwo))
                return Priority.High;
            else
                return Priority.low;
        }

        private void HandleStack(Stack<string> operators, Stack<string> operands)
        {
            string temp = "";
            string operandsLastItem;

            while (operators.Peek() != default && !operators.Peek().Contains("("))
            {
                string B = operands.Pop();
                string A = operands.Pop();

                if (operators.Peek().ToString() == "^")
                {
                    operators.Pop();
                    operands.Push($"^{A},{B}");
                    continue;
                }

                // for handeling last item of stack with low priority! 
                if (lowPriority.Contains(operators.Peek().ToString()))
                {
                    B = temp + B;
                    temp = default;
                }

                temp = temp + operators.Pop().ToString();
                operands.Push($"{A},{B}");
            }

            operandsLastItem = operands.Pop();
            operands.Push(temp + operandsLastItem);
        }
    }
}