#include <iostream>
using namespace std;

class PointXY
{
	protected:
		int x, y;
	
	public:
		void setxy(int n, int m)
		{
			x = n;
			y = m;
		}
		
};

class PointZ 
{
	protected:
		int z;
		
	public:	
		void setz(int o)
		{
			z = o;
		}
};

class Cube: public PointXY, public PointZ	//同時繼承了PointXY與Pointz 
{
	public:
		void showxy()
		{
			cout << "平面座標 : p(" << x << ", " << y << ") " << endl;
		}
		void showxyz()
		{
			cout << "空間座標 : s(" << x << ", " << y << ", " << z << ") " << endl;
		}
		void showarea()
		{
			cout << "面積 = " << x * y << endl; 
		}
		void showcube()
		{
			cout << "體積 = " << x * y * z << endl; 
		}
};

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

