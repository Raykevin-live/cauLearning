#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Date {
private:
    int _year;
    int _month;
    int _day;
    static int monthDay[13];
public:
    void normalize() {
        // �����·�
        while (_month > 12) {
            _month -= 12;
            _year++;
        }
        while (_month < 1) {
            _month += 12;
            _year--;
        }
        // ��������
        while (true) {
            int maxDay = Date::getDaysInMonth(_month, _year);
            if (_day > maxDay) {
                _day -= maxDay;
                _month++;
                if (_month > 12) {
                    _month = 1;
                    _year++;
                }
            } else if (_day < 1) {
                _month--;
                if (_month < 1) {
                    _month = 12;
                    _year--;
                }
                int prevMax = Date::getDaysInMonth(_month, _year);
                _day += prevMax;
            } else {
                break;
            }
        }
    }

public:
    Date(int year = 1, int month = 1, int day = 1) 
        : _year(year), _month(month), _day(day) {
        normalize();
    }
    // �������Է���
    int year() const { return _year; }
    int month() const { return _month; }
    int day() const { return _day; }
    // �����ж�
    bool isLeap() const {
        return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
    }
    // ��̬������ȡ�·�����
    static int getDaysInMonth(int month, int year) {
        if (month == 2) {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
        }
        return monthDay[month];
    }
    // ���ڼӼ������
    Date& operator+=(int nday) {
        _day += nday;
        normalize();
        return *this;
    }
    Date operator+(int nday) const {
        Date temp = *this;
        temp += nday;
        temp.normalize();
        return temp;
    }
    Date& operator-=(int nday) {
        *this += (-nday);
        return *this;
    }
    // ���ڲ����
    int operator-(const Date& other) const {
        return this->toDays() - other.toDays();
    }

private:
    int toDays() const {
        int days = 0;
        // �깱������
        for (int y = 1; y < _year; ++y) {
            days += (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? 366 : 365;
        }
        // �¹�������
        for (int m = 1; m < _month; ++m) {
            days += getDaysInMonth(m, _year);
        }
        // �չ�������
        days += _day;
        return days;
    }
};
int Date::monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
using date = Date;

//StudybarCommentBegin
int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;
    date D1,D2;
    int year;
    int month;
    int day;
    cin>>year>>month>>day; //shu ru di yi ge ri qi
    D1=date(year,month,day);
    cin>>year>>month>>day;  //shu ru di er ge ri qi
    D2=date(year,month,day);
    cout<<D2-D1<<endl; 
    cin>>day;  //shu ru yao jia jian de tian shu, 
    D1+=day;
    D2-=day;
    cout<<D1.year()<<" "<<D1.month()<<" "<<D1.day()<<endl;
    cout<<D2.year()<<" "<<D2.month()<<" "<<D2.day()<<endl;
    return 0;
}

//StudybarCommentEnd
