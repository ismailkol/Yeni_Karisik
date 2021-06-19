#pragma once
#include "Structlar.h"
#include <iostream>
#include <fstream>
using namespace std;

//listedeki elemaný dosyaya yazdýrma islemi icin fonk olusturdum
void ogrencliListe::dosyayaYaz() {

	ofstream dosya("dosyaCýktý.txt");

	ogrenci* first = head;
	while (first != NULL)
	{
		dosya << first->ogrno << "\t" << first->ad << "\t" << first->soyad;
		ders * dFirst = first->dersdugumu;

		while (dFirst != NULL) {
			dosya << "\t" << dFirst->derskodu << "\t" << dFirst->dersadi;
			dFirst = dFirst->sonraki;
		}
		dosya << endl;
		first = first->sonraki;

	}



}



void ogrencliListe::kesisimBul() {
	system("cls");
	char derskodu1[10], derskodu2[10];
	int kontrol = 0;
	cout << "kesisimlerini bulmak istediginiz 1. ders kodunu giriniz: ";
	cin >> derskodu1;
	cout << "kesisimlerini bulmak istediginiz 2. ders kodunu giriniz:";
	cin >> derskodu2;

	//kontrol ile iki derside alýnýp alýnmamasýný anlamak icin olusturdum ikisinide alýyorsa kontrol 2 olmaktadýr
	ogrenci *first = head;
	while (first != NULL) {
		kontrol = 0;
		ders *dfirst = first->dersdugumu;

		while (dfirst != NULL) {

			if (strcmp(dfirst->derskodu, derskodu1) == 0) {
				kontrol++;
			}
			else if (strcmp(dfirst->derskodu, derskodu2) == 0) {

				kontrol++;
			}


			dfirst = dfirst->sonraki;
		}


		if (kontrol == 2) {
			cout << "secilen  dersleri ortak alan ogrenci: " << first->ogrno << "\t" << first->ad << "\t" << first->soyad << endl;
		}

		first = first->sonraki;
	}



}






void ogrencliListe::ara() {
	system("cls");
	int secim;
	char ogrnNo[15];
	char soyad[30];
	int kontrol = 0;
	ogrenci *first;
	//istenilene gore ogrencinin bulunmasi icin
	cout << "ogrenciyi numarasina gore aramak icin 1'e soyadina gore aramak icin 2'e basiniz: ";
	cin >> secim;

	switch (secim)
	{
	case 1:
		kontrol = 0;
		cout << "ogerncinin ogrNo'sunu giriniz: ";
		cin >> ogrnNo;

		first = head;

		while (first != NULL) {

			if (strcmp(first->ogrno, ogrnNo) == 0) {
				cout << "\naradiginiz ogrenci bulunmustur bilgileri asagidadir; " << endl;
				cout << first->ogrno << "\t" << first->ad << "\t" << first->soyad;
				ders *dfirst = first->dersdugumu;
				kontrol = 1;
				while (dfirst != NULL) {
					cout << "\t" << dfirst->derskodu << "\t" << dfirst->dersadi;

					dfirst = dfirst->sonraki;
				}
				cout << endl;

			}

			first = first->sonraki;
		}

		if (kontrol == 0) {
			cout << "\naradiginiz ogrenci bulunmamaktadir." << endl;
		}


		break;

	case 2:
		kontrol = 0;
		cout << "ogrencinin soyadini giriniz: ";
		cin >> soyad;

		first = head;

		while (first != NULL) {

			if (strcmp(first->soyad, soyad) == 0) {
				cout << "\naradiginiz ogrenci bulunmustur bilgileri asagidadir; " << endl;
				cout << first->ogrno << "\t" << first->ad << "\t" << first->soyad;
				ders *dfirst = first->dersdugumu;
				kontrol = 1;
				while (dfirst != NULL) {
					cout << "\t" << dfirst->derskodu << "\t" << dfirst->dersadi;

					dfirst = dfirst->sonraki;
				}
				cout << endl;

			}

			first = first->sonraki;
		}

		if (kontrol == 0) {
			cout << "\naradiginiz ogrenci bulunmamaktadir." << endl;
		}


		break;



	default:
		cout << "\nsectiginiz deger dogru degildir." << endl;
		break;
	}

}




