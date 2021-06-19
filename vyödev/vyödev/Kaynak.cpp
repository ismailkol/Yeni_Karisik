#include <stdio.h>
#include <iostream>
#include <string> //stringler ile iþlem yapmak için ekledim


using namespace std;

struct Ogrenci {
	string isim, harfnotu;
	int ogrencino, *testnotlari;
	double ortalama;
};


//Kullanicidan alinan degerleri veriAl fonk. yardýmý ile struct deðerlerine kaydetme iþleminin gercekleþtirdik.
//3 tane paremereli yaptim. &student main'de oluþturdugum ogrenci verisi tutar ve degisiklik yaptigimiza main'de gozukur.
//kacinci degeri bizim kacinci ogrenciyi olusturdugumuzu gosterir.
//testS bize kac tane test oldugunu gosterir.


void veriAl(Ogrenci &student, int kacinci, int testS) {
	cout << endl;
	cout << kacinci << ". ogrencinin adini giriniz: ";
	cin >> student.isim;										//kullanýcýdan isim alýnýr ve struct'a kaydedilir.
	cout << kacinci << ". ogrencinin numarasini giriniz: ";
	cin >> student.ogrencino;									//kullanicidan ogrenciNo alýnýr ve oluþturulan struct ogrenci deðerine kaydedilir.
	student.testnotlari = new int[testS];						//testnotlari degerinin dinamik olarak oluþturduk.


	for (int i = 0; i < testS; i++) {
		cout << kacinci << ". ogrencinin " << (i + 1) << ". test notunu giriniz: ";
		cin >> student.testnotlari[i];													//oluþturulan testnotlarý kullanýdan alýnarak kaydedilir.

		//Girilen notlarýn harfli notlara ve 100 not sistemine uymasý için bir if koþulu koydum.
		//Bu sayede kullanýcýnýn eksi deðerler yada 100 büyük sayýlar girilmesi engellenmiþtir.
		if (student.testnotlari[i] > 100 || student.testnotlari[i] < 0) {
			cout << "hatali bir sinav notlamasi yaptiniz.Notu tekrar giriniz" << endl;
			exit(1);																	//100 sistem olmayan not girilirse sistemi kapat
		}
	}


}


//Not hesaplamak için 2 paremetre yolladim.
//student parametresi main'de oluþturulan ve bu fonksiyona yollanan struct deðerini tutar.
//testS test sayisini ifade eder.

double notHesaplama(Ogrenci &student, int testS) {

	double ortalama = 0;
	for (int i = 0; i < testS; i++) {
		ortalama += student.testnotlari[i];			//struct'tan alinan testnotlariyla ortalama hesabý için çaðrýldý ve kullanýldý
	}
	ortalama = ortalama / testS;					//Notlarýn ortalamýnýn alinmasi islemi gerçekleþtirildi.
	student.ortalama = ortalama;					//ortalama struct kaydedildi



	//ortalamaya göre hangi harfli notun geleceðinin ayarlanmasý için koþullar saðladým.
	//ortalamaya göre struct harfli nota kaydedildi.
	if (ortalama >= 85)
		student.harfnotu = "A";
	else if (ortalama >= 75 && ortalama < 85)
		student.harfnotu = "B";
	else if (ortalama >= 65 && ortalama < 75)
		student.harfnotu = "C";
	else if (ortalama >= 50 && ortalama < 65)
		student.harfnotu = "D";
	else {
		student.harfnotu = "F";
	}
	//ornek program çýktýsýnýn saðlanmasý için alttaki satýrý yazdým.
	cout << "Ortalama is: " << ortalama << " Harf notu: " << student.harfnotu << endl;

	return ortalama;		//double geri dönüþlü fonk. olduðu için geriye ortalama deðerini döndürdüm.
}



//oluþturulan verilerin ekrana gösterilmesi için 2 paremetreli goster fonk. oluþturdum.
//student parametresi main'de oluþturulan ve bu fonksiyona yollanan struct deðerini tutar.
//testS test sayisini ifade eder.
void goster(Ogrenci &student, int testS) {

	//student verisi ile bu structa ait deðerleri ekrana gösterme iþlemini gerçekleþtirdik.


	cout << endl;
	cout << "Ogrencinin adi: " << student.isim << endl;
	cout << "Ogrencinin numarasi:" << student.ogrencino << endl;
	for (int i = 0; i < testS; i++) {
		cout << "ogrencinin " << (i + 1) << ". test sonucu: " << student.testnotlari[i] << endl;
	}
	cout << "Ogrencinin ortalamasi: " << student.ortalama << endl;
	cout << "Ogrencinin harfli notu: " << student.harfnotu << endl;

}


//oluþturulan struct'ý bellekten silme iþlemini gerçekleþtirdim.
void sil(Ogrenci *student) {

	delete[]student;
}



int main() {

	//ogrenci sayisi ve test sayisini kullanýdan aldým
	int OgrenciSayi = 0;
	int TestSayi;
	cout << "Ogrenci sayisini giriniz:  ";
	cin >> OgrenciSayi;
	cout << "Test sayisini giriniz: ";
	cin >> TestSayi;

	Ogrenci *ogrenci = new Ogrenci[OgrenciSayi];	//Dinamik struct oluþturdum

	for (int i = 0; i < OgrenciSayi; i++) {
		veriAl(ogrenci[i], i + 1, TestSayi);		//	Kullanidan verilerin alýnmasý iþin fonk. caðrýldi
		notHesaplama(ogrenci[i], TestSayi);			//notlarýn ortalamasi ve harfli not için fonk. caðrýldi
	}


	for (int i = 0; i < OgrenciSayi; i++) {
		goster(ogrenci[i], TestSayi);				//ogrencilerin deðerlerin ekrana gösterilmesi için caðrýldi.
	}

	cout << endl;

	//Ogrencilerin fonk. ile ortalamalarýn döndürülmesinin gerçekleþtirildi.
	for (int i = 0; i < OgrenciSayi; i++) {
		cout << (i + 1) << ". ogrencinin not ortalamasi: " << notHesaplama(ogrenci[i], TestSayi) << endl << endl;
	}

	sil(ogrenci);									 //oluþturalan verinin bellekten silinmesi için sil fonk. caðrildi.

	system("pause");
	return 0;
}
