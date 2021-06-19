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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }
        private static calısanlar[] calısan = new calısanlar[100];

        internal static calısanlar[] Calısan { get => calısan; set => calısan = value; }
        static public int calisanSayisi=0;
        private void Form4_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < Form1.subeSayisi; i++)
            {
                comboBox1.Items.Add(Form1.Subeler[i].konum);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Visible = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string ad = textBox1.Text;
                string soyad = textBox2.Text;
                double maas = Convert.ToDouble(textBox3.Text);
                int tut2 = 0;
                if (maas < 0)
                {
                   tut2 = 1;
                }

                string calistigi = comboBox1.SelectedItem.ToString();
                string ikamet = textBox4.Text;
                string calismaPoz = comboBox2.SelectedItem.ToString();
                int gun = monthCalendar1.SelectionStart.Day;
                int ay = monthCalendar1.SelectionStart.Month;
                int yıl = monthCalendar1.SelectionStart.Year;
                int tut = 0;
                for(int i = 0; i < calisanSayisi; i++)
                {
                    if (calısan[i].calistigiSubeGets() == calistigi && calismaPoz == "müdür")
                    {
                        tut = 1;
                    }
                    {
                        
                    }
                }
                if (tut == 1)
                {
                    MessageBox.Show("bu şubenin zaten bi müdürü var");
                    
                }
                else if (tut2 == 1)
                {
                    MessageBox.Show("maasın eksi degeri olamaz");
                }
               
                else
                {
                    calısan[calisanSayisi] = new calısanlar(ad, soyad, calismaPoz, ikamet, calistigi, maas,gun,ay,yıl);
                    calisanSayisi++;
                    textBox1.Text = "";
                    textBox2.Text = "";
                    textBox3.Text = "";
                    textBox4.Text = "";
                
                }

            }
            catch (Exception)
            {

            }



        }

        private void button3_Click(object sender, EventArgs e)
        {

            Form6 form6 = new Form6();
            form6.Show();
            this.Visible = false;
          
        }

        
    }
}
