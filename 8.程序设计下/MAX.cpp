//StudybarCommentBegin
#include<iostream>
using namespace std;
//StudybarCommentEnd


template<class T1, class T2, class T3>
void max(T1 a, T2 b, T3 c){
	double r1 = static_cast<double>(a); 
	double r2 = static_cast<double>(b); 
	double r3 = static_cast<double>(c); 
	double ret = max(max(r1, r2), r3);
	if(ret==r1){
		cout<<a;
	}
	else if(ret==r2){
		cout<<b;
	}
	else{
		cout<<c;
	}
} 

//StudybarCommentBegin
int main(void)
{
        int a;
	float b;
	char c;
	cin >> a >> b >> c;
	max(c, b, a);
	cout << ' ';
	max(a,b,c);
	cout << ' ';
	max(b, a, c);
        return 0;
}
//StudybarCommentEnd
