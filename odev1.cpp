/*burcu tokol
bu program yıldızlarla duz ucgen,ters ucgen veya yıldız deseni olsuturur
*/
#include <iostream>
using namespace std;
void duzUcgen(int deger)//yıldız basmak için bir fonksiyon olusturdum.
 {
 	int bosluk=deger/2; //ilk basta basılan bosluk alınan kullanıcının girdiği degeri integer olarak 2'ye böldüğümüzde istediğimiz desen olusuyor.bunu döngüyle denedim ama başaramadım
 	for(int i=0;i<=deger;i=i+2)//bu fonksiyonla desenin dikey olarak ilerlemesini yani satırları yazdım,i'yi 2 arttırarak desenin tek sayılarla olusmasını sağladım
 	{
 		 	for(int k=0;k<bosluk;k++) //bu fonksiyonla desenin basında olusması gereken boslukları bastırdım ve birer azalatarak asagı satıra gectim
		 	{
		 		cout<<" ";
			}
		 	for(int j=0;j<=i;j++) //bu fonksiyonla yıldızları basırdım
		    {
		   
		    cout << "*";
		    }
		    bosluk--; //burda her satırdaki bosluğu 1 azalttım ki hem desen olussun hem de sonsuz döngüye girmesin
		    cout << "\n";
	}		 
}
void tersUcgen(int deger)
{
 	int bosluk=0;
 	int yildiz=deger;
 	int satir=0;
 	while(yildiz>0) //desenin dikey oluşumunu sağlayan döngü,yıldız sayısı en az 1 olabilir
 	{
 		while(bosluk<(deger-yildiz)/2) //son satırdaki bosluk sayısı girilen sayı ve o satırdaki yıldız sayısının farkının 2'ye bolumunden geliyor
 		{
 			cout<<" ";
 			bosluk++; //bosluk asağı indikçe artıyor
		}
 		while(satir<yildiz) //girilen degerden baslayarak 2'ser azalan yıldızlar basar
 		{
 			cout<<"*";
 			satir++;
		}
		 satir=0; //her döngüde bu degerleri 0'a eşitledim ve sonsuz döngü oluşumunu engelledim
		 bosluk=0; //her döngüde bu degerleri 0'a eşitledim ve sonsuz döngü oluşumunu engelledim
		 cout<<"\n";
		 yildiz=yildiz-2; //her döngüye girişinde 2 azalıyor böylece sadece tekli satırlar olusuyor
	}
}
void elmas(int deger) //elması bastırmak icin duzUcgen ve tersUcgen fonksiyonlarını çağırdım
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
   
    	if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //alınan deger 3 ve 15 arasında ve tek sayı mı diye kontrol ediyor
    	{
    		duzUcgen(alinandeger); //tekse sayıyı fonksiyona yolluyor
		}
		else
		{  
		    cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl; //sayı gecersiz ise tekrar giris hakkı veriyor
		    cin >> alinandeger;
		  if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //alınan deger 3 ve 15 arasında ve tek sayı mı diye kontrol ediyor
		  { 
		 	  duzUcgen(alinandeger); //tekse sayıyı fonksiyona yolluyor
		  }
		  else
		  {
		 	   cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl; //sayı gecersiz ise tekrar giris hakkı veriyor
		       cin >> alinandeger;
		    if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //alınan deger 3 ve 15 arasında ve tek sayı mı diye kontrol ediyor
		    {
		 	    duzUcgen(alinandeger); //tekse sayıyı fonksiyona yolluyor
		    }
		    else
		       cout << "3 hatali giris,program sonlandi..." ; //3 giris hakkı bittiği için programdan cıkıyor
          }
       }
   }

    if(desensecimi==2)
    {
    
        int alinandeger;
 	    cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl;
 	    cin >>alinandeger;
   
    	if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //alınan deger 3 ve 15 arasında ve tek sayı mı diye kontrol ediyor
    	{
    		tersUcgen(alinandeger); //tekse sayıyı fonksiyona yolluyor
		}
		else
		{  
		    cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl; //sayı gecersiz ise tekrar giris hakkı veriyor
		    cin >> alinandeger;
		  if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //alınan deger 3 ve 15 arasında ve tek sayı mı diye kontrol ediyor
		  { 
		 	  tersUcgen(alinandeger); //tekse sayıyı fonksiyona yolluyor
		  }
		  else
		  {
		 	   cout << "lutfen 3-15 arasinda bir tek sayi giriniz." <<endl; //sayı gecersiz ise tekrar giris hakkı veriyor
		       cin >> alinandeger;
		    if(alinandeger<=15 && alinandeger>=3 && alinandeger%2==1) //alınan deger 3 ve 15 arasında ve tek sayı mı diye kontrol ediyor
		    {
		 	    tersUcgen(alinandeger); //tekse sayıyı fonksiyona yolluyor
		    }
		    else
		       cout << "3 hatali giris,program sonlandi..." ; //3 giris hakkı bittiği için programdan cıkıyor
          }
       }
    }
    if(desensecimi==3)
    {
	
        int alinandeger;
 	    cout << "lutfen 5-15 arasinda bir tek sayi giriniz." <<endl;
 	    cin >>alinandeger;
   
    	if(alinandeger<=15 && alinandeger>=5 && alinandeger%2==1) //alınan deger 5 ve 15 arasında ve tek sayı mı diye kontrol ediyor
    	{
    		elmas(alinandeger); //tekse sayıyı fonksiyona yolluyor
		}
		else
		{  
		    cout << "lutfen 5-15 arasinda bir tek sayi giriniz." <<endl; //sayı gecersiz ise tekrar giris hakkı veriyor
		    cin >> alinandeger;
		  if(alinandeger<=15 && alinandeger>=5 && alinandeger%2==1) //alınan deger 5 ve 15 arasında ve tek sayı mı diye kontrol ediyor
		  { 
		 	  elmas(alinandeger); //tekse sayıyı fonksiyona yolluyor
		  }
		  else
		  {
		 	   cout << "lutfen 5-15 arasinda bir tek sayi giriniz." <<endl; //sayı gecersiz ise tekrar giris hakkı veriyor
		       cin >> alinandeger;
		    if(alinandeger<=15 && alinandeger>=5 && alinandeger%2==1) //alınan deger 5 ve 15 arasında ve tek sayı mı diye kontrol ediyor
		    {
		 	    elmas(alinandeger); //tekse sayıyı fonksiyona yolluyor
		    }
		    else
		       cout << "3 hatali giris,program sonlandi..." ; //3 giris hakkı bittiği için programdan cıkıyor
          }
       }
    }
   if(desensecimi!=1&&desensecimi!=2&&desensecimi!=3)
    cout<<"gecersiz deger,program sonlandi..\n";
  return 0;
}

	
	
