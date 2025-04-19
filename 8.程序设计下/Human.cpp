//StudybarCommentBegin
#include <iostream>
using namespace std;
class Human
{ int age;
public: 
	Human(int a )
	{
		age=a;
		cout<<"a person who is "<<age<<"is constructed!!!!\n";
	}
	~Human()
	{
		cout<<"a person who is "<<age<<"is deconstructed!!!!\n";
	}      
};
class Score
{ 
	int s;
public:	Score(int i)
	{
			s=i;
			cout<<"score "<<s<<" is constructed!!!!\n";	
		}
	~Score()
	{
		cout<<"score "<<s<<" is deconstructed!!!!\n";
	}      
};
//StudybarCommentEnd

class Student:public Human, public Score{
	int id;
public:
	Student(int id, int age, int score):Human(age), Score(score), id(id){
		cout<<"Student "<<id<<" is constructed!!!!\n";
	}
	~Student(){
		cout<<"Student "<<id<<" is deconstructed!!!!\n";
	}
};



//StudybarCommentBegin
int main()
{
	int id,age,score;
	cin>>id>>age>>score;
	Student jessic(id,age,score);
	cout<<"this is main function\n";  
	return 0;
}

//StudybarCommentEnd
