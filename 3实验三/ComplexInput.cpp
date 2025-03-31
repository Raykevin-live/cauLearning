#include<iostream>
#include<iomanip>
#include <cmath>

using namespace std;

class Cmycomplex{
private:
	double _real;
	double _imag;
	friend Cmycomplex operator+(const Cmycomplex& cplx, double x);
	friend Cmycomplex operator+(double x, const Cmycomplex& cplx);
	friend std::ostream& operator<<(std::ostream& os, const Cmycomplex& cplx);
	friend std::istream& operator>>(std::istream& is, Cmycomplex& cplx);
	friend Cmycomplex operator*( double x, const Cmycomplex& cplx);
	friend Cmycomplex operator/( double x, const Cmycomplex& cplx);
public:
	Cmycomplex(double real = 0, double imag = 0){
		_real = real;
		_imag = imag;
	}
	
//	void Show(){
//		cout <<setiosflags(ios::fixed); 
//		if(_imag<0){
//			cout<<"("<<setprecision(2)<<_real<<setprecision(2)<<_imag<<"i)"<<endl;
//		}
//		else if(_imag==0){
//			cout<<setprecision(2)<<_real<<endl;
//		}
//		else{
//			cout<<"("<<setprecision(2)<<_real<<"+"<<setprecision(2)<<_imag<<"i)"<<endl;
//		}
//	}
	
	void Show(){
		if(_imag<0){
			cout<<"("<<_real<<_imag<<"i)"<<endl;
		}
		else{
			cout<<"("<<_real<<"+"<<_imag<<"i)"<<endl;
		}
	}
	
	double GetReal(){
		return _real;
	} 
	double GetImaginary(){
		return _imag;
	}
	Cmycomplex Add(const Cmycomplex& x){
		_real += x.	_real;
		_imag += x._imag;
		return *this;
	}
	Cmycomplex operator+(const Cmycomplex& x)const{
		return Cmycomplex(_real+x._real, _imag+x._imag);
	}
	Cmycomplex operator-(const Cmycomplex& x)const{
		return Cmycomplex(_real-x._real, _imag-x._imag);
	}
	Cmycomplex operator*(const Cmycomplex& x)const{
		return Cmycomplex(_real*x._real-_imag*x._imag, _real*x._imag+_imag*x._real);
	}
	Cmycomplex operator/(const Cmycomplex& x)const{
		double newReal = (_real*x._real+_imag*x._imag)/(x._real*x._real + x._imag*x._imag);
		double newImag = (_imag*x._real-_real*x._imag)/(x._real*x._real + x._imag*x._imag);
		return Cmycomplex(newReal, newImag);
	}
	void Set(double real, double imag){
		_real = real;
		_imag = imag;
	}
	bool operator==(const Cmycomplex& x){
		return _real==x._real && _imag == x._imag;
	}
	
	bool operator!=(const Cmycomplex& x){
		return _real!=x._real || _imag != x._imag;
	}
//	Cmycomplex sqrt(){
//		double newReal = std::sqrt((_real+std::sqrt(_real*_real+_imag*_imag))/2);
//		double newImag = _imag/std::sqrt(2*_real+2*std::sqrt(_real*_real+_imag*_imag));
//		return Cmycomplex(newReal, newImag);
//	}

	Cmycomplex sqrt() const {
        double a = _real;
        double b = _imag;
        double r = std::sqrt(a * a + b * b);

        if (b == 0) {
            if (a >= 0) {
                return Cmycomplex(std::sqrt(a), 0);
            } else {
                return Cmycomplex(0, std::sqrt(-a));
            }
        }

        double real_part = std::sqrt((r + a) / 2.0);
        double imag_sign = (b < 0) ? -1.0 : 1.0;
        double imag_part = imag_sign * std::sqrt((r - a) / 2.0);

        return Cmycomplex(real_part, imag_part);
    }
	double getReal()const{
		return _real;
	}
	double getImaginary()const{
		return _imag;
	}
};

Cmycomplex operator+(const Cmycomplex& cplx, double x){
		return Cmycomplex(cplx._real+x, cplx._imag);
}
Cmycomplex operator+(double x, const Cmycomplex& cplx){
		return Cmycomplex(cplx._real+x, cplx._imag);
}
Cmycomplex operator*( double x, const Cmycomplex& cplx){
		return Cmycomplex(cplx._real*x, cplx._imag*x);
}
Cmycomplex operator/( double x, const Cmycomplex& cplx){
		return Cmycomplex(cplx._real/x, cplx._imag/x);
}	
std::ostream& operator<<(std::ostream& os, const Cmycomplex& cplx) {
	if(cplx._imag!=0){
		cout <<setiosflags(ios::fixed); 
	}

	if(cplx._imag<0){
		os<<setprecision(2)<<cplx._real<<setprecision(2)<<cplx._imag<<"i";
	}
	else if(cplx._imag==0){
		os<<cplx._real;
	}
	else{
		os<<setprecision(2)<<cplx._real<<"+"<<setprecision(2)<<cplx._imag<<"i";
	}
    return os; 
}
std::istream& operator>>(std::istream& is, Cmycomplex& cplx) {
        is >> cplx._real>>cplx._imag;
        return is;
}	





//StudybarCommentBegin
void CN() { //ComplexNumber
	ComplexNumber cn1, cn2;
	std::cin >> cn1 >> cn2;
	std::cout<<cn1+cn2 << std::endl;
	std::cout<<cn1 - cn2 << std::endl;
	std::cout<<cn1*cn2 << std::endl;
	std::cout<<cn1 / cn2 << std::endl;
}
int main(void) {
	CN();
	return 0;
}
//StudybarCommentEnd
