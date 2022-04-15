#include <iostream>
using namespace std;

/*
	類別內的函數也可以用遞迴來寫 
*/ 

class Division
{	
	private:
		int a, b, q;
	
	public:
		Division(int a1, int b1)
		{
			a = a1;
			b = b1;
			q = 0;
		}
		int quotient()
		{
			if (a>=b)
			{
				a -= b;
				q++;
				return quotient();
			}
			else	
				return q;
		}
		int remainder()
		{
			if (a>=b)
			{
				a -= b;
				return remainder();
			}
			else
				return a;
		}	
};

int main(void)
{
	int a, b;
	
	cout << "請輸入兩個整數: ";
	cin >> a >> b;
	Division div (a, b);
	
	cout << a << " / " << b << " = " << div.quotient();
	cout << " R " << div.remainder() << endl;
	
	system("PAUSE");
	return 0; 
}

