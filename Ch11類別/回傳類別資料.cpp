#include <iostream>
using namespace std;

class Calculate
{
	private:
	int x;
	public:
	Calculate(int n);
	Calculate calcSum(Calculate obj);
	void showSum(Calculate a, Calculate b);
};

Calculate::Calculate(int n)
{
	x = n;
};

Calculate Calculate::calcSum(Calculate obj)
{
	x += obj.x;		//將會接收b的x值 
	return *this;	//傳回(*this).x,(*this)即為a 
}

void Calculate::showSum(Calculate a, Calculate b)
{
	cout << "a = " << a.x << endl;
	cout << "b = " << b.x << endl;
	cout << "a + b = " << this->x << endl;
};

int main(int argc, char *argv[])
{
	Calculate a(100), b(200), c(0);
	c = a.calcSum(b);	//將b丟進a的calcSum函數裡面, 
	c.showSum(a, b);
	
	system("PAUSE");
	return 0;
}

