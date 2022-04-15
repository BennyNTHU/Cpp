#include <iostream>
#include <fstream>
using namespace std;

const char filename[] = "D:\\MyDocuments\\Programs\\C++\\Ch15檔案管理\\15-5.dat";

class Student	//此類別的功能是當作寫入資料時要用的緩衝區 
{
	protected:
		int id;
		char name[40];
	
	public:
		int getId();
		void setData();
		void showData();
		void write();
		void append();
		void read();
};

int Student::getId()
{
	return id;
}

void Student::setData()
{
	cout << "請輸入學號與姓名(輸入0 0 則結束): ";
	cin >> id >> name;
}

void Student::showData()
{
	cout << id << '\t' <<
	name << endl;
}

void Student::write()
{
	ofstream filePtr;
	filePtr.open(filename, ios::binary | ios::out);	//開啟輸出二進位檔 
	
	if (!filePtr)	//如果沒有成功開啟,filePtr會指向NULL 
	{
		cout << "open file ERROR" << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		while(1)
		{
			setData();
			if (getId() != 0)
				filePtr.write((char*) this, sizeof(*this));	//寫入資料,緩衝區指標當然是&stuData,每一筆寫入的長度設定為跟緩衝區剛好一樣 
			else
				break;
		}
	}
	filePtr.close();
}

void Student::append()
{
	ofstream filePtr;
	filePtr.open(filename, ios::binary | ios::app);	//開啟輸出二進位檔 
	
	if (!filePtr)	//如果沒有成功開啟,filePtr會指向NULL 
	{
		cout << "open file ERROR" << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		while(1)
		{
			setData();
			if (getId() != 0)
				filePtr.write((char*) this, sizeof(*this));	//寫入資料,緩衝區指標當然是&stuData,每一筆寫入的長度設定為跟緩衝區剛好一樣 
			else
				break;
		}
	}
	filePtr.close();
}

void Student::read()
{
	ifstream filePtr;
	filePtr.open(filename, ios::binary | ios::in);	//開啟輸入檔 
	
	if (!filePtr)	//如果沒有成功開啟,filePtr會指向NULL 
	{
		cout << "open file ERROR" << endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		filePtr.read((char*) this, sizeof(*this));	//不管有沒有東西,先讀一筆緩衝區大小的資料
		while (!filePtr.eof())	//只要檔案物件指標還沒指到檔案結束位置 
		{
			showData();	//顯示讀到的東西 
			filePtr.read((char*) this, sizeof(*this));	//再讀取下一筆 
		}
	}
	filePtr.close();
}

int main(void)
{
	Student stu;
	char n;
	
	while (1)
	{
		cout << "1.寫入 2.附加 3.讀取 0.結束: ";
		cin >> n;
		
		switch(n)
		{
			case '1':
				stu.write();
				break;
			case '2':
				stu.append();
				break;
			case '3':
				stu.read();
				break;
			case '0':
				exit(0);
			default:
				;
		 } 
	}
	
	system("PAUSE");
	return 0;
}
