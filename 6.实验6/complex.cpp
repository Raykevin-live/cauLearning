#include <iostream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<complex>
using namespace std;

template<class T>
T myabs(const T& x){
	return x>=0?x:-x;
}

double myabs (complex<double> z)
{
	double x= z.real(),y=z.imag(); //得到实部和虚部的值。
	double r=sqrt(fabs(x*x)+fabs(y*y));
	return r;
}

//StudybarCommentBegin
int main()
{	int a=-19;
	char c=-1*'a';
	double df=-123456.1234567;
	float f=-123456.1234567;
	complex<double> z(1.1,2.2);  //myabs参数是复数时，求复数的模 
	cout<<fixed<<setprecision(8)<<myabs(a)<<"\n"<<myabs(df)<<"\n"<<myabs(f)<<"\n"<< myabs(c);
	cout<<"\n"<<myabs(z)<<endl;
	cin>>df>>f;
	cout<<fixed<<setprecision(8)<<myabs(df)<<"\n"<<myabs(f)<<"\n";
	if (df*100*100==df*10000)
	{	cout<<"==";
	}else
	{	cout<<"!=";
	}
	return 0;	
}
//StudybarCommentEnd
