#include <iostream>

using namespace std;

class Date{
private:
	int _month;
	int _day;
	int _year;
public:
	Date(int month = 1, int day = 1, int year = 0){
		if(month <0 || month > 12){
			month = 1;
		}
		
		_month = month;
		_day = day;
		_year = year;
	}
	int getMonth(){
		return _month;
	}
	int getDay(){
		return _day;
	}
	int getYear(){
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
};


//StudybarCommentBegin
// function main begins program execution
int main()
{
    Date date( 5, 6, 1981 ); // create a Date object for May 6, 1981
    
    // display the values of the three Date data members
    cout << "Month: " << date.getMonth() << endl;
    cout << "Day: " << date.getDay() << endl;
    cout << "Year: " << date.getYear() << endl;
    
    cout << "\nOriginal date:" << endl;
    date.displayDate(); // output the Date as 5/6/1981
    
    // modify the Date
    date.setMonth( 13 ); // invalid month
    date.setDay( 1 );
    date.setYear( 2005 );
    
    cout << "\nNew date:" << endl;
    date.displayDate(); // output the modified date (1/1/2005)
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
