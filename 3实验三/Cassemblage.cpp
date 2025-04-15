#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Cmycomplex {
private:
    double _real;
    double _imag;
    friend Cmycomplex operator+(const Cmycomplex& cplx, double x);
    friend Cmycomplex operator+(double x, const Cmycomplex& cplx);
    friend std::ostream& operator<<(std::ostream& os, const Cmycomplex& cplx);
    friend std::istream& operator>>(std::istream& is, Cmycomplex& cplx);

public:
    Cmycomplex(double real = 0, double imag = 0) : _real(real), _imag(imag) {}

    double GetReal() const { return _real; }
    double GetImaginary() const { return _imag; }

    // Ä£¼ÆËã
    double modulus() const {
        return sqrt(_real * _real + _imag * _imag);
    }

    bool operator==(const Cmycomplex& other) const {
        return _real == other._real && _imag == other._imag;
    }

    void Set(double real, double imag) {
        _real = real;
        _imag = imag;
    }
};
Cmycomplex operator+(const Cmycomplex& cplx, double x){
		return Cmycomplex(cplx._real+x, cplx._imag);
}
Cmycomplex operator+(double x, const Cmycomplex& cplx){
		return Cmycomplex(cplx._real+x, cplx._imag);
}
std::istream& operator>>(std::istream& is, Cmycomplex& cplx) {
    is >> cplx._real >> cplx._imag;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Cmycomplex& cplx) {
    os << "(" << cplx._real;
    if (cplx._imag != 0) {
        os << (cplx._imag > 0 ? "+" : "") << cplx._imag << "i";
    }
    os << ")";
    return os;
}

class Cassemblage {
private:
    vector<Cmycomplex> elements;
public:
	Cassemblage() = default;
    void Set(Cmycomplex arr[], int n) {
        elements.clear();
        for (int i = 0; i < n; ++i) {
            if (find(elements.begin(), elements.end(), arr[i]) == elements.end()) {
                elements.push_back(arr[i]);
            }
        }
    }
    Cassemblage operator+(const Cassemblage& other) const {
        Cassemblage result = *this;
        for (const auto& e : other.elements) {
            if (find(result.elements.begin(), result.elements.end(), e) == result.elements.end()) {
                result.elements.push_back(e);
            }
        }
        return result;
    }
    Cassemblage operator&(const Cassemblage& other) const {
        Cassemblage result;
        for (const auto& e : elements) {
            if (find(other.elements.begin(), other.elements.end(), e) != other.elements.end()) {
                result.elements.push_back(e);
            }
        }
        return result;
    }
    Cassemblage operator-(const Cassemblage& other) const {
        Cassemblage result;
        for (const auto& e : elements) {
            if (find(other.elements.begin(), other.elements.end(), e) == other.elements.end()) {
                result.elements.push_back(e);
            }
        }
        return result;
    }
    void Show() const {
        if (elements.empty()) {
            cout << "empty";
            return;
        }
        vector<Cmycomplex> sorted = elements;
        sort(sorted.begin(), sorted.end(), [](const Cmycomplex& a, const Cmycomplex& b) {
            return a.modulus() < b.modulus();
        });
        for (size_t i = 0; i < sorted.size(); ++i) {
            cout << sorted[i] << (i != sorted.size()-1 ? " " : "");
        }
    }
};

//StudybarCommentBegin
int main(int argc, char* argv[])
{
	Cassemblage z1, z2, x1, x2, x3;
	Cmycomplex a1[1000], a2[1000];
	int i, n1, n2;
	double a11[1000], a12[1000], a21[1000], a22[1000];
	
	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> a11[i] >> a12[i];
		a1[i].Set(a11[i], a12[i]);
	}
       z1.Set(a1, n1);

	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> a21[i] >> a22[i];
		a2[i].Set(a21[i], a22[i]);
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

//StudybarCommentEnd
