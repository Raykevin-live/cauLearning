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
	int _mole; //分子 
	int _deno; //分母 
	
	friend void fswap(Fraction& a, Fraction& b);
	friend void printtest(Fraction& a);
	
	friend ostream& operator<<(ostream& os, const Fraction& x);
	friend istream& operator>>(istream& in, Fraction& x);
public:
	Fraction(int mole = 1, int deno = 1){
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
	void Show(){
		cout<<_mole<<"/"<<_deno;
	}
	double to_double(){
		return _mole*1.0/_deno;
	}
	
	Fraction operator-(const Fraction& b){
		int deno = lcm(_deno, b._deno);
		int mole = _mole*(deno/_deno) - b._mole*(deno/b._deno);
		return Fraction(mole, deno);
	}
	Fraction operator+(const Fraction& b){
		int deno = lcm(_deno, b._deno);
		int mole = _mole*(deno/_deno) + b._mole*(deno/b._deno);
		return Fraction(mole, deno);
	}
	Fraction operator*(const Fraction& b){
		return Fraction(_mole*b._mole, _deno*b._deno);
	}			
	Fraction operator/(const Fraction& b){
		return Fraction(_mole*b._deno, _deno*b._mole);
	}
	bool operator==(const Fraction& b ){
		return _mole==b._mole && _deno==b._deno;
	}
	bool operator!=(const Fraction& b ){
		return !(*this==b);
	}
	bool operator>(const Fraction& b){
		Fraction c = b;
		return to_double() > c.to_double();
	}	
	bool operator<=(const Fraction& b){
		return !(*this > b);
	}
};

void fswap(Fraction& a, Fraction& b){
	Fraction tmp = a;
	a = b;
	b = tmp;
}

ostream& operator<<(ostream& os, const Fraction& x){
	os<<x._mole<<"/"<<x._deno;
	return os;
}

istream& operator>>(istream& in, Fraction& x) {
    int mole, deno;
    in >> mole >> deno;
    Fraction temp(mole, deno);  // 通过构造函数处理符号和约分
    x._mole = temp.getMole();
    x._deno = temp.getDeno();
    return in;
}

//StudybarCommentBegin
int main(int argc, char *argv[]) {
    Fraction a(1,2),b,c(2);
    cout<<a<<"\n"<<b<<"\n"<<c<<'\n';
    cin>>a>>b;
//    if (a!=b)
//    {	cout<<"!="<<endl;
//    }
    cout<<a+b;		   
    return 1;
}
//StudybarCommentEnd
