#include <iostream>
using namespace std;

int main (void)
{	
	char choose = '0';
	
	cout << "人家才不想當你女朋友呢!";
	cout << '\n' << "請選擇\n";
	cout << "A.抱緊處理 B.推倒她\n : ";
	
	while ((choose != 'A')||(choose != 'B')) 
	{
		cin >> choose;
		if ( (choose != 'A') || (choose != 'B') )
			cout << "請輸入A或B : ";
	}
	
	if (choose = 'A')
		cout << "攻略成功!";
	else
		cout << "攻略失敗!";
		
	return 0;
}
