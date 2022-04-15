#include <iostream>
using namespace std;

class TwoD
{
	protected:
		int x, y;
	
	public:
		void setxy(int n, int m)
		{
			x = n;
			y = m;
		}
		void showxy()
		{
			cout << "平面座標 : p(" << x << ", " << y << ") " << endl;
		}
};

class ThreeD: public TwoD
{
	protected:
		int z;
		
	public:
		void setz(int o)
		{
			z = o;
		}
		void showxyz()
		{
			cout << "空間座標 : s(" << x << ", " << y << ", " << z << ") " << endl;
		}
};

class Cube: public ThreeD	//同時繼承了TwoD與ThreeD 
{
	public:
		void showarea()
		{
			cout << "面積 = " << x * y << endl; 
		}
		void showcube()
		{
			cout << "體積 = " << x * y * z << endl; 
		}
};
//如果以後要用破壞者函數時,記得先建立者後破壞 

int main(void)
{
	Cube p;
	p.setxy(2, 5);
	p.showxy();
	p.showarea();
	cout << endl;
	p.setz(8);
	p.showxyz();
	p.showcube();
	
	system("PAUSE");
	return 0;
}

