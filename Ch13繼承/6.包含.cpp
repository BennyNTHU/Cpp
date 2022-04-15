#include <iostream>
using namespace std;

/*
	包含類別:包含並不是指類別內又建立一個類別,而是在一個類別內以宣告建立"另一個類別的物件"
	這種作法不是繼承,但可以達到一些跟繼承類似的功效 
*/

class Point	//定義Point物件 
{
	private:
	int x, y;
	
	public:
	Point (int = 0, int = 0);	//Point建立者,藉由呼叫setPoint()來建立 
	void setPoint(int x, int y);
	int getx() const	//常數型態函數,不能更改資料成員的值 
	{
		return x;
	}
	int gety() const	//常數型態函數,不能更改資料成員的值 
	{
		return y;
	} 
};

class Square
{
	int area() const;
	
	public:
	Point comP; 					//在Square類別內建立一個叫做comP的Point物件,所以我們說Square類別包含了Point類別 
	Square(int x = 0, int y = 0);	//Square建立者 
	int getarea() const
	{
		return area();
	}
};

Point::Point(int a, int b)
{
	setPoint(a, b);
}

void Point::setPoint(int a, int b)
{
	x = a;
	y = b;
}

Square::Square(int a, int b)
{
	comP.setPoint(a,b);
}

int Square::area() const
{
	return comP.getx() * comP.gety();
}

int main(void)
{
	Point p(72, 115);	//建立Point物件p 
	Square s(37, 43);	//建立Square物件s 
	
	cout << "點座標: p(" << p.getx() << ", " << p.gety() << ')' << endl;
	cout << "矩形座標: s(" << s.comP.getx() << ", " << s.comP.gety() << ')' << endl;	//呼叫s中的Point物件comP的成員函數getx()與gety() 
	cout << "矩形面積: " << s.comP.getx() << " * " << s.comP.gety() << " = " << s.getarea() << endl;  
	
	system("PAUSE");
	return 0;
}

