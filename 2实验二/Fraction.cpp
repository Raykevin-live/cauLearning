#include <iostream>
#include <cmath>
#include <string>

using namespace std; 

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


class Fraction{
private:
	int _mole;
	int _deno;
public:
	Fraction(int mole = 0, int deno = 1){
		//处理分子分母负号问题 
		if(mole*deno<0){
			mole = -abs(mole);
			deno = abs(deno);
		}
		else if(mole<0 && deno<0){
			mole = abs(mole);
			deno = abs(deno);	
		}
		//处理最简分数
		int gcbNum = gcd(mole, deno);
		mole /= gcbNum;
		deno /= gcbNum;
		//赋值 
		_mole = mole;
		_deno = deno;
	}
	Fraction(double x){
		int sign = 1;
		while(int(x)!=x){
			x *= 10;
			sign *= 10;
		}
			
		int gcbNum = gcd(int(x), sign);
		x /= gcbNum;
		sign /= gcbNum;
		//赋值 
		_mole = int(x);
		_deno = sign;
	}
	int getMole(){
		return _mole;
	}
	int getDeno(){
		return _deno;
	}
	void show(){
		cout<<_mole<<"/"<<_deno;
	}
	double to_double(){
		return _mole*1.0/_deno;
	}
};


int myabs(int  x){
	return abs(x);
}
double myabs(double  x){
	return fabs(x);
}
Fraction myabs(Fraction x){
	return Fraction(abs(x.getMole()), x.getDeno());
}

void ifLessSwap(Fraction &a,Fraction &b){
	if(a.to_double() < b.to_double()){
		Fraction tmp = Fraction(a.getMole(), a.getDeno());
		a = b;
		b = tmp;
	}
}
//StudybarCommentBegin
int main()
{
	int a,b,c,d;
	double r;
	cin>>a>>b>>c>>r;
	Fraction f1(a,b),f2(c),f3(r);
	cout<<f1.to_double()<<endl;
	
	f1.show(); cout<<endl;
	f2.show(); cout<<endl;
	f3.show(); cout<<endl;	
	
	ifLessSwap(f1,f3);
	
	f1.show(); cout<<endl;
	f3.show(); cout<<endl;	
}
//StudybarCommentEnd

