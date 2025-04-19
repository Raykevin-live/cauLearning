//StudybarCommentBegin
#include <iostream>
using namespace std;
class Telephone
{
protected :
	int number;
public:
	Telephone()
	{number=1234;}
	Telephone(int n)
	{number=n;}
	void showNumber()
	{cout<<"my phone number is: "<<number<<endl;}
	void call()
	{cout<<"the phone is calling \n";}
};
class Mobile:public Telephone
{
	char *type;
	int cost;

public:
	Mobile();
	Mobile(char *t,int c,int n);
	void message()
	{cout<<number<<"\t"<<type<<"\tmessage send\n ";}
	friend int operator<(Mobile &x1,Mobile &x2);
};

//StudybarCommentEnd
Mobile::Mobile()
:Telephone(),type("samsung"), cost(0)
{}
Mobile::Mobile(char *t,int c,int n):Telephone(n){
	type = t, cost = c;
}
int operator<(Mobile &x1,Mobile &x2){
	return x1.number < x2.number;
}


//StudybarCommentBegin
int main()
{
	Mobile m1;
	Mobile m2("samsung",3500,1321);
	if(m1<m2)
		m1.message();
	else
		m2.message();
	return 0;
}    

//StudybarCommentEnd


