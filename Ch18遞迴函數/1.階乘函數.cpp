#include <iostream> 
#include <iomanip>
using namespace std;

/*
	遞迴函數的概念在之前就已經介紹過,舉幾例說明
*/ 

long factorial(int);

int main(void)
{
	int count = 1;
	
	cout << "記數\t" << setw(8) << "階乘\n";
	
	do {
		cout << setw(3) << count << '\t';
		cout << setw(7) << factorial(count) << endl;
	} while (++count<=10);
	
	system("PAUSE");
	return 0;
}

long factorial (int n)
{
	if (n>1)
		return n*factorial(n-1);
	else
		return 1;
}

