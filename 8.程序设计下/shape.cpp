//StudybarCommentBegin
#include<iostream>
#include<math.h>
using namespace std;
class shape
{
//StudybarCommentEnd
public:
virtual double area()=0;
};

class triangle:public shape
{
private:
	int base,height;
public:
	triangle(int a = 10, int b = 5) { base = a; height = b; }
    double area() {
        if (base <= 0 || height <= 0) return -1;
        return 0.5 * base * height; 
    }
};

//StudybarCommentBegin
class rectangle:public shape
{
private:
	int width,length;
public:
	rectangle(int c=10,int d=5)
	   {width=c;length=d;}
	double area()
	   {return width*length;}
};

double total(shape *s[],int n) 
{ double sum=0.0; 
  for(int i=0;i<n;i++)
   sum=sum+s[i]->area();
  return sum; 
}
int main()
{ 
	shape *sp[2];
	int x,y;
	cin>>x>>y;
	triangle one(x,y);
	rectangle two;
	sp[0]=&one;
	sp[1]=&two;
	cout<<"the total area is "<<total(sp,2)<<endl;
	return 0;
}
//StudybarCommentEnd