void ogrencliListe::dersSil() {

	system("cls");
	ogrenci *first = head;
	int kontrol = 0;

	char Sogrno[8], SdersKodu[8];
	cout << "silmek istediginiz dersin ogrenci no'sunu giriniz: ";
	cin >> Sogrno;
	cout << "silmek istediginiz dersin kodunu giriniz: ";
	cin >> SdersKodu;

	//ogrencinin bulunmasý ve ona ait olan dersin silinmesi
	while (first != NULL) {

		if (strcmp(first->ogrno, Sogrno) == 0) {


			//ilk elmanmý silinecek
			if (strcmp(first->dersdugumu->derskodu, SdersKodu) == 0) {
				ders *temp = first->dersdugumu;
				first->dersdugumu = first->dersdugumu->sonraki;
				delete temp;
				kontrol = 1;
				break;
			}

			ders *dfirst = first->dersdugumu;
			while (dfirst->sonraki != NULL) {

				if (strcmp(dfirst->sonraki->derskodu, SdersKodu) == 0) {
					ders *temp = dfirst->sonraki;
					dfirst->sonraki = dfirst->sonraki->sonraki;
					delete temp;
					kontrol = 1;
					break;

				}

			}
		}

		first = first->sonraki;
	}
	if (kontrol == 0) {
		cout << "\nSilinecek eleman bulunamadi.." << endl;
	}

}


void ogrencliListe::ogrenciSil() {

	system("cls");
	char Sogrno[8];
	int kontrol = 0;
	cout << "silmek istediginiz  ogrenci no'sunu giriniz: ";
	cin >> Sogrno;




	//ilk elemanmý silinecek
	if (strcmp(head->ogrno, Sogrno) == 0) {

		ogrenci *temp = head;
		head = head->sonraki;
		delete temp;

		return;

	}

	//silinecek elemanýn bulunmasý
	ogrenci *first = head;
	while (first->sonraki != NULL) {

		if (strcmp(first->sonraki->ogrno, Sogrno) == 0) {
			ogrenci * temp = first->sonraki;
			first->sonraki = first->sonraki->sonraki;
			delete temp;
			kontrol = 1;
			break;
		}
		first = first->sonraki;
	}

	if (kontrol == 0) {
		cout << "silinecek eleman bulunamadi.." << endl;
	}




}








//dersin ogrenciye kayýt etmek icin

void dersKayit(ogrenci *v, char ders_k[10], char ders_A[50]) {

	//ogrencinin ilk ders ekleme islemi mi
	if (v->dersdugumu == NULL) {

		ders *count = new ders;
		strcpy(count->derskodu, ders_k);
		strcpy(count->dersadi, ders_A);
		count->sonraki = NULL;
		v->dersdugumu = count;

	}
	
	else {
		ders *count = new ders;
		strcpy(count->derskodu, ders_k);
		strcpy(count->dersadi, ders_A);
		count->sonraki = NULL;
		ders* dFirst = v->dersdugumu;
		while (dFirst->sonraki != NULL)dFirst = dFirst->sonraki;
		dFirst->sonraki = count;

	}
}

//ogrenci no'larýný karsýlastýrmak icin
int karsilastýrma(char ogrno1[15], char ogrno2[15]) {

	int iogrno1 = 0, iogrno2 = 0;
	int fonk = 1;

	for (int i = 6; i >= 0; i--) {

		iogrno1 += (ogrno1[i] - '0')*fonk;
		iogrno2 += (ogrno2[i] - '0')*fonk;
		fonk = fonk * 10;

	}

	if (iogrno1 <= iogrno2) {
		return 1;
	}
	else {
		return 0;
	}


}

