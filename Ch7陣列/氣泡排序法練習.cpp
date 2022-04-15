# include <iostream>
using namespace std;

int main()
{
	const int max = 5;
	int counti, countj, buffer;
	int number[max] = {57, 19, 19, 92, 6};
	
	cout << "排序前: ";
	for ( counti = 0 ; counti < max ; counti++ )
		cout << number[counti] << '\0';
		
	for ( counti = 0 ; counti < max -1 ; counti++ )
		for ( countj = counti ; countj < max ; countj++ )
			if ( number[counti] > number[countj] )
				{
					buffer = number[counti];
					number[counti] = number[countj];
					number[countj] = buffer;
				}
	cout << "\n排序後:";
	for ( counti = 0 ; counti < max ; counti++ )
		cout << number[counti] << '\0';
	cout << endl;
	
	system("PAUSE");
	return 0;
}
