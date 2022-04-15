#include <iostream>
#include <cmath>
using namespace std;

/*
	同名異式又稱多型(polymorphism),
	指基礎類別與衍生類別中多載"相同名子"但"不同功能"的函數
	整個類別體系(基礎類別與衍生類別)中的某一函數f,又呼叫了此多載函數
	當一類別呼叫f時,f會呼叫"同一類別內"的多載函數 
*/
class InchArea
{
	protected:
		double inch;
	public:
		InchArea(double in)
		{
			inch = in;
		}
		double getLength()	//多載getLength函數 
		{
			return inch;
		}
		double getArea()	
		{
			return pow(getLength(), 2);	//呼叫InchArea的getLenth物件 
		}
};

class FeetArea: public InchArea
{
	protected:
		double feet;
	public:
		FeetArea(int ft): InchArea(ft*12)
		{
			feet = ft;
		}
		int getLength()	//多載getLength函數 
		{
			return feet;
		}
};

int main()
{
	InchArea ia(5);
	cout << "正方形長5英寸, 面積 = " << ia.getArea() << " 平方英寸" << endl;	//ia的getArea函數會去呼叫InchArea的getLenth物件 
	FeetArea fa(8);
	cout << "正方形長8英尺, 面積 = " << fa.getArea() << " 平方英寸" << endl;	//ia的getArea函數還是呼叫InchArea的getLenth物件 
	
	system("PAUSE");
	return 0;
}

