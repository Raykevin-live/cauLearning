//StudybarCommentBegin
#include <iostream> 
using namespace std;
class incount
{	int c1,c2;
public:	incount(int a=0,int b=0)	
	{	c1=a;	c2=b;	}
	void show()
	{cout<<"the object of incount : c1="<<c1<<'\t'<<"c2="<<c2<<endl;}
    friend istream & operator>>(istream &,incount &);
};
//StudybarCommentEnd
istream & operator>>(istream &is,incount &ic){
	is>>ic.c1>>ic.c2;
	return is;
}

//StudybarCommentBegin
int main()
{	incount x1,x2;
	cin>>x1;	
	cin>>x2;
	x1.show ();	
	x2.show ();
    return 0;
}

//StudybarCommentEnd
