//StudybarCommentBegin
#include <iostream>
#include <cstring>
using namespace std;
//StudybarCommentEnd

class MyString{
private:
	char* head;
	int size;
public:
	MyString(int size, const char* head = "BCD"){
		
		this->size = size;
		this->head = new char[size+1];
		if(size >= 2e5) {
			char *c="Constructor abnormal.";
			throw c; 
		}

		cout<<"Constructing...\n";
		strcpy(this->head, head);
		cout<<"Construction finished.\n";
	}	
	void ShowStr(){
		cin>>head;
		cout<<head<<endl;
	}
	~MyString(){
		cout<<"Destruction finished.\n";
		delete []head;
		
	}
};

//StudybarCommentBegin
int main(){
	long a;
	cin >> a;
	try{
		if (a > 0){
			MyString str1(a);   //生成容纳a个字符的字符串
			str1.ShowStr();
		}
		else 
         { 
             char *c="Array length error.";
             throw c; 
           //  throw "Array length error.";   work in VC not GCC
         }
	}
	catch (char* c){
		cout << c << endl;
	}
	catch (...){ 
		cout << "Other failures." << endl; 
	}
	cout << "Main finished." << endl;
	return 0;
}
//StudybarCommentEnd
