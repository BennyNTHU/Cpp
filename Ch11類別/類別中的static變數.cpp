#include <iostream>
using namespace std;

class Oddsum
{
	private:
	static int sum;
	public:
	static void addition(int n);
	void display();
};

int Oddsum::sum = 0;

void Oddsum::addition(int n)
{
	sum += n;
}

void Oddsum::display()
{
	cout << "sum = " << sum << endl;
}

int main(int argc, char *argv[])
{
	Oddsum a;
	for (int count = 1; count <= 100; count += 2)
		a.addition(count);
	
	a.display();
	
	system("PAUSE");
	return 0;
 } 
 
