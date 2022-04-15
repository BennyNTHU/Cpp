#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	ofstream filePtr;
	filePtr.open("D:\\MyDocuments\\Programs\\C++\\Ch15檔案管理\\15-1.txt", ios::out);	//寫入模式 
	
	if(!filePtr.is_open())	//未正常開啟檔案 
	{
		cout << "開啟檔案錯誤!";
		system("PAUSE");
		return 1;
	}
	else
	{
		filePtr << "Capoo \n";
	}
	
	filePtr.close();	//關閉檔案 
	system("PAUSE");
	return 0;
} 
