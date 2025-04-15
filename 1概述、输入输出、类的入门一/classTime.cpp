#include <iostream>
using namespace std;

class Cmytime{
private:
	int _h, _m, _s;	
public:
	Cmytime(int h = 3, int m = 2, int s = 1){
		_h = h, _m = m; _s = s;
	}
	int Set(int h,int m,int s){
		if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59){
			
			return 0;
		} 
		_h = h, _m = m; _s = s;
		return 1;
	}
	void Show(){
		cout<<_h<<":"<<_m<<":"<<_s;
	}	
	void  AddOneSecond(){
		_s += 1;
		if(_s == 60){
			_s = 0;
			_m += 1;
		}
		if(_m == 60){
			_m = 0;
			_h += 1;
		}
		if(_h == 24){
			_h = 0;
		}
	}
	int  AddNSeconds(int n){
		_s += n;
		if(_s >= 60){
			int muint = _s / 60;
			_s %=  60;
			_m += muint;
		}
		if(_m >= 60){
			int h_P = _m / 60;
			_m %= 60;
			_h += h_P;
		}
		if(_h >= 24){
			int day_p = _h / 24;
			_h %= 24;
			return day_p;
		}
		return 0;
	}
};

//StudybarCommentBegin
int main(void) {
    int h,m,s;
   	cin>>h>>m>>s;
 	Cmytime t1(3,2,1),t2,t3(5);
	t1.Show();
	cout<<"\n";
	t1.Set(h,m,s);
	t1.Show();
	cout<<"\n";
	t2.Show();
	cout<<"\n";
	t3.Show();
    return 0;
}
//StudybarCommentEnd
