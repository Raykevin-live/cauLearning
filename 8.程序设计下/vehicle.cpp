//StudybarCommentBegin
#include<iostream>
#include<string.h>
using namespace std;
class vehicle   
{ protected:
   char  carname[20];    //����
   char  name[20];        //������
   char  date[20];         //��������
public:
	vehicle(char cn[20],char na[20],char d[20])  //�����Ĺ��캯��
	{   strcpy(carname,cn);
		strcpy(name,na);
		strcpy(date,d);
	}

//StudybarCommentEnd
virtual void show(){
	
}

//StudybarCommentBegin
};
class car:public vehicle       //������С�����Ķ���
{protected:
  int zws;                  //��λ��
public:
	car(char cn[20],char na[20],char d[20],int zw):vehicle(cn,na,d)
	{		zws=zw;	}
	virtual void show()override
	{	cout<<name<<" "<<carname<<" "<<date<<" "<<zws<<endl;}
};
class truck:public vehicle   //����������Ķ���
{
protected:
	double dw;     //��λ
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
