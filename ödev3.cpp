#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
/*burcu tokol
kurba�an�n gidebilece�i farkl� yollar� iteratif ve rek�rsif olarak hesaplayan program
*/
using namespace std;

//a�a��daki sat�rlar� yoruma alarak kodunuzu farkl� �ekillerde test edebilirsiniz.
#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int numberOfStones)
{
	int yol[72]; //gidece�i yol �e�itlerini bir dizide tuttum 
	
	int temp=0; 
	if(numberOfStones==1 && numberOfStones==2 && numberOfStones==3) //ta� say�s�n�n 1'e,2'ye veya 3'e e�it oldugu durumu base case olarak ald�m
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
	        	
	        case 3: //3 geriye gitti�i i�in sonuc hatal� olacakt�r
	        	yol[3]=4;
	        	temp=yol[3];
	        	return temp;
	        	break;
	    }
    }
    else if(numberOfStones>3 && numberOfStones<72) //2'den 72'ye kadar ta� olan durumda ise n. ta� say�s�ndaki izleyebilece�i yol say�s�->(n-1),(n-2) ve (n-3). ta�lardaki yollar�n toplam� 
	{ 
	    temp=recursiveFunction(yol[numberOfStones-1])+recursiveFunction(yol[numberOfStones-2])+recursiveFunction(yol[numberOfStones-3]);//fonksiyonu tekrar �a��rarak base case durumuna kadar toplama yapmas�n� sa�lar
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
		for(int i=1;i<72;++i) //72ye kadar olan ta� say�lar�n� kontrol eder
		{
			if(numberOfStones>=4) // ta� say�s� 4'e e�it veya 4ten b�y�kse
			{
				yol[i]=yol[i-1]+yol[i-2]+yol[i-3]; //kendinden 3 basamak �nceki yol olas�klar�n�n toplam�na e�it
				tempResult=yol[i];
			}
			else //ilk 3 basamakta 3 ad�m geri gidemeyece�i i�in burdaki yol olas�l�klar�n� kendim atad�m
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
