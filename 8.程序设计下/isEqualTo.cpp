#include<iostream>
#include <string>
using namespace std;

template<class T>
bool isEqualTo(T a, T b){
	return a==b;
}

class SomeClass{
	private:
		int a;
		double b;
	public:
		SomeClass(int a = 0, double b = 0.0){
			this->a = a, this->b = b;
		}
		bool operator==(SomeClass& x){
			return a==x.a && b == x.b;
		}
	friend istream& operator>>(istream& is, SomeClass& x){
		is>>x.a>>x.b;
		return is;
	}
	friend ostream& operator<<(ostream& os, SomeClass& x){
		os<<"("<<x.a<<","<<x.b<<")";
		return os;
	}
};
//StudybarCommentBegin
int main()
{
    int a;   // integers used for
    int b;   // testing equality
    
    // test if two ints input by user are equal
//    cout << "Enter two integer values: ";
    cin >> a >> b;
    
    char c;  // chars used for
    char d;  // testing equality
    
    // test if two chars input by user are equal
//    cout << "\nEnter two character values: ";
    cin >> c >> d;
    
    double e;   // double values used for
    double f;   // testing equality
    
    // test if two doubles input by user are equal
//    cout << "\nEnter two double values: ";
    cin >> e >> f;
    
    SomeClass g( 1, 1.1 );  // SomeClass objects used
    SomeClass h;  // for testing equality
    
    cin >> h;
    
    cout << a << " and " << b << " are "
    << ( isEqualTo( a, b ) ? "equal" : "not equal" ) << '\n';
   
    cout << c << " and " << d << " are "
    << ( isEqualTo( c, d ) ? "equal" : "not equal" ) << '\n';
    
    
    cout << e << " and " << f << " are "
    << ( isEqualTo( e, f ) ? "equal" : "not equal") << '\n';
    
    // test if two SomeClass objects are equal
    // uses overloaded << operator
    cout << "The class objects " << g << " and " << h << " are "
    << ( isEqualTo( g, h ) ? "equal" : "not equal" ) << '\n';
    
    return 0;
    
} // end main

//StudybarCommentEnd
