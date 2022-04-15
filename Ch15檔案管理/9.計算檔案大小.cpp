#include <iostream>
#include <fstream>
using namespace std;

const char filename[] = "D:\\MyDocuments\\Programs\\C++\\Ch15檔案管理\\15-5.dat";

/*
	tellg()函數:回傳讀取指標位置 
	tellp()函數:回傳寫入指標位置 
*/
 
class Student
{
	int id;
	int name[40];
};

int main()
{
	Student stu;
	ifstream filePtr;
	
	filePtr.open(filename, ios::binary | ios::in);
	
	if(!filePtr)
	{
		cout << "ERROR when open!" << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		filePtr.seekg(0, ios::end);		//將讀取指標移到檔案結尾 
		int endpos = filePtr.tellg();	//回傳讀取指標位置 
		
		cout << filename << " 的大小 = " << endpos << " bytes" << endl;
		cout << filename << " 共有 " << endpos/sizeof(stu) << " 筆資料" << endl; 
	}
	
	filePtr.close();
	system("PAUSE");
	return 0;
}
