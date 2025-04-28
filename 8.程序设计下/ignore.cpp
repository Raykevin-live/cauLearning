#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string str;
	char name1[20], name2[20];
	stringstream ss;
	
	cin.getline(name1, 10, '.');
	cin.putback('.');
	cin>>name2;
	cout<<name1<<endl; 
	cout<<name2<<endl; 
	cin.get();
	cin.getline(name1, 10, '.');

	cin.getline(name2, 20);
	cout<<name1<<endl; 
	cout<<name2<<endl; 
	
	return 0;
}
