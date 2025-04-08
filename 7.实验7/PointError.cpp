#include <iostream>

using namespace std;

class Point {

public:

Point(int x = 0, int y = 0) : x(x), y(y) { }

int getX() const{ return this->x; }

int getY()  const{ return this->y; }

private:

	int x, y;

};


int main() {

Point a(4, 5); //��ͨ����
Point const b(6,7); //������

Point const* pa = &a; //���峣����ָ�룬��a�ĵ�ַ��ʼ��

const Point* pb= &b; //���峣����ָ�룬�ó�����b�ĵ�ַ��ʼ��

const Point & rb= b; //���峣����rb��������b�ı���

cout << pa->getX() << endl;//��ָ����ʶ����Ա

cout<< a.getY() <<endl;

cout << pb->getY() << endl; //��ָ����������������ʶ����Ա

cout << rb.getX() << endl; //�ó����������ʶ����Ա

return 0;

}
