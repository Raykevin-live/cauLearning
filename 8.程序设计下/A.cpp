#include <iostream>
using namespace std;
class A
{ 
	float x, y;
public:
	A(float a=0, float b=0){ x=a; y=b; }
	void set(float a, float b){ x=a; y=b; }
	void show(){ cout<<x<<'\t'<<y<<endl; }
};
int main()
{ 
	A a(2,3);
	a.set(20 , 30);
	a.show( );
	return 0;
}
