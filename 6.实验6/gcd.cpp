#include <iostream>

using namespace std;

int gcd(int a, int b){
	int t;
	while(b !=0){
		t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main(){
	 
	cout<<gcd(-4,-1)<<endl;
	
	return 0;
} 
