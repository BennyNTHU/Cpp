#include <iostream>
using namespace std;

int gcd(int,int,int);

int main(void)
{
	unsigned long long int a = 0, b = 0, n = 0;
	
	cout << "請輸入兩個整數: ";
	cin >> a >> b;
	n = a;
	cout << "GCD = " << gcd(a, b, n) << endl;
	
	system("PAUSE");
	return 0;
}

int gcd(int a, int b, int n)
{
	if (a%n == 0 && b % n == 0)
		return n;
	else
		return gcd(a, b, n-1);
}

