//StudybarCommentBegin
#include<iostream>
using namespace std;
//StudybarCommentEnd


template<class T>
class Sample{
private:
	T a;
public:
	Sample<T> operator+(Sample<T>& x){
		return Sample<T>(a+x.a);
	}
	Sample(T x = static_cast<T>(0)){
		a = x;
	}
	void disp(){
		cout<<a<<endl; 
	} 
};	
//StudybarCommentBegin
int main(){        
        int a1, a2;
	float b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	Sample<int> s1(a1), s2(a2),s3;
	Sample<float> t1(b1), t2(b2),t3;
	s3 = s1 + s2;
	t3 = t1 + t2;
	s3.disp();
	t3.disp();

       return 1;
}
//StudybarCommentEnd
