#include <iostream>
using namespace std;

int lcm(int,int,int);

int main(void)
{
	unsigned long long int a = 0, b = 0, n = 0;
	
	cout << "請輸入兩個整數: ";
	cin >> a >> b;
	n = a;
	cout << "LCM = " << lcm(a, b, n) << endl;
	
	system("PAUSE");
	return 0;
}

int lcm(int a, int b, int n)
{
	if (n%b == 0)
		return n;
	else
		return lcm(a, b, n+a);
}

