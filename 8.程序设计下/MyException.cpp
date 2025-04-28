//StudybarCommentBegin
#include <iostream>
using namespace std;
//StudybarCommentEnd

#include <exception>

class MyException: public exception {
private:
	int num;
public:
	MyException(int a):num(a) {
	}
	
	void Reason() const {
		switch (num) {
			case 1:cout << "Exception:1" << endl;break;
			case 2:cout << "Exception:2" << endl;break;
			case 3:cout << "Exception:3" << endl;break;
			default:break;
		}
	}
};

void fn1(int excpNo) {
	throw new MyException(excpNo);
}

//StudybarCommentBegin
int main(){        
        int excpNo;
	cin >> excpNo;
	try{
		if (excpNo > 3 || excpNo < 1)
			throw 1;
		fn1(excpNo);
	}
	catch (MyException* e){
		e->Reason();
	}
	catch (...){
		cout << "Other error." << endl;
	}
        return 0;
}
//StudybarCommentEnd
