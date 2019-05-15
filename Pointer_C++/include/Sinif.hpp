/**        
* @file  Sinif.hpp  
* @description Sinif class'ı ve içindekiler.  
* @course  1.Öğretim A Grubu  
* @assignment  1.Ödev   
* @date  20.10.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#ifndef SINIF_HPP
#define SINIF_HPP

#include "Ogrenci.hpp"

class Sinif
{
private:
	char sinif;
	Ogrenci *pOgrenciler = new Ogrenci[10];	//Ogrencileri tutacak Ogrenci classından ogrenci nesne pointer'ı olusturuldu.
	Ogrenci *temp = new Ogrenci;	//Ogrenci degisiminde kullanılacak gecici nesne pointer'ı olusturuldu.
public:
	Sinif()
	{

	}
	Ogrenci *getpOgrenciler()
	{
		return pOgrenciler;
	}
	Ogrenci *getTemp()
	{
		return temp;
	}
	char getSinif()
	{
		return sinif;
	}

	void setSinif(char a)
	{
		sinif = a;
	}

	~Sinif()
	{
		delete [] pOgrenciler;
		delete temp;
	}
};

#endif