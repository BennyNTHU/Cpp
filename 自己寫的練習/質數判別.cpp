#include <iostream>
#include <math.h>
using namespace std;

void primetest(int n);

int main()
{
	int n;
	cout<<"This program will test whether the number you input is a prime:";
	cin>>n;
	primetest(n);	
	system("PAUSE");
	return 0;
}

void primetest(int n)
{
	int find;

	for (int i = 2 ; i <= sqrt(n) + 1 ; i++) 
	{
		if ( n % i == 0)
		{
			find = 1;
			break;
		}	
		else 
		{
			find = 0 ;
		}
	}
	
	if(find ==0)
		cout<<"It's prime"<<endl;
	else if (find == 1)
		cout<< "It's not a prime"<<endl;
		
}
