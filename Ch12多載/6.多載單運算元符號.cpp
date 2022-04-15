#include <iostream>
using namespace std;

/*  C++中很多運算元都可以多載,如果想要知道其他例子可以翻書或上網找
	其實都大同小異 
*/

class Test
{
	private:
	int a;
	
	public:
	Test (int n)
	{
		a = n;
	}
	bool operator ! (void);
};

bool Test::operator ! (void)	//多載"!"運算元給Test使用,沒有參數 
{
	if (a != 0)
		return true;
	else
		return false;
}

int main(void)
{
	int n = 0;
	
	cout << "請輸入一個數字: ";
	cin >> n;
	
	Test s1(n);
	
	if (!s1)	// 多載"!"運算元 
		cout << "s1 != 0";
	else
		cout << "s1 = 0";
	
	system ("PAUSE");
	return 0;
}

