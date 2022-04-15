#include <iostream>
#include <iomanip>
using namespace std;

class Booklist
{
	private:
	char title[80];
	char auther[20];
	char number[20];
	float price;
	
	public:
	void setBook(void)
	{
		cout << "Key in the title:";
		cin.getline(title,79);
		cout << "Key in the author:";
		cin.getline(auther, 19);
		cout <<"Key in the number:";
		cin.getline(number, 19);
		cout << "Key in the price:";
		cin >> price;
		cout << endl;
	}
	void showBook()
	{
		cout.precision(2);	//effective digits
		cout.setf(ios::fixed|ios::left);	//teo digits after the decimal; allign left
		cout << setw(24) << title;
		cout << setw(16) << auther;
		cout << setw(16) << number;
		cout << price << '\n';
	}
};

int main(int argc, char *argv[])
{
	Booklist book[2];
	
	for (int i = 0; i < 2; i++)
	{
		book[i].setBook();
		cin.ignore();	//ignore the last character input
	}
	
	cout << "Title\t\t\tAuther\t\tnumber\t\tprice\n";
	
	for (int j = 0; j < 2; j++)
	{
		book[j].showBook();
	}
	
	system("PAUSE");
	return 0;
}

