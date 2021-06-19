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
    public partial class Form8 : Form
    {
        public Form8()
        {
            InitializeComponent();
        }


        private static izin[] ızinler = new izin[200]; //haftalıkları tutar
        private static izin[] ızinler1 = new izin[200];
        static int izinlerSayac = 0;
        static int izinlerSayac1 = 0;



        internal static izin[] Izinler { get => ızinler; set => ızinler = value; }
        internal static izin[] Izinler1 { get => ızinler1; set => ızinler1 = value; }

        private void Form8_Load(object sender, EventArgs e)
        {
            panel1.Visible = false;
            listBox2.Visible = false;
            listBox3.Visible = false;
            panel2.Visible = false;
            button2.Enabled = true;
            button1.Enabled = true;
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
        int sayi;
        private void button1_Click(object sender, EventArgs e)
        {

            try
            {
                

                sayi = Convert.ToInt32(textBox1.Text) - 1;
                if(sayi>=0 && sayi < Form4.calisanSayisi)
                {
                    comboBox1.Items.Clear();
                    comboBox2.Items.Clear();
                    for(int i = 0; i < 30; i++)
                    {
                        comboBox1.Items.Add(Form4.Calısan[sayi].CyılGets() + i);
                    }
                    for(int i = 1; i <= 52; i++)
                    {
                        comboBox2.Items.Add(i);
                    }
                    panel1.Visible = true;
                    button1.Enabled = false;
                }
                else
                {
                    MessageBox.Show("girilen sayida calısan bulunmamakta");
                }

            }
            catch (Exception)
            {

            }


        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                if (sayi >= 0 && sayi < Form4.calisanSayisi)
                {

                    int yıl = Convert.ToInt32(comboBox1.SelectedItem);
                    int yeniGerekYok = 0;
                    int ızinlerdekiYeri = 0;
                    int secilmishafta = 0;
                    int hafta = Convert.ToInt32(comboBox2.SelectedItem);
                    string gun = comboBox3.SelectedItem.ToString();

                    for (int i = 0; i < izinlerSayac; i++)
                    {
                        if (ızinler[i].calisanNoGets() == sayi && ızinler[i].alinanYılGets() == yıl)
                        {
                            ızinlerdekiYeri = i;
                            yeniGerekYok = 1;
                        }

                    }
                    if (izinlerSayac == 0)
                    {


                        ızinler[izinlerSayac] = new izin(Form4.Calısan[sayi].adGets(), Form4.Calısan[sayi].soyadGets(), Form4.Calısan[sayi].calismaPozGets(), Form4.Calısan[sayi].ikametGets(), Form4.Calısan[sayi].calistigiSubeGets(), Form4.Calısan[sayi].maasGets(), Form4.Calısan[sayi].CgunGets(), Form4.Calısan[sayi].CayGets(), Form4.Calısan[sayi].CyılGets());
                        Izinler[izinlerSayac].alinanYılSets(yıl);
                        ızinler[izinlerSayac].alinanHafta[ızinler[izinlerSayac].alinanHaftaSayac] = hafta;
                        ızinler[izinlerSayac].alinanGün[ızinler[izinlerSayac].alinanHaftaSayac] = gun;
                        ızinler[izinlerSayac].alinanHaftaSayac++;
                        ızinler[izinlerSayac].calisanNoSets(sayi);
                        izinlerSayac++;


                    }
                    else
                    {
                        if (yeniGerekYok == 1)
                        {
                            if (ızinler[ızinlerdekiYeri].alinanHaftaSayac < 52)
                            {

                                for (int i = 0; i < ızinler[ızinlerdekiYeri].alinanHaftaSayac; i++)
                                {
                                    if (ızinler[ızinlerdekiYeri].alinanHafta[i] == hafta)
                                    {
                                        MessageBox.Show("bu haftaya daha önceden alınmış");
                                        secilmishafta = 1;
                                    }

                                }
                                if (secilmishafta == 0)
                                {
                                    ızinler[ızinlerdekiYeri].alinanHafta[ızinler[ızinlerdekiYeri].alinanHaftaSayac] = hafta;
                                    ızinler[ızinlerdekiYeri].alinanGün[ızinler[ızinlerdekiYeri].alinanHaftaSayac] = gun;
                                    ızinler[ızinlerdekiYeri].alinanHaftaSayac++;

                                }

                            }
                            else
                            {
                                MessageBox.Show("haftalık izin hakkını doldurmussun");
                            }


                        }
                        else
                        {

                            ızinler[izinlerSayac] = new izin(Form4.Calısan[sayi].adGets(), Form4.Calısan[sayi].soyadGets(), Form4.Calısan[sayi].calismaPozGets(), Form4.Calısan[sayi].ikametGets(), Form4.Calısan[sayi].calistigiSubeGets(), Form4.Calısan[sayi].maasGets(), Form4.Calısan[sayi].CgunGets(), Form4.Calısan[sayi].CayGets(), Form4.Calısan[sayi].CyılGets());
                            Izinler[izinlerSayac].alinanYılSets(yıl);
                            ızinler[izinlerSayac].alinanHafta[ızinler[izinlerSayac].alinanHaftaSayac] = hafta;
                            ızinler[izinlerSayac].alinanGün[ızinler[izinlerSayac].alinanHaftaSayac] = gun;
                            ızinler[izinlerSayac].alinanHaftaSayac++;
                            ızinler[izinlerSayac].calisanNoSets(sayi);
                            izinlerSayac++;


                        }



                    }
                    listBox2.Items.Clear();
                    listBox2.Visible = true;
                    for (int i = 0; i < izinlerSayac; i++)
                    {
                        listBox2.Items.Add("ad: " + ızinler[i].adGets());
                        listBox2.Items.Add("soyad: " + ızinler[i].soyadGets());
                        listBox2.Items.Add("maas" + ızinler[i].maasGets().ToString());
                        listBox2.Items.Add("calistıgı sube: " + ızinler[i].calistigiSubeGets());
                        listBox2.Items.Add("ikamet adresi: " + ızinler[i].ikametGets());
                        listBox2.Items.Add("calisma Pozisyonu: " + ızinler[i].calismaPozGets());
                        listBox2.Items.Add("Calismaya basladıgı tarih: " + ızinler[i].CgunGets() + "." + ızinler[i].CayGets() + "." + ızinler[i].CyılGets());
                        listBox2.Items.Add("Calisan numarası: " + (ızinler[i].calisanNoGets()+1));
                        listBox2.Items.Add("\n");

                        for (int j = 0; j < Izinler[i].alinanHaftaSayac; j++)
                        {
                            listBox2.Items.Add(ızinler[i].alinanGün[j] + "." + ızinler[i].alinanHafta[j] + "." + ızinler[i].alinanYılGets());
                        }


                        listBox2.Items.Add("-------------------------------------");


                    }



                }
                else
                {
                    MessageBox.Show("girilen sayi bulunmamaktadır");
                }

                

            }
            catch (Exception)
            {
                MessageBox.Show("hata oluştu");
            }


        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form6 form6 = new Form6();
            form6.Show();
            this.Visible = false;
        }

        int sayi1;
        private void button5_Click(object sender, EventArgs e)
        {

            try
            {
                if (sayi1 >= 0 && sayi1 < Form4.calisanSayisi)
                {

                    int yıl = Convert.ToInt32(comboBox6.SelectedItem);
                    int yeniGerekYok = 0;
                    int ızinlerdekiYeri = 0;
                    int secilmishafta = 0;
                    int hafta = Convert.ToInt32(comboBox5.SelectedItem);
                   

                    for (int i = 0; i < izinlerSayac1; i++)
                    {
                        if (ızinler1[i].calisanNoGets() == sayi1 && ızinler1[i].alinanYılGets() == yıl)
                        {
                            ızinlerdekiYeri = i;
                            yeniGerekYok = 1;
                        }

                    }
                    if (izinlerSayac1 == 0)
                    {


                        ızinler1[izinlerSayac1] = new izin(Form4.Calısan[sayi1].adGets(), Form4.Calısan[sayi1].soyadGets(), Form4.Calısan[sayi1].calismaPozGets(), Form4.Calısan[sayi1].ikametGets(), Form4.Calısan[sayi1].calistigiSubeGets(), Form4.Calısan[sayi1].maasGets(), Form4.Calısan[sayi1].CgunGets(), Form4.Calısan[sayi1].CayGets(), Form4.Calısan[sayi1].CyılGets());
                        Izinler1[izinlerSayac1].alinanYılSets(yıl);
                        ızinler1[izinlerSayac1].yıllıkIznHafta[ızinler1[izinlerSayac1].yıllıkIzınSayac] = hafta;
                        ızinler1[izinlerSayac1].yıllıkIzınSayac++;//
                        ızinler1[izinlerSayac1].calisanNoSets(sayi1);
                        izinlerSayac1++;


                    }
                    else
                    {
                        if (yeniGerekYok == 1)
                        {
                            if (ızinler1[ızinlerdekiYeri].yıllıkIzınSayac < 2)
                            {

                                for (int i = 0; i < ızinler1[ızinlerdekiYeri].yıllıkIzınSayac; i++)
                                {
                                    if (ızinler1[ızinlerdekiYeri].yıllıkIznHafta[i] == hafta)
                                    {
                                        MessageBox.Show("bu haftaya daha önceden alınmış");
                                        secilmishafta = 1;
                                    }

                                }
                                if (secilmishafta == 0)
                                {
                                    ızinler1[ızinlerdekiYeri].yıllıkIznHafta[ızinler1[ızinlerdekiYeri].yıllıkIzınSayac] = hafta;

                                    ızinler1[ızinlerdekiYeri].yıllıkIzınSayac++;

                                }

                            }
                            else
                            {
                                MessageBox.Show("Yıllık izin hakkını doldurmussun");
                            }


                        }
                        else
                        {

                            ızinler1[izinlerSayac1] = new izin(Form4.Calısan[sayi1].adGets(), Form4.Calısan[sayi1].soyadGets(), Form4.Calısan[sayi1].calismaPozGets(), Form4.Calısan[sayi1].ikametGets(), Form4.Calısan[sayi1].calistigiSubeGets(), Form4.Calısan[sayi1].maasGets(), Form4.Calısan[sayi1].CgunGets(), Form4.Calısan[sayi1].CayGets(), Form4.Calısan[sayi1].CyılGets());
                            Izinler1[izinlerSayac1].alinanYılSets(yıl);
                            ızinler1[izinlerSayac1].yıllıkIznHafta[ızinler1[izinlerSayac1].yıllıkIzınSayac] = hafta;

                            ızinler1[izinlerSayac1].yıllıkIzınSayac++;
                            ızinler1[izinlerSayac1].calisanNoSets(sayi1);
                            izinlerSayac1++;


                        }



                    }
                    listBox3.Items.Clear();
                    listBox3.Visible = true;
                    for (int i = 0; i < izinlerSayac1; i++)
                    {
                        listBox3.Items.Add("ad: " + ızinler1[i].adGets());
                        listBox3.Items.Add("soyad: " + ızinler1[i].soyadGets());
                        listBox3.Items.Add("maas" + ızinler1[i].maasGets().ToString());
                        listBox3.Items.Add("calistıgı sube: " + ızinler1[i].calistigiSubeGets());
                        listBox3.Items.Add("ikamet adresi: " + ızinler1[i].ikametGets());
                        listBox3.Items.Add("calisma Pozisyonu: " + ızinler1[i].calismaPozGets());
                        listBox3.Items.Add("Calismaya basladıgı tarih: " + ızinler1[i].CgunGets() + "." + ızinler1[i].CayGets() + "." + ızinler1[i].CyılGets());
                        listBox3.Items.Add("Calisan numarası: " + (ızinler1[i].calisanNoGets() + 1));
                        listBox3.Items.Add("\n");

                        for (int j = 0; j < Izinler1[i].yıllıkIzınSayac; j++)
                        {
                            listBox3.Items.Add(ızinler1[i].yıllıkIznHafta[j] + "." + ızinler1[i].alinanYılGets());
                        }


                        listBox3.Items.Add("-------------------------------------");


                    }



                }
                else
                {
                    MessageBox.Show("girilen sayi bulunmamaktadır");
                }



            }
            catch (Exception)
            {
                MessageBox.Show("hata oluştu");
            }










        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {


                sayi1 = Convert.ToInt32(textBox2.Text) - 1;
                if (sayi1 >= 0 && sayi1 < Form4.calisanSayisi)
                {
                    comboBox6.Items.Clear();
                    comboBox5.Items.Clear();
                    for (int i = 0; i < 30; i++)
                    {
                        comboBox6.Items.Add(Form4.Calısan[sayi1].CyılGets() + i);
                    }
                    for (int i = 1; i <= 52; i++)
                    {
                        comboBox5.Items.Add(i);
                    }
                    panel2.Visible = true;
                    button4.Enabled = false;
                }
                else
                {
                    MessageBox.Show("girilen sayida calısan bulunmamakta");
                }

            }
            catch (Exception)
            {

            }

        }
    }
}
