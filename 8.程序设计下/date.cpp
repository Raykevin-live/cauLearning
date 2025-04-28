#include <iostream>

using namespace std;
class date{
private:
	int year, month, day;
public:
	date(int year=0, int month =0, int day = 0){
		this->year = year, this->month = month , this->day = day;
	}
//	date(date& dt){
//		this->year = dt.year, this->month = dt.month , this->day = dt.day;
//	}
	date& operator=(const date& dt){
		this->year = dt.year, this->month = dt.month , this->day = dt.day;
		return *this;
	}
	int to_day(){
		int baseYear = 1970, baseMonth = 1;
		int ret = 0;
		// year
		for(int i=baseYear; i<year; i++){
			if(i%4==0&&i%100!=0 || i%400==0){
				ret += 366;
			}
			else{
				ret += 365;
			}
		} 
		for(int i = baseMonth; i<month; i++){
			int list[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31};
			if(i==2 && ((year%4==0&&year%100!=0) || year%400==0)){
				ret += 29;
			}
			else{
				ret += list[i];
			}
		}
		return ret + day;
	}
	int operator-(date& dt){
		return this->to_day() - dt.to_day();
	}
};




//StudybarCommentBegin
int main() 
{
    date D1,D2;
    int year,month,day,t;
    cin>>year>>month>>day;    //输入你的生日 
    D1=date(year,month,day);
    cout<<endl;
    cin>>year>>month>>day;  //输入今天的日期 
    D2=date(year,month,day);
    cout<<endl;
    t=D2-D1;
    if(t<=0)
    {
    	cout<<"data error!"<<endl;
    }
    else if(t>0&&t<=40000)
    {
	cout<<"你已经活了"<<t<<"天。"<<endl;
    }
    else if(t>40000)
    {
	cout<<"如果没有冬眠的话，你已经去世了！"<<endl;
    }
    return 0;
}
//StudybarCommentEnd
