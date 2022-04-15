#include <iostream>
using namespace std;

/*	更篈才腹ㄧ计:
	笿更才腹ㄧ计诀璶琌戈篈┘锣传丁
	
								ヘ()竚		ㄓ方(玡)竚 
	1.膀セ篈锣膀セ篈:		C++ずㄧ计         C++ずㄧ计 
	2.膀セ篈锣摸篈:		ㄏノミㄧ计 		礚 
	3.摸篈锣膀セ篈:		礚					ㄏノ更篈才腹ㄧ计 
	4.摸篈锣摸篈:		ㄏノミㄧ计		ㄏノ更篈才腹ㄧ计
	
	セ祘Α量秆2,ノミㄧ计更盢膀セ戈篈锣璹摸戈篈 
*/

const float MTF = 3.280833f;

class Distance
{
	private:
	int feet;
	float inch;
	
	public:
	Distance(int f, float in);	// ㄢ把计ミ 
	Distance(float meter);	// 把计ミ 
	friend ostream & operator << (ostream& out, Distance& obj);	//更<<才腹块 
};

Distance::Distance(int f, float in)	// ㄢ把计ミ 
{
	feet = f;
	inch = in;
}

Distance::Distance(float meter)	 // 把计ミ,穦ノ硂ㄓ暗锣传戈篈 
{
	float fracfeet = MTF * meter;
	feet = (int)fracfeet;
	inch = 12 * (fracfeet - feet);
}

ostream & operator << (ostream& out, Distance& obj)	//更<<笲衡才腹 
{
	out << obj.feet << " 璣 " << obj.inch << " 璣";
	return out; 
}

int main(void)
{
	Distance d(11, 5.79499f);	//㊣ㄢ把计ミ 
	float m = 3.5f;				
	
	d = m;	// ㊣d跑计ミㄧ计,m把计メ,盢肚﹚倒d 
	
	cout << d << " = " << m << " そへ" << endl;	//更<<才腹 
	
	system ("PAUSE");
	return 0; 
}
