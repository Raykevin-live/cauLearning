#include <iostream>
#include <string>

using namespace std;

class Teacher{
public:
	Teacher(int num, string name, char sex)
	:num(num), name(name), sex(sex)
	{}
	void show(){
		cout<<"num: "<<num<<", "<<"name: "<<name<<", "<<"sex: "<<sex;
	}
private:
	int num;
	string name;
	char sex;
};

class BirthDate{
public:
	BirthDate(int year, int month, int day)
	:year(year), month(month), day(day)
	{}
	void setBirth(int year, int month, int day){
		year = year, month = month, day = day;
	}
	void show(){
		cout<<" year: "<<year<<", "<<"month: "<<month<<", "<<"day: "<<day<<endl;
	}
private:
	int year;
	int month;
	int day;
};
class Professor:public Teacher{
public:
	Professor(int num, string name, char sex, int year, int month, int day)
	:Teacher(num, name, sex), birthday(year, month, day)
	{}
	void show(){
		Teacher::show();
		birthday.show();
	}
	BirthDate& getBirthDate(){
		return birthday;
	}
private:
	BirthDate birthday;
};
int main(){
	Professor prof1(1, "kevin", 'C', 2025, 4, 19);
	prof1.getBirthDate().setBirth(2025, 4, 20);
//	prof1.show();
	
	return 0;
}
