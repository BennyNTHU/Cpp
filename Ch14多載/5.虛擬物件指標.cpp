#include <iostream>
using namespace std;

/*
	當我們將
	1.基礎類別物件的位址 或 
	2.衍生類別物件的位址 
	存入基礎類別物件的指標,
	並以此指標呼叫同名異式(多型)的virtual函數,
	此指標會依據物件的類別,存取適當的函數 
*/

class Base
{
	public:
		virtual void show()
		{
			cout << "基礎類別\n";
		}
};

class Derived1: public Base	//繼承了Base,擁有一個virtual的show()函數與一個普通的show函數 
{
	public:
		void show()
		{
			cout << "衍生類別1\n";
		}
};

class Derived2: public Base	//繼承了Base,擁有一個virtual的show()函數與一個普通的show函數 
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
	ptr->show();	//顯示"衍生類別1" 
	
	ptr = &d2;
	ptr->show();	//顯示"衍生類別2" 
	
	system("PAUSE");
	return 0;
}
