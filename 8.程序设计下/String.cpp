//StudybarCommentBegin
#include <iostream>
#include <cstring> // strcpy and strcat prototypes
using namespace std;


class String
{
public:
    String( const char * = "" ); // 输出"Conversion (and default) constructor: "
    String( const String & ); //输出 "Copy constructor: "
    ~String(); // 输出"Destructor: "

    bool operator==( const String & ) const; // test s1 == s2
    operator  char*(){ return this->sPtr; }; //转换函数 
    friend ostream &operator<<( ostream &out, const String &t );

private:
    int length; // string length (not counting null terminator)
    char *sPtr; // pointer to start of pointer-based string
}; 
//StudybarCommentEnd

String::String( const char * str){
	cout<<"Conversion (and default) constructor: ";
	if(str!=nullptr){
		length = strlen(str);
		sPtr = new char[length+1];
		strcpy(sPtr, str);
	}
	cout<<sPtr<<endl;
}
String::String( const String & str){
	cout<<"Copy constructor: ";
	length = str.length;
	sPtr = new char[length+1];
	strcpy(sPtr, str.sPtr);
	cout<<sPtr<<endl;
}
String::~String(){
	cout<<"Destructor: "<<sPtr<<endl;
	delete []sPtr;
	length = 0;
}
bool String::operator==( const String & str) const{
	return strcmp(sPtr, str.sPtr)==0;
}
ostream &operator<<( ostream &out, const String &t ){
	for(int i=0; i<t.length; i++){
		out<<t.sPtr[i];
	}
	return out;
}
//StudybarCommentBegin
int main()
{
	char msg[1000];
	cin>>msg;
	String a("This"), b(" is "), c(msg);
	cout<<a<<b<<c<<endl;	
	String A(a),B,C(c);
	cout<<A<<B<<C<<endl;
	cout <<"A==a is "<< (A==a ) <<endl<<"A==c is "<<(A==c)<<endl;
}
//StudybarCommentEnd
