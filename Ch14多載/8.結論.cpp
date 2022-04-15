#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926f

/*
	結論:C++中的虛擬有兩種:虛擬函數,虛擬繼承 
	當衍生類別與基礎類別同時呼叫基礎類別內的函數f
	且f又呼叫了兩種類別都有的同名異式(多型)函數g時
	需宣告g為虛擬函數,f才能藉由"被哪一種類別的物件呼叫"來存取對應的函數
	
	虛擬繼承則是用在繼承路徑不清楚時,
	將多個類別的指標都指向同一基礎類別,
	以避免繼承路徑模稜兩可造成編譯錯誤的狀況 
*/ 

class Line
{
	private:
		double length;
	
	public:
		Line(double length)		//建立者函數 
		{
			this->length = length;
		}
		double getLength()
		{
			return this->length;
		}
		virtual double getArea() = 0;	//宣告純虛擬函數 
};

class Square: public Line
{
	public:
		Square(double length): Line(length) {}	//Square建立者函數 
		double getArea()	//超載getArea函數 
		{
			return pow(getLength(), 2);
		}
};

class Circle: public Line
{
	public:
		Circle(int radius): Line(radius) {}	//Circle建立者 
		double getArea()	//超載getArea函數 
		{
			return PI * pow(getLength(), 2);
		}
};

int main()
{
	Square s(5);
	Circle c(10);
	
	cout << "正方形邊長 = " << s.getLength();
	cout << "\t正方形面積 = " << s.getArea();	//因為Line的getArea是純虛擬函數,且由於是Square類別的物件呼叫,所以呼叫的是Square的getArea函數 
	cout << "\n圓形半徑 = " << c.getLength();
	cout << "\t圓形面積 = " << c.getArea();		//因為Line的getArea是純虛擬函數,且由於是Square類別的物件呼叫,所以呼叫的是Square的getArea函數
	cout << endl; 
	
	system("PAUSE");
	return 0;
}
 
