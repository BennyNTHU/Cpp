#include <iostream>
using namespace std;

/*
	假設基礎類別A有一資料成員i
	且有兩個子類別B與C,而D類別繼承了B與C
	那當D要存取i的時候,編譯器會不知道是"A-C-D"還是"A-B-D"的繼承路徑而出現錯誤 
	這是由於B與C的指標並不是指向同一個基礎類別
	為了解決這種狀況,B與C繼承A時須使用"虛擬繼承",使兩者的指標都指向同一個基礎類別 
*/

class Base
{
	protected:
		int i;
};

class Derived1: virtual public Base
{
	protected:
		int j;
};

class Derived2: virtual public Base
{
	protected:
		int k;
};

class Derived3: public Derived1, public Derived2
{
	protected:
		int sum;
		
	public:
		Derived3(int n1, int n2, int n3)
		{
			i = n1;		//此時因為Derived1與Derived2都指向Base,所以可正常存取i 
			j = n2;
			k = n3;
			sum = i + j + k;
		}
		void show()
		{
			cout << "i = " << i << endl;
			cout << "j = " << j << endl;
			cout << "k = " << k << endl;
			cout << "sum = " << sum << endl;
		}
};

int main()
{
	Derived3 d3(10, 20, 30);
	d3.show();
	
	system("PAUSE");
	return 0;
}
