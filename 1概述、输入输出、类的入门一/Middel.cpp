//StudybarCommentBegin
#include<iostream>
using namespace std;


//StudybarCommentEnd


int middle(int iNumber[]){
	
	for(int i=0; i<2; i++){
		for(int j=i+1; j<3; j++){
			if(iNumber[i]>iNumber[j]){
				int tmp = iNumber[i];
				iNumber[i] = iNumber[j];
				iNumber[j] = tmp;
			}
		}		
	}
	return iNumber[1];
}
double middle(double dNumber[]){
	for(int i=0; i<2; i++){
		for(int j=i+1; j<3; j++){
			if(dNumber[i]>dNumber[j]){
				double tmp = dNumber[i];
				dNumber[i] = dNumber[j];
				dNumber[j] = tmp;
			}
		}
	}
	return dNumber[1];
}
unsigned middle(unsigned uNumber[]){
	for(int i=0; i<2; i++){
		for(int j=i+1; j<3; j++){
			if(uNumber[i]>uNumber[j]){
				double tmp = uNumber[i];
				uNumber[i] = uNumber[j];
				uNumber[j] = tmp;
			}
		}	
	}
	return uNumber[1];
}



//StudybarCommentBegin
int main()
{
	int iNumber[3]={45,3,89};
	double dNumber[3]={12.4,6,55.8};
	unsigned uNumber[3]={345,776,565};

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<iNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(iNumber)<<endl;

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<dNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(dNumber)<<endl;

	cout<<"\nThe numbers are ";
	for( int i=0;i<3;i++)
		cout<<uNumber[i]<<"\t";
	cout<<endl<<"the middle of them is "<<middle(uNumber)<<endl;

	return 0;
}
//StudybarCommentEnd
