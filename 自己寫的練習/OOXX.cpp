#include <iostream>
using namespace std;

int wintest ();
void printgame();

char game[3][3] = { {'*','*','*'}, 
					{'*','*','*'}, 
					{'*','*','*'} };
	
int main()
{
	int row = 0, col = 0;
	int test;
	
	printgame();
	
	while(1)
	{
		cout<<"玩家一執O 請輸入位置(先填橫再填縱):";
		cin >> col >> row;
		cout<<"\n";
		game[col][row] = 'O';
		test = wintest();
		if ( test = (1 || 2 ) )  break ;  
		
		printgame();
		
		cout<<"玩家二執X 請輸入位置(先填橫再填縱):";
		cin >> col >> row;
		cout<<"\n";
		game[col][row] = 'X';
		if ( test = (1 || 2 ) )  break ;  
		
		printgame();
	}
	
	cout << "player"<<wintest()<<" Win!";
	
	return 0;
} 

int wintest ( )
{
	int player1win = 1;
	int player2win = 2;
	int i;
	
	for ( i = 0 ; i <=2 ; i++ )
	{
		if	( game[i][0] == game[i][1] && game[i][1] == game[i][2] )
		{
			if ( game[i][0] = 'O' )
				return player1win; 
			else if( game[i][0] = 'X' )
				return player2win ;
			else
				return 0;
		}
	}
	
	for ( i = 0 ; i <=2 ; i++ )
	{
		if	( game[0][i] == game[1][i] && game[1][i] == game[2][i] )
		{
			if (game[i][0] = 'O' )
				return player1win ;
			else if( game[i][0] = 'X' )
				return player2win ;
			else
				return 0;
		}
	}
	
	if	( game[0][0] == game[1][1] && game[1][1] == game[2][2] )
	{
		if (game[0][0] = 'O' )
			return player1win ;
		else if( game[i][0] = 'X' )
			return player2win ;
		else
			return 0;
			
	}
	
	if	( game[0][2] == game[1][1] && game[1][1] == game[2][0] )
	{
		if (game[0][2] = 'O' )
			return player1win ;
		else if( game[i][0] = 'X' )
			return player2win ;
		else
			return 0;
	}
			
}

void printgame()
{
	for ( int i = 0 ; i <= 2 ; i++ )
		{
			{
				for ( int j = 0 ; j <= 2 ; j++ )
				cout<<game[i][j]<<" ";
			}
			cout<<"\n";
		}
}
