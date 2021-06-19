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
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void Form6_Load(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            for (int i = 0; i < Form4.calisanSayisi; i++)
            {
                listBox1.Items.Add(i + 1 + " calısanın durumu");
                listBox1.Items.Add("ad: " + Form4.Calısan[i].adGets());
                listBox1.Items.Add("soyad: " + Form4.Calısan[i].soyadGets());
                listBox1.Items.Add("maas" + Form4.Calısan[i].maasGets().ToString());
                listBox1.Items.Add("calistıgı sube: " + Form4.Calısan[i].calistigiSubeGets());
                listBox1.Items.Add("ikamet adresi: " + Form4.Calısan[i].ikametGets());
                listBox1.Items.Add("calisma Pozisyonu: " + Form4.Calısan[i].calismaPozGets());
                listBox1.Items.Add("Calismaya basladıgı tarih: " + Form4.Calısan[i].CgunGets() + "." + Form4.Calısan[i].CayGets() + "." + Form4.Calısan[i].CyılGets());
                listBox1.Items.Add("-------------------------------------");
}
            for (int i = 0; i < Form1.subeSayisi; i++)
            {
                comboBox1.Items.Add(Form1.Subeler[i].konum);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form4 form4 = new Form4();
            form4.Show();
            this.Visible = false;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            listBox2.Items.Clear();
            for (int i = 0; i < Form4.calisanSayisi; i++)
            {
                if (Form4.Calısan[i].calistigiSubeGets() == comboBox1.SelectedItem.ToString())
                {
                    
                    listBox2.Items.Add("ad: " + Form4.Calısan[i].adGets());
                    listBox2.Items.Add("soyad: " + Form4.Calısan[i].soyadGets());
                    listBox2.Items.Add("maas" + Form4.Calısan[i].maasGets().ToString());
                    listBox2.Items.Add("calistıgı sube: " + Form4.Calısan[i].calistigiSubeGets());
                    listBox2.Items.Add("ikamet adresi: " + Form4.Calısan[i].ikametGets());
                    listBox2.Items.Add("calisma Pozisyonu: " + Form4.Calısan[i].calismaPozGets());
                    listBox2.Items.Add("Calismaya basladıgı tarih: " + Form4.Calısan[i].CgunGets() + "." + Form4.Calısan[i].CayGets() + "." + Form4.Calısan[i].CyılGets());
                    listBox2.Items.Add("-------------------------------------");
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form7 form7 = new Form7();
            form7.Show();
            this.Visible = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form8 form8 = new Form8();
            form8.Show();
            this.Visible = false;
        }
    }
}
