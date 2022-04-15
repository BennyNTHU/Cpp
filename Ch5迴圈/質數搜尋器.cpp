#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	int upbound;
	int number,test;
	int count;
	
	cout<<"Welcome! This program will find out all prime numbers under the value you input:";
	cin>>upbound;

	
	if (upbound == 1)
		cout<<"NO PRIME NUMBERS!!"<<endl; 
	else if (upbound == 2)
		cout<<"2"<<'\n'<<"Only "<<"1"<<" Prime"<<endl;
	else	
	{
		cout<<"2"<<endl;
		for(number = 2 , count = 1; number <= upbound ; number++ )
		{
			for(test = 2 ; test < number ; test ++)	 
			{
				if( number%test == 0) //Prime Test 
					break;
				else if (number == test + 1)	//If every number before "number" aren't its factor, then "number" is a prime.”µ 
				{
					cout<<number<<endl;
					count++;
					break;
				}
			}
		}
		
		cout<<"Found "<<count<<" primes"<<endl; 
	}
	
	system("PAUSE");
	return 0;

}
