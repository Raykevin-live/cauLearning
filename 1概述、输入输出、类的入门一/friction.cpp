#include <iostream>

using namespace std;

int gcd(int a, int b){
	a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    
	if( b > a){
		int tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0) {
        int remainder = a % b;
        a = b;                 
        b = remainder;         
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0; 
    return (a * b) / gcd(a, b);     
}

int main(){
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	
	int lcmNum= lcm(b, d);
//	cout<<"lcmNum "<<lcmNum<<endl;
	int  Molecular = a*(lcmNum/b) + c*(lcmNum/d);
//	cout<<"Molecular "<<Molecular<<endl; 
	int gcbNum = gcd(lcmNum, Molecular);
//	cout<<"gcbNum "<<gcbNum<<endl;
	cout<<Molecular/gcbNum<<"/"<<lcmNum/gcbNum<<endl;
	
	return 0;
}
