//StudybarCommentBegin
#include<iostream>
#include<string.h>
using namespace std;
class vehicle   
{ protected:
   char  carname[20];    //车名
   char  name[20];        //车主名
   char  date[20];         //购买日期
public:
	vehicle(char cn[20],char na[20],char d[20])  //汽车的构造函数
	{   strcpy(carname,cn);
		strcpy(name,na);
		strcpy(date,d);
	}

//StudybarCommentEnd
virtual void show(){
	
}

//StudybarCommentBegin
};
class car:public vehicle       //派生类小汽车的定义
{protected:
  int zws;                  //座位数
public:
	car(char cn[20],char na[20],char d[20],int zw):vehicle(cn,na,d)
	{		zws=zw;	}
	virtual void show()override
	{	cout<<name<<" "<<carname<<" "<<date<<" "<<zws<<endl;}
};
class truck:public vehicle   //派生类货车的定义
{
protected:
	double dw;     //吨位
public:
	truck(char cn[20],char na[20],char d[20],double z):vehicle(cn,na,d)
	{		dw=z;	}
	virtual void show() override
	{	cout<<name<<" "<<carname<<" "<<date<<" "<<dw<<endl;}
};
int main()
{  
	car A("Benz","Kaka","2016-5-5",5);
	truck B("Dongfeng","Yua","2015-1-20",5.5);
	vehicle *p;
	p=&A;
	p->show();
	p=&B;
	p->show();
	return 0;
}

//StudybarCommentEnd
