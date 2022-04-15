#include <iostream>
using namespace std;

/*
	禬更ㄧ计琌璴ネ摸い穝﹚竡籔膀娄摸Θㄧ计妓
	把计计┪把计篈ぃㄧ计 
*/

class Base
{
	private:
		int a, b;
	public:
		Base(int l, int m)
		{
			a = 1;
			b = m;
		}
		void show()
		{
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
		}
 };
 
class Derived: public Base
{
	private:
		int c;
	public:
		Derived(int l, int m, int n): Base(l, m)
		{
			c = n;
		}
		void show()	//禬更show()ㄧ计 
		{
			Base::show();
			cout << "c = " << c << endl;
		}
} ;

int main()
{
	Derived d(2,3,5);
	d.show();
	
	system("PAUSE");
	return 0;
}

