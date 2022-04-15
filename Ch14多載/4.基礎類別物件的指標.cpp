#include <iostream>
using namespace std;

/*
	當我們將
	1.基礎類別物件的位址 或 
	2.衍生類別物件的位址 
	存入基礎類別物件的指標,並以此指標呼叫同名異式(多型)的函數,
	此指標一定會指向基礎類別,且都是呼叫基礎類別的同名函數 
*/

class Base
{
	public:
		void show()
		{
			cout << "基礎類別\n";
		}
};

class Derived1: public Base
{
	public:
		void show()
		{
			cout << "衍生類別1\n";
		}
};

class Derived2: public Base
{
	public:
		void show()
		{
			cout << "衍生類別2\n";
		}
};

int main()
{
	Base b;
	Derived1 d1;
	Derived2 d2;
	Base *ptr;
	
	ptr = &b;
	ptr->show();	//顯示"基礎類別" 
	
	ptr = &d1;
	ptr->show();	//顯示"基礎類別" 
	
	ptr = &d2;
	ptr->show();	//顯示"基礎類別" 
	
	system("PAUSE");
	return 0;
}
