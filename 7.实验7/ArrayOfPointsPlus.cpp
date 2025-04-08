#include <iostream>
#include <cassert>

using namespace std;

class Point {

public:

Point(int x = 0, int y = 0) : x(x), y(y) {cout<<"Default Constructor called."<<endl; }

int getX() const { return this->x; }

int getY() const { return  y; }
void move(int x, int y){
	this->x = x, this->y = y;
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
ArrayOfPoints(const ArrayOfPoints& pointsArray);

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

ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints& v) {

size = v.size;

points = new Point[size];

for (int i = 0; i < size; i++)

points[i] = v.points[i];

}

int main() {

int count;

cout << "Please enter the number of points: \n";

cin >> count;

ArrayOfPoints pointsArray1(count); //������������

pointsArray1.element(0).move(5,10);

pointsArray1.element(1).move(15,20);

ArrayOfPoints pointsArray2(pointsArray1); //��������

cout << "Copy of pointsArray1:" << endl;

cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "

<< pointsArray2.element(0).getY() << endl;

cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "

<< pointsArray2.element(1).getY() << endl;

pointsArray1.element(0).move(25, 30);

pointsArray1.element(1).move(35, 40);

cout<<"After the moving of pointsArray1:"<<endl;

cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "

<< pointsArray2.element(0).getY() << endl;

cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "

<< pointsArray2.element(1).getY() << endl;

return 0;

}
