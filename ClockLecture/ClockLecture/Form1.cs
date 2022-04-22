using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ClockLecture
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Clock clock = new Clock();
            clock.TimeUpdatedHandler += Tick;
            Alarm alarm1 = new Alarm(DateTime.Now.AddSeconds(10));
            clock.TimeUpdatedHandler += alarm1.CheckFire;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        public void Tick(DateTime time)
        {
            Invoke(new MethodInvoker(() =>
            {
                clockDisplay.Text = DateTime.Now.ToString("HH::mm::ss");
            }));
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}
