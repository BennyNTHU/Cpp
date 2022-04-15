#include <iostream>
#include <cmath>
using namespace std;

class Fracpri
{
	private:
	int whole;
	int numer;
	int denom;
	
	public:
	int getgcd();
	friend istream& operator >> (istream& in, Fracpri& obj);		// 多載>>運算子,使其能藉由cin輸入給自訂類別Fracpri 
	friend ostream& operator << (ostream& out, Fracpri& obj);		// 多載<<運算子,使其能藉由cout輸出自訂類別Fracpri 
	bool operator > (Fracpri);	//多載單運算元符號">"給Fracpri,並傳回bool資料型態 
};

int Fracpri::getgcd()	//使用輾轉相除法獲得最大公因數 
{
	int max = 0;
	int min = 0;
	int rmd = 0;
	
	max = denom;
	min = numer;
	rmd = min;
	
	while (rmd != 0)
	{
		rmd = max%min;
		if (rmd == 0)
			break;
		max = min;
		min = rmd;
	}
	
	return min;
}

bool Fracpri::operator > (Fracpri obj)
{
	int numer1, numer2;
	
	numer1 = whole * denom + numer;
	numer2 = obj.whole * obj.denom + obj.numer;
	
	if ((numer1*obj.denom) > (numer2*denom))
		return true;
	else
		return false;
} 

istream& operator >> (istream& in, Fracpri& obj)	// 主程式中,cin會丟給"in",  s1會丟給"obj"
{
	 
	in >> obj.whole >> obj.numer >> obj.denom;	// 定義Fracpri資料型態對>>的運算規則 
	
	obj.whole = abs(obj.whole);
	obj.numer = abs(obj.numer);
	obj.denom = abs(obj.denom);
	
	return in;
}

ostream& operator << (ostream& out, Fracpri& obj)	//// 主程式中,cout會丟給"in",  s1會丟給"obj" 
{
	int gcd = obj.getgcd();
	
	obj.numer = obj.numer / gcd;	//約分 
	obj.denom = obj.denom / gcd;
	
	out << obj.whole << ' ' << obj.numer << '/' << obj.denom;	// 定義Fracpri資料型態對<<的運算規則
	
	return out;
}

int main(void)
{
	Fracpri s1, s2;
	
	cout << "請輸入帶分數1(整數 分子 分母): ";
	cin >> s1;	// 多載
	cout << "請輸入帶分數2(整數 分子 分母): ";
	cin >> s2;	// 多載
	
	if (s1 > s2)
		cout << "帶分數1 (" << s1 << ") > " << "帶分數2 (" << s2 << ')' << endl;
	else
		cout << "帶分數1 (" << s1 << ") <= " << "帶分數2 (" << s2 << ')' << endl;
		
	system ("PAUSE");
	return 0; 
}
