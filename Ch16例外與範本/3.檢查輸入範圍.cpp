#include <iostream>
using namespace std;

/*	
	我們也可以把try,throw和catch都放在函數裡面 
*/
 
bool check(char i)
{
	try
	{
		if (i < '0' || i > '9')
			throw i;
		cout << "輸入值 = " << i << endl;
		return true;	
	}
	catch (char i)
	{
		cout << "輸入值 = " << i << ",超出範圍!" << endl;
		return false;
	} 
	 
}

int main(void)
{
	char n;
	
	do {
		cout << "請輸入1~9之間的字元: ";
		cin >> n;	
	} while (check(n));
	
	system("PAUSE");
	return 0; 
} 

