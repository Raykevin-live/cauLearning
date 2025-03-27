#include <iostream>
#include <cmath>
using namespace std;


typedef struct {
    double real;
    double imag;
} Complex;

// 复数加法
Complex add(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

// 复数减法
Complex sub(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

// 复数乘法
Complex mul(Complex a, Complex b) {
    double real = a.real * b.real - a.imag * b.imag;
    double imag = a.real * b.imag + a.imag * b.real;
    return (Complex){real, imag};
}

// 复数除法
Complex div(Complex a, Complex b) {
    double denominator = b.real * b.real + b.imag * b.imag;
    double real = (a.real * b.real + a.imag * b.imag) / denominator;
    double imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return (Complex){real, imag};
}

// 复数平方根
Complex sqrt_complex(Complex z) {
    double r = sqrt(z.real * z.real + z.imag * z.imag);
    double theta = atan2(z.imag, z.real);
    double sqrt_r = sqrt(r);
    double angle = theta / 2;
    return (Complex){sqrt_r * cos(angle), sqrt_r * sin(angle)};
}

// 格式化输出复数
void print_complex(Complex c) {
    if (c.imag >= 0)
        printf("(%.2lf+%.2lfi)\n", c.real, c.imag);
    else
        printf("(%.2lf-%.2lfi)\n", c.real, -c.imag);
}

int main() {
    Complex a, b, c;
    cin>>a.real>>a.imag;
    cin>>b.real>>b.imag;
	cin>>c.real>>c.imag;

    Complex D = sub(mul(b, b), mul(mul((Complex){4, 0}, a), c));
    Complex sqrtD = sqrt_complex(D);

    Complex root1 = div(add(sub((Complex){0, 0}, b), sqrtD), mul((Complex){2, 0}, a));
    Complex root2 = div(sub(sub((Complex){0, 0}, b), sqrtD), mul((Complex){2, 0}, a));

    if (root2.imag > root1.imag) {
        Complex temp = root1;
        root1 = root2;
        root2 = temp;
    }

    print_complex(root1);
    print_complex(root2);

    return 0;
}

