#include <iostream>
#include <cmath>
using namespace std;

/*
	類別型態間的轉換有兩種方法,一種是用operator的方法宣告一個"型態轉換函數" 
	另外一種方法是多載"="使其可以在兩個自訂的類別資料型態之間使用
	本程式示範第二種方法 
*/

class Polar	// 極座標 
{
	private:
	double radius;
	double angle;
	
	public:
	Polar() {radius = angle = 0.0;}
	Polar(double r, double a) {radius = r; angle = a;}
	double getr() {return radius;}
	double geta() {return angle;} 
	friend ostream& operator << (ostream& out, Polar& obj);	//多載"<<"運算符號  
};

class Cartesian	// 直角坐標 
{
	private:
	double x;
	double y;
	
	public:
	Cartesian() {x = y = 0.0;}
	Cartesian(double a, double b) {x = a; y = b;}
	Cartesian operator = (Polar p);	// 宣告多載"="號函數,注意這裡一定要先宣告Polar類別,否則會編譯錯誤 
	friend ostream& operator << (ostream& out, Cartesian& obj);	
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

Cartesian Cartesian::operator = (Polar p)
{
	double r = p.getr();
	double a = p.geta();
	
	x = r * cos(a);
	y = r * sin(a);
	
	return Cartesian(x, y);
}
 
int main()
{
	Polar p(2.0, 35.0);	// 建立Polar物件 
	Cartesian c;	// 建立一Cartesian物件
	 
	c = p;	// 呼叫多載"="號函數,以p為參數丟給"="函數,並將回傳值丟給c 
	
	cout << "極座標: " << p << endl
		 << "轉為平面座標: " << c << endl;
		 
	system("PAUSE");
	return 0; 
}

