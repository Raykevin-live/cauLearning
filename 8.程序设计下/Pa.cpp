//StudybarCommentBegin
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
int pA(string ss)
{
//StudybarCommentEnd

	int ret = 0;
	for(int i=0; i<ss.size(); i++){
		ret += (ss[i]-'A'+1);
	}
	return ret;
}

//StudybarCommentBegin
int main()
{
	string s;
	cin>>s;
	cout<<pA(s)<<endl;
        return 0;
}
//StudybarCommentEnd
