#include <iostream>

#include <cassert>

using namespace std;

class Point {

public:

Point(int x = 0, int y = 0) : x(x), y(y) {cout<<"Default Constructor called."<<endl; }

int getX() const { return this->x; }

int getY() const { return  y; }
void move(int x, int y){
	x = x, y = y;
}
~Point(){
	cout<<"Destructor called."<<endl;
}
private:

int x, y;

};

class ArrayOfPoints { //动态数组类

public:

ArrayOfPoints(int size) : size(size), points(NULL) {
	if(points == NULL){
		points = new Point[size];
	}
	else{
		points = NULL;
	}
	
}

~ArrayOfPoints() {
	cout << "Deleting..." << endl;	
	delete []points;
}

Point& element(int index) {
	
	return *(points+index);
}

private:
	int size; //数组大小	int size; //数组大小
	Point *points; //指向动态数组首地址
};

int main() {

int count;

cout << "Please enter the number of points: ";

cin >> count;
cout<<endl;
ArrayOfPoints points(count); //创建数组对象

points.element(0).move(5, 0); //访问数组元素的成员

points.element(1).move(15, 20); //访问数组元素的成员

return 0;

}
