#include <iostream>
using namespace std;

/*
	private繼承:就是所有成員被繼承後都會變成衍生類別的private成員
	但衍生類別可以存取基礎類別的protected和public成員 
*/
class Point	// 基礎類別 
{
	protected:
	int x;
	int y;
	
	public:
	void set (int n, int m)
	{
		x = n;
		y = m;
	}
	void show()
	{
		cout << "位置 = p(" << x << ", " << y << ")" << endl;
	}
}; 

class Area: private Point	// 宣告Area類別是Point類別的衍生類別,且是用private型態繼承 
{
	public:
	/* 由於x跟y是被繼承後變成private成員且不能存取(相當於沒被繼承),
	   故我們藉由呼叫(存取)基礎類別的public成員(被繼承後變成Area的private成員,但仍可以存取) 
	   來間接存取x跟y 
	*/ 
	void setpoint(int n, int m)	 
	{
		set(n, m);
	}
	void showpoint()
	{
		show();
	}
	void showarea()
	{
		cout << "面積 = " << x*y << endl; 	
	}
};

int main(void)
{
	Area p;
	
	p.setpoint(2, 5);
	p.showpoint();
	p.showarea();
	
	system("PAUSE");
	return 0;
}

