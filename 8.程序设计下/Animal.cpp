//StudybarCommentBegin
#include <iostream>
//补充待添加的代码，即4个类的定义，1个全局函数
using namespace std;
//StudybarCommentEnd

class Animal{
protected:
	int weight;
	static int count;
public:
	Animal(int weight):weight(weight){}
	int getCount(){
		return count;
	}
	virtual int  getWeight()const{
		return weight;
	}
	virtual void spark() = 0;
}; 
int Animal::count = 0;
class Dog:public Animal{
public:
	Dog(int weight):Animal(weight){
		count++;
	}
	int  getWeight()const{
		return weight;
	}
	void spark(){
		cout<<"the dog is wa wa wa\n";
	}
}; 
class Cat:public Animal{
public:
	Cat(int weight):Animal(weight){
		count++;
	}
	int  getWeight()const{
		return weight;
	}
	void spark(){
		cout<<"the cat is miao miao\n";
	}
};

int totalWeight(const Animal& a, const Animal& b){
	return a.getWeight() + b.getWeight();
}
//StudybarCommentBegin
int main()
{
	Dog d(2);
	d.spark();
	Cat c(3);
	c.spark();
	cout<<"共有 "<<c.getCount()<<" 个动物"<<endl;
	cout<<"动物共 "<<totalWeight(d,c)<<" kg"<<endl;
	return 0;
}

//StudybarCommentEnd
