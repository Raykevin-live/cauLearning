#include <iostream>
using namespace std;
class Human
{
protected:
	int age;
};
class student:protected Human {//公有继承
public:
	void showAge()
	{
	  cout<<"the student age is "<<age<<endl; // 调用基类的成员
	}
};
class Primary:public student //公有继承
{
public :
	void setAge(int a)
	{age=a;} // 调用Human类的成员
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
