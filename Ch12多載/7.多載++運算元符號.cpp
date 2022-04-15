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
	Fracpri() {}	//無參數建立者
	Fracpri(int, int, int);	//有參數建立者,建立者函數多載 
	int getgcd();
	friend istream& operator >> (istream& in, Fracpri& obj);		// 多載>>運算子,使其能藉由cin輸入給自訂類別Fracpri 
	friend ostream& operator << (ostream& out, Fracpri& obj);		// 多載<<運算子,使其能藉由cout輸出自訂類別Fracpri 
	Fracpri operator ++ ();	//多載前置運算元符號"++"給Fracpri,並傳回Fracpri資料型態
	Fracpri operator ++ (int);	//多載後置運算元符號"++"給Fracpri,並傳回Fracpri資料型態
	//此時也用到了函數成員多載的概念 
};

Fracpri::Fracpri(int a, int b, int c)
{
	whole = a;
	denom = b;
	numer = c;	
}
 
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

Fracpri Fracpri::operator ++ ()	//多載前置++號 
{
	return Fracpri(++whole, denom, numer);
}

Fracpri Fracpri::operator ++ (int)	//多載後置++號
{
	return Fracpri(whole++, denom, numer);
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
	Fracpri s1, s2, s3, s4;
	
	cout << "請輸入帶分數1(整數 分子 分母): ";
	cin >> s1;	// 多載
	cout << "請輸入帶分數2(整數 分子 分母): ";
	cin >> s2;	// 多載
	
	s3 = ++s1;	// 多載
	s4 = s2++;	// 多載
	
	cout << "\ns3 = ++s1 = " << s3;
	cout << "\n 運算後 s1 = " << s1 << endl;
	cout << "\ns4 = s2++ = " << s4;
	cout << "\n 運算後 s2 = " << s2 << endl;
	
	system ("PAUSE");
	return 0; 
}
