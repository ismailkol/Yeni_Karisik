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
    public partial class Form3 : Form
    {
        

        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < Form1.subeSayisi; i++)
            {
                comboBox1.Items.Add(Form1.Subeler[i].konum);
            }

            panel1.Visible = false;
           for(int i = 0; i < Form2.urunSayac; i++)
            {
                listBox1.Items.Add((i+1) + ". urun hakkında bilgiler");
                listBox1.Items.Add("adi: "+Form2.Urun[i].adiGets());
                listBox1.Items.Add("stok: "+Form2.Urun[i].stokGets());
                listBox1.Items.Add("fiyat "+Form2.Urun[i].fiyatGets());
                listBox1.Items.Add("urunCesit: "+Form2.Urun[i].uruncesitGets());
                listBox1.Items.Add("urunun hangi markette: " + Form2.Urun[i].konum);

                if (Form2.Urun[i].indirimYapGets() == 0)
                {
                    listBox1.Items.Add("Bu urunu indirim gerceklestirilmemis");
                }
                else
                {
                    listBox1.Items.Add("indirim tarih: " + Form2.Urun[i].indirimTarihGets());
                }

                listBox1.Items.Add("--------------------------");

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
            
            this.Visible = false;
        }
        int sayi;
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {

                sayi = Convert.ToInt32(textBox1.Text)-1;
                if (textBox1.Text != "" && sayi >= 0 && sayi < Form2.urunSayac)
                {
                    panel1.Visible = true;
                    label4.Text = Form2.Urun[sayi].adiGets();
                    label5.Text = Form2.Urun[sayi].stokGets().ToString();
                    label6.Text = Form2.Urun[sayi].fiyatGets().ToString();
                    label7.Text = Form2.Urun[sayi].uruncesitGets();

                }
            }
            catch(Exception)
            {
                MessageBox.Show("hatalı deger girdiniz");
            }
        }

       


        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            listBox2.Items.Clear();
           for(int i = 0; i < Form2.urunSayac; i++)
            {
                if (Form2.Urun[i].konum == comboBox1.SelectedItem.ToString())
                {
                    listBox2.Items.Add("adi: " + Form2.Urun[i].adiGets());
                    listBox2.Items.Add("stok: " + Form2.Urun[i].stokGets());
                    listBox2.Items.Add("fiyat " + Form2.Urun[i].fiyatGets());
                    listBox2.Items.Add("urunCesit: " + Form2.Urun[i].uruncesitGets());
                    listBox2.Items.Add("urunun hangi markette: " + Form2.Urun[i].konum);
                    listBox2.Items.Add("--------------------------");
                }
            }

        }

        

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                double sayi2 = Convert.ToInt32(textBox2.Text);
                if (sayi2 > 0 && sayi2 <= 100)
                {
                    double indirim = (Form2.Urun[sayi].fiyatGets() * sayi2) / 100;
                    sayi2 = Form2.Urun[sayi].fiyatGets() - indirim;
                    Form2.Urun[sayi].fiyatSets(sayi2);

                    Form2.Urun[sayi].indirimYapSets(1);
                    Form2.Urun[sayi].indirimTarihSets(DateTime.Now.ToLongDateString());


                }
                Form3 form3 = new Form3();
                form3.Show();
                this.Visible = false;
            }
            catch (Exception)
            {
                MessageBox.Show("hatalı deger girdiniz");
            }
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            Form3 form3 = new Form3();
            form3.Show();
            this.Visible = false;
        }

    }
}
