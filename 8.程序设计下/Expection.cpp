#include <iostream>
//#include <exception>

int main(){
	double a, b;
	std::cin>>a>>b;
	
	try{
		double ret = a/b;
		if(b==0) throw false;
		std::cout<<ret<<std::endl;	
	} 
	catch(bool){
		std::cout<<"Attempted to divide by zero!"<<std::endl;
	}
	catch(...){
		
	}	
	
	return 0;
}
