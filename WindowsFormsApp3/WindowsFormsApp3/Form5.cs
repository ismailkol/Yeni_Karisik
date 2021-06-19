using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;
namespace WindowsFormsApp3
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }
      
        ArrayList[] ilce = new ArrayList[5];



        static public int tutamac = 0;
        

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                


               Form1.Subeler[Form1.subeSayisi] = new Sube();
               Form1.Subeler[Form1.subeSayisi].konumSet(comboBox1.SelectedItem.ToString()+"/"+comboBox2.SelectedItem.ToString());
                Form1.subeSayisi++;
            }
            catch (Exception)
            {

            }

        }

        private void Form5_Load(object sender, EventArgs e)
        {
           



            ilce[0] = new ArrayList();
            ilce[0].Add("güngören");
            ilce[0].Add("zeytinburnu");
            ilce[0].Add("eyüp");
            ilce[0].Add("bağcilar");
            ilce[0].Add("esenler");
            ilce[1] = new ArrayList();
            ilce[1].Add("bornova");
            ilce[1].Add("konak");
            ilce[1].Add("menderes");
            ilce[2] = new ArrayList();
            ilce[2].Add("çankaya");
            ilce[2].Add("polatlı");
            ilce[2].Add("keçiören");
            ilce[3] = new ArrayList();
            ilce[3].Add("osmangazi");
            ilce[3].Add("inegöl");
            ilce[4] = new ArrayList();
            ilce[4].Add("çorlu");
            ilce[4].Add("marmaraereğlisi");
            tutamac = 1;

            

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox2.Items.Clear();
            for(int i = 0; i < comboBox1.Items.Count; i++)
            {
                if (comboBox1.SelectedIndex == i)
                {
                    for(int j = 0; j < ilce[i].Count; j++)
                    {
                        comboBox2.Items.Add(ilce[i][j].ToString());
                    }
                }
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Visible = false;
        }
    }
}
