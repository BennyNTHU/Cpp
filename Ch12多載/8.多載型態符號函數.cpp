#include <iostream>
using namespace std;

/*	更篈才腹ㄧ计:
	笿更才腹ㄧ计诀璶琌戈篈┘锣传丁
	
								ヘ()竚		ㄓ方(玡)竚 
	1.膀セ篈锣膀セ篈:		C++ずㄧ计         C++ずㄧ计 
	2.膀セ篈锣摸篈:		ㄏノミㄧ计 		礚 
	3.摸篈锣膀セ篈:		礚					ㄏノ更篈才腹ㄧ计 
	4.摸篈锣摸篈:		ㄏノミㄧ计		ㄏノ更篈才腹ㄧ计
	
	1.玡碞厩筁ノint(), float()单单暗 
	2.籔ミㄧ计Τ闽 
	┮и璶栋い癚阶3籔4,琌3.ㄒ,и盢璹Distance摸篈锣传float篈
*/

const float MTF = 3.280833f;

class Distance
{
	private:
	int feet;
	float inch;
	
	public:
	Distance(int f, float in);
	operator float();	//更篈才腹
	friend ostream & operator << (ostream& out, Distance& obj);	//更<<才腹块 
};

Distance::Distance(int f, float in)
{
	feet = f;
	inch = in;
}

/*	更float篈ㄧ计,更玡ぃэ跑,
	┮硂柑更,float()ㄧ计临琌ゲ斗肚float戈篈
*/ 
Distance::operator float()	 
{
	float fracfeet = inch / 12;
	fracfeet += float(feet);
	
	return fracfeet / MTF;
}

ostream & operator << (ostream& out, Distance& obj)	//更<<笲衡才腹 
{
	out << obj.feet << " 璣 " << obj.inch << " 璣";
	return out; 
}

int main(void)
{
	Distance d(11, 5.79499f);	//㊣ミ 
	float m;					//疊翴计跑计m 
	
	m = d;	// d㊣更floatㄧ计,盢肚メ倒m 
	
	cout << d << " = " << m << " そへ" << endl;	//更<<才腹 
	
	system ("PAUSE");
	return 0; 
}
