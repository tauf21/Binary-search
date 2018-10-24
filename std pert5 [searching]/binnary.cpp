#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

class ArrayTerurut
{
private:
	vector<double>v;//vektor v
	int jumElemen;//jumlah item data

public:
	ArrayTerurut(int max)//konstruktor
	{
	v.resize(max);//ukuran array
	jumElemen=0;
	}

		int bacaUkuran()//menghasilkan jumlah elemen
		{return jumElemen;}
		int cari(double kunciPencarian)
		{
		return cariRekursif(kunciPencarian, 0, jumElemen-1);
		}
			int cariRekursif(double kunciPencarian, int batasBawah, int batasAtas)
		{
		int posSkrng;
		posSkrng =(batasBawah+batasAtas)/2;
		if(v[posSkrng]==kunciPencarian)
			return posSkrng;//ditemukan
		else if(batasBawah>batasAtas)
			return jumElemen;//tidak ditemukan
		else//membagi rentang
		{
		if(v[posSkrng]<kunciPencarian)//ada dipotongan atas
			return cariRekursif(kunciPencarian, posSkrng+1, batasAtas);
		else//ada dipotongan bawah
			return cariRekursif(kunciPencarian, batasBawah, posSkrng-1);
		}//akhir else
		}//akhir carirekursif()

		void sisip(double nilai)//mebndapat elemen ke dalam array
			{
			int j;
			for(j=0;j<jumElemen;j++)
				if(v[j]>nilai)//(pencarian linier)
					break;
			for(int k=jumElemen;k>j;k--)
				v[k]=v[k-1];
				v[j]=nilai;
				jumElemen++;
			}//akhir sisip()

			void tampil(){
				for(int j=0;j<jumElemen;j++)
					cout<<v[j]<<" ";
				cout<<endl;
			}
		};//akhir kelas ArrayTerurut

		int main(){
		int ukuranMaks=100;//ukuran array
		ArrayTerurut arr(ukuranMaks);//array terurut
		arr.sisip(72);//menyisipkan item-item
		arr.sisip(90);
		arr.sisip(45);
		arr.sisip(126);
		arr.sisip(54);
		arr.sisip(99);
		arr.sisip(144);
		arr.sisip(27);
		arr.sisip(135);
		arr.sisip(81);
		arr.sisip(18);
		arr.sisip(108);
		arr.sisip(9);
		arr.sisip(117);
		arr.sisip(63);
		arr.sisip(36);
			arr.tampil();//menampilkan array
		int kunciPencarian = 117;//mencari item dengan nilai 117
		if(arr.cari(kunciPencarian)!=arr.bacaUkuran())
			cout<<"\nMenemukan "<<kunciPencarian<<endl;
		else 
			cout<<"\nTidak Menemukan "<<kunciPencarian<<endl;
		getch();
		
		return 0;
		}//akhir main
		