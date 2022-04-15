#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926

struct Cuboid
{
	int length;
	int width;
	int height;
};

int area(Cuboid r)
{
	return 2 * (r.length * r.width
			+ r.width * r.height 
			+ r.height * r.length);
}

int volume(Cuboid r)
{
	return r.height*r.length*r.width;
}

int main (int argc, char *argv[])
{
	Cuboid rt = {6,8,10};
	
	cout << "長方體:\n";
	cout << "長 = " << rt.length << endl; 
	cout << "寬 = " << rt.width << endl; 
	cout << "高 = " << rt.height << endl; 
	cout << "表面積 = " << area(rt) << endl; 
	cout << "體積 = " << volume(rt) << endl;
	
	system ("PAUSE");
	return 0; 
 } 
 
