//StudybarCommentBegin
#include <iostream>
using namespace std;
class incount
{	int c1,c2;
public:		incount(int a=0,int b=0)
		{	c1=a;	c2=b;	}
		void show()	
		{cout<<"c1="<<c1<<'\t'<<"c2="<<c2<<endl;	}
	 
//StudybarCommentEnd
friend istream& operator>>(istream& is, incount& x);
friend ostream& operator<<(ostream& os, incount& x);
};
istream& operator>>(istream& is, incount& x){
	is>>x.c1>>x.c2;
	return is;
}
ostream& operator<<(ostream& os, incount& x){
	os<<"c1="<<x.c1<<"\tc2="<<x.c2<<endl;
	return os;
}
//StudybarCommentBegin
int main()
{	incount x1,x2;
	cin>>x1;	
	cin>>x2;
	cout<<x1<<x2;   
    return 0;
 }
//StudybarCommentEnd
