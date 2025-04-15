#include <iostream>
#include <cctype> // isdigit function prototype
#include <cstring> // strlen function prototype
#include <cstdlib>
#include <cmath>
#include <exception>
using namespace std;

class HugeInt
{
    friend ostream &operator<<( ostream &, const HugeInt & );
public:
    static const int digits = 30;
    HugeInt( long = 0 ); // conversion/default constructor
    HugeInt( const char * ); // conversion constructor
    // addition operator; HugeInt + HugeInt
    HugeInt operator+( const HugeInt & ) const;
    HugeInt operator-( const HugeInt & ) const;
    HugeInt operator*( const HugeInt & ) const;
    HugeInt operator*(int ) const;
    HugeInt operator/( const HugeInt & ) const;
    // addition operator; HugeInt + int
    HugeInt operator+( int ) const;
    // addition operator;
    // HugeInt + string that represents large integer value
    HugeInt operator+( const char * ) const;
    
    int getLength() const;
    bool operator>( const HugeInt & ) const;
    bool operator<=( const HugeInt & ) const;
    bool operator<( const HugeInt & ) const;
    bool operator>=( const HugeInt & ) const;
    bool operator==( const HugeInt & ) const;
    bool operator!=( const HugeInt & ) const;
private:
    short integer[ digits ];
}; // end class HugeInt

