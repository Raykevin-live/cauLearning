#include <iostream>

using namespace std;


int main(){
	int day;
	cin >> day;
	string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	day %= 8;
	switch(day){
		case 1:
			cout<<days[0]<<endl;
			break;
		case 2:
			cout<<days[1]<<endl;
			break;
		case 3:
			cout<<days[2]<<endl;
			break;
		case 4:
			cout<<days[3]<<endl;
			break;
		case 5:
			cout<<days[4]<<endl;
			break;
		case 6:
			cout<<days[5]<<endl;
			break;
		case 7:
			cout<<days[6]<<endl;
			break;
		default:
			cout<<"ÊäÈë´íÎó"<<endl;
			
	}

	return 0;
} 
