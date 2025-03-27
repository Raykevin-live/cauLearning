#include <iostream>

using namespace std;

int maxinum(int a, int b, int c){
	int max = a>b?a:b;
	max = max>c?max:c;
	return max;
}
float maxinum(float a, float b, float c){
	float max = a>b?a:b;
	max = max>c?max:c;
	return max;
}
char maxinum(char a, char b, char c){
	char max = a>b?a:b;
	max = max>c?max:c;
	return max;
}
//StudybarCommentBegin
int main()
{
 	int b1, b2, b3;
	float c1, c2, c3;
	char a1, a2, a3;
	cin >> b1 >> b2 >> b3 >> c1 >> c2 >> c3>> a1 >> a2 >> a3;
	cout << maxinum(b1, b2, b3) << ' ' << maxinum(c1, c2, c3) << ' ' << maxinum(a1, a2, a3);
	return 0;
}
//StudybarCommentEnd
