#include<iostream>
using namespace std;

/*
	純虛擬函數:
	如果基礎類別定義了虛擬函數,但衍生類別沒有超載之,則衍生類別物件將使用"基礎類別的虛擬函數"
	 
	但如果要存取衍生類別的資料成員,不能使用基礎類別的虛擬函數
	不過一個程式可能有一大堆類別,
	不可能一一檢查各個物件是呼叫到哪一個類別的虛擬函數 
	
	因此我們在基礎類別中定義一個"純虛擬函數",讓他完全沒有作用
	這時在各個衍生類別中各自定義超載函數,就省去了檢查的麻煩 
*/

/*
	抽象基礎類別:
	是指包含一個或多個純虛擬函數的類別
	可以把它想成各個衍生類別的"函式名稱資料庫", 
*/

class Base	//抽象基礎類別 
{
	public:
		virtual void show() = 0;	//純虛擬函數 
};

class Derived1: public Base	//繼承了Base的純虛擬函數 
{
	public:
		void show()	//超載show()函數 
		{
			cout << "衍生類別1" << endl; 
		}
};

class Derived2: public Base	//繼承了Base的純虛擬函數
{
	public:
		void show()	//超載show()函數 
		{
			cout << "衍生類別2" << endl; 
		}
};

int main()
{
	Base *list[2];
	Derived1 d1;
	Derived2 d2;
	
	list[0] = &d1;	//讓Base類別的指標list[0]指向d1的位址 
	list[1] = &d2;	//讓Base類別的指標list[1]指向d2的位址 
	
	list[0]->show();	//由於Base的show()函數被宣告為純虛擬函數,且指標又指向d1,所以會呼叫Derived1的show()函數成員 
	list[1]->show();	//由於Base的show()函數被宣告為純虛擬函數,且指標又指向d2,所以會呼叫Derived2的show()函數成員 
	
	system("PAUSE");
	return 0;
}
