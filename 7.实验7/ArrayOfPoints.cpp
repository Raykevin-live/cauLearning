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

class ArrayOfPoints { //��̬������

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
	int size; //�����С	int size; //�����С
	Point *points; //ָ��̬�����׵�ַ
};

int main() {

int count;

cout << "Please enter the number of points: ";

cin >> count;
cout<<endl;
ArrayOfPoints points(count); //�����������

points.element(0).move(5, 0); //��������Ԫ�صĳ�Ա

points.element(1).move(15, 20); //��������Ԫ�صĳ�Ա

return 0;

}
