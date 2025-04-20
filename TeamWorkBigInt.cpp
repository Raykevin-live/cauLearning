#include <iostream>
#include <string>
using namespace std; 


class TeamWorkBigInt
{
private:
    static const int digits = 10000;
    short integer[digits];
public:
int sign=1;

// 构造函数 
TeamWorkBigInt(long = 0 ); 
explicit TeamWorkBigInt(int);
TeamWorkBigInt& operator=(int); // 拷贝构造 

// 加减乘除运算 
TeamWorkBigInt operator+(int) const;
friend TeamWorkBigInt operator+(const TeamWorkBigInt&, const TeamWorkBigInt&);
TeamWorkBigInt operator-(const TeamWorkBigInt&) const; 
TeamWorkBigInt operator * (const TeamWorkBigInt&) const;
TeamWorkBigInt operator * (int) const;
TeamWorkBigInt operator / (int);
TeamWorkBigInt operator / (const TeamWorkBigInt&);
TeamWorkBigInt& operator /= (int) ;
TeamWorkBigInt& operator+=(const TeamWorkBigInt&);

// 比较运算符 return  True:1, False : 0 
int operator>(const TeamWorkBigInt&) const;
int operator>=(const TeamWorkBigInt&) const;
int operator==(const TeamWorkBigInt&) const;

// 幂运算 
friend TeamWorkBigInt pow(TeamWorkBigInt&, int);
int getLength() const;

// 流重载 
friend ostream &operator<<(ostream&, const TeamWorkBigInt&);
};

/* 类外实现  */
// 构造函数 begin 
TeamWorkBigInt::TeamWorkBigInt(long value)
{
    for (short& num : integer)
        num = 0;
    int i = 0;
    while (value != 0)
    {
        integer[i] = value % 10;
        value /= 10;
        i++;
    }
}
TeamWorkBigInt::TeamWorkBigInt(int value) {
    for (short & num : integer) {
        num = 0;
    }
    int k = 0;
    while (value != 0) {
        integer[k] = value % 10;
        value /= 10;
        k++;
    }
}
TeamWorkBigInt& TeamWorkBigInt::operator=(const int num) {
    for (short & j : integer) {
        j = 0;
    }
    int a = num;
    int k = 0;
    while (a != 0) {
        integer[k] = a % 10;
        a /= 10;
        k++;
    }
    return *this;
}
// 构造函数 end

