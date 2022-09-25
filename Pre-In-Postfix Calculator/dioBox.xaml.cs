using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Threading;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Calculator
{
    /// <summary>
    /// Interaction logic for Window1.xaml
    /// </summary>
    public partial class Window1 : Window
    {
        public AutoResetEvent event_1;
        public event EventHandler onSubmit;

        public string Answer { get => inputValue.Text; }
        public bool dioResult = false;

        public Window1(string inputNameStr)
        {
            InitializeComponent();
            inputName.Text = inputNameStr + " :";
            inputValue.Focus();
            event_1 = new AutoResetEvent(false);
        }       

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            dioResult = false;
            if (!double.TryParse(Answer, out double res))
            {
                inputValue.Text = "Please Enter a valid value";
                inputValue.Focus();
                inputValue.SelectAll();
            }
            else
            {
                dioResult = true;
                onSubmit(sender, e);
                event_1.Set();
                this.Close();
            }
        }
    }
}
