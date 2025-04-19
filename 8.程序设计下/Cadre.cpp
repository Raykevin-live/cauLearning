#include <iostream>
#include <string>
using namespace std;

class Teacher{
public:
	string name;
	int age;
	string sex;
	string address;
	string tele;
	string title;
	Teacher(string name, int age, string sex, string address, string tele, string title);
	void display();
};
Teacher::Teacher(string name, int age, string sex, string address, string tele, string title)
:name(name), age(age), sex(sex), address(address), tele(tele), title(title)
{};
void Teacher::display(){
	std::cout<<"name: "<<name<<", "<<"age: "<<age<<", "<<
	"sex: "<<sex<<", "<<"title: "<<title<<", "<<
	"address: "<<address<<", "<<"tele: "<<tele;
}	
class Cadre{
public:
	string name;
	int age;
	string sex;
	string address;
	string tele;
	string post;
	Cadre(string name, int age, string sex, string address, string tele, string post);
};
Cadre::Cadre(string name, int age, string sex, string address, string tele, string post)
:name(name), age(age), sex(sex), address(address), tele(tele), post(post)
{};
class Teacher_Cadre:public Teacher, public Cadre{
	int wages;
public:
	Teacher_Cadre(string name, int age, string sex, string address, string tele, string title, string post, int wages);
	void show();
};
Teacher_Cadre::Teacher_Cadre(string name, int age, string sex, string address, string tele, string title, string post, int wages)
:Teacher(name, age, sex, address, tele, title), Cadre(name, age, sex, address, tele, post), wages(wages)
{}
void Teacher_Cadre::show(){
	Teacher::display();
	std::cout<<" post: "<<Cadre::post<<","<<"wages: "<<wages<<std::endl;
}

int main(){
	Teacher_Cadre teacher_cadre("kevin", 18, "man", "XXXX", "182345", "teacher", "buzhang", 1000000);
//	teacher_cadre.show();
	
	return 0;
} 
