# include <iostream>
using namespace std;

int main()
{
	const int max = 5;							//陣列長度 
	int counti = 0, countj = 0, buffer = 0;		//排序與輸出區塊用的迴圈計數器與緩衝器 
	int search = 0,								//欲搜尋的資料 
	int low = 0, high = max - 1					//搜尋上下界索引值 
	int middle = 0;								//中位數索引值 
	int number[max] = { 57, 19, 33, 92, 6 };	//原陣列 
	
	/* 輸出原陣列 */ 
	cout << "排序前: ";						 
	for ( counti = 0 ; counti < max ; counti++ )
		cout << number[counti] << '\0';

	cout << "\n請輸入要搜尋數值: ";
	cin >> search;
	
	/* 氣泡排序法 */ 
	for ( counti = 0 ; counti < max - 1 ; counti++ ) 
		for ( countj = counti ; countj < max ; countj++ )
			if ( number[counti] > number[countj] )
			{
				buffer = number[counti];
				number[counti] = number[countj];
				number[countj] = buffer;
			}
		
	/* 輸出排列後的陣列 */	
	cout << "\n排序後: ";	
	for ( counti = 0 ; counti < max ; counti++ )
		cout << number[counti] << '\0';
	
	/* 二分搜尋法 */ 
	do
	{
		if ( (low+high)%2 > 0.5 )				//先求出中位數 
			middle = ( low + high ) / 2 + 1;
		else
			middle = ( low + high) / 2;
		
		if ( search < number[middle] )			//如果欲搜尋值比中位數小 
			high = middle - 1;					//就維持原下界,並把上界改為中位數的前一個數 
		else if ( search > number[middle] )		//如果欲搜尋值比中位數大 
			low = middle + 1;					//就維持原上界,並把下界改為中位數的後一個數 
		else if ( search == number[middle] )	//如果找到了 
			break;								//就結束搜尋 
	} while ( low <= high );					//如果找不到,最後下界與上屆必定會交錯 
	
	/* 輸出搜尋結果 */ 
	if ( low > high )
		cout << "\n找不到數值: " << search << endl;
	else
		cout << "\n找到數值: " << search << endl;
		
	system("PAUSE");
	return 0; 
 } 
