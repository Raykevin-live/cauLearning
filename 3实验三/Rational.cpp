#include <iostream>
#include <iomanip>

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


class Rational{
private:
	int _mole;
	int _deno;
	friend void fswap(Rational& a, Rational& b);
	friend void printtest(Rational& a);
	
public:
	friend Rational operator+(const Rational& a, const Rational& b);
	friend Rational operator-(const Rational& a, const Rational& b);
	friend Rational operator*(const Rational& a, const Rational& b);
	friend Rational operator/(const Rational& a, const Rational& b);
public:
	Rational(int mole = 0, int deno = 1){
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
	Rational(double x){
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
	void printFormal(){
		cout<<_mole<<"/"<<_deno<<endl;
	}
	void printBoth(){
		cout<<"the Formal format of the rational is : ";
		printFormal();
		cout<<"the Fixed format of the rational is : ";
		cout<<std::fixed<<std::setprecision(2)<<to_double()<<endl;
	}
	double to_double(){
		return _mole*1.0/_deno;
	}
	
	
	Rational operator-(const Rational& b){
		int deno = lcm(_deno, b._deno);
		int mole = _mole*(deno/_deno) - b._mole*(deno/b._deno);
		return Rational(mole, deno);
	}
	Rational operator+(const Rational& b){
		int deno = lcm(_deno, b._deno);
		int mole = _mole*(deno/_deno) + b._mole*(deno/b._deno);
		return Rational(mole, deno);
	}
	Rational operator*(const Rational& b){
		return Rational(_mole*b._mole, _deno*b._deno);
	}			
	Rational operator/(const Rational& b){
		return Rational(_mole*b._deno, _deno*b._mole);
	}
	bool operator==(const Rational& b ){
		return _mole==b._mole && _deno==b._deno;
	}
	bool operator!=(const Rational& b ){
		return !(*this==b);
	}
	bool operator>(const Rational& b){
		Rational c = b;
		return to_double() > c.to_double();
	}	
	bool operator<=(const Rational& b){
		return !(*this > b);
	}
	
	void add(const Rational& a, const Rational& b){
		Rational tmp = a + b;
		_mole = tmp._mole;
		_deno = tmp._deno;
	}
	void minus(const Rational& a, const Rational& b){
		Rational tmp = a - b;
		_mole = tmp._mole;
		_deno = tmp._deno;
	}
	void multi(const Rational& a, const Rational& b){
		Rational tmp = a * b;
		_mole = tmp._mole;
		_deno = tmp._deno;
	}
	void divide(const Rational& a, const Rational& b){
		Rational tmp = a / b;
		_mole = tmp._mole;
		_deno = tmp._deno;
	}
	
};

Rational operator+(const Rational& a, const Rational& b){
		int deno = lcm(a._deno, b._deno);
		int mole = a._mole*(deno/a._deno) + b._mole*(deno/b._deno);
		return Rational(mole, deno);
}
Rational operator-(const Rational& a, const Rational& b){
		int deno = lcm(a._deno, b._deno);
		int mole = a._mole*(deno/a._deno) - b._mole*(deno/b._deno);
		return Rational(mole, deno);
}
Rational operator*(const Rational& a, const Rational& b){
	return Rational(a._mole*b._mole, a._deno*b._deno);
}
Rational operator/(const Rational& a, const Rational& b){
		return Rational(a._mole*b._deno, a._deno*b._mole);
}
//StudybarCommentBegin
int main()
{
    int firstN,firstD,secondN,secondD;
    char op;
    
//    cout<<"Please input the numerator of first Rational: ";
    cin>>firstN;
//    cout<<"Please input the denominator of first Rational: ";
    cin>>firstD;
//    cout<<"Please input the numerator of second Rational: ";
    cin>>secondN;
//    cout<<"Please input the denominator of second Rational: ";
    cin>>secondD;

    
    Rational r1(firstN,firstD),r2(secondN,secondD),r3;

    
    cin>>op;
    
    cout<<"the Formal format of the first rational is : ";
    r1.printFormal();
    cout<<"the Formal format of the second rational is : ";
    r2.printFormal();
    cout<<endl;
    
    switch(op)
    {
        case '+' :
            r3.add(r1,r2);
            r3.printBoth();
            break;
        case '-' :
            r3.minus(r1,r2);
            r3.printBoth();
            break;
        case '*':
            r3.multi(r1,r2);
            r3.printBoth();
            break;
        case '/':
            r3.divide(r1,r2);
            r3.printBoth();
            break;
        default:
            cout<<"Invalid operator!";
    }
    
    return 0;
}
//StudybarCommentEnd
