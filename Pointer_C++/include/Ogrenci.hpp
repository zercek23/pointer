/**        
* @file  Ogrenci.hpp 
* @description Ogrenci class'ı ve içindekiler.  
* @course  1.Öğretim A Grubu  
* @assignment  1.Ödev   
* @date  20.10.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#ifndef OGRENCI_HPP
#define OGRENCI_HPP

#include <iostream>
#include <fstream>
#include <string>

class Ogrenci
{
private:
	char isim;
public:
	Ogrenci()
	{
	}
	char getisim()
	{
		return isim;
	}

	void setisim(char a)
	{
		isim = a;
	}

	~Ogrenci()
	{
	}
};

#endif