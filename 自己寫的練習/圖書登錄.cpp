#include <iostream>
#include <iomanip>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

struct Booklist
{
	char title[25];
	char auther[9];
	char number[11];
	float price;
};

void getBook(Booklist*);
void showBook(const Booklist []);

int main(void)
{
	Booklist book[2];
	
	for (int i = 0; i < 2; i++)
	{
		getBook(&book[i]);
		cin.ignore();
	}
	
	cout << "書名\t\t\t作者\t書號\t定價\n";
	showBook(book);
	
	system("PAUSE");
	return 0; 
} 

void getBook(Booklist *b1)
{
	
	cout << "Title:";
	cin.getline(b1->title, 24);
	cout << "Auther:";
	cin.getline(b1->auther, 8);
	cout << "Number:";
	cin.getline(b1->number, 10);
	cout << "Price";
	cin >> b1->price;

	cout << endl;

}

void showBook(const Booklist b[])
{
	cout.precision(2);
	cout.setf(ios::fixed|ios::left);
	
	for (int j = 0; j < 2; j++)
	{
		cout << setw(24) << b[j].title;
		cout << setw(8) << b[j].auther;
		cout << setw(12) << b[j].number;
		cout << b[j].price << '\t';	
		cout << endl;
	}
	
}

