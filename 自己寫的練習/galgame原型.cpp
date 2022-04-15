#include <iostream>
#include <string>
using namespace std;

class Girl
{
	private:
		string name;
		int galpoints;
		string style;
	public:
		void set_girl(string n, int g, string s)
		{
			name = n;
			galpoints = g;
			style = s;
		}
		int pointcounting(int point)
		{
			galpoints += point;
		}
		void show_girl()
		{
			cout << name 
				 << galpoints 
				 << style 
				 << endl;
		}
};

int main()
{
	int point = 0;
	Girl Kizuna;
	
	Kizuna.set_girl("Kizuna", 0, "Tsundere");
	cin >> point;
	Kizuna.pointcounting(point);
	Kizuna.show_girl();
	
	return 0;
}
