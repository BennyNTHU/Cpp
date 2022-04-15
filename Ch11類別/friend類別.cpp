#include <iostream>
using namespace std;

class First
{
	private:
	int x;
	public:
	void setx(int var)
	{
		x = var;
	}
	friend int getx(First obj)	// define friend function
	{
		return obj.x;
	}
}; 

class Second
{
	private: 
	int y;
	public: 
	void sety(int var)
	{
		y = var;
	}
	void showxy(First obj)
	{
		cout << "x = " << getx(obj) << endl;
		cout << "y = " << y << endl;
	}
};

int main(int argc, char *argv[])
{
	First A;
	Second B;
	A.setx(10);
	B.sety(20);
	B.showxy(A);
	
	system("PAUSE");
	return 0;
}

