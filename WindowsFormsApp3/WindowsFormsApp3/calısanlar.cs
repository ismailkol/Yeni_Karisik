using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp3
{
    class calısanlar
    {
        private string ad;
        private string soyad;
        private string calismaPozisyonu;
        private string ikametAdresi;
        private string calistigiSube;
        private double maas;
        private int  Cgun, Cay, Cyıl;

        public calısanlar(string ad,string soyad,string calismaPozisyonu,string ikametAdresi,string calistigiSube,double maas,int Cgun,int Cay,int Cyıl)
        {
            this.ad = ad;
            this.soyad = soyad;
            this.calismaPozisyonu = calismaPozisyonu;
            this.ikametAdresi = ikametAdresi;
            this.calistigiSube = calistigiSube;
            this.maas = maas;
            this.Cgun = Cgun;
            this.Cay = Cay;
            this.Cyıl = Cyıl;
        }
       public string calistigiSubeGets()
        {
            return calistigiSube;
        }
        public string adGets()
        {
            return ad;
        }
        public string soyadGets()
        {
            return soyad;
        }
        public string calismaPozGets()
        {
            return calismaPozisyonu;
        }
        public string ikametGets()
        {
            return ikametAdresi;
        }
        public double maasGets()
        {
            return maas;
        }
        public int CgunGets()
        {
            return Cgun;
        }
        public int CayGets()
        {
            return Cay;
        }
        public int CyılGets()
        {
            return Cyıl;
        }
        public void maasSets(double maas)
        {
            this.maas = maas;
        }
        public void calisanPozSets( string calismaPozisyonu)
        {
            this.calismaPozisyonu = calismaPozisyonu;
        }
        public void calisanSubeSets(string calistigiSube)
        {
            this.calistigiSube = calistigiSube;
        }


    }
}