HugeInt::HugeInt( long num){
	for(int i=0; i<digits; i++){
		integer[i] = 0;
	}
	int pos = digits-1;
	while(num>0){
		integer[pos--] = num % 10;
		num /= 10;
	}
}
HugeInt::HugeInt( const char * num){
	// 初始化为0 
	for(int i=0; i<digits; i++){
		integer[i] = 0;
	}
	int pos = digits-1;
	int len = strlen(num);
	int posLen = len-1;
	while(posLen>=0){
		integer[pos--] = (num[posLen--]-'0');
	} 
}
HugeInt HugeInt::operator+( const HugeInt & x) const{
	HugeInt tmp(*this);
	for(int i = digits-1; i>=0; i--){
		tmp.integer[i] += x.integer[i];
		if(tmp.integer[i]>9){
			tmp.integer[i] %= 10;
			tmp.integer[i-1] += 1; 
		}
	}
	return tmp; 
}
HugeInt HugeInt::operator-( const HugeInt & x) const{
	HugeInt tmp(*this);
	for(int i = digits-1; i>=0; i--){
		tmp.integer[i] -= x.integer[i];
		if(tmp.integer[i]<0){
			tmp.integer[i] += 10;
			tmp.integer[i-1] -= 1; 
		}
	}
	return tmp; 
}
HugeInt HugeInt::operator*( const HugeInt & x) const{
	HugeInt tmp;
	// 先累积 
	for(int i = digits-1; i>=0; i--){
		for(int j = digits-1; j>=0; j--)
			tmp.integer[i+j-digits+1] += integer[j]*x.integer[i]; 
	}
	//进位 
	for(int i = digits-1; i>=0; i--){
		if(tmp.integer[i]>9){
			tmp.integer[i-1] += tmp.integer[i]/10;
			tmp.integer[i] %= 10;
		}
	}
	return tmp; 
}
HugeInt HugeInt::operator*(int x) const{
	HugeInt tmp(x);
	return (*this)*tmp; 
}
int getCount(const HugeInt& num, const HugeInt& base){
	if(num < base) return 0;
	int len_diff = num.getLength() - base.getLength();
	int multiplier = std::pow(10, len_diff);
	
	while (true) {
        HugeInt base_scaled = base * multiplier;
        if (base_scaled <= num) break;
        
        // 幂次过高时需要递减
        multiplier = std::pow(10, --len_diff);
        if (len_diff < 0) return 0;
    }
    
    // 二分查找
    int low = 0, high = 9, best = 0;
    HugeInt base_scaled = base * multiplier;
    
    while (low <= high) {
        int mid = (low + high + 1) / 2; // 修正中点计算
        HugeInt temp = base_scaled * mid;
        
        if (temp == num) {
            best = mid;
            break;
        } else if (temp < num) {
            best = mid;    // 记录可能的最大值
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // 处理余数部分
    HugeInt remainder = num - base_scaled * best;
    int sub_result = getCount(remainder, base);
    return best * multiplier + sub_result;
} 
HugeInt HugeInt::operator/( const HugeInt & x) const{
	if (x == HugeInt()) exit(-1);
    if (*this < x) return HugeInt();
    return HugeInt(getCount(*this, x));
}
HugeInt HugeInt::operator+( int x) const{
	HugeInt tmp(x);
	return *this+tmp;
}
HugeInt HugeInt::operator+(const char *  x) const{
	HugeInt tmp(x);
	return *this+tmp;
}
int HugeInt::getLength() const{
	int i=0;
	for(i=0; i<digits; i++){
		if(integer[i]!=0){
			break;
		}
	}
	return digits - i;
}
ostream &operator<<( ostream & os, const HugeInt & x){
	int i=0;
	for(i=0; i<HugeInt::digits; i++){
		if(x.integer[i]!=0){
			break;
		}
	}
	if(i!=HugeInt::digits){
		for(;i<HugeInt::digits; i++){
			os<<x.integer[i];
		}
	}
	else{
		os<<0;
	}
	
	return os;
}
bool HugeInt::operator>( const HugeInt & x) const{
	for(int i=0; i<digits; i++){
		if(integer[i]>x.integer[i]){
			return true;
		}
		else if(integer[i]<x.integer[i])
		{
			return false;
		}
	}
	return false;
}
bool HugeInt::operator<=( const HugeInt & x) const{
	return !(*this>x);
}
bool HugeInt::operator<( const HugeInt & x) const{
	for(int i=0; i<digits; i++){
		if(integer[i]>x.integer[i]){
			return false;
		}
		else if(integer[i]<x.integer[i])
		{
			return true;
		}
	}
	return false;
}
bool HugeInt::operator>=( const HugeInt & x) const{
	return !(*this<x);
}
bool HugeInt::operator==( const HugeInt & x) const{
	for(int i=0; i<digits; i++){
		if(integer[i]!=x.integer[i]){
			return false;
		}
	}
	return true;
}
bool HugeInt::operator!=( const HugeInt & x) const{
	return !(*this==x);
}
//StudybarCommentBegin
int main()
{
    HugeInt n1( 7654321 );
    HugeInt n2( 7891234 );
    HugeInt n3( "99999999999999999999999999999" );
    HugeInt n4( "1" );
    HugeInt n5( "12341234" );
    HugeInt n6( "7888" );
    HugeInt result;
    
    cout << "n1 is " << n1 << "\nn2 is " << n2
    << "\nn3 is " << n3 << "\nn4 is " << n4
    << "\nn5 is " << n5 << "\nn6 is " << n6
    << "\nresult is " << result << "\n\n";
    
    // test relational and equality operators
    if ( n1 == n2 )
        cout << "n1 equals n2" << endl;
    
    if ( n1 != n2 )
        cout << "n1 is not equal to n2" << endl;
    
    if ( n1 < n2 )
        cout << "n1 is less than n2" << endl;
    
    if ( n1 <= n2 )
        cout << "n1 is less than or equal to n2" << endl;
    
    if ( n1 > n2 )
        cout << "n1 is greater than n2" << endl;
    
    if ( n1 >= n2 )
        cout << "n1 is greater than or equal to n2" << endl;
    
    result = n1 + n2;
    cout << n1 << " + " << n2 << " = " << result << "\n\n";
    
    cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";
    
    result = n1 + 9;
    cout << n1 << " + " << 9 << " = " << result << endl;
    
    result = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << result << endl;
    
    result = n5 * n6;
    cout << n5 << " * " << n6 << " = " << result << endl;
    
    result = n5 - n6;
    cout << n5 << " - " << n6 << " = " << result << endl;
    
    result = n5 / n6;
    cout << n5 << " / " << n6 << " = " << result << endl;
    return 0;
} // end main
//StudybarCommentEnd


