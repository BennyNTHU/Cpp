/*  Sovling BSE
	Developer: Benny lee
	2017/10/13	*/

# include <iostream> 
using namespace std;

double determine(double,double,double,double);	// A 2-stage determine includes 4 numbers
void Solve_BSE( double,double,double );	// To solve the BSE by Cramer's rule

int main()
{
	double BSE[2][3];	// Coefficient of BSE.
		
	cout<<"Solving Binary Simultaneous Equations\n"
		<< "ax+by=c "
		<< "Enter two sets of a, b, c\n";	// A BSE also represents two lines on Cartesian Coordinates.
	
	cin>>BSE[0][0]>>BSE[0][1]>>BSE[0][2]  // a1 b1 c1 
	   >>BSE[1][0]>>BSE[1][1]>>BSE[1][2]; // a2 b2 c2
	
	double delta = determine( BSE[0][0],BSE[0][1],
					   		  BSE[1][0],BSE[1][1] );
						  
	double delta_X = determine( BSE[0][2],BSE[0][1],
					     	    BSE[1][2],BSE[1][1] );
							
	double delta_Y = determine( BSE[0][0],BSE[0][2],
							    BSE[1][0],BSE[1][2] );
	
	if( delta == 0 )	// Delta = 0 means two line vector of two lines parallel
		delta_X == 0 ? cout<<"Infinite number of solutions!\n" : cout<<"NO solution!\n";	
		// If delta_X = 0 , then it means two lines are the same one; Otherwise, they're parallel lines.
	else
		Solve_BSE( delta_X, delta_Y, delta );
		
	system("PAUSE");
	return 0;
}

double determine( double a, double b, double c, double d )
{
	/*  |a b|
		|c d|	*/
	return a*d - b*c;
}

void Solve_BSE( double a, double b, double c )	//By Cramer's rule
{	
	double x = a / c;
	double y = b / c;
	cout<< "the root of this BSE is "<<"( "<<x<<" , "<<y<<" )\n";
}
