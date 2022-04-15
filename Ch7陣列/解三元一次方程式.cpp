/* Solving three-dimensional linear equations 
   Benny Lee, 2017/10/18
*/

# include <iostream>
# include <iomanip>
using namespace std;

void showArray( int[][3], int, char[] );
int calArray( int [][3]);
void solve_TDLE ();

int main()
{
	int TDLE[3][4];
	int dd[3][3] = {0};
	int d, dx, dy, dz;
	int y;
	
	cout << "Solving three-dimensional linear equations\n";
	cout << "a1x + b1y + c1z = d1 "<<endl;
	cout << "a2x + b2y + c2z = d2 "<<endl;
	cout << "a3x + b3y + c3z = d3\n"<<endl;
	cout << "Entering coefficient:\n";
	cin >>TDLE[0][0]>>TDLE[0][1]>>TDLE[0][2]>>TDLE[0][3]
		>>TDLE[1][0]>>TDLE[1][1]>>TDLE[1][2]>>TDLE[1][3]
		>>TDLE[2][0]>>TDLE[2][1]>>TDLE[2][2]>>TDLE[2][3];
	cout << "\nThe three-dimensional linear equations:\n";
	
	/* Print the equations out */
	for ( y = 0 ; y < 3 ; y++ )
	{
		cout << TDLE[y][0] << (TDLE[y][1] > 0 ? "x +" : "x " );
		cout << TDLE[y][1] << (TDLE[y][2] > 0 ? "y +" : "y " );
		cout << TDLE[y][2] << "z= ";
		cout << TDLE[y][3] << "\n";
	}
	
	/* Get Delta */
	for ( y = 0 ; y <3 ; y++ )
	{
		dd[y][0] = TDLE[y][0];
		dd[y][1] = TDLE[y][1];
		dd[y][2] = TDLE[y][2];
	} 
	d = calArray(dd);
	showArray( dd, d, "d  = | ");
	
	/* Get Delta X */
	for ( y = 0 ; y < 3 ; y++)
	{
		dd[y][0] = TDLE[y][3];
		dd[y][1] = TDLE[y][1];
		dd[y][2] = TDLE[y][2];
	}					
	dx = calArray(dd);
	showArray( dd, d, "dx = | ");
	
	/* Get Delta y */
	for ( y = 0 ; y < 3 ; y++)
	{
		dd[y][0] = TDLE[y][0];
		dd[y][1] = TDLE[y][3];
		dd[y][2] = TDLE[y][2];
	}
	dy = calArray(dd);
	showArray(dd, dy, "dy = | ");
	
	/* Get Delta z */
	for ( y = 0 ; y < 3 ; y++)
	{
		dd[y][0] = TDLE[y][0];
		dd[y][1] = TDLE[y][1];
		dd[y][2] = TDLE[y][3];
	}
	dz = calArray(dd);
	showArray( dd, dz, "dz = | ");
	
	/* The roots */
	cout<<endl;
	cout << " x = "<< dx << '/' << d << endl;
	cout << " y = "<< dy << '/' << d << endl;
	cout << " z = "<< dz << '/' << d << endl;
	
	system("PAUSE");
	return 0;
}

int calArray ( int array[][3] )
{
	int a = 0;
	for ( int i = 0 ; i < 3 ; i++ )
	{
		a += array[0][i]*array[1][(i+1)%3]*array[2][(i+2)%3];
		a -= array[0][i]*array[1][(i+2)%3]*array[2][(i+1)%3];
	}
	return a;
}

void showArray(int array[][3], int d, char s[])
{
	cout << endl;
	for ( int y = 0 ; y < 3 ; y++ )
	{
		y == 1 ? cout << s : cout << "     | ";
		for( int x = 0 ; x < 3 ; x++ )
			cout << setw(2) << array[y][x] << ' ';
		y == 1 ? cout << "| = " << d << endl : cout << "|\n";			 
	}
}
