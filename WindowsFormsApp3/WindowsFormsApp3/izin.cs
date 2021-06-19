using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp3
{
    class izin:calısanlar
    {
        public int []alinanHafta=new int[52];
        private int alinanYıl;
        public int alinanHaftaSayac=0;
        public string []alinanGün=new string[52];
        private int calisanNo;
        public int[] yıllıkIznHafta = new int[2];
        public int yıllıkIzınSayac = 0;



        public izin(string ad, string soyad, string calismaPozisyonu, string ikametAdresi, string calistigiSube, double maas, int Cgun, int Cay, int Cyıl) : base(ad, soyad, calismaPozisyonu, ikametAdresi, calistigiSube, maas, Cgun, Cay, Cyıl)
        {
        }
        public int calisanNoGets()
        {
            return calisanNo;
        }
        public int alinanYılGets()
        {
            return alinanYıl;
        }
        public void alinanYılSets(int alinanYıl)
        {
            this.alinanYıl = alinanYıl;
        }
        public void calisanNoSets(int calisanNo)
        {
            this.calisanNo = calisanNo;
        }

    }
}
