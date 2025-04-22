#include <iostream> //cin、cout
#include <string> //string
#include <stdio.h> //freopen
#include <iomanip>
using namespace std;

int main() 
{ 
//	fflush;
//	string name, url;
//	//将标准输入流重定向到 in.txt 文件
//	freopen("in.txt", "r", stdin);
//	cin >> name >> url;
//	//将标准输出重定向到 out.txt文件
//	freopen("out.txt", "w", stdout); 
//	cout << name << "\n" << url; 
//	int a;
//	cout<<"input a:";
//	cin>>a;
//	cout<<"dec:"<<dec<<a<<endl;
//	cout<<"hex:"<<hex<<a<<endl;
//	cout<<"oct:"<<setbase(10)<<a<<endl;
//	char *pt="China";
//	cout<<setw(10)<<pt<<endl;
//	cout<<setfill('*')<<setw(10)<<pt<<endl;
//	double pi=22.0/7.0;
////	cout<<setiosflags(ios::scientific)<<setprecision(10);
////	cout<<setiosflags(ios::scientific)<<setprecision(8);
////	cout<<"pi="<<pi<<endl;
////	cout<<"pi="<<setprecision(4)<<pi<<endl;
//	cout<<"pi="<<setiosflags(ios::fixed)<<pi<<endl;
//	return 0;

//string str = "nc.ude.uac.www";
//for (int i = str.length() - 1; i >= 0; i--)  
//{
//cout.put(str[i]); //从最后一个字符开始输出
//}
//	cout.put('\n'); return 0;

	cout.write("www.", 6).write("cau.edu",10).write("cn",4); //
	return 0;
}
