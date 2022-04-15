/* 陣列複製與清除練習:
   以求三元一次聯立方程組之D與Dx為例 */
    
# include <iostream>
# include <iomanip>
using namespace std;

int main()
{
	int i, x, y;
	int STE[3][4] = { { 7, 1, 3, 6 },
					  { 4, -1, 1, 1},
					  { 5, 3, -2, 8} };	//三元一次方程式的係數 
	int determine[3][3] = {0};	//將輸出的兩個陣列 
	
	cout << "三元一次方程組\n";
	for ( i = 0 ; i < 3 ; i++ )
	{
		cout << STE[i][0] <<(STE[i][1]>0? "x +":"x "); //如果y的係數是負的,就不用輸出+號 
		cout << STE[i][1] <<(STE[i][2]>0? "y +":"y "); //如果z的係數是負的,就不用輸出+號 
		cout << STE[i][2] << "z= ";	
		cout << STE[i][3] <<"\n";
	}
	
	for ( y = 0 ; y < 3 ; y++ )
		for ( x = 0 ; x < 3 ; x++ )
			determine[y][x] = STE[y][x]; //將STE的係數3*3矩陣複製給行列式
	
	/* 輸出3*3的係數行列式D */ 
	cout << "\n行列式 = \n";
	for ( y = 0 ; y < 3 ; y++ )
	{
		cout <<"| ";
		for ( x = 0 ; x < 3 ; x++ )
			cout << setw(2) <<determine[y][x]<< ' ';  
		cout << "|\n";
	}
	
	/* 將行列式給清除,才能把Dx賦值給它 
	但41行到47行其實是多餘的,即使不執行仍然能正常運作 */ 
	for ( y = 0 ; y < 3 ; y++ )
		for ( x = 0 ; x < 3 ; x++ )
			determine[y][x] = 0; 
	
	for ( y = 0 ; y < 3 ; y++ )
		for ( x = 0 ; x < 3 ; x++ )
			determine[y][x] = STE[y][x]; 
			
	for ( y = 0 ; y < 3 ; y++ )
		determine[y][0] = STE[y][3];
	
	/* 輸出Dx */ 
	cout << "\nDx = \n";
	
	for ( y = 0 ; y < 3 ; y++ )
	{
		cout <<"| ";
		for ( x = 0 ; x < 3 ; x++ )
			cout << setw(2) <<determine[y][x]<< ' ';
		cout << "|\n";
	}
	
	system("PAUSE");
	return 0;
} 
