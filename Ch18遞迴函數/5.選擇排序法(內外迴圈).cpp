#include <iostream>
using namespace std;

void innerSort(int [], int);
void outerSort(int [], int);
const int MAX = 5;
int minimum, mindex;

int main(void)
{
	int counti, i;
	int number[MAX] = {57, 19, 33, 92, 6};
	
	cout << "排序前: ";
	for (i = 0; i < MAX; i++)
		cout << number[i] <<  ' ';
	cout << endl;
		
	outerSort(number, 0);
	
	cout << "排序後: ";
	for (i = 0; i < MAX; i++)
		cout << number[i] << ' ';
	cout << endl;
	
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

