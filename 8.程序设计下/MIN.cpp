//StudybarCommentBegin
#include<iostream>
#include <string>
using namespace std;
//StudybarCommentEnd

//template<class T>
//const T min(T a, T b){
//	return a>b?b:a;
//}
//
//string min(string a, string b){
//	return a<b?a:b;
//}
//StudybarCommentBegin
int main(void) 
{int a1, a2;
	double b1, b2;
	char c1, c2;
	std::string s1, s2;
	std::cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> s1 >> s2;
	std::cout << min(a1, a2) << ' ' << min(b1, b2) << ' ' << min(c1, c2) << ' ' << min(s1, s2) << std::endl;
return 1;
} 
//StudybarCommentEnd
