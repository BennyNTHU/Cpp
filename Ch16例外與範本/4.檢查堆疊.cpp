#include <iostream>
using namespace std;

#define MAX 5

/*
	類別也可以使用例外處理,此時try和catch位在主程式,throw位在類別內的函數
	當例外出現時,throw回丟回一個空的類別給catch用,稱為錯誤處理類別 
*/
 
class Stack
{
	private:
		int st[MAX];
		int top;
	
	public:
		class Empty {};			//Empty錯誤處理類別,Full跟Empty是包含在Stack的空類別 
		class Full {};			//Full錯誤處理類別 
		Stack() {top = -1;}
		void push (int i)		//推入資料 
		{
			if (top >= MAX-1)	//如果堆疊滿了 
				throw Full();	//把例外類別丟去給47行的catch處理 
			st[++top] = i;		//堆疊指標+1 
		}
		int pop()	//彈出資料 
		{
			if (top < 0)		//如果堆疊是空的 
				throw Empty();	//把例外類別丟給51行的catch處理 
			return st[top--];	//堆疊指標-1 
		}
};

int main(void)
{
	Stack s;
	
	try
	{
		s.push(10);					// top=0; st[0]=10
		s.push(40);					// top=1; st[1]=40
		cout << s.pop() << endl;	//傳回st[1]=40; top=0 
		cout << s.pop() << endl;	//傳回st[0]=10; top=-1 
		cout << s.pop() << endl;	//top<0; throw Empty()
	}
	catch (Stack::Full)	//例外處理 
	{
		cout << "堆疊滿了!" << endl; 
	}
	catch (Stack::Empty)
	{
		cout << "堆疊空了!" << endl; 
	}
	
	system("PAUSE");
	return 0;
}

