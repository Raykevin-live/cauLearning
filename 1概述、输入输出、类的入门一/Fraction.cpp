#include <iostream>

using namespace std;

class Fraction{
private:
	int _inter;
	int _floater;
public:
	Fraction(int inter = 1, int floater = 1){
		_inter = inter;
		_floater = floater;
	}
	void show(){
		cout<<_inter<<"/"<<_floater<<endl;
	}
};

//StudybarCommentBegin
int main()
{
	Fraction f1,f2(2),f3(1,3);
	f1.show(); cout<<endl;
	f2.show(); cout<<endl;
	f3.show(); cout<<endl;
}
//StudybarCommentEnd
