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
    public partial class Form9 : Form
    {
        public Form9()
        {
            InitializeComponent();
        }

        static Tedarik []tedarikciler = new Tedarik[100];
        static int tedarikSayisi=0;

        internal Tedarik[] Tedarikciler { get => tedarikciler; set => tedarikciler = value; }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Visible = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string cesit = comboBox1.SelectedItem.ToString();
                string konum = textBox1.Text;
                tedarikciler[tedarikSayisi] = new Tedarik(cesit, konum);
                tedarikSayisi++;
                
                listBox1.Items.Clear();
                for (int i = 0; i < tedarikSayisi; i++)
                {
                    listBox1.Items.Add("tedarikci sagladıgı urun cesidi: " + tedarikciler[i].cesitGets());
                    listBox1.Items.Add("tedarikcinin ikamet adresi: " + tedarikciler[i].konumGets());
                    listBox1.Items.Add("-----------------------------------------");
                }
                textBox1.Text = "";


            }
            catch (Exception)
            {
                MessageBox.Show("hata gercekleşti");
            }
        }

        private void Form9_Load(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            for(int i = 0; i < tedarikSayisi; i++)
            {
                listBox1.Items.Add("tedarikci sagladıgı uruncesidi: " + tedarikciler[i].cesitGets());
                listBox1.Items.Add("tedarikcinin ikamet adresi: " + tedarikciler[i].konumGets());
                listBox1.Items.Add("-----------------------------------------");
            }
        }
    }
}
