#include <iostream>
#include <iomanip>
using namespace std;

class Clock24 {
private:
	int _hour,_minute,_second;
public:
	bool IS24;
	Clock24(int h=0,int m=0,int s=0,bool is24=true):IS24(is24),_hour(h%24),_minute(m%60),_second(s%60) {}	
	
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
			mod = (-_second + 59)/ 60; //����ȡ�� 
			_second = _second%60 + 60; //����ȡ�� 
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
	Clock24& operator++(){
		++_second;
		setStandard();
		return *this;
	}
	Clock24 operator++(int){
		Clock24 tmp = *this;
		++_second;
		setStandard();
		return tmp;
	}
	friend istream& operator>>(istream & in,Clock24 &c);
	friend ostream& operator<<(ostream & out,const Clock24 &c);
	int getSecondsOfDay()const{
			return _second + _minute*60+_hour*3600;
	}
};
ostream& operator<<(ostream & out,const Clock24 &c)
{
	if (c.IS24)
	out<<setfill('0')<<setw(2)<<c._hour<<":"<<setw(2)<<c._minute<<":"<<setw(2)<<c._second;
	else
	out<<setfill('0')<<setw(2)<< (c._hour%12==0? 12:c._hour%12 )<<":"<<setw(2)<<c._minute<<":"<<setw(2)<<c._second << (c._hour>=12?" PM":" AM");
	return out;
}
istream& operator>>(istream & in,Clock24 &c){
	in>>c._hour>>c._minute>>c._second;
	c.setStandard();
	c.setStandardMinus();
	return in;
}





//StudybarCommentBegin
int main()
{
    const Clock24 t0(0,1,2,false); //���ĸ�������Ϊfalse,��ʾ��12Сʱ����ʾʱ�䡣 
    cout<<"t0 is "<< t0 <<" (ע��0���12Сʱ��Ϊ 12:XX:XX AM )";
    cout<<"\nt0��һ���е�"<<t0.getSecondsOfDay()<<"��";
    Clock24 t1(12,1,2,false), t2(t0), t3(23,45,2);       
	cout<<"\nt1 is "<<t1<<" (12���12Сʱ����ʾΪ 12:XX:XX PM) ";
	t2.IS24=true; //����������24Сʱ��(true),����12Сʱ��(false)����ʾ�� 
	cout<<"\nt2 is "<<t2<<"\nt3 is "<<t3<<endl;   
    t3.IS24=false;
    cout<<"(++t3)++ is "<<(++t3)++<<endl;
    cout<<"t3 is "<<t3<<endl;

    cin >> t2;
    cout<<"(++(++(++t2)))++ is "<<(++(++(++t2)))++<<endl;
    t2.IS24=false;
    cout<<"t2��12Сʱ�ƣ�"<<t2;
    cout<<"\nt2��һ���е�"<<t2.getSecondsOfDay()<<"��"<<endl;

    return 0;
}
//StudybarCommentEnd
