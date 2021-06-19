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
    public partial class Form2 : Form




    {
        public Form2()
        {
            InitializeComponent();
        }
        static public int urunSayac = 0;
        private static urunler[] urun = new urunler[100];

        internal static urunler[] Urun { get => urun; set => urun = value; }

        private void Form2_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < Form1.subeSayisi; i++)
            {
                comboBox2.Items.Add(Form1.Subeler[i].konum);
            }
        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            
            try
            {
                string adi = textBox1.Text;
                int stok = Convert.ToInt32(textBox4.Text);
                double fiyat = Convert.ToDouble(textBox3.Text);
                 object uruncesit = comboBox1.SelectedItem;
                string konum = comboBox2.SelectedItem.ToString();




                urun[urunSayac] = new urunler(adi, stok, fiyat, uruncesit.ToString(),konum);
                urunSayac++;

                textBox1.Text = "";
                
                textBox3.Text = "";
                textBox4.Text = "";
            }
            catch (Exception)
            {
                MessageBox.Show("hatalı deger girişi yaptınız");
            }


        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form3 form3 = new Form3();
            form3.Show();
            
            this.Visible = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Visible = false;
        }
    }
}
