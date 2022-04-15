#include <iostream>
#include <cmath>
using namespace std;

/*
	類別型態間的轉換有兩種方法,一種是用operator的方法宣告一個"型態轉換函數" 
	另外一種方法是多載"="使其可以在兩個自訂的類別資料型態之間使用
	本程式示範第一種方法 
	在Polar類別中先宣告
	operator Cartesian()為座標轉換函數 
	並在主程式中以"="使用之
	"="在牽涉類別型態轉換間的作用是,等號右邊的東西會呼叫型態轉換函數
	並將回傳值傳回給等號左邊的東西 
*/

class Cartesian	// 直角坐標 
{
	private:
	double x;
	double y;
	
	public:
	Cartesian() {x = y = 0.0;}
	Cartesian (double a, double b) {x = a; y = b;}
	friend ostream& operator << (ostream& out, Cartesian& obj);	
};

class Polar	// 極座標 
{
	private:
	double radius;
	double angle;
	
	public:
	Polar() {radius = angle = 0.0;}
	Polar(double r, double a) {radius = r; angle = a;}
	friend ostream& operator << (ostream& out, Polar& obj);	//多載"<<"運算符號 
	operator Cartesian();	//宣告型態轉換函數 
};

ostream& operator << (ostream& out, Cartesian& obj)
{
	out << "c(" << obj.x << ", " << obj.y << ")";
	return out;
}

ostream& operator << (ostream& out, Polar& obj)
{
	out << "p(" << obj.radius << ", " << obj.angle << ")";
	return out;
}

Polar::operator Cartesian()
{
	double xx, yy;
	xx = radius * cos(angle);
	yy = radius * sin(angle);
	return Cartesian(xx, yy);	// 回傳值是Cartesian類別 
}
 
int main()
{
	Polar p(2.0, 35.0);	// 建立Polar物件 
	Cartesian c;	// 建立一Cartesian物件
	 
	c = p;	// p呼叫了Polar中的Cartesian型態轉換函數,並將回傳值指定給c 
	
	cout << "極座標: " << p << endl
		 << "轉為平面座標: " << c << endl;
		 
	system("PAUSE");
	return 0; 
}

