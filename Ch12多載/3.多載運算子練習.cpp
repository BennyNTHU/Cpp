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
	/*	istream& 與 ostream& 是"一種運算元的型態"(比如cin是istream&型態,cout是ostream&型態)
		其他程式會看到不同的"運算元的型態"
		而設為friend是因為他需要直接輸出private中的資料
		多載不能改變運算子的用途,比方說>>左邊一定要是istream&型態
		你多載後>>的左邊也只能istream&型態(也就是說多載前後運算元左右程式碼的結構要相同) 
		但多載前>>可能只能處理int,double,char之類的資料型態
		多載完後>>就能拿來處理你自己定義的資料型態  
	*/ 
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
	Fracpri s1;
	cout << "請輸入帶分數(整數 分子 分母): ";
	
	cin >> s1;	// 多載 
	cout << "化簡後的帶分數為: " << s1 << endl;	// 多載 
	
	system ("PAUSE");
	return 0; 
}
