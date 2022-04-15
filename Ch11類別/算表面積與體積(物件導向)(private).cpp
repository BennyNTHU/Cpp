#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926

class Cuboid
{
	private:
	int length;
	int height;
	int width;
	
	public:
	void setCuboid(int l, int w, int h)
	{
		length = l;
		width = w;
		height = h;
	}
	int getLength()
	{
		return length;
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
	int area()
	{
		return 2 * (length * width + width * height + height * length);
	}
	int volumn()
	{
		return height * length * width;
	}
};

class Cylinder
{
	private:
	float radius;
	float height;
	
	public:
	void setCylinder(float r, float h)
	{
		radius = r;
		height = h;
	}
	float getRadius()
	{
		return radius;
	}
	float getHeight()
	{
		return height;
	}
	float area()
	{
		return 2 * PI * radius * height;
	}
	float volumn()
	{
		return PI * float(pow(radius,2)) * height;
	}
};

int main(int argc, char *argv[])
{
	Cuboid rt;
	rt.setCuboid(6,8,10);
	cout << "長方體:\n";
	cout << "長 = " << rt.getLength() << endl; 
	cout << "寬 = " << rt.getWidth() << endl; 
	cout << "高 = " << rt.getHeight() << endl; 
	cout << "表面積 = " << rt.area() << endl; 
	cout << "體積 = " << rt.volumn() << endl;
	
	Cylinder cl;
	cl.setCylinder(5.0,10.0);
	cout << "圓柱體:\n";
	cout << "半徑 = " << cl.getRadius() << endl; 
	cout << "高 = " << cl.getHeight() << endl; 
	cout << "表面積 = " << cl.area() << endl; 
	cout << "體積 = " << cl.volumn() << endl;
	
	system("PAUSE");
	return 0;
}
