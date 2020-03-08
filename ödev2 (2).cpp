/*burcu tokol
karmasýk sayýlarla ilgili toplama cýkarma ve bolme gibi islemleri yapan program
*/

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
using namespace std;
class complexNumber {
private: //tanýmladýgým sýnýftaki verileri gizli tuttum
    int reel; //sayýnýn gercel kýsmýný tutar
    int imaginary; //sanal kýsmýný tutar
public:
	void karmasigaDonusturucu(string karmasikSayi) //string seklinde alinan sayiyi reel ve sanal olarak ikiye ayýran fonksiyon
	{
		int index1,index2;
		int boyut;
		string reel2;
		string imaginary2;
		boyut=karmasikSayi.length(); //alinan stringin uzunluðunu bulur
		index1=karmasikSayi.find("+"); //artý ifadesini bulur
		index2=karmasikSayi.find("-"); //eksi ifadesini bulur
		if(index1!=string::npos || index2==string::npos) //find fonksiyonu bulamazsa npos döner,npos dönmediyse + ifadesi vardýr
		{	
		    reel2=karmasikSayi.substr(0,index1); //bastan artýnýn bulundugu yere kadar olan kýsmý reel kýsma atar
		    imaginary2=karmasikSayi.substr(index1,boyut); //artýdan sona kadar olan kýsmý sanal kýsma atar
	    }
	    else if(index2!=string::npos || index1==string::npos) //find fonksiyonu bulamazsa npos döner,npos dönmediyse - ifadesi vardýr
	    {
	    	reel2=karmasikSayi.substr(0,index2); //bastan eksinin bulundugu yere kadar olan kýsmý reel kýsma atar
		    imaginary2=karmasikSayi.substr(index2,boyut); //eksiden sona kadar olan kýsmý sanal kýsma atar
		}
		else if(index1==string::npos && index2==string::npos) //+ veya - yoksa hatali giris vardýr
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
	void defaultConstructor() //reel ve sanal kýsmýna 0 atayan default constructor
	{
		reel=0;
		imaginary=0;	
	}
    int getReel()const //reel kýsým için getter fonksiyon
    {
    	cout<<"\nreel kismin degeri:\n"<<reel;
    	return reel;
	}
	int getImaginary()const //sanal kýsým için getter fonksiyon
	{
		cout<<"\nsanal kismin degeri:\n"<<imaginary<<"i";
		return imaginary;
	}
	void setReel(int newReel) //reel kýsým için setter fonksiyon
	{
		reel=newReel;
	}
	void setImaginary(int newImaginary) //sanal kýsým için getter fonksiyon
	{
		imaginary=newImaginary;
	}
	int gerceleDonusturucu(int alinanSayi ) //alýnan int sayýyý reel kýsma atayýp sanal kýsmý sýfýrlayan fonksiyon
	{
		reel=alinanSayi;
		imaginary=0;  	
	}
	double gerceleDonusturucu(double alinanSayi) //alinan double sayýyý reel ksýma atayýp sanal kýsmý sýfýrlayan fonksiyon
	{
		reel=alinanSayi;
		imaginary=0;
	}
	void printNumber(string karmasikSayi) //karmasik sayýyý ekrana bastýran fonksiyon
	{
		cout<<"\nkarmasik sayi:\n"<<karmasikSayi;
	}
	string karmasikUreten(int alinanReel,int alinanImaginary) //iki int deger alýp reel ve sanal kýsma atayan fonksiyon
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
		int reel3=n1.getReel(); //ilk alýnan sayýnýn reel kýsmýný yazdýrdým
		int img3=n1.getImaginary(); //ilk alýnan sayýnýn sanal kýsmýný yazdýrdým
		int newReel=alinanSayi.getReel(); //sonradan alýnan sayýnýn reel kýsmýný yazdýrdým
		int newImg=alinanSayi.getImaginary(); //sonradan alýnan sayýnýn sanal kýsmýný yazdýrdým
		int toplamReel=reel3+newReel; //iki sayýnýn reel kýsmýný toplayýp yeni bir degiskene atadým
		int toplamSanal=img3+newImg; //iki sayýnýn sanal kýsmýný toplayýp yeni bir degiskene atadým
		cout<<"\ntoplam gercel:"<<toplamReel<<"  \ntoplam sanal:"<<toplamSanal<<"i  ";
	}
	void subtract(complexNumber n1,complexNumber alinanSayi)
	{
		int reel3=n1.getReel(); //ilk alýnan sayýnýn reel kýsmýný yazdýrdým
		int img3=n1.getImaginary(); //ilk alýnan sayýnýn sanal kýsmýný yazdýrdým
		int newReel=alinanSayi.getReel(); //sonradan alýnan sayýnýn sanal kýsmýný yazdýrdým
		int newImg=alinanSayi.getImaginary(); //sonradan alýnan sayýnýn sanal kýsmýný yazdýrdým
		int toplamReel=reel3-newReel; //ilk sayýnýn reel kýsmýndan ikincinin reel kýsmýný cýkararak yeni bir degiskene atadým
		int toplamSanal=img3-newImg; //ilk sayýdan sanal kýsmýndan ikincinin sanal kýsmýný cýkararak yeni bir degiskene atadým
		cout<<"\ntoplam gercel:"<<toplamReel<<"  \ntoplam sanal:"<<toplamSanal<<"i  ";
	}
	void divide(complexNumber n1,complexNumber alinanSayi)
	{
		double reel3=n1.getReel(); //ilk alýnan sayýnýn reel kýsmýný yazdýrdým
		double img3=n1.getImaginary(); //ilk alýnan sayýnýn sanal kýsmýný yazdýrdým
		double newReel=alinanSayi.getReel(); //sonradan alýnan sayýnýn sanal kýsmýný yazdýrdým
		double newImg=alinanSayi.getImaginary(); //sonradan alýnan sayýnýn sanal kýsmýný yazdýrdým
		double toplamReel=reel3/newReel; //ilk sayýnýn reel kýsmýný ikincinin reel kýsmýna böldüm
		double toplamSanal=img3/newImg; //ilk sayýnýn sanal kýsmýný ikincinin sanal kýsmýna böldüm
		try
		{
		    if(newReel==0 || newImg==0) //alýnan sayýnýn sanal veya reel kýsmý sýfýrsa 1 deger fýrlatýr
	    	{
			    throw 1;
	    	}
	    }
	    catch(int deger)
	    {
	    	if(deger==1) //eger 1 geldiyse hata mesajý yazar
	    	cout<<"\nhata:sifira bolme hatasi...\n";
		}
		cout<<"\ngercel kismi:"<<toplamReel<<"  \nsanal kismi:"<<toplamSanal<<"i  ";
		
	}
};
void menu(string alinan,complexNumber n); //yapýlan islemler için menu fonksiyonu
int main()
{
	string alinanSayi;
	cout<<"lutfen bir karmasik sayi girin.(a+bi seklinde...)"<<endl;
	cin>>alinanSayi;
	complexNumber n1;
	n1.karmasigaDonusturucu(alinanSayi); //sayýyý direkt karmasýgaDonusturucu üye fonksiyonuna yollayarak reel ve sanal kýsmýný ayýrdým
	menu(alinanSayi,n1); //menuyu alinansayýyla cagýrdým
	return 0;
}
void menu(string alinanSayi,complexNumber n1)
{
	int sec;
	cout<<"\n1.default constructor testi\n2.verileri gormek\n3.verileri duzenlemek\n4.karmasik sayi uretmek\n5.karmasik sayiyi bastirmak\n6.karmasik sayilari toplamak\n7.karmasik sayilari cikarmak\n8.karmasik sayilari bolmek\n9.cikis\n";
	while(sec!=9) //cýkýsa basýlmadýgý surece secim yapýlacak
	{
	cout<<"\nlutfen yapmak istediginiz islemi secin...\n";
	cin>>sec;
	if(sec==1)
	n1.defaultConstructor(); //default constructor reel ve sanal kýsmýný sýfýrlar
	else if(sec==2) //degerleri gormek icin getter üye fonksiyonlarýný cagýrdým
	{
		n1.getReel();
		cout<<"\n";
		n1.getImaginary();
	}
	else if(sec==3) //degerleri duzenlemek icin setter uye fonksiyonlarý cagýrdým
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
	else if(sec==4) //iki deger alarak karmasýk sayý uretir
	{
		int sanal;
		int reel;
		cout<<"sanal kismini girin\n";
		cin>>sanal;
		cout<<"reel kismini girin\n";
		cin>>reel;
		n1.karmasikUreten(reel,sanal);
	}
	else if(sec==5) //sayýyý bastýrýr
	{
		n1.printNumber(alinanSayi);
	}
	else if(sec==6) //iki sayýyý toplamak icin add üye fonksiyonunu cagýrýr
	{
		string yeniKarmasik;
		complexNumber alinanKarmasik;
		cout<<"\nyeni bir karmasik sayi girin.(a+bi seklinde...)\n";
		cin>>yeniKarmasik;
		alinanKarmasik.karmasigaDonusturucu(yeniKarmasik);
		n1.add(n1,alinanKarmasik);
		
	}
	else if(sec==7) //iki sayýyý cýkarmak icin subtract üye fonksiyonunu cagýrýr
	{
		string yeniKarmasik;
		complexNumber alinanKarmasik;
		cout<<"\nyeni bir karmasik sayi girin.(a-bi seklinde...)\n";
		cin>>yeniKarmasik;
		alinanKarmasik.karmasigaDonusturucu(yeniKarmasik);
		n1.subtract(n1,alinanKarmasik);
	}
	else if(sec==8) //iki sayýyý bolmek icin divide üye fonksiyonunu cagýrýr
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
