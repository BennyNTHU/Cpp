#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout<<"Welcome using the useless and non-stop and non-accurate electric clock!"<<endl;
	system("PAUSE");
	cout.setf(ios::fixed | ios::right);
	cout.fill('0');
	
	while(true)
	{
		for (int hrs = 0 ; hrs<24 ; hrs++)
			for (int min = 0 ; min<60 ; min++)
				for(int sec = 0 ; sec < 60 ; sec++)
				{
					cout << setw(2) <<hrs<<':';
					cout << setw(2) <<min<<':';
					cout << setw(2) <<sec<<' ';
					
					for(int delay = 0 ; delay <= 10000 ; delay++)					
						cout<< '\r';
				}
	}
	
	system("PAUSE");
	return 0;
}
