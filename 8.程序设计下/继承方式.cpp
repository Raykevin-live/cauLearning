#include <iostream>
using namespace std;
class Human
{
protected:
	int age;
};
class student:protected Human {//���м̳�
public:
	void showAge()
	{
	  cout<<"the student age is "<<age<<endl; // ���û���ĳ�Ա
	}
};
class Primary:public student //���м̳�
{
public :
	void setAge(int a)
	{age=a;} // ����Human��ĳ�Ա
};

int main()
{
	student jack;
//	jack.age = 12;
	jack.showAge();
	
	Primary  jessic;
//	jessic.age=12;
	jessic.showAge();
	jessic.setAge(10);
	jessic.showAge();
	return 0;
}
