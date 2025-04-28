#include <iostream>
#include<string>
#include <exception>
#include <stdexcept>
using namespace std;


class TriExcpt:public runtime_error{
public:
	explicit TriExcpt(const char* msg = "Not a normal triangle, a=b+c.") : runtime_error(msg) {} 
    const char* what() const noexcept  { return runtime_error::what(); }	
};
class SubTriExcpt:public TriExcpt{
public:
	SubTriExcpt(const char* msg = "Not a triangle, a>b+c."):TriExcpt(msg){}
	const char* what() const noexcept  { return runtime_error::what(); }
}; 

class triangle{
private:
	float a, b, c;
	int flag;
public:
	triangle(float a, float b, float c){
		this->a = a, this->b = b, this->c = c;
		flag = judgement(); 
		if(flag == 1) {
			throw TriExcpt();
		} 
		else if(flag == 2) {
			throw SubTriExcpt();
		} 
		else if(flag==3){
			throw SubTriExcpt("Not a triangle, a=0.");
		}
		else if(flag == 4) {
			throw runtime_error("All o inputted.");
		}
	}
	float perimeter(){
		return a+b+c;
	}
	~triangle(){
		
	}
	int judgement(){
		if(a == 0 && b == 0 && c == 0) {
			return 4;
		} 
		else if( a == 0 || b == 0 || c == 0){
			return 3;
		}
		else if(a + b < c || a + c < b || b + c < a) {
			return 2;
		} 
		else if(a + b == c || a + c == b || b + c == a) {
			return 1;
		}
		return -1;
	}
};
//StudybarCommentBegin
int main()
{
	float a, b, c;
	cin >> a >> b >> c;
	try	{
		triangle Tr1(a, b, c);
		cout << Tr1.perimeter() << endl;
	}
	catch (const runtime_error &e) {
		cout << e.what() << endl;
	}
        return 1;
}
//StudybarCommentEnd
