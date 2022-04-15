#include <iostream>
#include <fstream>
using namespace std;

const char filename[] = "D:\\MyDocuments\\Programs\\C++\\Ch15檔案管理\\15-5.dat";

/*
	seekg()函數:將讀取指標從指定的起始位置向前或向後移動指定的距離
	seekp()函數:將寫入指標從指定的起始位置向前或向後移動指定的距離
	使用方法:
	 
	輸入檔案物件.seekg(移動距離, ios::起始位置)
	輸入檔案物件.seekp(移動距離, ios::起始位置)
	
	起始位置可以是beg(檔案開始位置,向後), cur(指標目前位置,向後) 或 end(檔案結束位置,向前) 
*/

class Student
{
	protected:
		int id;
		int name[40];
	public:
		void showdata()
		{
			cout << id << '\t' << name << endl;
		}
};

int main(void)
{
	Student stu;
	ifstream filePtr;
	int n = 0;	//第幾筆資料 
	int pos = 0;	//欲讀取之資料的位置 
	
	filePtr.open(filename, ios::binary | ios::in);	//開啟寫入檔 
	
	if(!filePtr)	//開啟異常 
	{
		cout << "ERROR when open!" << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		cout << "要讀取第幾筆資料: ";
		cin >> n;
		
		pos = (n-1) * sizeof(stu);	//計算要讀取的位置 
		
		filePtr.seekg(pos, ios::beg);	//自檔案開始之處移動到該筆資料位置 
		filePtr.read((char*) &stu, sizeof(stu));	//讀取資料 
		stu.showdata();	//顯示資料 
	}
	
	filePtr.close();
	system("PAUSE");
	return 0;
}

