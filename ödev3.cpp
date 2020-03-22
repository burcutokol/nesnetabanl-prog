#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
/*burcu tokol
kurbaðanýn gidebileceði farklý yollarý iteratif ve rekürsif olarak hesaplayan program
*/
using namespace std;

//aþaðýdaki satýrlarý yoruma alarak kodunuzu farklý þekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int numberOfStones)
{
	int yol[72]; //gideceði yol çeþitlerini bir dizide tuttum 
	
	int temp=0; 
	if(numberOfStones==1 && numberOfStones==2 && numberOfStones==3) //taþ sayýsýnýn 1'e,2'ye veya 3'e eþit oldugu durumu base case olarak aldým
	{
		switch(numberOfStones)
		{
			case 0:
				yol[0]=0;
				temp=yol[0];
				return temp;
				break;
				
			case 1:
				yol[1]=1;
				temp=yol[1];
	            return temp;
	            break;
	        
	        case 2:
	        	yol[2]=2;
	        	temp=yol[2];
	        	return temp;
	        	break;
	        	
	        case 3: //3 geriye gittiði için sonuc hatalý olacaktýr
	        	yol[3]=4;
	        	temp=yol[3];
	        	return temp;
	        	break;
	    }
    }
    else if(numberOfStones>3 && numberOfStones<72) //2'den 72'ye kadar taþ olan durumda ise n. taþ sayýsýndaki izleyebileceði yol sayýsý->(n-1),(n-2) ve (n-3). taþlardaki yollarýn toplamý 
	{ 
	    temp=recursiveFunction(yol[numberOfStones-1])+recursiveFunction(yol[numberOfStones-2])+recursiveFunction(yol[numberOfStones-3]);//fonksiyonu tekrar çaðýrarak base case durumuna kadar toplama yapmasýný saðlar
		return temp;
    } 
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int numberOfStones)
{
	int tempResult;
	int yol[72];
	yol[0]=0; 
	yol[1]=1;
	yol[2]=2;
	yol[3]=4;
	while(numberOfStones<72)
	{
		for(int i=1;i<72;++i) //72ye kadar olan taþ sayýlarýný kontrol eder
		{
			if(numberOfStones>=4) // taþ sayýsý 4'e eþit veya 4ten büyükse
			{
				yol[i]=yol[i-1]+yol[i-2]+yol[i-3]; //kendinden 3 basamak önceki yol olasýklarýnýn toplamýna eþit
				tempResult=yol[i];
			}
			else //ilk 3 basamakta 3 adým geri gidemeyeceði için burdaki yol olasýlýklarýný kendim atadým
			{
				switch(numberOfStones)
				{
					case 1:
						yol[1]=1;
						tempResult=yol[1];
						return tempResult;
					case 2:
						yol[2]=2;
						tempResult=yol[2];
						return tempResult;
					case 3:
						yol[3]=4;
						tempResult=yol[3];
						return tempResult;	
						
				}
			}
		}
		numberOfStones++;
	}
	return tempResult;
}



int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i < MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}
