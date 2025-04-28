//StudybarCommentBegin
#include <iostream>
#include<string>
using namespace std;
//StudybarCommentEnd

void f2(){
	cout<<"In f2 function\n";
	throw "Exception from f2\n";
}
void f1(int a, int b){
	if(b==0) throw "You inputted:0\n";
	try{
		f2();
	}
	catch(const char* err){
		cout<<err;
	}
	cout<<a<<"%"<<b<<"="<<a%b<<endl;
	cout<<"In f1 function\n";
}
#include <typeinfo>
int main(){
	
	double a, b;
	cin>>a>>b;
	try{
		if((int)a!=a || (int)b!=b) throw "Non-int was inputted, try again\n";
		f1((int)a, (int)b);
	}
	catch(const char* err){
		cout<<err;
	}
	cout<<"In main function\n";
	return 0;
}
