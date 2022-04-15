#include <iostream>
using namespace std;

/*
	繼承:當一類別繼承了另一類別時,我們稱被繼承的叫"基礎類別",繼承的叫"衍生類別"
	繼承就是指衍生類別可以"存取"基礎類別的某些成員,也就是成為了 
	但基礎類別的private成員不能被衍生類別直接存取
	(亦即private不會被繼承到衍生類別),但可以用一些方式繞過去 
	
	protected成員:只有成員函數與friend函數可以存取(與private相同),
	但protected成員可以被存取(繼承) 
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

/*
	public型態繼承:
	private成員繼承後仍為private(衍生類別存取不了,形同沒有繼承) 
	protected成員繼承後為protected
	public繼承後為public 
	如果要存取基礎類別的private成員,會在private繼承中討論 
*/ 
class Area: public Point	// 宣告Area類別是Point類別的衍生類別,且是用public型態繼承 
{
	public:
	void showarea()
	{
		cout << "面積 = " << x*y << endl; 	// Point類別中的protected成員被繼承了,所以可以直接存取 
	}
};

int main(void)
{
	Area p;			// 建立Area物件p 
	p.set(2,5);		// 由於繼承的關係,p可以存取Point的public成員 
	p.show();
	p.showarea();	//p自己的函數 
	
	system("PAUSE");
	return 0;
}

