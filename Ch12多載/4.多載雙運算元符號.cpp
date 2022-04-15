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
	Fracpri operator + (Fracpri);	//多載雙運算元符號"+"給Fracpri,並傳回Fracpri資料型態 
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

Fracpri Fracpri::operator + (Fracpri obj)	//多載雙運算元符號+ 
{
	/*	在主程式中,s1呼叫了"+"函數並以s2為參數傳進這裡的obj
		所以在這裡看到的numer, denom, 其實是呼叫者(s1)的資料成員
		obj.numer, obj.denom, obj.whole是參數(s2)的資料成員
		此函數回傳temp回去 
	*/ 
	Fracpri temp;
	
	int t = (numer * obj.denom + obj.numer * denom);
	
	temp.denom = denom * obj.denom;
	temp.numer = t % temp.denom;
	temp.whole = whole + obj.whole + (t / temp.denom);
	
	return temp;
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
	Fracpri s1, s2, s3;
	
	cout << "請輸入帶分數1(整數 分子 分母): ";
	cin >> s1;	// 多載
	cout << "請輸入帶分數2(整數 分子 分母): ";
	cin >> s2;	// 多載
	
	/*	s1呼叫了"+"函數,並以s2為參數傳遞進"+"裡面
		C++會自動藉由"="將回傳值指定給s3("="是不需要被多載的) 
	*/ 
	s3 = s1 + s2;	 
	
	cout << "帶分數1 + 帶分數2 = " << s1 << " + " << s2 << " = " << s3 << endl;	// 多載 
 
	system ("PAUSE");
	return 0; 
}
