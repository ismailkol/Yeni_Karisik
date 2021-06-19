#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode										
{
	char *ogrno, *ad, *soyad;

	TreeNode*   parent;						//parent node		
	TreeNode*   left;						//left child node	
	TreeNode*   right;						//right child node

	TreeNode()										
	{
		ogrno = new char[15];
		ad = new char[30];
		soyad = new char[30];
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

struct BinaryTree
{
	TreeNode* root;								//root node
	int n;										

	BinaryTree();								
	int size() const;								
	bool empty() const;								


	void ekleme(TreeNode* p, char *ogrNo, char *ad, char *soyad);
	void agacKurma();


	void ogrenciSil();
	void DerinlikAra(TreeNode* v,stack <char*> yigin,char *AranacakNo,int sayac,int &ToplamIslemAdimSayisi);
	

	void GeniþlikAra(TreeNode* v, queue <TreeNode*> kuyruk, char *AranacakNo, int sayac, int &ToplamIslemAdimSayisi);

	void postorderKayit(TreeNode* v);
	void preorderKayit(TreeNode* v);
	void inorderKayit(TreeNode* v);

	void preorder(TreeNode* v) const;				
	void inorder(TreeNode* v) const;				
	void postorder(TreeNode* v) const;				
	void dosyayaYazma(TreeNode* v, string dosyaAd);


};

static int kacicinciDosya = 0;			//hangi dosyanýn yazýlacagýna karar vermek icin

ofstream dosya;							//dosya yazma islemleri icin

BinaryTree::BinaryTree()						// constructor
{
	root = NULL;
	n = 0;
}


int BinaryTree::size() const					// number of nodes
{
	return n;
}

bool BinaryTree::empty() const					// is tree empty?
{
	return size() == 0;
}



//dosyaya yazmak icin agacýn kokunu ve dosya adýný yollanýyor

void BinaryTree::dosyayaYazma(TreeNode* v,string dosyaAd) {
	system("cls");

	char chr;

	cout << "dosyaya hangi sekilde kaydetmek istersiniz? "<<endl;
	cout << "Preorder kaydetmek icin: R" << endl;
	cout << "Inorder kaydetmek icin: I" << endl;
	cout << "Postorder kaydetmek icin: O" << endl;
	cout << "seciminini giriniz: ";


	cin >> chr;

	switch (chr)
	{

	case 'O':
		
		dosya.open(dosyaAd);
		postorderKayit(root);
		dosya.close();


		break;
	case 'R':
		dosya.open(dosyaAd);
		preorderKayit(root);
		dosya.close();


		break;

	case 'I':
		dosya.open(dosyaAd);
		inorderKayit(root);
		dosya.close();

		break;


	default:
		cout << "yanlis bir secimde bulundunuz.." << endl;
		break;
	}






}




//char olan ogrenci numaralarýný karsýlastýrmak icin

int karsilastýrma(char *ogrno1, char *ogrno2) {

	int iogrno1 = 0, iogrno2 = 0;
	int fonk = 1;



	for (int i = strlen(ogrno1)-1; i >= 0; i--) {
		iogrno1 += (ogrno1[i] - '0')*fonk;
		fonk = fonk * 10;
	}

	fonk = 1;

	for (int i = strlen(ogrno2)-1; i >= 0; i--) {

	
		iogrno2 += (ogrno2[i] - '0')*fonk;
		fonk = fonk * 10;

	}

	if (iogrno1 < iogrno2) {
		return 1;
	}
	else {
		return 0;
	}


}




//agaclar icin genislik arama islemi 
//aranacak noyu kullanýcý menude secme islemi gerceklestirir


void BinaryTree::GeniþlikAra(TreeNode* v, queue <TreeNode*> kuyruk, char *AranacakNo, int sayac, int &ToplamIslemAdimSayisi) {

	if (v == NULL) {
		return;
	}
	

	if(v->left!=NULL)
	kuyruk.push(v->left);

	if(v->right !=NULL)
	kuyruk.push(v->right);

	if (strcmp(kuyruk.front()->ogrno, AranacakNo) == 0) {
		cout << endl;
		//+1 konmasýnýn sebebi 0 islem diye birseyin mantýklý olmadýgýndan
		ToplamIslemAdimSayisi = sayac+1;    //aranan degerin kacýncý islemde bulundugu tutar
		cout << "Aranan bulundu bilgileri: " << kuyruk.front()->ogrno << " " << kuyruk.front()->ad << " " << kuyruk.front()->soyad << endl;

	}
	
	kuyruk.pop();

	
	if (kuyruk.size() < 1) {
		return;
	}

	 GeniþlikAra(kuyruk.front(), kuyruk, AranacakNo,sayac+1,ToplamIslemAdimSayisi);

	

}



//agaclar icin derinlik arama islemi 
//aranacak noyu kullanýcý menude secme islemi gerceklestirir


void BinaryTree::DerinlikAra(TreeNode *v, stack <char*> yigin,char *AranacakNo,int sayac,int &ToplamIslemAdimSayisi) {

	yigin.push(v->ogrno);

	if (v->left != NULL) DerinlikAra(v->left, yigin, AranacakNo,sayac+1,ToplamIslemAdimSayisi);

	
	if (v->right != NULL) 	DerinlikAra(v->right, yigin, AranacakNo, sayac + 1,ToplamIslemAdimSayisi);
	
	

	
	if (strcmp(yigin.top(), AranacakNo) == 0) {

		//n-sayac yapmamýzýn sebebi yýgýnda LIFO olmasýndandýr
		//yýgýnda en son buldugunda sayac 0 olur ama biz yýgýnda en sonki aramayý yapýyor oluruz buda simdiye kadar n kere arama yapýldýgýný gosterir
		//bizde n-sayac+1 yaparak aslýnda yýgýnýn en altýnda bulunan degerin arandýgýndaki arama sayýsý ulasýlýr

		ToplamIslemAdimSayisi = n-sayac+1;		 //aranan degerin kacýncý islemde bulundugu tutar
		cout << "Aranan bulundu bilgileri: " << v->ogrno << " " << v->ad << " " << v->soyad << endl;
		
	}

	yigin.pop();



}








// inorder listeleme
void BinaryTree::inorder(TreeNode* v) const
{

	if (v->left != NULL)	inorder(v->left);

	cout << v->ogrno << " " << v->ad << " " << v->soyad << endl;

	if (v->right != NULL)	inorder(v->right);
}

// preorder listeleme
void BinaryTree::preorder(TreeNode* v) const
{
	cout << v->ogrno << " " << v->ad << " " << v->soyad << endl;

	if (v->left != NULL)	preorder(v->left);

	if (v->right != NULL)	preorder(v->right);
}

// postorder listeleme
void BinaryTree::postorder(TreeNode* v) const
{
	if (v->left != NULL)	postorder(v->left);

	if (v->right != NULL)	postorder(v->right);

	cout << v->ogrno << " " << v->ad << " " << v->soyad << endl;
}



// inorder dosyaya kayit islemi
void BinaryTree::inorderKayit(TreeNode* v) 
{

	if (v->left != NULL)	inorderKayit(v->left);

	dosya << v->ogrno << " " << v->ad << " " << v->soyad << endl;

	if (v->right != NULL)	inorderKayit(v->right);
}

// preorder dosyaya kayit islemi
void BinaryTree::preorderKayit(TreeNode* v) 
{
	dosya << v->ogrno << " " << v->ad << " " << v->soyad << endl;

	if (v->left != NULL)	preorderKayit(v->left);

	if (v->right != NULL)	preorderKayit(v->right);
}

// postorder dosyaya kayit islemi


void BinaryTree::postorderKayit(TreeNode* v) 
{


	if (v->left != NULL)	postorderKayit(v->left);

	if (v->right != NULL)	postorderKayit(v->right);

	dosya << v->ogrno << " " << v->ad << " " << v->soyad << endl;
}


//ogrenci silme fonk.
void BinaryTree::ogrenciSil() {


	system("cls");
	char * silinecekOgrNo;
	silinecekOgrNo = new char[15];

	cout << "silmek istediginiz ogrencinin nosunu giriniz: ";
	cin >> silinecekOgrNo;


	TreeNode *p = root;


	
	
	//binaryTree node ekleme islemlerinde kucuk olan sol dugum , buyuk olan sag dugum seklinde olusturulmasýndan faydalanarak
	//aranan ogrencinin binaryTreede bulunmasi
	while (p != NULL)  
	{
		if (strcmp(p->ogrno, silinecekOgrNo) == 0)	break;
		else
		{
			if (karsilastýrma(silinecekOgrNo, p->ogrno))
				p = p->left;
			else
				p = p->right;
		}
	}

	if (p == NULL)
	{
		cout << "ogrenci mevcut degil" << endl;
		system("pause");

		return;
	}
	else
	{
		cout << p->ogrno << " silindi" << endl;
		TreeNode* temp;

		// Kendisinden büyük en küçük düðümü kendi yerine koy
		if (p->right != NULL)
		{
			temp = p->right;

			if (temp->left != NULL)
			{
				while (temp->left != NULL) temp = temp->left;
				strcpy(p->ogrno, temp->ogrno);

				if (temp->right != NULL)
				{
					temp->parent->left = temp->right;
					temp->right->parent = temp->parent;
				}
				else
				{
					temp->parent->left = NULL;
				}
			}
			else
			{
				strcpy(p->ogrno, temp->ogrno);
				strcpy(p->ad, temp->ad);
				strcpy(p->soyad, temp->soyad);

				if (temp->right != NULL)
				{
					temp->parent->right = temp->right;
					temp->right->parent = temp->parent;
				}
				else
				{
					temp->parent->right = NULL;
				}
			}
			n--;
			
			delete temp;
			return;


		}


		// Kendisinden büyük düðüm yoksa sol çocuðu kendi yerine koy
		else if (p->left != NULL)
		{
			if (p->parent != NULL)
			{
				if (p == p->parent->left)
				{
					p->parent->left = p->left;
					p->left->parent = p->parent;
				}
				else
				{
					p->parent->right = p->left;
					p->left->parent = p->parent;

				}
			}
			else
			{
				p->left->parent = NULL;
				root = p->left;
			}
			n--;
		
			delete p;
			return;
		}
	
		else
		{
			if (p->parent != NULL)
			{
				if (p->parent->left == p)
					p->parent->left = NULL;
				else
					p->parent->right = NULL;

				n--;
				
				delete p;
			}
			else
			{
				root = NULL;
				n--;
				delete root;  
			}
		}


	}

}



//node'u agaca ekleme fonk.
void BinaryTree::ekleme(TreeNode* p, char *ogrNo, char *ad, char *soyad) {

	TreeNode* newNode = new TreeNode;
	strcpy(newNode->ogrno, ogrNo);
	strcpy(newNode->ad, ad);
	strcpy(newNode->soyad, soyad);

	//olustural yeni dügüm agacta gezinerek uygun olan yere yerlestirilir.
	//yerlestirme algoritmasi dugum isaret edilen dugumden kucuk ise sola dogru
	//buyuk ise saga dogru olmak uzere agacta gezdirilir ve uygun sekilde agaca eklenir

	if (empty())
	{
		root = newNode;
		n = 1;
	}
	else
	{
		while (true)

		{

			if (karsilastýrma(ogrNo, p->ogrno)) //ogrencilerin numara karsýlastýrma
			{
				if (p->left == NULL)
				{
					p->left = newNode;
					newNode->parent = p;
					n++;
					return;
				}
				else p = p->left;
			}
			else
			{
				if (p->right == NULL)
				{
					p->right = newNode;
					newNode->parent = p;
					n++;
					return;
				}
				else p = p->right;
			}
		}
	}

}


//agac yapýsnýný olusturma

void BinaryTree::agacKurma() {


	ifstream dosya1;



	if (kacicinciDosya == 0) {
		dosya1.open("data1.txt");
	}
	else if (kacicinciDosya == 1) {
		dosya1.open("data2.txt");
	}
	else {
		dosya1.open("data3.txt");
	}

	kacicinciDosya++;

	
	char *ptr;
	char satirAl[75];
	char *ogrno, *ad, *soyad;
	ogrno = new char[15];
	ad = new char[30];
	soyad = new char[30];

	dosya1.getline(satirAl, 75);
	for (int i = 0; i < 75; i++) {				//satýr sonundaki '\r' karakterini, '\0' karakteri ile deðiþtirme
		if (satirAl[i] == '\r')
			satirAl[i] = '\0';
	}


	while (dosya1) {					//while döngüsü içinde dosyayý sonuna kadar satýr satýr okuma ve okunan satýrlarý boþluklara göre parçalayýp, 
		ptr = strtok(satirAl, "\t");		//	j sayacýnýn deðerine göre deðiþkenlere atama
		int j = 0;


		while (ptr != NULL) {
			if (j == 0)
				strcpy(ogrno, ptr);
			if (j == 1)
				strcpy(ad, ptr);
			if (j == 2)
				strcpy(soyad, ptr);
			if (j == 3) {			//bir ad ve bir soyad okunmasýna raðmen satýr sonu gelmedi ise öðrencinin iki adý var demektir,
				strcat(ad, " ");		//	bu iki ad arada bir boþluk býrakýlarak öðrenci deðiþkenine atanýr ve soyadý tekrar okunur
				strcat(ad, soyad);
				strcpy(soyad, ptr);
			}
			ptr = strtok(NULL, " ");
			j++;
		}

		ekleme(root, ogrno, ad, soyad); //agaca dugum ekleme
		
		dosya1.getline(satirAl, 75);
		for (int i = 0; i < 75; i++) {
			if (satirAl[i] == '\r')
				satirAl[i] = '\0';
		}
	}
	dosya1.close();


}


void menu(BinaryTree *binaryTree1, BinaryTree *binaryTree2, BinaryTree *binaryTree3) {

	system("cls");
	
	char secim,secim2;
	int secim3;
	char *aranan;
	int sayac;
	
	int ToplamIslemAdimSayisi = 0;
	aranan = new char[15];
	stack <char *> yigin;

	queue <TreeNode *>kuyruk;
	int kisiBulmaKontrol = 0;

	cout << "Asagidaki islemlerden birini seciniz: " << endl;

	cout << "Arama yapmak icin: A" << endl;
	cout << "Listeyi ekrana yazdirmak icin: L" << endl;
	cout << "Ogrenci silmek icin: S" << endl;
	cout << "Dosyaya yazman icin: Y" << endl;
	cout << "Cikis icin: C" << endl;

	cout << endl << "Seciminizi giriniz: ";
	cin >> secim;

	if (secim == 'A' || secim == 'a') {  //arama yapma

		cout << endl << "Derinlik arama icin: D" << endl;
		cout << "Genislik arama icin: G" << endl;
		cout << endl << "seciminizi giriniz: ";

		cin >> secim2;
		


		if (secim2 == 'D' || secim == 'd') {  //derinlik ara

			cout << endl << "Hangi dosya icin Derinlik  arama yapmak istiyorsunuz? " << endl;
			cout << "data1.txt icin: 1" << endl;
			cout << "data1.txt icin: 2" << endl;
			cout << "data1.txt icin: 3" << endl;
			cout << endl << "secimini giriniz: ";

			cin >> secim3;


			if (secim3 == 1) {
				cout << "Arama yapmak istediginiz ogrencinin nosunu giriniz: ";
				cin >> aranan;
				sayac = 0;
				binaryTree1->DerinlikAra(binaryTree1->root, yigin, aranan,sayac, ToplamIslemAdimSayisi);
				
				if (ToplamIslemAdimSayisi != 0) {
					cout << endl << "arana ogrenci " << ToplamIslemAdimSayisi << ". islemden sonra bulundu" << endl;
				}
				else {
					cout << "aranan ogrenci bulunamadi" << endl;
				}

			}


			 else if (secim3 == 2) {
				cout << "Arama yapmak istediginiz ogrencinin nosunu giriniz: ";
				cin >> aranan;
				sayac = 0;
				binaryTree2->DerinlikAra(binaryTree2->root, yigin, aranan, sayac, ToplamIslemAdimSayisi);

				if (ToplamIslemAdimSayisi != 0) {
					cout << endl << "arana ogrenci " << ToplamIslemAdimSayisi << ". islemden sonra bulundu" << endl;
				}
				else {
					cout << "aranan ogrenci bulunamadi" << endl;
				}

			}


			else if (secim3 == 3) {
				cout << "Arama yapmak istediginiz ogrencinin nosunu giriniz: ";
				cin >> aranan;
				sayac = 0;
				binaryTree3->DerinlikAra(binaryTree3->root, yigin, aranan, sayac, ToplamIslemAdimSayisi);

				if (ToplamIslemAdimSayisi != 0) {
					cout << endl << "arana ogrenci " << ToplamIslemAdimSayisi << ". islemden sonra bulundu" << endl;
				}
				else {
					cout << "aranan ogrenci bulunamadi" << endl;
				}

			}



		}


		else if (secim2 == 'G' || secim2 == 'g') { //genislik ara


			cout << endl << "Hangi dosya icin Genislik  arama yapmak istiyorsunuz? " << endl;
			cout << "data1.txt icin: 1" << endl;
			cout << "data1.txt icin: 2" << endl;
			cout << "data1.txt icin: 3" << endl;
			cout << endl << "secimini giriniz: ";

			cin >> secim3;


			if (secim3 == 1) {
				cout << "Arama yapmak istediginiz ogrencinin nosunu giriniz: ";
				cin >> aranan;

				kuyruk.push(binaryTree1->root);
				sayac = 0;
				binaryTree1->GeniþlikAra(binaryTree1->root, kuyruk, aranan, sayac, ToplamIslemAdimSayisi);

				if (ToplamIslemAdimSayisi != 0) {
					cout << endl << "arana ogrenci " << ToplamIslemAdimSayisi << ". islemden sonra bulundu" << endl;
				}
				else {
					cout << "aranan ogrenci bulunamadi" << endl;
				}

			}


			else if (secim3 == 2) {
				cout << "Arama yapmak istediginiz ogrencinin nosunu giriniz: ";
				cin >> aranan;

				kuyruk.push(binaryTree2->root);
				sayac = 0;
				binaryTree2->GeniþlikAra(binaryTree2->root, kuyruk, aranan, sayac, ToplamIslemAdimSayisi);

				if (ToplamIslemAdimSayisi != 0) {
					cout << endl << "arana ogrenci " << ToplamIslemAdimSayisi << ". islemden sonra bulundu" << endl;
				}
				else {
					cout << "aranan ogrenci bulunamadi" << endl;
				}

			}


			else if (secim3 == 3) {
				cout << "Arama yapmak istediginiz ogrencinin nosunu giriniz: ";
				cin >> aranan;


				kuyruk.push(binaryTree3->root);
				sayac = 0;
				binaryTree3->GeniþlikAra(binaryTree3->root, kuyruk, aranan, sayac, ToplamIslemAdimSayisi);

				if (ToplamIslemAdimSayisi != 0) {
					cout << endl << "arana ogrenci " << ToplamIslemAdimSayisi << ". islemden sonra bulundu" << endl;
				}
				else {
					cout << "aranan ogrenci bulunamadi" << endl;
				}

			}


		}
		else {
			cout << "yanlis secim girdininiz.." << endl;
			
		}


	}






	else if (secim == 'L' || secim == 'l') { //listeyi ekrana yazma


	cout <<endl<< "Preorder listeleme yapmak icin: R" << endl;
	cout << "Inorder listeleme yapmak icin: I" << endl;
	cout << "Postorder listeleme yapmak icin: O" << endl;
	cout << "seciminini giriniz: ";
	
	cin >> secim2;

	if (secim2 == 'R' || secim2 == 'r') {  // Preorder listeleme

		cout <<endl<< "Hangi dosya icin Preorder listelemek yapmak istiyorusnuz? " << endl;
		cout << "data1.txt icin: 1" << endl;
		cout << "data1.txt icin: 2" << endl;
		cout << "data1.txt icin: 3" << endl;
		cout << endl << "secimini giriniz: ";

		cin >> secim3;

		if (secim3 == 1) {

			binaryTree1->preorder(binaryTree1->root);
			cout << endl;

		}
		else if (secim3 == 2) {

			binaryTree2->preorder(binaryTree2->root);
			cout << endl;

		}
		else if (secim3 == 3) {
			binaryTree3->preorder(binaryTree3->root);
			cout << endl;

		}
		else {
			cout << "yanlis secim girdininiz.." << endl;

		}



	}

	else if (secim2 == 'I' || secim2 == 'ý') {  // Inorder listeleme



		cout << endl << "Hangi dosya icin Inorder listelemek yapmak istiyorusnuz? " << endl;
		cout << "data1.txt icin: 1" << endl;
		cout << "data1.txt icin: 2" << endl;
		cout << "data1.txt icin: 3" << endl;
		cout << endl << "secimini giriniz: ";

		cin >> secim3;

		if (secim3 == 1) {

			binaryTree1->inorder(binaryTree1->root);
			cout << endl;

		}
		else if (secim3 == 2) {

			binaryTree2->inorder(binaryTree2->root);
			cout << endl;

		}
		else if (secim3 == 3) {
			binaryTree3->inorder(binaryTree3->root);
			cout << endl;

		}
		else {
			cout << "yanlis secim girdininiz.." << endl;

		}




	}
	else if (secim2 == 'O' || secim2 == 'o') {  // Postorder listeleme

		cout << endl << "Hangi dosya icin Postorder listelemek yapmak istiyorusnuz? " << endl;
		cout << "data1.txt icin: 1" << endl;
		cout << "data1.txt icin: 2" << endl;
		cout << "data1.txt icin: 3" << endl;
		cout << endl << "secimini giriniz: ";

		cin >> secim3;

		if (secim3 == 1) {

			binaryTree1->postorder(binaryTree1->root);
			cout << endl;

		}
		else if (secim3 == 2) {

			binaryTree2->postorder(binaryTree2->root);
			cout << endl;

		}
		else if (secim3 == 3) {
			binaryTree3->postorder(binaryTree3->root);
			cout << endl;

		}
		else {
			cout << "yanlis secim girdininiz.." << endl;

		}




	}
	else {
		cout << "yanlis secim girdininiz.." << endl;

	}




	}






	else if (secim == 'S' || secim == 's') { //ogrenci silme

	cout << endl << "Hangi dosya icin ogrenci silmek  istiyorusnuz? " << endl;
	cout << "data1.txt icin: 1" << endl;
	cout << "data1.txt icin: 2" << endl;
	cout << "data1.txt icin: 3" << endl;
	cout << endl << "secimini giriniz: ";

	cin >> secim3;



	if (secim3 == 1) {

		binaryTree1->ogrenciSil();
		cout << endl;

	}
	else if (secim3 == 2) {
		binaryTree2->ogrenciSil();
		cout << endl;

	}
	else if (secim3 == 3) {
		binaryTree2->ogrenciSil();
		cout << endl;


	}
	else {
		cout << "yanlis secim girdininiz.." << endl;
	}



	}







	else if (secim == 'Y' || secim == 'y') { //dosyaya yazma


	cout << endl << "Hangi dosya icin dosya yazma islemi istiyorusnuz? " << endl;
	cout << "data1.txt icin: 1" << endl;
	cout << "data1.txt icin: 2" << endl;
	cout << "data1.txt icin: 3" << endl;
	cout << endl << "secimini giriniz: ";

	cin >> secim3;


	if (secim3 == 1) {

		binaryTree1->dosyayaYazma(binaryTree1->root, "data1Yeni.txt");
		cout << endl;

	}

	else if (secim3 == 2) {
		binaryTree2->dosyayaYazma(binaryTree2->root, "data2Yeni.txt");
		cout << endl;

	}
	else if (secim3 == 3) {
		binaryTree3->dosyayaYazma(binaryTree3->root, "data3Yeni.txt");
		cout << endl;

	}

	else {
		cout << "yanlis secim girdininiz.." << endl;
	}






	}
	else if (secim == 'C' || secim == 'c') { //cikis


	exit(0);

	}
	else {
		cout << "yanlis secim girdininiz.." << endl;
		
	}

	cout << "Menuye donmek icin enter'a basiniz.." <<endl;
	system("pause");
	menu(binaryTree1, binaryTree2, binaryTree3);




}



int main() {

	//agaclar
	BinaryTree *binaryTree1, *binaryTree2, *binaryTree3;
	binaryTree1 = new BinaryTree;
	binaryTree2 = new BinaryTree;
	binaryTree3 = new BinaryTree;


	//agaclari olusturma
	binaryTree1->agacKurma();
	cout << endl;

	binaryTree2->agacKurma();
	cout << endl;
	binaryTree3->agacKurma();
	cout << endl;



	menu(binaryTree1, binaryTree2, binaryTree3);

	

	return 0;

}