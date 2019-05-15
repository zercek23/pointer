/**        
* @file  main.cpp  
* @description main fonksiyonunu ve program burada sonlanır.  
* @course  1.Öğretim A Grubu  
* @assignment  1.Ödev   
* @date  20.10.2018 
* @author  Burak Bayram E-posta: burakbyrm99@gmail.com  */ 
#include "Yonetim.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int sec;
	int sinif1, sinif2;
	char ogr1, ogr2;
	Yonetim yonet;
	
	yonet.DosyaOku();
	do //MENU
	{
		system("cls");
		yonet.SonDurumYaz();
		cout << "1-Sinif Degistir" << endl;
		cout << "2-Ogrenci Degistir" << endl;
		cout << "3-Cikis" << endl;
		cout << "=> ";
		cin >> sec;
		switch (sec)
		{
		case 1:
			cout << "1. Sinif: ";
			cin >> sinif1;
			cout << "2. Sinif: ";
			cin >> sinif2;
			yonet.SinifDegis(sinif1, sinif2); break;
		case 2:
			cout << "1. Ogrenci: ";
			cin >> ogr1;
			cout << "2. Ogrenci: ";
			cin >> ogr2;
			yonet.OgrenciDegis(ogr1, ogr2); break;
		case 3:
			break;
		default:
			cout<<"Hatali Secim!"<<endl;
			cin.get();
			cin.ignore();break;
		}
	} while (sec != 3);
	
	return 0;
}

