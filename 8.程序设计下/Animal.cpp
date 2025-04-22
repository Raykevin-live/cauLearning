//StudybarCommentBegin
#include <iostream>
//�������ӵĴ��룬��4����Ķ��壬1��ȫ�ֺ���
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
	cout<<"���� "<<c.getCount()<<" ������"<<endl;
	cout<<"���ﹲ "<<totalWeight(d,c)<<" kg"<<endl;
	return 0;
}

//StudybarCommentEnd
