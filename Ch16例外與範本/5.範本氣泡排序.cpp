#include <iostream>
using namespace std;

/*
	範本:有時候我們設計的函數或類別只能限定某種資料型態或自訂類別使用(比如int),
	如果想要其他資料型態(比方說double),或其他自訂類別也能使用的話,可以使用範本 
*/

template <class X>				// 定義類別範本, X是我們希望可以通用的資料型態 
void sort(X *items, int max)	// 氣泡排序函數,X為型態範本,可以是int, double....,但max一定得是int 
{
	register int si, di;
	X temp;
	
	for (si=0; si<max-1; si++)
		for (di=si; di<max; di++)
			if (items[si] > items[di])
			{
				temp = items[si];
				items[si] = items[di];
				items[di] = temp;
			}
} 

int main (void)
{
	int iArray[7] = {6, 8, 9, 1, 10, 13, 3};
	double dArray[5] = {3.5, 2.1, 7.6, 9.6, 8.7};
	int i = 0;
	
	cout << "排序前: ";
	for (i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl;
	
	sort(iArray, 7);	// 整數陣列可以我們寫的函數排序 
	
	cout << "排序後: ";
	for (i=0; i<7; i++)
		cout << iArray[i] << ' ';
	cout << endl;
	
	cout << "排序前: ";
	for (i=0; i<5; i++)
		cout << dArray[i] << ' ';
	cout << endl;
	
	sort(dArray, 5);	// double陣列也可以使用我們寫的函數排序 
	
	cout << "排序後: ";
	for (i=0; i<5; i++)
		cout << dArray[i] << ' ';
	cout << endl;
	
	system("PAUSE");
	return 0;
}