// 基本运算符 begin
TeamWorkBigInt operator+(const TeamWorkBigInt& op2, const TeamWorkBigInt& op3)
{
    if ((op2.sign==-1&&op3.sign==-1)||(op2.sign==1&&op3.sign==1))
    {
        TeamWorkBigInt temp;
        int carry = 0;
        for (int i = 0; i < TeamWorkBigInt::digits; i++)
        {
            temp.integer[i] = op2.integer[i] + op3.integer[i] + carry;
            if (temp.integer[i] > 9)
            {
                temp.integer[i] -= 10;
                carry = 1;
            }
            else
                carry = 0;
        }
        return temp;
    }
    else if ( op2>op3)
    {
        TeamWorkBigInt temp;
        int carry = 0;
        for (int i = 0; i < TeamWorkBigInt::digits; i++)
        {
            temp.integer[i] = op2.integer[i] - op3.integer[i] - carry;
            if (temp.integer[i] < 0)
            {
                temp.integer[i] += 10;
                carry = 1;
            }
            else
                carry = 0;
        }
        temp.sign=op2.sign;
        return temp;
    }
    else
    {
        TeamWorkBigInt temp;
        int carry = 0;
        for (int i = 0; i < TeamWorkBigInt::digits; i++)
        {
            temp.integer[i] = op3.integer[i] - op2.integer[i] - carry;
            if (temp.integer[i] < 0)
            {
                temp.integer[i] += 10;
                carry = 1;
            }
            else
                carry = 0;
        }
        temp.sign=op3.sign;
        return temp;
    }

}
TeamWorkBigInt TeamWorkBigInt::operator+(int num) const
{
    TeamWorkBigInt temp;
    int carry = 0;
    for (int i = 0; i < digits; i++)
    {
        temp.integer[i] = integer[i] + num % 10 + carry;
        num /= 10;
        if (temp.integer[i] > 9)
        {
            temp.integer[i] -= 10;
            carry = 1;
        }
        else
            carry = 0;
    }
    return temp;
}
TeamWorkBigInt TeamWorkBigInt::operator-(const TeamWorkBigInt& op2) const
{
    TeamWorkBigInt temp;
    int carry = 0;
    for (int i = 0; i < digits; i++)
    {
        temp.integer[i] = integer[i] - op2.integer[i] - carry;
        if (temp.integer[i] < 0)
        {
            temp.integer[i] += 10;
            carry = 1;
        }
        else
            carry = 0;
    }
    return temp;
}
TeamWorkBigInt TeamWorkBigInt::operator*(const TeamWorkBigInt& op2) const {
    TeamWorkBigInt temp;
    int carry = 0;
    for (int i = 0; i <= this->getLength(); i++) {
        for (int j = 0; j <= op2.getLength(); j++) {
            if (i + j < digits) {
                temp.integer[i + j] += integer[i] * op2.integer[j] + carry;
                carry = temp.integer[i + j] / 10;
                temp.integer[i + j] %= 10;
            }
        }
    }
    return temp;
}
TeamWorkBigInt TeamWorkBigInt::operator/(int num)  {
    TeamWorkBigInt temp=*this;
    if (num<0){
        num=-num;
        temp.sign=temp.sign*-1;
    }
    int temptemp;
    int carry = 0;
    for (int i = getLength() - 1; i >= 0; i--) {
        temptemp = temp.integer[i] + carry * 10;
        temp.integer[i] = temptemp / num;
        carry = temptemp % num;
    }
    return temp;

}
TeamWorkBigInt& TeamWorkBigInt::operator+=(const TeamWorkBigInt& op2)  {
    if (op2.sign == -1) {
        TeamWorkBigInt b = op2;
        b.sign = 1;
        *this = *this - b;
        return *this;
    }
        int carry = 0;
    for (int i = 0; i < digits; i++) {
        integer[i] += op2.integer[i] + carry;
        if (integer[i] >= 10) {
            integer[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    return *this;
}
TeamWorkBigInt& TeamWorkBigInt::operator/=(const int num) {
    int carry = 0;
    int a=-num;
    int temp;
    for (int i = getLength() - 1; i >= 0; i--) {
        temp=integer[i];
        integer[i] = (integer[i] + carry * 10) / a;
        carry = (temp + carry * 10) % a;
    }
    sign*=-1;
    return *this;
}
TeamWorkBigInt TeamWorkBigInt::operator/(const TeamWorkBigInt& op2) {
	TeamWorkBigInt temp=*this;
	int num=op2.getLength()-1;
	for (int i = 0; i < getLength(); i++) {
	    temp.integer[i]=integer[i+num];
	}
	for(int i=getLength();i<digits;i++)
	    temp.integer[i]=0;
	return temp;
}
TeamWorkBigInt TeamWorkBigInt::operator*(int num) const {
    TeamWorkBigInt temp;
    int carry = 0;
    for (int i = 0; i <= this->getLength(); i++) {
        temp.integer[i] += integer[i] * num + carry;
        carry = temp.integer[i] / 10;
        temp.integer[i] %= 10;
    }
    return temp;
}
// 基本运算符 end

// 比较运算符 begin
int TeamWorkBigInt::operator>(const TeamWorkBigInt& op2) const
{
    int i = digits - 1;
    while (integer[i] == op2.integer[i] && i >= 0)
        i--;
    if (i == -1)
        return 0;
    else if (integer[i] > op2.integer[i])
        return 1;
    else
        return 0;
}
int TeamWorkBigInt::operator>=(const TeamWorkBigInt& op2) const
{
    int i = digits - 1;
    while (integer[i] == op2.integer[i] && i >= 0)
        i--;
    if (i == -1)
        return 1;
    else if (integer[i] > op2.integer[i])
        return 1;
    else
        return 0;
}
int TeamWorkBigInt::operator==(const TeamWorkBigInt& op2) const
{
    int i = digits - 1;
    while (integer[i] == op2.integer[i] && i >= 0)
        i--;
    if (i == -1)
        return 1;
    else
        return 0;
}
// 比较运算符 end

 
TeamWorkBigInt pow(TeamWorkBigInt& op1, int num) {
    TeamWorkBigInt temp(op1);
    temp.integer[num] = 1;
    return temp;
}
int TeamWorkBigInt::getLength() const{
	int i=digits-1;
	while(integer[i--]==0) ;
	return i+2;
}

// 流重载 
ostream& operator<<(ostream& os, const TeamWorkBigInt& a){
	int i=a.getLength()-1;
	while(i>=0){
		os<<a.integer[i--];
	}
	return os;
}


//StudybarCommentBegin
int main()
{	int i,N;
    TeamWorkBigInt  n=10,b,x1,x2,s,t,pi;

    cin>>N;
	N--;  
	b=pow(n,N+10);

	x1=b*4/5;
	x2=b/-239;
	s=x1+x2;
	
	for(i=3;i<=N*2;i+=2)
	{	x1/=-25;
		x2/=-57121;
		t=(x1+x2)/i;
		s+=t;	
	}
	pi=s*4;
	cout<< (pi/pow(n,10))<<endl;
    return 0;
}
//StudybarCommentEnd
