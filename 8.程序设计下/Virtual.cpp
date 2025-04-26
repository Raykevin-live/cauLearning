#include <iostream>

using namespace std;

class A{
	public:
		int a;
	virtual void print(){
		cout<<"a"<<endl;
	}
};

class B:public A{
	public:
		void print(){
			cout<<"b"<<endl;
		}
};

class C : public B{
	public:
		void print(){
			cout<<"c"<<endl;
		}
};
int main(){
	A* p = new C;
	p->print();
	
	
	return 0;
} 
