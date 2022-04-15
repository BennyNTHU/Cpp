 # include<iostream>
# include<iomanip>
using namespace std;

int main()
{
	int TVE  [3][3] = { { 7, 1, 3 },
				    	{ 4, -1, 1},
						{ 5, 3, -2} };
	long d = 0;
	
	cout << "­pºâ¦æ¦C¦¡ a ­È\n";
	for ( int i = 0 ; i < 3 ; i++ )
	{
		d += TVE[0][i]*TVE[1][(i+1)%3]*TVE[2][(i+2)%3];
		d -= TVE[0][i]*TVE[1][(i+2)%3]*TVE[2][(i+1)%3];		
	}
	for ( int y = 0 ; y < 3 ; y++ )
	{
		if ( y == 1 )
			cout << "a = | ";
		else
			cout << "    | ";
		
		for ( int x = 0 ; x < 3 ; x++ )
			cout << setw(2) << TVE[y][x] << ' ';
			
		if ( y == 1)
			cout << "| =" << d << endl;
		else
			cout << "|\n";
	}	
	system("PAUSE");
	return 0;
}
