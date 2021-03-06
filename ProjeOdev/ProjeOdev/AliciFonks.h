#pragma once
#include<string>
#include <iostream>
#include <string>
#include "Kullanici.h"
using namespace std;


void Alici::paraEkleme(double para) {

	this->para = para + this->para;
}

void Alici::setPara(double para) {

	this->para = this->para - para;
}

//alınan urunlerin dizilerde tutulma islemi icin olusturuldu
void Alici::siparisEdilenlerEkleme(string alinanUrunAd, double alinanmiktar, double odenenTutar, int siparisEdilenUrunYıl, int siparisEdilenUrunAy, int siparisEdilenUrunGun, double siparisEdilenBirimFiyat) {

	siparisEdilenUrun[siparisSayisi] = alinanUrunAd;
	siparisEdilenUrunMiktar[siparisSayisi] = alinanmiktar;
	siperisteOdenentutar[siparisSayisi] = odenenTutar;
	this->siparisEdilenBirimFiyat[siparisSayisi] = siparisEdilenBirimFiyat;
	this->siparisEdilenUrunYıl[siparisSayisi] = siparisEdilenUrunYıl;
	this->siparisEdilenUrunAy[siparisSayisi] = siparisEdilenUrunAy;
	this->siparisEdilenUrunGun[siparisSayisi] = siparisEdilenUrunGun;

	siparisSayisi++;
}

void Alici::siparislerGosterme() {
	system("cls");

	cout << "\t\t -- SİPARİSLERİM ---" << endl;


	if (siparisSayisi > 0) {

		for (int i = 0; i < siparisSayisi; i++) {
			cout << "\tTarih:"<< siparisEdilenUrunGun[i]<<"."<< siparisEdilenUrunAy[i]<<"."<< siparisEdilenUrunYıl[i] <<"  alinan urun ad: " << siparisEdilenUrun[i] << " alinan urunun miktari: " << siparisEdilenUrunMiktar[i] <<" alinan urun birim fiyat: "<< siparisEdilenBirimFiyat[i] <<" alinan urun icin odenen tutar: " << siperisteOdenentutar[i] << endl;
		}

	}
	else {
		cout << "siparisiniz bulunmamaktadir." << endl;
	}

}

