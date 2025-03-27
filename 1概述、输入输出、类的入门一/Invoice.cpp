#include <iostream>
using namespace std;

class Invoice{
private:
	string _part_number;
	string _part_description;
	int _quantity;
	int _price_per_item;
public:
	Invoice(string part_number = "111", string part_description = "None", int quantity = 0, int price_per_item = 0){
		if(quantity<0){
			quantity = 0;
		}
		if(price_per_item<0){
			price_per_item = 0;
		}
		_part_number = part_number, _part_description = part_description;
		_quantity = quantity;
		_price_per_item = price_per_item;
	}
	string getPartNumber(){
		return _part_number;
	}
	string getPartDescription(){
		return _part_description;
	}
	int getQuantity(){
		return _quantity;
	}
	int getPricePerItem(){
		return _price_per_item;
	}
	int getInvoiceAmount(){
		return _quantity*_price_per_item;
	}
	void setPartNumber(const string& part_number){
		_part_number = part_number;
	}
	void setPartDescription(const string& part_description){
		_part_description  = part_description;
	}
	void setQuantity(const int& quantity){
		if(quantity<0){
			_quantity = 0;
			cout<<"quantity set to 0";
		}
		else{
			_quantity = quantity;
		}
		
	}
	void setPricePerItem(const int& price_per_item){
		if(price_per_item < 0){
			_price_per_item = 0;
		}
		else{
			_price_per_item = price_per_item;
		}
	}
};

//StudybarCommentBegin
int main()
{
    // create an Invoice object
    Invoice invoice( "12345", "Hammer", 100, 5 );
    
    // display the invoice data members and calculate the amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    
    // modify the invoice data members
    invoice.setPartNumber( "123456" );
    invoice.setPartDescription( "Saw" );
    invoice.setQuantity( -5 ); // negative quantity, so quantity set to 0
    invoice.setPricePerItem( 10 );
    cout << "\nInvoice data members modified.\n";
    
    // display the modified invoice data members and calculate new amount
    cout << "Part number: " << invoice.getPartNumber() << endl;
    cout << "Part description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice amount: $" << invoice.getInvoiceAmount() << endl;
    return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
