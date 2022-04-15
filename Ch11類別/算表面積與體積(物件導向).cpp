#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926

class Cuboid
{
	public:
	int length;
	int height;
	int width;
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
	public:
	float radius;
	float height;
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
	Cuboid rt = {6,8,10};
	cout << "長方體:\n";
	cout << "長 = " << rt.length << endl; 
	cout << "寬 = " << rt.width << endl; 
	cout << "高 = " << rt.height << endl; 
	cout << "表面積 = " << rt.area() << endl; 
	cout << "體積 = " << rt.volumn() << endl;
	
	Cylinder cl = {5.0, 10.0};
	cout << "圓柱體:\n";
	cout << "半徑 = " << cl.radius << endl; 
	cout << "高 = " << cl.height << endl; 
	cout << "表面積 = " << cl.area() << endl; 
	cout << "體積 = " << cl.volumn() << endl;
	
	system("PAUSE");
	return 0;
}
