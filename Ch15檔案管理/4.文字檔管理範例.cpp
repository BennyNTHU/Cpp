#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const char filename[] = "D:\\MyDocuments\\Programs\\C++\\Ch15檔案管理\\15-3.txt";

class Note
{
	private:
		char outStr[81];
	
	public:
		void write();
		void append();
		void read();
};

void Note::write()
{
	ofstream filePtr;
	filePtr.open(filename, ios::out);
	
	if (!filePtr)
	{
		cout << "開啟檔案錯誤!" << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		cout << "請輸入字串,輸入兩次Enter則結束" << endl;
		cin.ignore();
		
		while(1)
		{
			cin.getline(outStr, 81);
			if (!strlen(outStr) == 0)
				filePtr << outStr <<'\n';
			else
				break;
		} 
		
		filePtr.close();
	}
}

void Note::append()
{
	ofstream filePtr;
	filePtr.open(filename, ios::app);
	
	if (!filePtr)
	{
		cout << "開啟檔案錯誤!" << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		cout << "請輸入字串,輸入兩次Enter則結束" << endl;
		cin.ignore();
		
		while(1)
		{
			cin.getline(outStr, 81);
			if (!strlen(outStr) == 0)
				filePtr << outStr <<'\n';
			else
				break;
		} 
		
		filePtr.close();
	}
}

void Note::read()
{
	ifstream filePtr;
	filePtr.open(filename, ios::in);
	char inChar;
	
	if(!filePtr)
	{
		cout << "開啟輸入檔錯誤!\n";
		system("PAUSE");
		exit(0);
	}
	else
		while(filePtr.get(inChar))
			cout << inChar;
	
	filePtr.close();
}

int main(void)
{
	Note text;
	char n;
	
	while(1)
	{
		cout << "1.寫入 2.附加 3.讀取 0.結束: ";
		cin >> n;
		
		switch(n)
		{
			case '1':
				text.write();
				break;
			case '2':
				text.append();
				break;
			case '3':
				text.read();
				break;
			case'0':
				system("PAUSE");
				return 0;
		}
	}
}















