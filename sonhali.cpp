/*burcu tokol
bu program y�ld�zlarla duz ucgen,ters ucgen veya y�ld�z deseni olsuturur
*/
#include <iostream>
using namespace std;
void duzUcgen(int deger)//y�ld�z basmak i�in bir fonksiyon olusturdum.
 {
 	int bosluk=deger/2; //ilk basta bas�lan bosluk al�nan kullan�c�n�n girdi�i degeri integer olarak 2'ye b�ld���m�zde istedi�imiz desen olusuyor.bunu d�ng�yle denedim ama ba�aramad�m
 	for(int i=0;i<=deger;i=i+2)//bu fonksiyonla desenin dikey olarak ilerlemesini yani sat�rlar� yazd�m,i'yi 2 artt�rarak desenin tek say�larla olusmas�n� sa�lad�m
 	{
 		 	for(int k=0;k<bosluk;k++) //bu fonksiyonla desenin bas�nda olusmas� gereken bosluklar� bast�rd�m ve birer azalatarak asag� sat�ra gectim
		 	{
		 		cout<<" ";
			}
		 	for(int j=0;j<=i;j++) //bu fonksiyonla y�ld�zlar� bas�rd�m
		    {
		   
		    cout << "*";
		    }
		    bosluk--; //burda her sat�rdaki boslu�u 1 azaltt�m ki hem desen olussun hem de sonsuz d�ng�ye girmesin
		    cout << "\n";
	}		 
}
void tersUcgen(int deger)
{
 	int bosluk=0;
 	int yildiz=deger;
 	int satir=0;
 	while(yildiz>0) //desenin dikey olu�umunu sa�layan d�ng�,y�ld�z say�s� en az 1 olabilir
 	{
 		while(bosluk<(deger-yildiz)/2) //son sat�rdaki bosluk say�s� girilen say� ve o sat�rdaki y�ld�z say�s�n�n fark�n�n 2'ye bolumunden geliyor
 		{
 			cout<<" ";
 			bosluk++; //bosluk asa�� indik�e art�yor
		}
 		while(satir<yildiz) //girilen degerden baslayarak 2'ser azalan y�ld�zlar basar
 		{
 			cout<<"*";
 			satir++;
		}
		 satir=0; //her d�ng�de bu degerleri 0'a e�itledim ve sonsuz d�ng� olu�umunu engelledim
		 bosluk=0; //her d�ng�de bu degerleri 0'a e�itledim ve sonsuz d�ng� olu�umunu engelledim
		 cout<<"\n";
		 yildiz=yildiz-2; //her d�ng�ye giri�inde 2 azal�yor b�ylece sadece tekli sat�rlar olusuyor
	}
}
void elmas(int deger) //elmas� bast�rmak icin duzUcgen ve tersUcgen fonksiyonlar�n� �a��rd�m
{
	duzUcgen(deger);
	tersUcgen(deger);
}
int main()
{
	int desensecimi=0;
	cout<<"lutfen istediginiz deseni secin \n1-Duz Ucgen\n2-Ters Ucgen\n3-Elmas\n0-Cikis\n";
	cin>>desensecimi;
	if(desensecimi==0)
    {
	    exit(0);
    }  
    if(desensecimi==1)
   {    
        int alinandeger;
 	    cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl;
 	    cin >>alinandeger;
   
    	if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //al�nan deger 3 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
    	{
    		duzUcgen(alinandeger); //tekse say�y� fonksiyona yolluyor
		}
		else
		{  
		    cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl; //say� gecersiz ise tekrar giris hakk� veriyor
		    cin >> alinandeger;
		  if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //al�nan deger 3 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
		  { 
		 	  duzUcgen(alinandeger); //tekse say�y� fonksiyona yolluyor
		  }
		  else
		  {
		 	   cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl; //say� gecersiz ise tekrar giris hakk� veriyor
		       cin >> alinandeger;
		    if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //al�nan deger 3 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
		    {
		 	    duzUcgen(alinandeger); //tekse say�y� fonksiyona yolluyor
		    }
		    else
		       cout << "3 hatali giris,program sonlandi..." ; //3 giris hakk� bitti�i i�in programdan c�k�yor
          }
       }
   }

    if(desensecimi==2)
    {
    
        int alinandeger;
 	    cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl;
 	    cin >>alinandeger;
   
    	if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //al�nan deger 3 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
    	{
    		tersUcgen(alinandeger); //tekse say�y� fonksiyona yolluyor
		}
		else
		{  
		    cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl; //say� gecersiz ise tekrar giris hakk� veriyor
		    cin >> alinandeger;
		  if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //al�nan deger 3 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
		  { 
		 	  tersUcgen(alinandeger); //tekse say�y� fonksiyona yolluyor
		  }
		  else
		  {
		 	   cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl; //say� gecersiz ise tekrar giris hakk� veriyor
		       cin >> alinandeger;
		    if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //al�nan deger 3 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
		    {
		 	    tersUcgen(alinandeger); //tekse say�y� fonksiyona yolluyor
		    }
		    else
		       cout << "3 hatali giris,program sonlandi..." ; //3 giris hakk� bitti�i i�in programdan c�k�yor
          }
       }
    }
    if(desensecimi==3)
    {
	
        int alinandeger;
 	    cout << "lutfen 5-15 arasinda bir tek sayi giriniz." <<endl;
 	    cin >>alinandeger;
   
    	if(alinandeger<=15 && alinandeger>=5 && alinandeger%2==1) //al�nan deger 5 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
    	{
    		elmas(alinandeger); //tekse say�y� fonksiyona yolluyor
		}
		else
		{  
		    cout << "lutfen 5-15 arasinda bir tek sayi giriniz." <<endl; //say� gecersiz ise tekrar giris hakk� veriyor
		    cin >> alinandeger;
		  if(alinandeger<=15 && alinandeger>=5 && alinandeger%2==1) //al�nan deger 5 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
		  { 
		 	  elmas(alinandeger); //tekse say�y� fonksiyona yolluyor
		  }
		  else
		  {
		 	   cout << "lutfen 5-15 arasinda bir tek sayi giriniz." <<endl; //say� gecersiz ise tekrar giris hakk� veriyor
		       cin >> alinandeger;
		    if(alinandeger<=15 && alinandeger>=5 && alinandeger%2==1) //al�nan deger 5 ve 15 aras�nda ve tek say� m� diye kontrol ediyor
		    {
		 	    elmas(alinandeger); //tekse say�y� fonksiyona yolluyor
		    }
		    else
		       cout << "3 hatali giris,program sonlandi..." ; //3 giris hakk� bitti�i i�in programdan c�k�yor
          }
       }
    }
   if(desensecimi!=1&&desensecimi!=2&&desensecimi!=3)
    cout<<"gecersiz deger,program sonlandi..\n";
  return 0;
}

	
	
