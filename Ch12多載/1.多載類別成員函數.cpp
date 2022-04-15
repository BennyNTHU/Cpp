#include <iostream>
using namespace std;

class Cuboid
{
	private:
		int length;
		int width;
		int height;
	
	public:
		void setSide(int l, int w)	//設定長方形邊長 
		{
			length = l;
			width = w;
			height = 0;
		}
		void setSide(int l, int w, int h)	//設定長方體邊長
		{
			length = l;
			width = w;
			height = h;
		}
		int area()
		{
			if (height == 0)
				return length * width;
			else
				return 2*(length*width+width*height+height*length);
		 } 
 };
 
int main()
{
	Cuboid rt, cb;
	rt.setSide(6, 8);
	cb.setSide(6,8,10);
	
	cout << "長方形面積 = " << rt.area() << "平方公分" << endl;
	cout << "長方體表面積 = " << cb.area() << "平方公分" << endl;
	
	system("PAUSE");
	return 0; 
} 

