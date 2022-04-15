#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.1415926
using namespace std; 

int main()
{
	double pitch; //Pitch of the angles. 
	double i ;	//The angles which the program will calculate their trigonometric functions
	
	cout<<"Trigonometric functions table of angles between 0~90 degree!\n"
		<<"Please enter the pitch: ";
	cin>>pitch;
	cout<<endl;
	
	if (pitch<0.001)
	{ 
		cout<<"The pitch can't less than 0.001 degree!'"<<endl;
	}	
	else
	{
		cout<<"Angle"<<'\t'<<"sin"<<'\t'<<"cos"<<'\t'<<"tan"<<endl; //The first column of the table. 
		for(i=0;i<=90;i+=pitch)
		{	
		
			if(i == 90)
			{
				cout<<setprecision(3)<<setiosflags(ios::fixed);
				cout<<i<<'\t'<<1.000<<'\t'<<0.000<<'\t'<<"meanless"<<endl; //tan90deg is meanless. 
				cout<<"Angle"<<'\t'<<"sin"<<'\t'<<"cos"<<'\t'<<"tan"<<endl; //Last column of the table. Print out the names of the functions again.
			}
			else
			{
				double sine = sin(i*(PI/180));	//sine 
				double cosine = cos(i*(PI/180));	//cosine 
				double tangent = tan(i*(PI/180));	//tangentÇÐ 
				cout<<setprecision(3)<<setiosflags(ios::fixed); //Print out three digits after the decimal points.”µ 
				cout<<i<<'\t'<<sine<<'\t'<<cosine<<'\t'<<tangent<<endl; //Print out the value of each functions.
			}
		}
	}
	
	system("PAUSE");
	return 0;
	
}


