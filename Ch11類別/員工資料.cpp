#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
	private:
	int EmpId;
	char name[20];
	
	public:
	void inputEmp();
	void outputEmp();
	Employee()
	{
		EmpId = 0;
		strcpy (name, "ZZZ");
	}
	Employee (int id, char *n)
	{
		EmpId = id;
		strcpy (name, n);
	}
};

void Employee::inputEmp()
{
	cout << "EmpID:" << endl;
	cin >> EmpId;
	cout << "EmpName:" << endl;
	cin >> name;
}
void Employee::outputEmp()
{
	cout << "EmpID:" << EmpId << endl;
	cout << "EmpName:" << name << endl;
}

int main(int argc, char *argv[])
{
	Employee emp1;
	Employee emp2 (23, "TOM");
	Employee emp3;
	
	emp1.outputEmp();
	emp2.outputEmp();
	cout << endl;
	emp3.inputEmp();
	emp3.outputEmp();
	
	system("PAUSE");
	return 0;
}

