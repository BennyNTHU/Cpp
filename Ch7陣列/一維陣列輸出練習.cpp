# include <iostream>
# include <iomanip>
using namespace std;

int main()
{
	int prime[10] = { 2, 3, 5, 7, 11, 13, 17, 23, 29, 31 };
	int febna[5] = { 1 , 1 , 2 , 3 , 5};
	char ASCII[10] = {'A','B','C'};
	float pi[4] = {3, 3.1, 3.14, 3.141};
	char str1[4] = "C++";
	char str[3] = {'C','+','+'};
	
	for (int i = 0 ; i<=5 ; i++)
		cout<<prime[i]<<'\t';
	cout<<'\n';
	
	for (int i = 0 ; i<=5 ; i++)
		cout<<febna[i]<<'\t';
	cout<<'\n';
	
	for (int i = 0 ; i<=5 ; i++)
		cout<<ASCII[i]<<'\t';
	cout<<'\n';
	
	for (int i = 0 ; i<=5 ; i++)
		cout<<pi[i]<<'\t';	//Why the fifth value isn't 0? 
	cout<<'\n';
	
	for (int i = 0 ; i<=5 ; i++)
		cout<<str1[i]<<'\t';
	cout<<'\n';
	
	for (int i = 0 ; i<=5 ; i++)
		cout<<str[i]<<'\t';
	cout<<'\n';
	
	return 0;
}
