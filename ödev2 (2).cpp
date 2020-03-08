/*burcu tokol
karmas�k say�larla ilgili toplama c�karma ve bolme gibi islemleri yapan program
*/

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
using namespace std;
class complexNumber {
private: //tan�mlad�g�m s�n�ftaki verileri gizli tuttum
    int reel; //say�n�n gercel k�sm�n� tutar
    int imaginary; //sanal k�sm�n� tutar
public:
	void karmasigaDonusturucu(string karmasikSayi) //string seklinde alinan sayiyi reel ve sanal olarak ikiye ay�ran fonksiyon
	{
		int index1,index2;
		int boyut;
		string reel2;
		string imaginary2;
		boyut=karmasikSayi.length(); //alinan stringin uzunlu�unu bulur
		index1=karmasikSayi.find("+"); //art� ifadesini bulur
		index2=karmasikSayi.find("-"); //eksi ifadesini bulur
		if(index1!=string::npos || index2==string::npos) //find fonksiyonu bulamazsa npos d�ner,npos d�nmediyse + ifadesi vard�r
		{	
		    reel2=karmasikSayi.substr(0,index1); //bastan art�n�n bulundugu yere kadar olan k�sm� reel k�sma atar
		    imaginary2=karmasikSayi.substr(index1,boyut); //art�dan sona kadar olan k�sm� sanal k�sma atar
	    }
	    else if(index2!=string::npos || index1==string::npos) //find fonksiyonu bulamazsa npos d�ner,npos d�nmediyse - ifadesi vard�r
	    {
	    	reel2=karmasikSayi.substr(0,index2); //bastan eksinin bulundugu yere kadar olan k�sm� reel k�sma atar
		    imaginary2=karmasikSayi.substr(index2,boyut); //eksiden sona kadar olan k�sm� sanal k�sma atar
		}
		else if(index1==string::npos && index2==string::npos) //+ veya - yoksa hatali giris vard�r
		{
			reel="";
			imaginary="";
			cout<<"\ngecersiz deger...\n";
		}
		stringstream geek(reel2); //reel2 string bir ifadedir.int veri tipine cevirdim
		geek>>reel;
		stringstream geek2(imaginary2); //imaginary2 string bir ifadedir. int veri tipine cevirdim
		geek2>>imaginary;
	}
	void defaultConstructor() //reel ve sanal k�sm�na 0 atayan default constructor
	{
		reel=0;
		imaginary=0;	
	}
    int getReel()const //reel k�s�m i�in getter fonksiyon
    {
    	cout<<"\nreel kismin degeri:\n"<<reel;
    	return reel;
	}
	int getImaginary()const //sanal k�s�m i�in getter fonksiyon
	{
		cout<<"\nsanal kismin degeri:\n"<<imaginary<<"i";
		return imaginary;
	}
	void setReel(int newReel) //reel k�s�m i�in setter fonksiyon
	{
		reel=newReel;
	}
	void setImaginary(int newImaginary) //sanal k�s�m i�in getter fonksiyon
	{
		imaginary=newImaginary;
	}
	int gerceleDonusturucu(int alinanSayi ) //al�nan int say�y� reel k�sma atay�p sanal k�sm� s�f�rlayan fonksiyon
	{
		reel=alinanSayi;
		imaginary=0;  	
	}
	double gerceleDonusturucu(double alinanSayi) //alinan double say�y� reel ks�ma atay�p sanal k�sm� s�f�rlayan fonksiyon
	{
		reel=alinanSayi;
		imaginary=0;
	}
	void printNumber(string karmasikSayi) //karmasik say�y� ekrana bast�ran fonksiyon
	{
		cout<<"\nkarmasik sayi:\n"<<karmasikSayi;
	}
	string karmasikUreten(int alinanReel,int alinanImaginary) //iki int deger al�p reel ve sanal k�sma atayan fonksiyon
	{
		string karmasik;
		reel=alinanReel;
		imaginary=alinanImaginary;
	    stringstream ss; //int tipindeki verileri stringe cevirdim(?)
        ss <<reel+imaginary;
        karmasik = ss.str();
	    return karmasik;
	}
	void add(complexNumber n1,complexNumber alinanSayi) //iki karmasik sayiyi toplayan fonksiyon
	{
		int reel3=n1.getReel(); //ilk al�nan say�n�n reel k�sm�n� yazd�rd�m
		int img3=n1.getImaginary(); //ilk al�nan say�n�n sanal k�sm�n� yazd�rd�m
		int newReel=alinanSayi.getReel(); //sonradan al�nan say�n�n reel k�sm�n� yazd�rd�m
		int newImg=alinanSayi.getImaginary(); //sonradan al�nan say�n�n sanal k�sm�n� yazd�rd�m
		int toplamReel=reel3+newReel; //iki say�n�n reel k�sm�n� toplay�p yeni bir degiskene atad�m
		int toplamSanal=img3+newImg; //iki say�n�n sanal k�sm�n� toplay�p yeni bir degiskene atad�m
		cout<<"\ntoplam gercel:"<<toplamReel<<"  \ntoplam sanal:"<<toplamSanal<<"i  ";
	}
	void subtract(complexNumber n1,complexNumber alinanSayi)
	{
		int reel3=n1.getReel(); //ilk al�nan say�n�n reel k�sm�n� yazd�rd�m
		int img3=n1.getImaginary(); //ilk al�nan say�n�n sanal k�sm�n� yazd�rd�m
		int newReel=alinanSayi.getReel(); //sonradan al�nan say�n�n sanal k�sm�n� yazd�rd�m
		int newImg=alinanSayi.getImaginary(); //sonradan al�nan say�n�n sanal k�sm�n� yazd�rd�m
		int toplamReel=reel3-newReel; //ilk say�n�n reel k�sm�ndan ikincinin reel k�sm�n� c�kararak yeni bir degiskene atad�m
		int toplamSanal=img3-newImg; //ilk say�dan sanal k�sm�ndan ikincinin sanal k�sm�n� c�kararak yeni bir degiskene atad�m
		cout<<"\ntoplam gercel:"<<toplamReel<<"  \ntoplam sanal:"<<toplamSanal<<"i  ";
	}
	void divide(complexNumber n1,complexNumber alinanSayi)
	{
		double reel3=n1.getReel(); //ilk al�nan say�n�n reel k�sm�n� yazd�rd�m
		double img3=n1.getImaginary(); //ilk al�nan say�n�n sanal k�sm�n� yazd�rd�m
		double newReel=alinanSayi.getReel(); //sonradan al�nan say�n�n sanal k�sm�n� yazd�rd�m
		double newImg=alinanSayi.getImaginary(); //sonradan al�nan say�n�n sanal k�sm�n� yazd�rd�m
		double toplamReel=reel3/newReel; //ilk say�n�n reel k�sm�n� ikincinin reel k�sm�na b�ld�m
		double toplamSanal=img3/newImg; //ilk say�n�n sanal k�sm�n� ikincinin sanal k�sm�na b�ld�m
		try
		{
		    if(newReel==0 || newImg==0) //al�nan say�n�n sanal veya reel k�sm� s�f�rsa 1 deger f�rlat�r
	    	{
			    throw 1;
	    	}
	    }
	    catch(int deger)
	    {
	    	if(deger==1) //eger 1 geldiyse hata mesaj� yazar
	    	cout<<"\nhata:sifira bolme hatasi...\n";
		}
		cout<<"\ngercel kismi:"<<toplamReel<<"  \nsanal kismi:"<<toplamSanal<<"i  ";
		
	}
};
void menu(string alinan,complexNumber n); //yap�lan islemler i�in menu fonksiyonu
int main()
{
	string alinanSayi;
	cout<<"lutfen bir karmasik sayi girin.(a+bi seklinde...)"<<endl;
	cin>>alinanSayi;
	complexNumber n1;
	n1.karmasigaDonusturucu(alinanSayi); //say�y� direkt karmas�gaDonusturucu �ye fonksiyonuna yollayarak reel ve sanal k�sm�n� ay�rd�m
	menu(alinanSayi,n1); //menuyu alinansay�yla cag�rd�m
	return 0;
}
void menu(string alinanSayi,complexNumber n1)
{
	int sec;
	cout<<"\n1.default constructor testi\n2.verileri gormek\n3.verileri duzenlemek\n4.karmasik sayi uretmek\n5.karmasik sayiyi bastirmak\n6.karmasik sayilari toplamak\n7.karmasik sayilari cikarmak\n8.karmasik sayilari bolmek\n9.cikis\n";
	while(sec!=9) //c�k�sa bas�lmad�g� surece secim yap�lacak
	{
	cout<<"\nlutfen yapmak istediginiz islemi secin...\n";
	cin>>sec;
	if(sec==1)
	n1.defaultConstructor(); //default constructor reel ve sanal k�sm�n� s�f�rlar
	else if(sec==2) //degerleri gormek icin getter �ye fonksiyonlar�n� cag�rd�m
	{
		n1.getReel();
		cout<<"\n";
		n1.getImaginary();
	}
	else if(sec==3) //degerleri duzenlemek icin setter uye fonksiyonlar� cag�rd�m
	{
		int secim2;
		cout<<"1.imaginary kismi duzenle\n2.reel kismi duzenle\n";
		cin>>secim2;
		if(secim2==1)
		{
			int new1;
			cout<<"\nyeni degeri girin...\n";
			cin>>new1;
			n1.setImaginary(new1);
		}
		else if(secim2==2)
		{
			int new2;
			cout<<"\nyeni degeri girin...\n";
			cin>>new2;
			n1.setReel(new2);	
		}
		else
		cout<<"\nhatali giris...\n";
	}
	else if(sec==4) //iki deger alarak karmas�k say� uretir
	{
		int sanal;
		int reel;
		cout<<"sanal kismini girin\n";
		cin>>sanal;
		cout<<"reel kismini girin\n";
		cin>>reel;
		n1.karmasikUreten(reel,sanal);
	}
	else if(sec==5) //say�y� bast�r�r
	{
		n1.printNumber(alinanSayi);
	}
	else if(sec==6) //iki say�y� toplamak icin add �ye fonksiyonunu cag�r�r
	{
		string yeniKarmasik;
		complexNumber alinanKarmasik;
		cout<<"\nyeni bir karmasik sayi girin.(a+bi seklinde...)\n";
		cin>>yeniKarmasik;
		alinanKarmasik.karmasigaDonusturucu(yeniKarmasik);
		n1.add(n1,alinanKarmasik);
		
	}
	else if(sec==7) //iki say�y� c�karmak icin subtract �ye fonksiyonunu cag�r�r
	{
		string yeniKarmasik;
		complexNumber alinanKarmasik;
		cout<<"\nyeni bir karmasik sayi girin.(a-bi seklinde...)\n";
		cin>>yeniKarmasik;
		alinanKarmasik.karmasigaDonusturucu(yeniKarmasik);
		n1.subtract(n1,alinanKarmasik);
	}
	else if(sec==8) //iki say�y� bolmek icin divide �ye fonksiyonunu cag�r�r
	{
		string yeniKarmasik;
		complexNumber alinanKarmasik;
		cout<<"\nyeni bir karmasik sayi girin.(a+bi seklinde...)\n";
		cin>>yeniKarmasik;
		alinanKarmasik.karmasigaDonusturucu(yeniKarmasik);
		n1.divide(n1,alinanKarmasik);
	}
   }  
}
