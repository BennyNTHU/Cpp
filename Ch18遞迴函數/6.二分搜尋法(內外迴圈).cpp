#include <iostream>
using namespace std;

void innerSort(int [], int);
void outerSort(int [], int);
void search(int[], int, int, int);
const int MAX = 5;
int minimum, mindex;

int main(void)
{
	int counti, i, navi;
	int number[MAX] = {57, 19, 33, 92, 6};
	
	cout << "排序前: ";
	for (i = 0; i < MAX; i++)
		cout << number[i] <<  ' ';
	cout << endl;
	
	cout << "\n請輸入要搜尋數值: ";
	cin >> navi;
		
	outerSort(number, 0);
	
	cout << "排序後: ";
	for (i = 0; i < MAX; i++)
		cout << number[i] << ' ';
	cout << endl;
	
	search(number, 0, MAX-1, navi);
	
	system("PAUSE");
	return 0; 
}

void outerSort(int number[], int counti)
{
	if (counti < MAX)
	{
		mindex = counti;
		minimum = number[counti];
		innerSort(number, counti+1);
		number[mindex] = number[counti];
		number[counti] = minimum;
		outerSort(number, counti+1);
	}
}

void innerSort(int number[], int countj)
{
	if (countj < MAX)
	{
		if (number[countj] < minimum)
		{
			minimum = number[countj];
			mindex = countj;
		}
		innerSort(number, countj+1);
	}
}

void search(int number[], int low, int high, int nav)
{
	int middle;
	
	if (low <= high)
	{
		if ((low+high)%2 > 0.5)
			middle = (low+high)/2 + 1;
		else
			middle = (low+high)/2;
			
		if (nav < number[middle])
			search(number, low, middle-1, nav);
		else if (nav > number[middle])
			search(number, middle+1, high, nav);
		else if (nav == number[middle])
			cout << "\n找到數值: " << nav << endl; 
	}
	else
		cout << "\n找不到數值: " << nav << endl;  
}

