#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;

class date{
private:
	int _year;
	int _month;
	int _day;
public:
	int year(){
		return _year;
	}
	int month(){
		return _month;
	}
	int day(){
		return _day;
	}
	void setStandard(){
		int mod = 0;
		if(_day >= monthTable[month]){
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
			mod = _minute / 24;
			_hour %= 24;
		}
	}
	date& operator++(int){
		_day++;
		
		return *this;
	}
	date operator++(int){
		date tmp = *this;
		_day++;
		return tmp;
	}
};

//StudybarCommentBegin
int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	date D1,D2;

	int year;
	int month;
	int day;

	cin>>year>>month>>day; //shu ru di yi ge ri qi
	D1=date(year,month,day);

	D2=D1++;

	cout<<D1.year()<<" "<<D1.month()<<" "<<D1.day()<<endl;
	cout<<D2.year()<<" "<<D2.month()<<" "<<D2.day()<<endl;
	return 0;
}

//StudybarCommentEnd