void Alici::raporOlusturma() {
	system("cls");
	
	int tarih1Yıl, tarih1Ay, tarih1Gun, tarih2Yıl, tarih2Ay, tarih2Gun;
	int temp;
	string tarih;
	int kontrol = 0;
	string urunAD;
	cout << "hangi tarihlerde rapor olusturmak istediginizi giriniz.." << endl;
	cout << "Birinci tarih'in Yılı: ";
	cin >> tarih1Yıl;
	cout << "Birinci tarih'in Ayı: ";
	cin >> tarih1Ay;
	cout << "Birinci tarih'in Gun: ";
	cin >> tarih1Gun;
	cout << endl;

	cout << "Ikinci tarih Yılı: ";
	cin >> tarih2Yıl;
	cout << "Ikıncı tarih Ay'ı: ";
	cin >> tarih2Ay;
	cout << "Ikıncı tarih Gun: ";
	cin >> tarih2Gun;


	//kucuk olan tarihi tarih1'e atanmasını kontrol ediyorum
	if (tarih1Yıl > tarih2Yıl) {
		temp = tarih1Yıl;
		tarih1Yıl = tarih2Yıl;
		tarih2Yıl = temp;

		temp = tarih1Ay;
		tarih1Ay = tarih2Ay;
		tarih2Ay = temp;

		temp = tarih1Gun;
		tarih1Gun = tarih2Gun;
		tarih2Gun = temp;

	}
	else if (tarih1Yıl == tarih2Yıl && tarih1Ay > tarih2Ay) {

		temp = tarih1Ay;
		tarih1Ay = tarih2Ay;
		tarih2Ay = temp;

		temp = tarih1Gun;
		tarih1Gun = tarih2Gun;
		tarih2Gun = temp;

	}
	else if (tarih1Yıl == tarih2Yıl && tarih1Ay == tarih2Ay && tarih1Gun > tarih2Gun) {

		temp = tarih1Gun;
		tarih1Gun = tarih2Gun;
		tarih2Gun = temp;

	}
	cout << endl << "Hangi ürünün listelenmek istediginizi giriniz: ";
	cin >> urunAD;

	cout << endl << tarih1Gun << "." << tarih1Ay << "." << tarih1Yıl << "  --  " << tarih2Gun << "." << tarih2Ay << "." << tarih2Yıl << " tarihleri arasindaki "<<urunAD <<" adlı urunlerin raporlari olusturuluyor.." << endl;

	ofstream dosya;
	dosya.open("AliciRapor.csv");

	dosya << "Tarih" << ";" << "Urun tipi" << ";" << "Alım tutari" << ";" << "Miktar" << endl;



	for (int i = 0; i < siparisSayisi; i++) {
		
		if (siparisEdilenUrun[i] == urunAD) {

			if (siparisEdilenUrunYıl[i] > tarih1Yıl && siparisEdilenUrunYıl[i] < tarih2Yıl) {

				tarih = to_string(siparisEdilenUrunGun[i]) + "." + to_string(siparisEdilenUrunAy[i]) + "." + to_string(siparisEdilenUrunYıl[i]);
				dosya << tarih<<";" << urunAD << ";" << siparisEdilenBirimFiyat[i] << ";" << siparisEdilenUrunMiktar[i] << endl;

				kontrol = 1;
			}
			else if (siparisEdilenUrunYıl[i] == tarih1Yıl) {

				if (siparisEdilenUrunAy[i] > tarih1Ay) {
					tarih = to_string(siparisEdilenUrunGun[i]) + "." + to_string(siparisEdilenUrunAy[i]) + "." + to_string(siparisEdilenUrunYıl[i]);

					dosya <<tarih << ";" << urunAD << ";" << siparisEdilenBirimFiyat[i] << ";" << siparisEdilenUrunMiktar[i] << endl;
					kontrol = 1;
				}
				else if (siparisEdilenUrunAy[i] == tarih1Ay) {
					if (siparisEdilenUrunGun[i] >= tarih1Gun) {

						tarih = to_string(siparisEdilenUrunGun[i]) + "." + to_string(siparisEdilenUrunAy[i]) + "." + to_string(siparisEdilenUrunYıl[i]);

						dosya <<tarih<< ";" << urunAD << ";" << siparisEdilenBirimFiyat[i] << ";" << siparisEdilenUrunMiktar[i] << endl;
						kontrol = 1;
					}
				}
			}
			else if (siparisEdilenUrunYıl[i] == tarih2Yıl) {

				if (siparisEdilenUrunAy[i] < tarih2Ay) {

					tarih = to_string(siparisEdilenUrunGun[i]) + "." + to_string(siparisEdilenUrunAy[i]) + "." + to_string(siparisEdilenUrunYıl[i]);
					dosya << tarih<< ";" << urunAD << ";" << siparisEdilenBirimFiyat[i] << ";" << siparisEdilenUrunMiktar[i] << endl;
					kontrol = 1;
				}
				else if (siparisEdilenUrunAy[i] == tarih2Ay) {
					if (siparisEdilenUrunGun[i] <= tarih2Gun) {

						tarih = to_string(siparisEdilenUrunGun[i]) + "." + to_string(siparisEdilenUrunAy[i]) + "." + to_string(siparisEdilenUrunYıl[i]);

						dosya <<tarih << ";" << urunAD << ";" << siparisEdilenBirimFiyat[i] << ";" << siparisEdilenUrunMiktar[i] << endl;
						kontrol = 1;
					}
				}

			}


}

	}

	if (kontrol == 0) {
		cout<<endl << "Girilen degerlere uygun urunler bulunamamistir" << endl;
	}

	dosya.close();

	





}




