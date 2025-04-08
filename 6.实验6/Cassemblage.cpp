#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
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
	Cmycomplex operator=(const Cmycomplex& x){
		_real = x._real, _imag = x._imag;
		return *this;
	}
	bool operator!=(const Cmycomplex& x){
		return _real!=x._real || _imag != x._imag;
	}
	Cmycomplex sqrt(){
		double newReal = std::sqrt((_real+std::sqrt(_real*_real+_imag*_imag))/2);
		double newImag = _imag/std::sqrt(2*_real+2*std::sqrt(_real*_real+_imag*_imag));
		return Cmycomplex(newReal, newImag);
	}
	bool operator>(const Cmycomplex& x){
		return std::sqrt(_real*_real + _imag*_imag) > std::sqrt(x._real*x._real + x._imag*x._imag);
	}
	bool operator<=(const Cmycomplex& x){
		return !(*this > x);
	}
	bool operator<(const Cmycomplex& x){
		return std::sqrt(_real*_real + _imag*_imag) < std::sqrt(x._real*x._real + x._imag*x._imag);
	}
	bool operator>=(const Cmycomplex& x){
		return !(*this < x);
	}
};

Cmycomplex operator+(const Cmycomplex& cplx, double x){
		return Cmycomplex(cplx._real+x, cplx._imag);
}
Cmycomplex operator+(double x, const Cmycomplex& cplx){
		return Cmycomplex(cplx._real+x, cplx._imag);
}
	
std::ostream& operator<<(std::ostream& os, const Cmycomplex& cplx) {
	os<<"("<<cplx._real;
	os<<(cplx._imag < 0 ? "":"+")<<cplx._imag<<"i)"; 
    return os; 
}
std::istream& operator>>(std::istream& is, Cmycomplex& cplx) {
        is >> cplx._real>>cplx._imag;
        return is;
}


class Cassemblage {
private:
    int count;
    Cmycomplex* elements;

public:
    Cassemblage() : count(0), elements(nullptr) {}
    ~Cassemblage() { delete[] elements; }

    Cassemblage(const Cassemblage& other) : count(other.count) {
        if (count > 0) {
            elements = new Cmycomplex[count];
            for (int i = 0; i < count; ++i)
                elements[i] = other.elements[i];
        } else {
            elements = nullptr;
        }
    }

    Cassemblage& operator=(const Cassemblage& other) {
        if (this != &other) {
            delete[] elements;
            count = other.count;
            if (count > 0) {
                elements = new Cmycomplex[count];
                for (int i = 0; i < count; ++i)
                    elements[i] = other.elements[i];
            } else {
                elements = nullptr;
            }
        }
        return *this;
    }

    void Set(Cmycomplex a[], int n) {
        vector<Cmycomplex> temp;
        for (int i = 0; i < n; ++i) {
            bool found = false;
            for (Cmycomplex num : temp) {
                if (num == a[i]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                temp.push_back(a[i]);
        }
        delete[] elements;
        count = temp.size();
        if (count == 0) {
            elements = nullptr;
            return;
        }
        elements = new Cmycomplex[count];
        for (int i = 0; i < count; ++i)
            elements[i] = temp[i];
    }

    void Show() {
        if (count == 0) {
            cout << "empty";
            return;
        }
        sort(elements, elements + count);
        for (int i = 0; i < count; ++i) {
            cout << elements[i];
            if (i != count - 1)
                cout << " ";
        }
    }

    Cassemblage operator+(const Cassemblage& other) const {
        vector<Cmycomplex> combined;
        for (int i = 0; i < count; ++i)
            combined.push_back(elements[i]);
        for (int i = 0; i < other.count; ++i)
            combined.push_back(other.elements[i]);
        Cassemblage result;
        Cmycomplex* arr = combined.empty() ? nullptr : new Cmycomplex[combined.size()];
        copy(combined.begin(), combined.end(), arr);
        result.Set(arr, combined.size());
        delete[] arr;
        return result;
    }

    Cassemblage operator&(const Cassemblage& other) const {
        vector<Cmycomplex> intersection;
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < other.count; ++j) {
                if (elements[i] == other.elements[j]) {
                    intersection.push_back(elements[i]);
                    break;
                }
            }
        }
        Cassemblage result;
        Cmycomplex* arr = intersection.empty() ? nullptr : new Cmycomplex[intersection.size()];
        copy(intersection.begin(), intersection.end(), arr);
        result.Set(arr, intersection.size());
        delete[] arr;
        return result;
    }

    Cassemblage operator-(const Cassemblage& other) const {
        vector<Cmycomplex> difference;
        for (int i = 0; i < count; ++i) {
            bool found = false;
            for (int j = 0; j < other.count; ++j) {
                if (elements[i] == other.elements[j]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                difference.push_back(elements[i]);
        }
        Cassemblage result;
        Cmycomplex* arr = difference.empty() ? nullptr : new Cmycomplex[difference.size()];
        copy(difference.begin(), difference.end(), arr);
        result.Set(arr, difference.size());
        delete[] arr;
        return result;
    }
};


int main(int argc, char* argv[])
{
	Cassemblage z1, z2, x1, x2, x3;
	Cmycomplex a1[1000], a2[1000];
	int i, n1, n2;
	
	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> a1[i];
	}
    z1.Set(a1, n1);

	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> a2[i];
	}	
	z2.Set(a2, n2);

	x1=z1+z2;
	x1.Show();
	cout << endl;

	x2=z1&z2;
	x2.Show();
	cout << endl;

	x3=z1-z2;
	x3.Show();


	return 0;
}

