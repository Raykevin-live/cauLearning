#include <iostream>

using namespace std;



template <class T>
bool isEqualTo(const T& a, const T& b){
	return a==b;
}

class SomeClass{
public:
	int _a;
	double _b;
	SomeClass(int a = 0, double b = 0.0){
		_a = a;
		_b = b;
	}
	bool operator==(const SomeClass& x)const{
		return _a==x._a&&_b==x._b;
	}
	bool operator!=(const SomeClass& x)const{
		return !(*this==x);
	}
};

istream& operator>>(istream& in, SomeClass& x){
	in>>x._a>>x._b;
	return in;
} 
ostream& operator<<(ostream& out, const SomeClass& x){
	out<<"("<<x._a<<","<<x._b<<")";
	return out;
} 
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
