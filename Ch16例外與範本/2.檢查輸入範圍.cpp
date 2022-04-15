#include <iostream>
using namespace std;

/*
	如果例外出現在函數中,可以將throw放在函數內,並將函數放在try內
*/ 

void check(char i)
{
	if (i < '0' || i > '9')	//例外出現 
		throw i;	//傳送造成例外的變數,跳到29行 
		 
	cout << "輸入值 = " << i << endl; 
}

int main(void)
{
	char n;
	
	while (1)
	{
		cout << "請輸入1~9之間的字元: ";
		cin >> n;
		
		try	//可能出現例外的情形:輸入不是1~9之間的字元 
		{
			check(n); 
		}
		catch (char i)
		{
			cout << "輸入值 = " << i << ",超出範圍!" << endl;
			system("PAUSE");
			return 0; 
		} 
	}
	
	system("PAUSE");
	return 0; 
} 

