#include <iostream>
#include <string>
using namespace std;

#define max 10
 
template <class TYPE> class Stack	//定義Stack類別範本,裡面會有通用的資料型態,以TYPE表示 
{
	private:
		TYPE st[max];			//堆疊空間 
		int ptr;				//堆疊指標 
	
	public:
		Stack() {ptr = 0;}		//建立者函數 
		void push(TYPE obj);	//推入資料 
		TYPE pop();				//彈出資料 
};

template <class TYPE> void Stack<TYPE>::push(TYPE obj)	//類別範本的函數,注意此時Stack後面要加<TYPE> 
{
	string error = "堆疊滿了!\n";
	
	if (ptr == max)		//例外出現:堆疊滿了 
		throw error;	//將記錄錯誤訊息的字串變數丟給主程式的catch 
		
	st[ptr]= obj;		//如果沒有出現例外就推入資料 
	ptr++; 				//指標+1 
}

template <class TYPE> TYPE Stack<TYPE>::pop()
{
	string error = "堆疊空了!\n";
	
	if (ptr == 0)
		throw error;	//將記錄錯誤訊息的字串變數丟給主程式的catch
		
	ptr--;				//指標-1
	return st[ptr];		//傳回被彈出的資料 
}

int main(void)
{
	int i;
	
	try		//可能出現例外之處(堆疊可能空了或滿了) 
	{
		Stack<int> iStack;		//建立整數的堆疊 
		Stack <char> cStack;	//建立字元堆疊 
		
		iStack.push(10);
		iStack.push(20);
		cStack.push('a');
		cStack.push('b');
		
		for (i=2; i>=0; i--) 	//從整數堆疊取出東西 
			cout << "iStack[" << i << "] = " << iStack.pop() << '\t';
		cout << endl;
		
		for (i=2; i>=0; i--) 	//從字元堆疊取出東西 
			cout << "cStack[" << i << "] = " << cStack.pop() << '\t';
		cout << endl;	
	}
	catch (string str)	//有例外時執行 
	{
		cout << str;
	}
	
	system ("PAUSE");
	return 0;
}

