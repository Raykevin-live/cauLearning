#include <iostream>
#include <iomanip> 
using namespace std;

class Rectangle{
public:
	double _length;
	double _width;
public:
	double verif(double num){
		if(num <= 0.0 || num >= 20.0){
			num = 1.0;
		}
		return num;
	}
	void setLength(double length){
		length = verif(length);
		_length = length;
	}
	void setWidth(double width){
		width = verif(width);
		_width = width;
	}
	double perimeter(){
		return (_length+_width)*2;
	}
	double area(){
		return _length*_width;
	}
};


//StudybarCommentBegin
int main()
{
    Rectangle r;
    double length,width;
    
//    cout<<"please input the length of Rectangle:";
    cin>>length;
//    cout<<"please input the width of Rectangle:";
    cin>>width;
    r.setLength(length);
    r.setWidth(width);
    cout<<"the perimeter is:"<<setprecision(2)<<fixed<<r.perimeter()<<endl;
    cout<<"the area is:"<<setprecision(2)<<fixed<<r.area()<<endl;
    return 0;
    
}
//StudybarCommentEnd
