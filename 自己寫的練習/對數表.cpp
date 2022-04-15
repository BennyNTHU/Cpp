#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	float base; //The base of log. 
	float upbound, lowbound, pitch; //Upper bound, lower bound and the pitch of the table. 
	int i; //Outputing the columns of the table and also used in the cell of the table.
	float j; //real number 
	
	cout<<"Welcome to use my logarithm table. Please extend the window to the same width of your screen."<<endl;
	
	cout<<"Please enter the base: ";							cin>>base; 
	cout<<"Please enter the Upper bound and lower bound: ";		cin>>upbound>>lowbound;
	cout<<"Please enter the pitch: 0.1 or 0.01 or 0.001:";		cin>>pitch;
	cout<<"Here comes the table...\n";							
	system("PAUSE");
	
	for(i=0;i<=9;i++)
		cout<<'\t' <<i;	//Print out the first column (the last digit after the decimal point).	
	cout<<'\n';
	
	for(j=lowbound ; j<=upbound ; j+=(10*pitch) )	//Print out the other digits.
	{
		int show = (-log10(pitch))-1;	//The first row of the table. That is, the last digit after the decimal pointǰ  
		cout<<setprecision(show)<<setiosflags(ios::fixed)<<j;	//The first value of each column. Print out the digits before the last one of the real number.ǰ 
		
		for(i=0;i<=9;i++)	//Fill in the table from left to right
		{
			double logarithm = log(j+pitch*i) / log(base);	//Calculating the logarithm. log(base)X=lnX/lnbase
			cout<<'\t' <<setprecision(4)<<setiosflags(ios::fixed)<<logarithm;	//Show the four digits after the decimal point.
		}
		
		cout<<'\n';
		
	}
	
	system("PAUSE");
	return 0; 
} 
