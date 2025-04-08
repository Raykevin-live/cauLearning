#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

class Rectangle {
 private:
  double points_[4][2];
  double length_;
  double width_;

  void SetPoints(const double rect[4][2]) {
    // �������겢��֤��Ч��
    for (int i = 0; i < 4; ++i) {
      // ���������
      if (rect[i][0] < 0 || rect[i][0] > 20.0) {
        cout << "��" << (i+1) << "����ĺ�����ֵ��Ч,����Ϊ0" << endl;
        points_[i][0] = 0;
      } else {
        points_[i][0] = rect[i][0];
      }

      // ����������
      if (rect[i][1] < 0 || rect[i][1] > 20.0) {
        cout << "��" << (i+1) << "�����������ֵ��Ч,����Ϊ0" << endl;
        points_[i][1] = 0;
      } else {
        points_[i][1] = rect[i][1];
      }
    }

    // �����ṹ������
    struct Point {
      double x, y;
      bool operator<(const Point& other) const {
        return (y != other.y) ? (y > other.y) : (x < other.x);
      }
    };

    Point sorted[4];
    for (int i = 0; i < 4; ++i) {
      sorted[i] = {points_[i][0], points_[i][1]};
    }
    sort(sorted, sorted + 4);

    // ��֤�ı��λ�������
    const bool top_pair = (sorted[0].y == sorted[1].y);
    const bool bottom_pair = (sorted[2].y == sorted[3].y);
    const bool vertical_edges = (sorted[0].x == sorted[2].x) && 
                               (sorted[1].x == sorted[3].x);
    const bool horizontal_edges = ((sorted[1].x - sorted[0].x) == 
                                  (sorted[3].x - sorted[2].x));
    const bool vertical_length = ((sorted[0].y - sorted[2].y) == 
                                  (sorted[1].y - sorted[3].y));

    if (!(top_pair && bottom_pair && vertical_edges && 
          horizontal_edges && vertical_length)) {
      cout << "���ܹ��ɳ����Σ�" << endl;
      exit(0);
    }

    // ���㳤��
    const double edge_x = sorted[1].x - sorted[0].x;
    const double edge_y = sorted[0].y - sorted[2].y;
    length_ = fmax(edge_x, edge_y);
    width_ = fmin(edge_x, edge_y);
  }

 public:
  explicit Rectangle(const double rect[4][2]) {
    SetPoints(rect);
  }

  double length() const { return length_; }
  double width() const { return width_; }
  double perimeter() const { return 2 * (length_ + width_); }
  double area() const { return length_ * width_; }
  bool square() const { return length_ == width_; }
};

//StudybarCommentBegin
int main()
{
    double rect[4][2];
    int i;
    
    for(i=0;i<4;i++)
    {
//        cout<<"�������"<<i+1<<"����ĺ������꣨����0��С��20��,�Կո�ָ���";
        cin>>rect[i][0]>>rect[i][1];
    }
    
    Rectangle myRect(rect);
    cout<<"����Ϊ��"<<myRect.length()<<endl;
    cout<<"���Ϊ��"<<myRect.width()<<endl;
    cout<<"�ܳ�Ϊ��"<<myRect.perimeter()<<endl;
    cout<<"���Ϊ��"<<myRect.area()<<endl;
    
    if(myRect.square())
        cout<<"�˳�������һ��������"<<endl;
    else
        cout<<"�˳����β���һ��������"<<endl;
    
    return 0;
}
//StudybarCommentEnd
