#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926f
 
/*
	將多型函數宣告為virtual
	則編譯器會給多型函數不同的指標
	不同類別的物件,就能依據各自類別的指標,來存取適當的函數	
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
		virtual double getLength()	//虛擬getLength函數 
		{
			return inch;
		}
		double getArea()	
		{
			return int(pow(getLength(), 2));	//依據類別指標判斷是要呼叫InchArea的getLength成員函數,還是FeetArea的getLength成員函數 
		}
};

class FeetArea: public InchArea
{
	protected:
		double feet;
	public:
		FeetArea(double ft): InchArea(ft*12)
		{
			feet = ft;
		}
		virtual double getLength()	//多載getLength函數 
		{
			return feet;
		}
};

int main()
{
	InchArea ia(5);		//建立InchArea物件ia 
	cout << "正方形長5英寸, 面積 = " << ia.getArea() << " 平方英寸" << endl;	
	//ia的getArea函數,經由判斷InchArea的指標後,會去呼叫InchArea的getLenth物件
	 
	FeetArea fa(8);		//建立FeetArea物件ia 
	cout << "正方形長8英尺, 面積 = " << fa.getArea() << " 平方英尺" << endl;
	//fa的getArea函數,經由判斷FeetArea的的指標後,會去呼叫FeetArea的getLenth物件 
	
	system("PAUSE");
	return 0;
}

