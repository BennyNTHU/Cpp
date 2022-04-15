#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	ifstream filePtr;	//檔案物件 
	char inData;	//存放資料緩衝區 
	
	filePtr.open("D:\\MyDocuments\\Programs\\C++\\Ch15檔案管理\\15-2.txt", ios::in);	//讀取模式 
	
	if(!filePtr)	//開啟檔案異常 
	{
		cout << "開啟檔案錯誤!" << endl;
		system("PAUSE");
		return 0; 
	}
	else
		while(filePtr.get(inData))	//逐字讀取檔案並存放到inData 
			cout << inData;	//輸出到螢幕上 
	
	filePtr.close();	//關閉檔案 
	system("PAUSE");
	return 0;
} 
 
