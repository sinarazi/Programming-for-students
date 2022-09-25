using Calculator;
using System;

namespace Calculator
{
    class ConvertTo
    {
        public string INstr = "", POSTstr = "", eval = "";
        private Stack<string> myStack;

        public ConvertTo(string myStr = "", string myStr2 = "")
        {
            INstr = myStr;
            POSTstr = myStr2;
        }



        private bool IsLetter(char ele)
        {
            return (ele >= 'a' && ele <= 'z') || (ele >= 'A' && ele <= 'Z');
        }

        private bool IsOperator(char symbol)
        {
            switch (symbol)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                case '(':
                case ')':
                case '%':
                    return true;
            }
            return false;
        }

        private bool IsStringANum(string op1)
        {
            for (var i = 0; i < op1.Length; i++)
                if (char.IsNumber(op1[i]))
                    return true;
            return false;
        }

        private short priority(char symbol)
        {
            switch (symbol)
            {
                case '+':
                case '-':
                    return 2;
                case '*':
                case '/':
                case '%':
                    return 3;
                case '^':
                    return 4;
                default:
                    return 1;
            }
        }


        public string GetPostfix()
        {
            //if (POSTstr != "") return POSTstr;
            if (INstr.Contains("Error"))
                return "Error";
            POSTstr = InToPostfix();
            return POSTstr;
        }


        public string Evaluate()
        {
            //if (eval != "") return eval;
            if (POSTstr.Contains("Error"))
                return "Error";
            if (POSTstr == "")
            {
                if (INstr != "")
                    POSTstr = GetPostfix();

                else
                    return "Error";
            }
            eval = EvaPost();
            return eval;
        }

        public string GetInfix()
        {
            INstr = PostToInfix();
            return INstr;
        }

        private string InToPostfix()
        {
            if (INstr.Contains("Error") || INstr == "")
                return "Error";

            myStack = new Stack<string>(INstr.Length);
            var result = "";
            char ele;
            for (var pivot = 0; pivot != INstr.Length; pivot++)
            {
                ele = INstr[pivot];
                if (IsLetter(ele))
                    result += ele;
                else if (char.IsNumber(ele))
                {
                    var newStr = ele.ToString();
                    for (var j = pivot + 1; j < INstr.Length; j++, pivot++)
                    {
                        var newNum = INstr[j];
                        if (!char.IsNumber(newNum))
                            break;
                        newStr += newNum;
                    }
                    if (newStr != ele.ToString())
                        newStr = "," + newStr + ",";
                    result += newStr;
                }
                else if (IsOperator(ele))
                {
                    while (true)
                    {
                        if (myStack.IsEmpety || ele == '(')
                        {
                            myStack.Push(ele.ToString());
                            break;
                        }
                        if (ele == ')')
                        {
                            while (myStack.Peek() != "(")
                                result += myStack.Pop();
                            if (myStack.Pop() != "(")
                                return "Error";
                            break;
                        }

                        if (priority(ele) > priority(myStack.Peek()[0]))
                        {
                            myStack.Push(ele.ToString());
                            break;
                        }
                        if (priority(ele) <= priority(myStack.Peek()[0]))
                            result += myStack.Pop();
                        else
                            return "Error";
                    }
                }
                else
                    return "Error";
            }
            while (!myStack.IsEmpety)
                result += myStack.Pop();
            return result;
        }



        private string PostToInfix()
        {
            if (POSTstr.Contains("Error") || POSTstr == "")
                return "Error";

            string result = "", right = "", left = "";
            myStack = new Stack<string>(POSTstr.Length);
            for (var pivot = 0; pivot < POSTstr.Length; pivot++)
            {
                if (IsOperator(POSTstr[pivot]))
                {
                    right = myStack.Pop();
                    left = myStack.Pop();
                    myStack.Push("(" + left + POSTstr[pivot] + right + ")");
                }
                else if (POSTstr[pivot] == ',')
                {
                    var newstr = "";
                    var ch = ' ';
                    while (true)
                    {
                        if (pivot < POSTstr.Length)
                            pivot++;
                        ch = POSTstr[pivot];
                        if (ch == ',')
                            break;
                        newstr += ch;
                    }
                    myStack.Push(newstr);
                }
                else if (POSTstr[pivot] != ' ')
                {
                    myStack.Push(POSTstr[pivot].ToString());
                }
            }
            result += myStack.Pop();
            return result;
        }

 
        private string EvaPost()
        {
            myStack = new Stack<string>(POSTstr.Length);
            for (var pivot = 0; pivot < POSTstr.Length; pivot++)
            {
                var ele = POSTstr[pivot];
                if (IsLetter(ele) || char.IsNumber(ele))
                    myStack.Push(ele.ToString());
                else if (ele == ',')
                {
                    var newStr = "";
                    for (var i = pivot + 1; i < POSTstr.Length; i++)
                    {
                        var ch = POSTstr[i];
                        pivot++;
                        if (ch == ',')
                            break;
                        newStr += ch;
                    }
                    myStack.Push(newStr);
                }
                else if (IsOperator(ele))
                {
                    ///if op2&op1 where number
                    var op2 = myStack.Pop();
                    var op1 = myStack.Pop();
                    if (IsStringANum(op2) && IsStringANum(op1))
                    {
                        var fst = Convert.ToDouble(op1);
                        var scnd = Convert.ToDouble(op2);
                        switch (ele)
                        {
                            case '+':
                                myStack.Push((fst + scnd).ToString());
                                break;

                            case '-':
                                myStack.Push((fst - scnd).ToString());
                                break;

                            case '*':
                                myStack.Push((fst * scnd).ToString());
                                break;

                            case '/':
                                if (scnd == 0)
                                    return "Error-Division by zero";
                                myStack.Push((fst / scnd).ToString());
                                break;
                           
                            case '^':
                                myStack.Push(Math.Pow(fst, scnd).ToString());
                                break;
                           
                            case '%':
                                if (scnd == 0)
                                    return "Error-Division by zero";
                                myStack.Push((fst % scnd).ToString());
                                break;
                            default:
                                return "Error- Unknown Char";
                        }
                    }
                    ///if op2&op1 where not NUM
                    else
                        myStack.Push('(' + op1 + ele + op2 + ')');
                }
            }
            return myStack.Pop();
        }

    }
}