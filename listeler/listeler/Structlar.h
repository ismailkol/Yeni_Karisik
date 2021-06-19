#pragma once

#include <iostream>
using namespace std;

struct ders {
	char derskodu[10];
	char dersadi[50];
	ders *sonraki;
};

struct ogrenci {
	char ogrno[15];
	char ad[30];
	char soyad[30];
	ders *dersdugumu;
	ogrenci *sonraki;

	ogrenci() {
		dersdugumu = NULL;
	};
};


//ogrencilerin listesinini olusturmak icin ogrenciliste struct olusturdum bu sayede ogrencilere ve derslerine daha kolay bir sekilde ulasýlmasýnýn sagladým
struct ogrencliListe {

	ogrencliListe() {
		head = NULL;
	};

	ogrenci * head;
	void listeKur();
	void listele();
	bool empty();
	void dersSil();
	void ogrenciSil();
	void ara();
	void kesisimBul();
	void dosyayaYaz();
	void menu();
};
