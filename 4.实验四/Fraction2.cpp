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
	
	int getMole()const{
		return _mole;
	}
	int getDeno()const{
		return _deno;
	}
	void Show()const{
		cout<<_mole<<"/"<<_deno;
	}
	double to_double()const{
		return _mole*1.0/_deno;
	}
	
	Fraction operator-(const Fraction& b)const{
		int deno = lcm(_deno, b._deno);
		int mole = _mole*(deno/_deno) - b._mole*(deno/b._deno);
		
		return Fraction(mole, deno);
	}
	Fraction operator+(const Fraction& b)const{
		int deno = lcm(_deno, b._deno);
		int mole = _mole*(deno/_deno) + b._mole*(deno/b._deno);
		
		return Fraction(mole, deno);
	}
	Fraction operator*(const Fraction& b)const{
		return Fraction(_mole*b._mole, _deno*b._deno);
	}			
	Fraction operator/(const Fraction& b)const{
		return Fraction(_mole*b._deno, _deno*b._mole);
	}
	bool operator==(const Fraction& b )const{
		return _mole==b._mole && _deno==b._deno;
	}
	bool operator!=(const Fraction& b )const{
		return !(*this==b);
	}
	bool operator>(const Fraction& b)const{
		Fraction c = b;
		return to_double() > c.to_double();
	}	
	bool operator<=(const Fraction& b)const{
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
    Fraction a(1, 2), b;
    Fraction const c(1,-2);
    cout << a << "\n" << b << "\n" << c << '\n';
    cin >> a >> b;
    
    if (c != b) 
        cout << "!=" << endl;
    else
    	cout<<"=="<<endl;
    	
    cout <<c<<" - "<<a<<" = "<< c - a <<endl ;
    return 0;
}     
//StudybarCommentEnd
