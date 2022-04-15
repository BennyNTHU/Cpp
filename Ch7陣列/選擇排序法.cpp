# include <iostream>
using namespace std;

const int MAX = 5;

int main()
{
	int counti = 0, countj = 0, 
	int minimum = 0									//紀錄當前最小值,亦具有緩衝器功能 
	int mindex = 0;									//最小值之索引值 
	int number[MAX] = { 57, 19, 33, 92, 6 };
	
	cout << "排序前: ";
	for ( counti = 0 ; counti < MAX ; counti++ )	//輸出原陣列 
 		cout << number[counti] << '\0';
 	
	for ( counti = 0 ; counti < MAX-1 ; counti++ )	//開始排序,令a[0]為當前最小值 
	{
		mindex = counti;							//重令counti為當前最小值之索引值 
		minimum = number[counti];					//重令minimum為當前最小值 
		for ( countj = counti + 1 ; countj < MAX ; countj++ )
		{
			if ( number[countj] < minimum )			//逐一檢查當前最小值之後各元素,若當前之元素比當前之minimum還小 
			{
				minimum = number[countj];			//則令它為新的最小值 
				mindex = countj;					//它的索引值就是新的最小值索引 
			}
		}
		number[mindex] = number[counti];			//將當前新發現的最小值與原數交換 
		number[counti] = minimum;
	}
	
	cout << "\n排序後: ";
	for ( counti = 0 ; counti < MAX ; counti++ )	//輸出排序完成的數列 
		cout << number[counti] << '\0';
	cout << endl;
	
	system("PAUSE");
	return 0;
}
