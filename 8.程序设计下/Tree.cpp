//StudybarCommentBegin
#include<iostream>
#include <cstring>
using namespace std;
class Tree
{
	int age;
	int height;
public:
	void showTree()
	{cout<<"the tree's age="<<age<<", height="<<height<<endl;}
	void growing(int y,int d)
	{age+=y;height+=d;}
	Tree(int a,int d)
	{age=a;height=d;}
};
class Human
{
	int age;
	char name[20];
	Tree t;
public:
	int getAge()
	{return age;}
	char *getName()
	{return name;}
	Human(int a,char *n,int ta,int td):t(ta,td)
	{age=a;strcpy(name,n);}
};
//StudybarCommentEnd

class Farmer:public Human{
	int field;
public:
	Farmer(int age, char *name, int treeage, int height, int field):Human(age, name, treeage, height),field(field){}
	 
	int getField(){
		return field;
	}
};
//StudybarCommentBegin
int main()
{
	Farmer f(30,"jessic",5,2,100);
	cout<<"the farmer's name is "<<f.getName()<<endl;
	cout<<"and she is "<<f.getAge()<<" years old!"<<endl;
	cout<<"she has "<<f.getField()<<" fields"<<endl;
	return 0;
}
//StudybarCommentEnd
