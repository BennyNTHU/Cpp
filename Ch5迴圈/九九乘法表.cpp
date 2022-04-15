#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, j, n;	//n*n multiple table
	
	cout<<"n*n multiple table, please enter n:" ;
	cin>>n;
	
	for(i = 1 ; i <= n ; i++ )
	{
		for(j = 1 ; j <= n ; j++)
			cout<<setw(3)<<i<<' '<<"*"
				<<' '<<setw(3)<<j<<' '
				<<"="<<' '<<setw(3)<<i*j<<' ';
			
		cout<<endl; 
	}
	
	system("PAUSE");
	return 0;
 } 
