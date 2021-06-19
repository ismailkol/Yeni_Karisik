#include <stdio.h>
#include <iostream>
#include <string> //stringler ile i�lem yapmak i�in ekledim


using namespace std;

struct Ogrenci {
	string isim, harfnotu;
	int ogrencino, *testnotlari;
	double ortalama;
};


//Kullanicidan alinan degerleri veriAl fonk. yard�m� ile struct de�erlerine kaydetme i�leminin gercekle�tirdik.
//3 tane paremereli yaptim. &student main'de olu�turdugum ogrenci verisi tutar ve degisiklik yaptigimiza main'de gozukur.
//kacinci degeri bizim kacinci ogrenciyi olusturdugumuzu gosterir.
//testS bize kac tane test oldugunu gosterir.


void veriAl(Ogrenci &student, int kacinci, int testS) {
	cout << endl;
	cout << kacinci << ". ogrencinin adini giriniz: ";
	cin >> student.isim;										//kullan�c�dan isim al�n�r ve struct'a kaydedilir.
	cout << kacinci << ". ogrencinin numarasini giriniz: ";
	cin >> student.ogrencino;									//kullanicidan ogrenciNo al�n�r ve olu�turulan struct ogrenci de�erine kaydedilir.
	student.testnotlari = new int[testS];						//testnotlari degerinin dinamik olarak olu�turduk.


	for (int i = 0; i < testS; i++) {
		cout << kacinci << ". ogrencinin " << (i + 1) << ". test notunu giriniz: ";
		cin >> student.testnotlari[i];													//olu�turulan testnotlar� kullan�dan al�narak kaydedilir.

		//Girilen notlar�n harfli notlara ve 100 not sistemine uymas� i�in bir if ko�ulu koydum.
		//Bu sayede kullan�c�n�n eksi de�erler yada 100 b�y�k say�lar girilmesi engellenmi�tir.
		if (student.testnotlari[i] > 100 || student.testnotlari[i] < 0) {
			cout << "hatali bir sinav notlamasi yaptiniz.Notu tekrar giriniz" << endl;
			exit(1);																	//100 sistem olmayan not girilirse sistemi kapat
		}
	}


}


//Not hesaplamak i�in 2 paremetre yolladim.
//student parametresi main'de olu�turulan ve bu fonksiyona yollanan struct de�erini tutar.
//testS test sayisini ifade eder.

double notHesaplama(Ogrenci &student, int testS) {

	double ortalama = 0;
	for (int i = 0; i < testS; i++) {
		ortalama += student.testnotlari[i];			//struct'tan alinan testnotlariyla ortalama hesab� i�in �a�r�ld� ve kullan�ld�
	}
	ortalama = ortalama / testS;					//Notlar�n ortalam�n�n alinmasi islemi ger�ekle�tirildi.
	student.ortalama = ortalama;					//ortalama struct kaydedildi



	//ortalamaya g�re hangi harfli notun gelece�inin ayarlanmas� i�in ko�ullar sa�lad�m.
	//ortalamaya g�re struct harfli nota kaydedildi.
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
	//ornek program ��kt�s�n�n sa�lanmas� i�in alttaki sat�r� yazd�m.
	cout << "Ortalama is: " << ortalama << " Harf notu: " << student.harfnotu << endl;

	return ortalama;		//double geri d�n��l� fonk. oldu�u i�in geriye ortalama de�erini d�nd�rd�m.
}



//olu�turulan verilerin ekrana g�sterilmesi i�in 2 paremetreli goster fonk. olu�turdum.
//student parametresi main'de olu�turulan ve bu fonksiyona yollanan struct de�erini tutar.
//testS test sayisini ifade eder.
void goster(Ogrenci &student, int testS) {

	//student verisi ile bu structa ait de�erleri ekrana g�sterme i�lemini ger�ekle�tirdik.


	cout << endl;
	cout << "Ogrencinin adi: " << student.isim << endl;
	cout << "Ogrencinin numarasi:" << student.ogrencino << endl;
	for (int i = 0; i < testS; i++) {
		cout << "ogrencinin " << (i + 1) << ". test sonucu: " << student.testnotlari[i] << endl;
	}
	cout << "Ogrencinin ortalamasi: " << student.ortalama << endl;
	cout << "Ogrencinin harfli notu: " << student.harfnotu << endl;

}


//olu�turulan struct'� bellekten silme i�lemini ger�ekle�tirdim.
void sil(Ogrenci *student) {

	delete[]student;
}



int main() {

	//ogrenci sayisi ve test sayisini kullan�dan ald�m
	int OgrenciSayi = 0;
	int TestSayi;
	cout << "Ogrenci sayisini giriniz:  ";
	cin >> OgrenciSayi;
	cout << "Test sayisini giriniz: ";
	cin >> TestSayi;

	Ogrenci *ogrenci = new Ogrenci[OgrenciSayi];	//Dinamik struct olu�turdum

	for (int i = 0; i < OgrenciSayi; i++) {
		veriAl(ogrenci[i], i + 1, TestSayi);		//	Kullanidan verilerin al�nmas� i�in fonk. ca�r�ldi
		notHesaplama(ogrenci[i], TestSayi);			//notlar�n ortalamasi ve harfli not i�in fonk. ca�r�ldi
	}


	for (int i = 0; i < OgrenciSayi; i++) {
		goster(ogrenci[i], TestSayi);				//ogrencilerin de�erlerin ekrana g�sterilmesi i�in ca�r�ldi.
	}

	cout << endl;

	//Ogrencilerin fonk. ile ortalamalar�n d�nd�r�lmesinin ger�ekle�tirildi.
	for (int i = 0; i < OgrenciSayi; i++) {
		cout << (i + 1) << ". ogrencinin not ortalamasi: " << notHesaplama(ogrenci[i], TestSayi) << endl << endl;
	}

	sil(ogrenci);									 //olu�turalan verinin bellekten silinmesi i�in sil fonk. ca�rildi.

	system("pause");
	return 0;
}