//baglý liste olustururken,olusturuluken atanacak degerleri dosyalardan alma islemlerini gerceklestirmek icin olusturdum
void ogrencliListe::listeKur() {

	//dosya adlarýný diziye atadým
	string *dersDosyalarý = new string[3];
	dersDosyalarý[0] = "mat101.txt";
	dersDosyalarý[1] = "fiz101.txt";
	dersDosyalarý[2] = "eng101.txt";
	int dersSayac = 0;
	int kontrol;
	while (dersSayac < 3) {

		ifstream dosyaOku(dersDosyalarý[dersSayac]);
		char ders_k[10], ders_A[50];
		dosyaOku >> ders_k;
		dosyaOku >> ders_A;

		//ogrenci kayýtlarýný ve ders kayýtlama islemlerini donguler ile gerceklestirdim
		while (!dosyaOku.eof()) {

			ogrenci *v = new ogrenci;

			dosyaOku >> v->ogrno;
			dosyaOku >> v->ad;

			dosyaOku >> v->soyad;

			v->sonraki = NULL;

			//dersSayac ile ilk dosyanýn okuma islemimi yoksa ilkinden sonraki okumamý gerceklestiriyor diye olusturdum.
			//ilk dosyayý okuduktan sonra dersSayac=1 atayarak algoritmayý ona göre olusturdum
			if (dersSayac == 0) {

				//ilk elemanmý eklenecek
				if (head == NULL) {
					head = v;

					dersKayit(v, ders_k, ders_A);


				}

				else {

					//degerleri sýrasýyla eklemek icin olusturdum
					if (karsilastýrma(v->ogrno, head->ogrno)) {

						v->sonraki = head;
						head = v;
						dersKayit(v, ders_k, ders_A);

					}
					else {


						//listeki elemanlarý sýrasýyla karsýlastýrmak ve dogru yere yerlestirmek icin olsuturdum
						//Bu sayede sýralý ekleme islemlerini gerceklestirdim
						ogrenci *first = head;
						while (first->sonraki != NULL) {


							if (karsilastýrma(first->sonraki->ogrno, v->ogrno))
								first = first->sonraki;
							else
								break;

						}


						v->sonraki = first->sonraki;
						first->sonraki = v;

						dersKayit(v, ders_k, ders_A);
					}
				}


			}
			//ilk dosyanýn okumasýndan sonraki liste olusturma islemlerini gerceklestirmek icin 
			else {

				ogrenci *first = head;
				kontrol = 0;
				
				//eklenmek isteden ogrenci listede daha once varsa sadece ders kayýdýný o ogrenciye eklenmesi icin
				while (first != NULL) {

					if (strcmp(first->ogrno, v->ogrno) == 0) {
						dersKayit(first, ders_k, ders_A);
						delete v;
						kontrol = 1;
						break;
					}
					first = first->sonraki;
				}
				//listeye ilk eleman mý eklenecek
				if (kontrol == 0) {
					if (head == NULL) {
						head = v;

						dersKayit(v, ders_k, ders_A);


					}

					else {
						//eklenecek ogrenci bastaki listedeki degerden kucuk ise eklenecek eleman listenin en basýna eklenmesi icin
						if (karsilastýrma(v->ogrno, head->ogrno)) {
							v->sonraki = head;
							head = v;
							dersKayit(v, ders_k, ders_A);

						}
						else {


							//degerlerin sýrasýyla eklenmesi icin
							ogrenci *first = head;
							while (first->sonraki != NULL) {
								if (karsilastýrma(first->sonraki->ogrno, v->ogrno))
									first = first->sonraki;
								else
									break;

							}


							v->sonraki = first->sonraki;
							first->sonraki = v;

							dersKayit(v, ders_k, ders_A);
						}

					}

				}




			}







		}

		dersSayac++;
		dosyaOku.close();
	}
}





//listede eleamanýn olup olmadigini kontrol ettim
bool ogrencliListe::empty()
{
	return head == NULL;
}

//listedeki elemanlarin gösterilme islemlerini gerceklestirdim
void ogrencliListe::listele()
{
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	//listedeki ilk degere pointýrla ulasýp sýrayla gösterimlerini gerceklestirdim
	ogrenci* first = head;
	while (first != NULL)
	{
		cout << first->ogrno << "\t" << first->ad << "\t" << first->soyad;
		ders * dFirst = first->dersdugumu;

		while (dFirst != NULL) {
			cout << "\t" << dFirst->derskodu << "\t" << dFirst->dersadi;
			dFirst = dFirst->sonraki;
		}
		cout << endl;
		first = first->sonraki;

	}
}

//menu fonk. olustusturarak listede yapilmasi istenen fonksiyonlara ulasmak icin olusturdum
void  ogrencliListe::menu() {
	system("cls");
	string secim = "";
	cout << "\t\t----islem menusu----" << endl << endl;
	cout << "Yapmak istediginiz islem icin asagadiki durumlardan  birini giriniz..." << endl;
	cout << "Arama yapmak icin: A " << endl;
	cout << "Ders silmel icin: D" << endl;
	cout << "Kesisim bulmak icin: K" << endl;
	cout << "Listeyi ekrana yazdirmak icin: L" << endl;
	cout << "Ogrenci silmek icin: O" << endl;
	cout << "Dosya yaz: Y" << endl;
	cout << "Cikis icin: C" << endl;
	cout << "Seciminizi giriniz: ";
	cin >> secim;

	if (secim == "A" || secim == "a") {
		ara();
		cout<<endl << "menuye donmek icin enter'a basiniz..";
		system("pause");
		menu();
	}
	else if (secim=="D" || secim=="d") {
		dersSil();
		cout<<endl << "menuye donmek icin enter'a basiniz..";
		system("pause");
		menu();
	}

	else if (secim == "K" || secim == "k") {

		kesisimBul();
		cout<<endl << "menuye donmek icin enter'a basiniz..";
		system("pause");
		menu();
	}

	else if (secim=="L" || secim=="l") {
		listele();
		cout<<endl << "menuye donmek icin enter'a basiniz..";
		system("pause");
		menu();
	}

	else if (secim == "O" || secim == "o") {
		ogrenciSil();
		cout << endl << "menuye donmek icin enter'a basiniz..";
		system("pause");
		menu();
	}

	else if (secim == "Y" || secim == "y") {
		dosyayaYaz();
		cout << endl << "menuye donmek icin enter'a basiniz..";
		system("pause");
		menu();
	}
	else if (secim == "C" || secim == "c") {
		exit(1);
	}
	else {
		cout << "Girilen deger istenilen degerlere uymamaktadir.." << endl;
		cout << "Tekrardan menuye donmek icin enter'a basiniz.." << endl;
		system("pause");
		menu();
	}




}