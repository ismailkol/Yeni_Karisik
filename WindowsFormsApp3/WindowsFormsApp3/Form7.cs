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
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void Form7_Load(object sender, EventArgs e)
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
                comboBox2.Items.Add(Form1.Subeler[i].konum);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                int sayi = Convert.ToInt32(textBox1.Text)-1;
                if(sayi>=0 && sayi < Form4.calisanSayisi)
                {
                    double yuzde = Convert.ToDouble(textBox2.Text);
                    if (yuzde > 0)
                    {
                        yuzde = (Form4.Calısan[sayi].maasGets() * yuzde) / 100;
                        Form4.Calısan[sayi].maasSets(Form4.Calısan[sayi].maasGets() + yuzde);
                    }
                    else
                    {
                        MessageBox.Show("eksi degerde zam yapılmaz");
                    }

                }
                else
                {
                    MessageBox.Show("calısan sayısıyla girilen deger uyuşmuyor");
                }

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

            }
            catch (Exception)
            {
                MessageBox.Show("hatalı işlem gerçekleşti");
            }


        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                int tut = 0;
                int sayi = Convert.ToInt32(textBox3.Text)-1;
                if (sayi >= 0 && sayi < Form4.calisanSayisi)
                {
                    string poz = comboBox1.SelectedItem.ToString();
                    string sube = Form4.Calısan[sayi].calistigiSubeGets();

                    if (poz == "müdür")
                    {
                        for(int i = 0; i < Form4.calisanSayisi; i++)
                        {
                            if(Form4.Calısan[i].calistigiSubeGets()== sube && Form4.Calısan[i].calismaPozGets() == "müdür")
                            {
                                tut = 1;
                            }
                        }

                        if (tut == 1)
                        {
                            MessageBox.Show("buranın zaten bir müdürü var");
                        }
                        else
                        {
                            Form4.Calısan[sayi].calisanPozSets(poz);
                        }

                    }
                    else
                    {
                        Form4.Calısan[sayi].calisanPozSets(poz);
                    }


                }
                else
                {
                    MessageBox.Show("calısan sayısıyla girilen deger uyuşmuyor");
                }



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

            }
            catch (Exception)
            {
                MessageBox.Show("hatalı işlem gerçekleşti");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {

            try
            {
                int sayi = Convert.ToInt32(textBox4.Text)-1;
                if (sayi >= 0 && sayi < Form4.calisanSayisi)
                {
                    int tut = 0;
                    string sube = comboBox2.SelectedItem.ToString();
                    string poz = Form4.Calısan[sayi].calismaPozGets();

                    if (poz == "müdür")
                    {
                        for (int i = 0; i < Form4.calisanSayisi; i++)
                        {
                            if (Form4.Calısan[i].calistigiSubeGets() == sube && Form4.Calısan[i].calismaPozGets() == "müdür")
                            {
                                tut = 1;
                            }
                        }

                        if (tut == 1)
                        {
                            MessageBox.Show("buranın zaten bir müdürü var");
                        }
                        else
                        {
                            Form4.Calısan[sayi].calisanSubeSets(sube);
                        }


                    }
                    else
                    {
                        Form4.Calısan[sayi].calisanSubeSets(sube);
                    }




                }
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






            }
            catch (Exception)
            {
                MessageBox.Show("hatalı işlem gerçekleşti");
            }



        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form4 form4 = new Form4();
            form4.Show();
            this.Visible = false;
        }
    }
}
