#include <iostream>

using namespace std; 

template<class T>
T abs(T x){
	return x>=0?x:-x;
}

int main()
{
	int n=-5;
	double d=-5.5;
	cout<<abs(n)<<endl;
	cout<<abs(d)<<endl;
	return 0;
}
