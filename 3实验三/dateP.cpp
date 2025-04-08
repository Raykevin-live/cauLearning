#include <iostream>

using namespace std;

class Date{
private:
	int _year;
	int _month;
	int _day;
	
	static int monthDay[13];
public:
	Date(int year = 1, int month = 1, int day = 0){
		if(month <0 || month > 12){
			month = 1;
		}
		_month = month;
		_day = day;
		_year = year;
	}
	int month(){
		return _month;
	}
	int day(){
		return _day;
	}
	int year(){
		return _year;
	}
	void displayDate(){
		cout<<_month<<"/"<<_day<<"/"<<_year<<endl;
	}
	
	void setMonth(int month){
		if(month <0 || month > 12){
			month = 1;
		}
		_month = month;
	}
	void setDay(int day){
		_day = day;
	}
	void setYear(int year){
		_year = year;
	}
	
	bool isLeap(){
		return (_year%4==0&&_year%100!=0) || _year%400==0; 
	}
	Date& operator+(int nday){
		int mod = 0;
		_day += nday;
		
		if(isLeap()){
			monthDay[2] = 29;
		}
		else{
			monthDay[2] = 28;
		}
		
		// ´¦ÀíÈÕ 
		if(_day > monthDay[_month]){
			mod = _day/monthDay[_month];
			_day = _day % monthDay[_month];
		} 
		
		_month += mod;
		if(_month > 12){
			mod = _month/12;
			_month %= 12;
		}
		else{
			mod = 0;
		}
		
		_year += mod;
		return 	*this;		
	}
	Date& operator++() {
        (*this) = (*this) + 1;
        return *this;
    }
	Date operator ++(int){
		Date old = *this;
		++(*this);
		return old;
	}
};

int Date::monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

using date = Date;


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
