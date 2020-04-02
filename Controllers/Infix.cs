using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace Calculator
{
    class Infix
    {
        public static string[] expressions = new string[] { "tan", "sin", "cos", "log", "lgn", "fct" };
        public static string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        public static string[] expANDopr = new string[] { "tan", "sin", "cos", "log", "lgn", "fct", "(", ")", "^", "*", "/", "+", "-" };
        public static string[] operators = new string[] { "(", ")", "^", "*", "/", "+", "-", "!" };
        public static string[] operands = new string[] { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

        public static string Evaluate(string entry)
        {
            return ExpAns(Expcreate(entry));
        }

        public static List<string> Expcreate(string input)
        {
            List<String> tempkm = new List<string>();
            for (int i = 0; i < input.Length; i++)
            {
                if (letters.Contains(input[i]) && input.Length >= 1)
                {
                    string exp;
                    try
                    {
                        exp = String.Concat(input[i], input[i + 1], input[i + 2]);
                        if (expressions.Contains(exp))
                        {
                            Console.WriteLine(exp);
                            tempkm.Add(exp);
                            i += 2;
                        }
                        //else
                        //{
                        //    string tempparam = input[i].ToString();
                        //    i++;
                        //    while (letters.Contains(input[i]) && i < input.Length)
                        //    {
                        //        tempparam += input[i];
                        //        i++;
                        //    }
                        //    tempkm.Add(GetValue(tempparam));
                        //}
                    }
                    catch
                    {
                        exp = "";
                    }
                }
                else if (operands.Contains(input[i].ToString()) || input[i].ToString() == ".")
                {
                    List<string> foundNumber = input[i].ToString() == "." ? new List<string> { "0", "." } : new List<string> { input[i].ToString() };
                    i++;
                    while ((operands.Contains(input[i].ToString()) || input[i].ToString() == ".") && i < input.Length)
                    {
                        foundNumber.Add(input[i].ToString());
                        i++;
                    }
                    i--;
                    tempkm.Add(String.Join("", foundNumber));
                }
                else if (operators.Contains(input[i].ToString()))
                {
                    if (input[i].ToString() == "!")
                    {
                        if (tempkm.Last() == ")")
                        {
                            double number = double.Parse(tempkm[tempkm.Count - 2]);
                            tempkm[tempkm.Count - 2] = Factorial(number).ToString();
                        }
                        else
                        {
                            double number = double.Parse(tempkm[tempkm.Count - 1]);
                            tempkm[tempkm.Count - 1] = Factorial(number).ToString();
                        }
                    }
                    else
                    {
                        tempkm.Add(input[i].ToString());
                    }
                }
            }

            for (int i = 1; i < tempkm.Count - 2; i++)
            {
                if (tempkm[i] == "-" && operators.Contains(tempkm[i - 1]))
                {
                    tempkm.Insert(i + 2, ")");
                    tempkm.Insert(i, "0");
                    tempkm.Insert(i, "(");
                }
            }

            return (tempkm);
        }

        public static string ExpAns(List<string> explist)
        {
            Console.WriteLine(String.Join(",", explist));
            Stack<string> operatorStack = new Stack<string>();
            Stack<string> operandStack = new Stack<string>();

            for (int i = 0; i < explist.Count; i++)
            {
                string item = explist[i];
                if (expANDopr.Contains(item))
                {
                    if (item != ")")
                    {
                        operatorStack.Push(item);
                    }
                    else
                    {
                        if (!expressions.Contains(operatorStack.Peek()))
                        {

                            string OPTEMP = operatorStack.Pop();

                            if (OPTEMP == "(")
                            {
                                try
                                {
                                    if (expressions.Contains(operatorStack.Peek()))
                                    {
                                        OPTEMP = operatorStack.Pop();
                                        double expOperator;
                                        switch (OPTEMP)
                                        {
                                            case "tan":
                                                expOperator = Convert.ToDouble(operandStack.Pop()) * (Math.PI / 180);
                                                operandStack.Push(Math.Tan(expOperator).ToString());
                                                break;
                                            case "sin":
                                                expOperator = Convert.ToDouble(operandStack.Pop()) * (Math.PI / 180);
                                                operandStack.Push(Math.Sin(expOperator).ToString());
                                                break;
                                            case "cos":
                                                expOperator = Convert.ToDouble(operandStack.Pop()) * (Math.PI / 180);
                                                operandStack.Push(Math.Cos(expOperator).ToString());
                                                break;
                                            case "log":
                                                operandStack.Push(Math.Log10(Convert.ToDouble(operandStack.Pop())).ToString());
                                                break;
                                            case "lgn":
                                                operandStack.Push(Math.Log(Convert.ToDouble(operandStack.Pop())).ToString());
                                                break;
                                            case "fct":
                                                operandStack.Push(Factorial(Convert.ToDouble(operandStack.Pop())).ToString());
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                }
                                catch
                                {
                                    Console.WriteLine("Got an error, maybe stack is empty and tried to get peek");
                                }
                            }
                            else
                            {
                                double SECONDNUM = Convert.ToDouble(operandStack.Pop());
                                double FIRSTNUM = Convert.ToDouble(operandStack.Pop());
                                double eqAnswer;
                                switch (OPTEMP)
                                {
                                    case "^":
                                        eqAnswer = Math.Pow(FIRSTNUM, SECONDNUM);
                                        operandStack.Push(eqAnswer.ToString());
                                        break;
                                    case "*":
                                        eqAnswer = FIRSTNUM * SECONDNUM;
                                        operandStack.Push(eqAnswer.ToString());
                                        break;
                                    case "/":
                                        eqAnswer = FIRSTNUM / SECONDNUM;
                                        operandStack.Push(eqAnswer.ToString());
                                        break;
                                    case "+":
                                        eqAnswer = FIRSTNUM + SECONDNUM;
                                        operandStack.Push(eqAnswer.ToString());
                                        break;
                                    case "-":
                                        eqAnswer = FIRSTNUM - SECONDNUM;
                                        operandStack.Push(eqAnswer.ToString());
                                        break;
                                }
                                try
                                {
                                    if (operatorStack.Peek() == "(")
                                    {
                                        operatorStack.Pop();
                                    }
                                }
                                catch
                                {
                                    Console.WriteLine("Tried to pop operator stack after finding the answer but got an error \nMaybe stack is emty");
                                }
                            }
                        }
                        else
                        {
                            try
                            {
                                while (expressions.Contains(operatorStack.Peek()))
                                {
                                    string expression = operatorStack.Pop();
                                    double lastOperand = Convert.ToDouble(operandStack.Pop()) * (Math.PI / 180);
                                    switch (expression)
                                    {
                                        case "tan":
                                            operandStack.Push(Math.Tan(lastOperand).ToString());
                                            break;
                                        case "sin":
                                            operandStack.Push(Math.Sin(lastOperand).ToString());
                                            break;
                                        case "cos":
                                            operandStack.Push(Math.Cos(lastOperand).ToString());
                                            break;
                                        case "log":
                                            operandStack.Push(Math.Log10(Convert.ToDouble(operandStack.Pop())).ToString());
                                            break;
                                        case "Lgn":
                                            operandStack.Push(Math.Log(Convert.ToDouble(operandStack.Pop())).ToString());
                                            break;
                                        case "fct":
                                            operandStack.Push(Factorial(Convert.ToDouble(operandStack.Pop())).ToString());
                                            break;
                                        default:
                                            break;
                                    }
                                    operatorStack.Pop();
                                }
                            }
                            catch
                            {
                                Console.WriteLine("A while was trying to access operator or expression but stack apeared to be empty");
                            }
                        }
                    }
                }
                else
                {
                    operandStack.Push(item);
                }
            }
            try
            {
                return operandStack.Peek();
            }
            catch
            {
                return "0";
            }
        }

        private static double Factorial(double n)
        {
            if (n == 1)
            {
                return 1;
            }
            else
            {
                return n * Factorial(n - 1);
            }
        }

        //public static string GetValue(string valueName)
        //{
        //    string ans = "/";
        //    Window1 diobox = new Window1(valueName);
        //    Thread thread = new Thread(() =>
        //    {
        //        diobox.Show();
        //    });
        //    thread.Start();

        //    diobox.event_1.WaitOne();
        //    ans = diobox.Answer;

        //    return ans;
        //}

    }
}