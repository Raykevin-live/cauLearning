#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;

class Time {
private:
    int year, month, day, hour, minute, second;
    static bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    static int getDaysInMonth(int m, int y) {
        if (m == 2) return isLeapYear(y) ? 29 : 28;
        const static int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        return days[m];
    }
    void normalize() {
        // 处理秒
        minute += second / 60;
        second %= 60;
        if (second < 0) {
            minute--;
            second += 60;
        }
        // 处理分钟
        hour += minute / 60;
        minute %= 60;
        if (minute < 0) {
            hour--;
            minute += 60;
        }
        // 处理小时
        day += hour / 24;
        hour %= 24;
        if (hour < 0) {
            day--;
            hour += 24;
        }
        // 处理天数
        while (day > getDaysInMonth(month, year)) {
            day -= getDaysInMonth(month, year);
            if (++month > 12) {
                month = 1;
                year++;
            }
        }
        while (day < 1) {
            if (--month < 1) {
                month = 12;
                year--;
            }
            day += getDaysInMonth(month, year);
        }
        // 处理月份
        year += (month - 1) / 12;
        month = (month - 1) % 12 + 1;
    }
public:
    Time(int y=1, int m=1, int d=1, int h=0, int min=0, int s=0) 
        : year(y), month(m), day(d), hour(h), minute(min), second(s) {
        normalize();
    }
    void setTime(int y, int m, int d, int h, int min, int s) {
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = min;
        second = s;
        normalize();
    }
    Time& operator++() {  // 前置++
        ++second;
        normalize();
        return *this;
    }
    Time operator+(int sec) const {
        Time t = *this;
        t.second += sec;
        t.normalize();
        return t;
    }
    int operator-(const Time& other) const {
        return this->totalSeconds() - other.totalSeconds();
    }
    void printTime() const {
        cout << year << "/" << month << "/" << day << " "
             << setw(2) << setfill('0') << hour << ":" 
             << setw(2) << minute << ":" << setw(2) << second << endl;
    }
	void printTime();
private:
    int totalDays() const {
        int days = day;
        for (int m = 1; m < month; ++m)
            days += getDaysInMonth(m, year);
        for (int y = 1; y < year; ++y)
            days += isLeapYear(y) ? 366 : 365;
        return days;
    }
    int totalSeconds() const {
        return totalDays() * 86400 + hour*3600 + minute*60 + second;
    }
};
void Time::printTime()
{
 cout<<year<<"/"<<month<<"/"<<day
  <<" "<<setfill('0')<<setw(2)<<hour                   
  <<":"<<setw(2)<<minute<<":"
  <<setw(2)<<second<<endl;
}    


//StudybarCommentBegin
int main()
{
	
	int year,month,day;
	int hour,minute,second;
	int increase;
	int capacity=0;
	Time t1(2016,3,31,23,45,0),t2,t3(t1),t4;
	cin>>year>>month>>day>>hour>>minute>>second;
	t1.setTime(year,month,day,hour,minute,second);
	cin>>year>>month>>day>>hour>>minute>>second;
	t2.setTime(year,month,day,hour,minute,second);
	cin>>increase;
	t1.printTime();
	t2.printTime();
	t3=++t1;
	t3.printTime();
	t4=t1+increase;
	t4.printTime();
	capacity = t2-t1;
	cout<<capacity<<endl;
}
//StudybarCommentEnd
