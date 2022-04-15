#include <iostream>
using namespace std;

/*  錯誤處理
	當我們寫出來的程式被使用者以預想外的情形使用時,稱為例外 
	(比方說:要輸入數字卻輸入字母,輸入密碼等等)
	這時可以使用try-catch-throw這一組關鍵字來處理 
*/ 

int main(void)
{
	char ps[9] = "year2012";
	char str[9];
	cout << "Please enter password: ";	//輸入密碼 
	cin >> str;
	
	try	//裡面放的是可能出現例外的狀況 
	{
		for (int i = 0; i < 9; i++)
			if (str[i] != ps[i])	//密碼錯誤! 
				throw i;	//將出現例外的變數丟給catch區塊 
		cout << "密碼正確!" << endl; 
	}
	catch (int i)	//處理例外 
	{
		cout << "密碼錯誤!" << endl; 
	}

	system("PAUSE");
	return 0;
} 
