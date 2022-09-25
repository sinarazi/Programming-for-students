using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Calculator
{

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 
    public partial class MainWindow : Window
    {
        // evaluation method
        private Method method = Method.Infix;

        public static Color SelectString = (Color) ColorConverter.ConvertFromString("#7cebb0");
        public static Color DeSelectString = (Color) ColorConverter.ConvertFromString("#8f8f8f");

        public static List<int> lastCommand = new List<int>();

        public MainWindow()
        {
            InitializeComponent();            
            FixChange(In, new RoutedEventArgs());
        }

        private void FixChange (object sender, RoutedEventArgs e)
        {
            Button s = sender as Button;
            switch (s.Content)
            {
                case "Prefix":
                    method = Method.PreFix;
                    Pre.Foreground = new System.Windows.Media.SolidColorBrush(SelectString);
                    In.Foreground = new System.Windows.Media.SolidColorBrush(DeSelectString);
                    Post.Foreground = new System.Windows.Media.SolidColorBrush(DeSelectString);
                    break;
                case "Infix":
                    method = Method.Infix;
                    In.Foreground = new System.Windows.Media.SolidColorBrush(SelectString);
                    Pre.Foreground = new System.Windows.Media.SolidColorBrush(DeSelectString);
                    Post.Foreground = new System.Windows.Media.SolidColorBrush(DeSelectString);
                    break;
                case "Postfix":
                    method = Method.PostFix;
                    Post.Foreground = new System.Windows.Media.SolidColorBrush(SelectString);
                    Pre.Foreground = new System.Windows.Media.SolidColorBrush(DeSelectString);
                    In.Foreground = new System.Windows.Media.SolidColorBrush(DeSelectString);
                    break;
                default:
                    break;
            }
        }

        private void OP_Click (object sender, RoutedEventArgs e)
        {
            string name = (sender as Button).Name.ToString();
            switch (name)
            {
                case "Π":
                    Rbox1.Text += Math.PI.ToString ();
                    lastCommand.Add(2);
                    return;
                case "e":
                    Rbox1.Text += Math.E.ToString ();
                    lastCommand.Add(1);
                    return;
                case "ExpPow":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += Math.E.ToString() + "^(" + Rbox2.Text;
                        lastCommand.Add(3 + Rbox2.Text.Length);
                    }
                    else
                    {
                        Rbox1.Text += Math.E.ToString() + "^(";
                        lastCommand.Add(3);
                    }
                    return;
                case "PowTwo":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += "(" + Rbox2.Text + ")^2";
                        lastCommand.Add(4 + Rbox2.Text.Length);
                    }
                    else
                    {
                        Rbox1.Text += "()^2";
                        lastCommand.Add(4);
                    }
                    return;
                case "TenPow":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += "10^(" + Rbox2.Text + ")";
                        lastCommand.Add(5 + Rbox2.Text.Length);
                    }
                    else
                    {
                        Rbox1.Text += "10^(";
                        lastCommand.Add(4);
                    }
                    return;
                case "XPowY":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += "(" + Rbox2.Text + ")^(";
                        lastCommand.Add(5 + Rbox2.Text.Length);
                    }
                    else
                    {
                        Rbox1.Text += "()^(";
                        lastCommand.Add(5);
                    }
                    return;
                default:
                    break;
            }
            string cont = (sender as Button).Content.ToString();
            string rb1txt = Rbox1.Text;

            switch (cont)
            {
                case "+":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += Rbox2.Text;
                    }
                    Rbox1.Text += "+";
                    lastCommand.Add(1);                   
                    return;
                case "-":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += Rbox2.Text;
                    }
                    Rbox1.Text += "-";
                    lastCommand.Add(1);                    
                    return;
                case "/":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += Rbox2.Text;
                    }
                    Rbox1.Text += "/";
                    lastCommand.Add(1);
                    
                    return;
                case "x":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += Rbox2.Text;
                    }
                    Rbox1.Text += "*";
                    lastCommand.Add(1);                    
                    return;
                case "(":
                    Rbox1.Text += "(";
                    lastCommand.Add(1);
                    return;
                case ")":
                    Rbox1.Text += ")";
                    lastCommand.Add(1);
                    return;
                case "n!":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += "(" + Rbox2.Text + ")!";
                        lastCommand.Add(3 + Rbox2.Text.Length);
                    }
                    else
                    {
                        Rbox1.Text += "()!";
                        lastCommand.Add(3);
                    }
                    return;
                case "1/x":
                    if (Rbox1.Text == "" && Rbox2.Text != "0.0")
                    {
                        Rbox1.Text += "1/(" + Rbox2.Text + ")";
                        lastCommand.Add(4 + Rbox2.Text.Length);
                    }
                    else
                    {
                        Rbox1.Text += "1/(";
                        lastCommand.Add(3);
                    }
                    return;
                default:             
                    break;
            }
            Rbox1.Text = rb1txt;
            if (Rbox1.Text == "" && Rbox2.Text != "0.0")
            {
                Rbox1.Text += cont + "(" + Rbox2.Text;
                lastCommand.Add(cont.Length + 1 + Rbox2.Text.Length);
            }
            else
            {
                Rbox1.Text += cont + "(";
                lastCommand.Add(cont.Length + 1);
            }            
        }

        private void NUMOP_Click (object sender, RoutedEventArgs e)
        {
            Button newsender = sender as Button;
            Rbox1.Text += newsender.Content.ToString();
            lastCommand.Add(newsender.Content.ToString().Length);
        }

        private void CMD_Click (object sender, RoutedEventArgs e)
        {
            string cmdCase = (sender as Button).Content.ToString();

            switch (cmdCase)
            {
                case "C":
                    Rbox1.Text = "";
                    return;
                case "CE":
                    Rbox1.Text = "";
                    Rbox2.Text = "0.0";
                    return;
                default:
                    break;
            }
            string tmp = "";
            bool toGo = true;
            if (lastCommand.Count == 0)
            {
                toGo = false;
            }
            for (int i = 0; i < Rbox1.Text.Length - (lastCommand.Count == 0 ? 1 : lastCommand[lastCommand.Count - 1] ); i++)
            {
                tmp += Rbox1.Text[i].ToString();
            }
            if (toGo)
                lastCommand.RemoveAt(lastCommand.Count - 1);
            Rbox1.Text = tmp;
        }

        private void Evaluation(object sender, RoutedEventArgs e)
        {
            // get the value.
            string value = Rbox1.Text;
            if (value == "" || value == null)
                return;
            string valuex = "(" + value + ")";

            switch (method)
            {
                case Method.PostFix:
                    Rbox2.Text = Evaluate.PostFix(value).ToString();
                    break;
                case Method.PreFix:
                    var handler = new Input(value);
                    Rbox2.Text = handler.GetPreFix();
                    Rbox1.Text = "";
                    break;
                case Method.Infix:
                    Rbox2.Text = Infix.Evaluate(valuex).ToString();
                    Rbox1.Text = "";
                    break;
                default:
                    break;
            }
        }
        
    }
}