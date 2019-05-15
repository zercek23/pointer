/**        
* @file  main.cpp  
* @description Yonetim class'ı ve içindekiler. Menü içindeki işlemleri gerçekleştiren fonksiyonlara sahiptir. Ek olarak dosyaOku() fonksiyonu da buradadır. 
* @course  1.Öğretim A Grubu  
* @assignment  1.Ödev   
* @date  26.10.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#ifndef YONETIM_HPP
#define YONETIM_HPP

#include "Okul.hpp"

using namespace std;

int sinifSayisi; //Toplam sinif sayisini tutar.
int ogrenciSayilari[10]; //Siniflardaki ogrenci sayilarini tutar.

class Yonetim
{
private:
	int sayiTemp;
	Okul *okul = new Okul;
public:
	Yonetim()
	{
	}
	int MaksSiniftakiOgrSayisi() //Siniflardaki ogrenci sayilarindan en fazla ogrencisi olan sayiyi ceker.
	{
		int mak;
		mak = ogrenciSayilari[0];
		for (int i = 1; i < sinifSayisi; i++)
		{
			if (mak < ogrenciSayilari[i])
			{
				mak = ogrenciSayilari[i];
			}
		}
		return mak;
	}
	void DosyaOku()
	{
		string satir;
		int c = 0;
		sinifSayisi = 0;
		ifstream dosyaOku;
		dosyaOku.open("Okul.txt", ios::in);
		while (getline(dosyaOku, satir))
		{
			c = 0;
			okul->getpSiniflar()[sinifSayisi].setSinif(satir[0]);
			for (int i = 0; i < satir.length(); i++)
			{
				if (isalpha(satir[i]))
				{
					okul->getpSiniflar()[sinifSayisi].getpOgrenciler()[c].setisim(satir[i]);
					c++;
				}
			}
			ogrenciSayilari[sinifSayisi] = c;
			sinifSayisi++;
			if (dosyaOku.eof())	break;
		}
		dosyaOku.close();
	}

	void SonDurumYaz()
	{
		for (int i = 0; i < sinifSayisi; i++)
		{
			cout << "Sinif: " << i + 1 << "	";
		}
		cout << endl;

		int a;
		for (int i = 0; i < MaksSiniftakiOgrSayisi(); i++)
		{
			a = 0;
			for (int j = 0; j < sinifSayisi; j++)
			{
				if (ogrenciSayilari[a] > i)
				{
					cout << okul->getpSiniflar()[j].getpOgrenciler()[i].getisim() << "(" << &(okul->getpSiniflar()[j].getpOgrenciler()[i]) << ")	";
				}
				else
				{
					cout << "		";
				}
				a++;
			}
			cout << endl;
		}
	}
	void SinifDegis(int sinif1, int sinif2)
	{
		okul->getTemp()[0] = okul->getpSiniflar()[sinif1 - 1];	//Gecici pointer nesneye ilk istenilen atanır.
		okul->getpSiniflar()[sinif1 - 1] = okul->getpSiniflar()[sinif2 - 1]; //Ilk istenilene ikinci istenen atanır.
		okul->getpSiniflar()[(sinif2 - 1)] = okul->getTemp()[0];	//Ikinci istenene gecici pointer atanir ve yerler degismis olur.

		sayiTemp = ogrenciSayilari[sinif1 - 1];	//Bu 3 satir ise secilen ilk sinif ile ikinci sinif ogrenci sayilarini yer degistirir.
		ogrenciSayilari[sinif1 - 1] = ogrenciSayilari[sinif2-1];
		ogrenciSayilari[sinif2 - 1] = sayiTemp;
	}
	void OgrenciDegis(char ogr1, char ogr2)
	{
		int sinif1 = 0;
		int sinif2 = 0;
		int ogrSayi1 = 0;
		int ogrSayi2 = 0;
		int a;
		
		if (isalpha(ogr1) && isalpha(ogr2))	//Karakter harf diye mi kontrol eder.(Buyuk kucuk kontrolu yapmadım.)
		{
			for (int i = 0; i < MaksSiniftakiOgrSayisi(); i++)
			{
				a = 0;
				for (int m = 0; m < sinifSayisi; m++)
				{
					if (ogrenciSayilari[a] > i)
					{
						if (ogr1 == okul->getpSiniflar()[m].getpOgrenciler()[i].getisim())
						{
							sinif1 = m;
							ogrSayi1 = i;
						}
						if (ogr2 == okul->getpSiniflar()[m].getpOgrenciler()[i].getisim())
						{
							sinif2 = m;
							ogrSayi2 = i;
						}
					}
					a++;
				}
			}
			okul->getpSiniflar()->getTemp()[0] = okul->getpSiniflar()[sinif1].getpOgrenciler()[ogrSayi1]; //Gecici pointer nesneye ilk istenilen atanır.
			okul->getpSiniflar()[sinif1].getpOgrenciler()[ogrSayi1] = okul->getpSiniflar()[sinif2].getpOgrenciler()[ogrSayi2];//Ilk istenilene ikinci istenen atanır.
			okul->getpSiniflar()[sinif2].getpOgrenciler()[ogrSayi2] = okul->getpSiniflar()->getTemp()[0];//Ikinci istenene gecici pointer atanir ve yerler degismis olur.
		}
		else {}
	}
	~Yonetim()
	{
		
	}
};

#endif

