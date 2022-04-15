#include <iostream>
using namespace std;

/*
	protected繼承:private成員仍為private成員,protected與public成員都被繼承為protected
	但衍生類別不能直接存取基礎類別的public函數
	因為他們都被繼承為protected,只能靠衍生類別的成員函數去間接存取他們 
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

class Area: protected Point	// 宣告Area類別是Point類別的衍生類別,且是用protected型態繼承 
{
	public:
	/* 由於x跟y是被繼承後變成protected成員且不能存取,
	   故我們藉由呼叫(存取)基礎類別的public成員(被繼承後變成Area的protected成員,但仍可以存取) 
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

