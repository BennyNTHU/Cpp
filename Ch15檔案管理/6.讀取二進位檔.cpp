#include <iostream>
#include <fstream>
using namespace std;

/*
	如果我們要讀取二進位檔,可使用以下程式碼
	
	物件名稱.open("檔案名稱", ios::binary | ios::in);
	
	如果成功開啟,可以呼叫ifstream類別的read函數 
	要讀取資料時,可使用 
	
	物件名稱.read(const char *緩衝區, 讀取長度)
	
	來讀取,讀取長度一般會跟緩衝區一樣大,
	程式會一次挖一塊讀取長度大小的資料到緩衝區後,再做輸出 
	
	eof()函數:如果讀取指標已經到檔案結束位置會回傳True,反之回傳False
	使用方式是:
	
	輸入檔案物件.eof() 
*/ 

class Student
{
	protected:
		int id;
		char name[40];
	
	public:
		void showdata()
		{
			cout << id << '\t' << name << endl;
		}
};

int main(void)
{
	Student stuData;	//建立緩衝區 
	ifstream filePtr;	//建立輸出物件檔案 
	filePtr.open("D:\\MyDocuments\\Programs\\C++\\Ch15檔案管理\\15-4.dat", ios::in);	//開啟輸入檔 
	
	if (!filePtr)
	{
		cout << "open file ERROR" << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		filePtr.read((char*) &stuData, sizeof(stuData));	//不管有沒有東西,先讀一筆緩衝區大小的資料
		while (!filePtr.eof())	//只要檔案物件指標還沒指到檔案結束位置 
		{
			stuData.showdata();	//顯示讀到的東西 
			filePtr.read((char*) &stuData, sizeof(stuData));	//再讀取下一筆 
		}
	}
	
	filePtr.close();	//關閉檔案 
	system("PAUSE");
	return 0;
}

