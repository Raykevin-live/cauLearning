//StudybarCommentBegin
#include <iostream>
using namespace std;
class Complex
 {  public :
		Complex(double a=0.0,double b=0.0)
		{r=a;
		 i=b;}
		void   display()
		{cout<<"Real="<<r<<'\t'<<"Image="<<i<<'\n'; }
		Complex operator +(Complex & t);
    private:
		double r, i ;	
}; 
//StudybarCommentEnd

//using namespace std;
Complex Complex::operator +(Complex & t){
	return Complex(r+t.r, i+t.i);
}
 
//StudybarCommentBegin
int main()
{	Complex c1(3.2,3.2),c2(1.2,1.2),c3;
	c3=c1+c2;
	c3.display();
	return 0;
}    
//StudybarCommentEnd
