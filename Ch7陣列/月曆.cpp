# include <iostream>
# include <iomanip>
using namespace std;

int main()
{
	int ini, max;
	char days[7][7] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
	
	cout << "輸入本月的總天數: ";	cin >> max;
	cout << "本月第一天星期幾? ";	cin >> ini;
	cout << endl;
	
	for ( int i = 0 ; i <= 6 ; i++ )
		cout << days[i] << '\t';
	cout << endl;
	
	for ( int j = 1 ; j <= ini ; j++ )
		cout << setw(4) << '\t';
	
	for ( int k = 1 ; k <= max ; k++ )
	{	
		cout << setw(4) << k;
		if ( ( k + ini ) % 7 != 0 ) 
			cout << '\t';
		else
			cout << '\n';
	}
	cout << endl;
	system("PAUSE");
	return 0;
} 
