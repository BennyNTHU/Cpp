#include <iostream>
#include <fstream>
using namespace std;

/*
	這裡的二進位檔指的是未格式化的二進位檔,這種檔案格式處理起來比文字檔更有效率
	我們可以用
	
	物件名稱.open("檔案名稱", ios::binary | ios::模式)
	
	來開啟一個二進位檔,模式可以是out(寫入),app(附加),in(讀取)
	如果只輸入ios::binary,預設為ofstream檔案且為out模式 
	如果已知檔案是二進位檔,可以只輸入ios::模式
	
	如果我們要寫入資料到二進位檔內,要用
	
	物件名稱.write(const char *緩衝區指標, 寫入長度)
	
	二進位檔最大的優點就是每一筆資料的長度在寫入時不受檔案格式限制,可以用上式自訂 
*/

class Student	//此類別的功能是當作寫入資料時要用的緩衝區 
{
	protected:
		int id;
		char name[40];
	
	public:
		int getid()
		{
			return id;
		}
		void setdata()
		{
			cout << "請輸入學號與姓名(輸入0 0 則結束): ";
			cin >> id >> name;
		}
};

int main(void)
{
	Student stuData;	//此物件會當作寫入檔案前的緩衝區 
	ofstream filePtr;	//建立輸出檔案物件 
	filePtr.open("D:\\MyDocuments\\Programs\\C++\\Ch15檔案管理\\15-4.dat", ios::binary);	//開啟輸出二進位檔 
	
	if (!filePtr)	//如果沒有成功開啟,filePtr會指向NULL 
	{
		cout << "open file ERROR" << endl;
		system("PAUSE");
		exit(0);	//異常結束程式 
	}
	else
	{
		while(1)
		{
			stuData.setdata();
			if (stuData.getid() != 0)
				filePtr.write((char*) &stuData, sizeof(stuData));
				//寫入資料,緩衝區指標當然是&stuData,每一筆寫入的長度設定為跟緩衝區剛好一樣 
			else
				break;
		}
	}
	
	filePtr.close();
	system("PAUSE");
	return 0;
}

