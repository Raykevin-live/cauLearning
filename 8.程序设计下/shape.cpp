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
	int width,length, h;
public:
	triangle(int a=10, int b=5, int c = 1)
	   {width=a;length=b;h = c;}
	double area()
	{
	   // 验证是否为有效三角形
    if (width <= 0 || length <= 0 || h <= 0 || 
        (width + length <= h) || (width + h <= length) || (length + h <= width)) {
        return -1; 
	    }
	    double s = (width + length + h) / 2;             
	    return sqrt(s * (s - width) * (s - length) * (s - h)); 
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
	shape *sp[2] ;
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
