using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private static Sube[] subeler = new Sube[100];
        static public int subeSayisi = 0;
        internal static Sube[] Subeler { get => subeler; set => subeler = value; }
       

        private void Form1_Load(object sender, EventArgs e)
        {
            if (Form5.tutamac==0)
            {
                subeler[0] = new Sube();
                subeler[0].konumSet("istanbul/güngören");
                subeler[1] = new Sube();
                subeler[1].konumSet("istanbul/esenler");
                subeler[2] = new Sube();
                subeler[2].konumSet("izmir/bornova");
                subeSayisi = 3;
               
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
            this.Visible = false;

            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form5 form5 = new Form5();
            form5.Show();
            this.Visible = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form4 form4 = new Form4();
            form4.Show();
            this.Visible = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form9 form9 = new Form9();
            form9.Show();
            this.Visible = false;
        }
    }
}
