#include <iostream>

using namespace std;

//Point(int,int) is called.
//Point(const Point &) is called.
//Point(int,int) is called.
//operator=(const Point &p) is called.
//~Point() is called.
//~Point() is called.
//~Point() is called.


class Point{
public:
	int _a;
	int _b;
	
	Point(int a = 0, int b = 0){
		_a = a, _b = b;
		cout<<"Point(int,int) is called."<<endl;
	}
	Point(const Point& x){
		cout<<"Point(const Point &) is called."<<endl;
	}
	Point& operator=(const Point &p){
		cout<<"operator=(const Point &p) is called."<<endl;
	}
	~Point(){
		cout<<"~Point() is called."<<endl;
	}
};
//StudybarCommentBegin
int main()
{
	Point a(1,2);
	Point b(a);
	Point c;
	c=a;
	return 0;
}
//StudybarCommentEnd
