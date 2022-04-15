# include <iostream>
using namespace std;

int main()
{
	bool flag = false;
	int count, search;
	int number[5] = { 57, 19, 33, 92, 6 };
	
	cout << "顯示資料: ";
	for ( count = 0 ; count <= 4 ; count++ )
		cout << number[count] << ' ';
	
	cout << "\n輸入資料: ";
	cin >> search;
	
	for ( count = 0 ; count <= 4 ; count++ )
		if ( number[count] == search )
			flag = 1;
	
	if (flag)
		cout << "找到資料: " << search << endl;
	else
		cout << "找不到資料: " << search << endl; 
	
	system("PAUSE");
	return 0;
} 
