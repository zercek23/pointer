/**        
* @file  Okul.hpp  
* @description Okul class'ı ve içindekiler.  
* @course  1.Öğretim A Grubu  
* @assignment  1.Ödev   
* @date  20.10.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#ifndef OKUL_HPP
#define OKUL_HPP

#include "Sinif.hpp"

class Okul
{
private:
	Sinif *pSiniflar = new Sinif[10];	//Siniflari tutacak Sinif classından sinif nesne pointer'ı olusturuldu.
	Sinif *temp = new Sinif;	//Sinif degisiminde kullanılacak gecici nesne pointer'ı olusturuldu.
public:
	
	Okul()
	{

	}
	Sinif *getpSiniflar()
	{
		return pSiniflar;
	}
	Sinif *getTemp()
	{
		return temp;
	}
	~Okul()
	{
		delete [] pSiniflar;
		delete temp;
	}
};

#endif