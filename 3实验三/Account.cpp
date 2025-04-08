// Copyright 2025 Lenovo

#include <iostream>
 
using namespace std;

class Account{
public:
	double _Balance;
	explicit Account(double balance){
		if(balance < 0){
			cout<<"\nError:Initial balance cannot be negative.\n"<<endl;
			balance = 0;
		}
		_Balance = balance;
	}
	void credit(double money){
		_Balance += money;
	}
	void debit(double money){
		if(money <= _Balance){
			_Balance -= money;
		}
		else
		{cout<<"Debit amount exceeded account balance.\n"<<endl; }
	}
	double getBalance(){
		return _Balance;
	}
};
//StudybarCommentBegin
int main()
{
    Account account1(50.0);

    double withdrawalAmount;
//    cout<<"\nEnter withdrawal amount for account1:";
    cin>>withdrawalAmount;
    cout<<"\nattempting to subtract "<<withdrawalAmount<<" from account1 balance\n";
    
    account1.debit(withdrawalAmount);
    cout<<"account1 balance:$"<<account1.getBalance()<<endl;
    
    Account account2(-2);
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;
    account2.credit(156.4);
    cout<<"\nattempting to add "<<156.4<<" to account2\n";
    cout<<"account2 balance :$"<<account2.getBalance()<<endl;

    return 0;
}
//StudybarCommentEnd
