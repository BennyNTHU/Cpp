#include <iostream>
using namespace std;

class Calculate
{
	private:
		int x;
		
	public:
		Calculate(int n);
		Calculate *calcSum(Calculate obj);	//傳回型態是指標Calculate ,也就是Calculate的位置 
		void showSum(Calculate a, Calculate b);
};

Calculate::Calculate(int n)
{
	x = n;
};

Calculate *Calculate::calcSum(Calculate obj)
{
	x += obj.x;
	return this;
};

void Calculate::showSum(Calculate a, Calculate b)
{
	cout << "a = " << a.x << endl;
	cout << "b = " << b.x << endl;
	cout << "a + b = " << this->x << endl;
};

int main(int argc, char *argv[])
{
	Calculate a(100), b(200), c(0);
	c = *(a.calcSum(b));	//將b丟進a的calcSum函數裡面, a的x值會先被加上b的x值 
	c.showSum(a, b);
	
	system("PAUSE");
	return 0;
}
