//StudybarCommentBegin
#include <iostream>
#include <iomanip>
using std::cin;
 using std::cout;
 using std::endl;
 using std::setfill;
 using std::setw;
//StudybarCommentEnd

class Time{
private:
	int _hour;
	int _minute;
	int _second;
	
	friend Time operator+(const int n, const Time t);
	friend Time operator-(const Time t, const int n);
public:
	Time(int hour = 0, int minute=0, int second=0){
		_hour = hour, _minute = minute, _second = second;
		setStandard();
		setStandardMinus();
	}	
	void setTime(int hour, int minute, int second){
		_hour = hour, _minute = minute, _second = second;
		setStandard();
		setStandardMinus();
	}
	void setStandard(){
		int mod = 0;
		if(_second >= 60){
			mod = _second / 60;
			_second %= 60;
		}
		_minute += mod;
		if(_minute >= 60){
			mod = _minute / 60;
			_minute %= 60;
		}
		else{
			mod = 0;
		}
		_hour += mod;
		if(_hour >= 24){
			mod = _hour / 24;
			_hour %= 24;
		}
	}
	void setStandardMinus(){
		int mod = 0;
		if(_second < 0){
			mod = (-_second + 59)/ 60; //向上取整 
			_second = _second%60 + 60; //向上取整 
		}
		_minute -= mod;
		if(_minute < 0 ){
			mod = (-_minute + 59) / 60;
			_minute = _minute%60 + 60;
		}
		else{
			mod = 0;
		}
		_hour -= mod;
		if(_hour < 0){
			_hour =  _hour % 24 + 24;
		}
	}
	Time& operator++(){
		++_second;
		setStandard();
		return *this;
	}
	Time operator++(int){
		Time tmp = *this;
		++_second;
		setStandard();
		return tmp;
	}
	
	Time& operator--(){
		--_second;
		setStandardMinus();
		return *this;
	}
	Time operator--(int){
		Time tmp = *this;
		--_second;
		setStandardMinus();
		return tmp;
	}
	
	void printTime();
};


void Time::printTime()
{
 cout<<setfill('0')<<setw(2)<<_hour
  <<":"<<setw(2)<<_minute<<":"
  <<setw(2)<<_second<<endl;
}

Time operator+(const int n, const Time t){
	Time tmp = t;
	tmp._second += n;
	tmp.setStandard();
	tmp.setStandardMinus();
	return tmp;
}
Time operator-(const Time t, const int n){
	Time tmp = t;
	tmp._second -= n;
	tmp.setStandardMinus();
	tmp.setStandard();
	return tmp;
}
//StudybarCommentBegin
int main()
 {
 int hour,minute,second;
 int number;
 Time t1(23,45,0),t2,t3(t1),t4;
cin>>hour>>minute>>second>>number;
 t1.setTime(hour,minute,second);
 t2=t1--;
 t2.printTime();
 t1.printTime();
 t3=--t1;
 t3.printTime();
 t4=number+t1;
 t4.printTime();
 }
//StudybarCommentEnd
