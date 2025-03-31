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
public:
	Cmycomplex(double real = 0, double imag = 0){
		_real = real;
		_imag = imag;
	}
	
	void Show(){
		cout <<setiosflags(ios::fixed); 
		if(_imag<0){
			cout<<"("<<setprecision(2)<<_real<<setprecision(2)<<_imag<<"i)"<<endl;
		}
		else if(_imag==0){
			cout<<setprecision(2)<<_real<<endl;
		}
		else{
			cout<<"("<<setprecision(2)<<_real<<"+"<<setprecision(2)<<_imag<<"i)"<<endl;
		}
	}
	
//	void Show(){
//		if(_imag<0){
//			cout<<"("<<_real<<_imag<<"i)"<<endl;
//		}
//		else{
//			cout<<"("<<_real<<"+"<<_imag<<"i)"<<endl;
//		}
//	}
	
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
	Cmycomplex operator+(const Cmycomplex& x){
		return Cmycomplex(_real+x._real, _imag+x._imag);
	}
	Cmycomplex operator-(const Cmycomplex& x){
		return Cmycomplex(_real-x._real, _imag-x._imag);
	}
	Cmycomplex operator*(const Cmycomplex& x){
		return Cmycomplex(_real*x._real-_imag*x._imag, _real*x._imag+_imag*x._real);
	}
	Cmycomplex operator/(const Cmycomplex& x){
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
	Cmycomplex sqrt(){
		double newReal = std::sqrt((_real+std::sqrt(_real*_real+_imag*_imag))/2);
		double newImag = _imag/std::sqrt(2*_real+2*std::sqrt(_real*_real+_imag*_imag));
		return Cmycomplex(newReal, newImag);
	}
};

Cmycomplex operator+(const Cmycomplex& cplx, double x){
		return Cmycomplex(cplx._real+x, cplx._imag);
}
Cmycomplex operator+(double x, const Cmycomplex& cplx){
		return Cmycomplex(cplx._real+x, cplx._imag);
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
    double real = 0, imag = 0;
    char ch = 0;
    
    // 尝试读取实部
    if (is >> real) {
        // 探测下一个字符
        ch = is.peek();
        
        // 处理虚部
        if (ch == '+' || ch == '-') {
            char op;
            is >> op;  // 读取运算符
            
            // 尝试读取虚部数值
            if (is >> imag) {
                if (is.peek() == 'i') {
                    is.get();  // 消耗i
                    imag = (op == '+') ? imag : -imag;
                } else {
                    is.setstate(ios::failbit);
                }
            }
        } 
        // 处理纯虚部格式（如3i）
        else if (ch == 'i') {
            is.get();  // 消耗i
            imag = real;
            real = 0;
        }
    } 
    // 处理纯虚部（如i/-i/4.5i）
    else {
        is.clear();
        char first;
        is >> first;
        
        if (first == 'i') {          // 单i情况
            imag = 1;
        } else if (first == '+' && is.peek() == 'i') {  // +i
            is.get();
            imag = 1;
        } else if (first == '-' && is.peek() == 'i') {  // -i
            is.get();
            imag = -1;
        } else {                     // 数值虚部（如3i/-4.5i）
            is.unget();
            if (is >> imag && is.get() == 'i') {
                imag = (first == '-') ? -imag : imag;
            } else {
                is.setstate(ios::failbit);
            }
        }
    }

    if (is) {
        cplx._real = real;
        cplx._imag = imag;
    }
    return is;
}

typedef Cmycomplex ComplexNumber;
 
//流重载

 
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
