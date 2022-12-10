#include "Order_Node.h"

//All difficult working and core programming is done here.....
class Rider{
public:
	Order *Dilever;
	string Name, Customer;
	int Total_Items;
	int Price;
	Node *Path;
	Node *Items;
	string Destination;
	
	Rider(){
		cout << "Enter Name: ";
		cin >> Name;
		Total_Items = 0;
		Price = 30;
		Dilever = NULL;
		Path = NULL;
		Items = NULL;
	}
	
	bool Departure(Order* O){
		if(O->Items == NULL){
			cout << "Nothing to diliver.....\n";
			return false;
		}
		this->Destination = O->Destination;
		this->Items = O->Items;
		this->Total_Items = O->Total_Items;
		this->Price += O->Total_Price;
		this->Customer = O->Name;
		return true;
	}
};

