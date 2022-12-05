#include "Shop.h"

//Set orders from Others and collect important Data....
class Order{
public:
	string Name, Destination;
	int Total_Price, Total_Items;
	Node *Items;
	
	Order(string Array[] =  NULL, int Total = 0){
		cout << "Enter Name: ";
		cin >> Name;
		cout << "Locations:\n";
		for(int i=0; i<Total; i++){
			cout << i+1 << ") " << Array[i] << "\n";
		}
		cout << "Select your Location: ";
		int x;
		cin >> x;
		Destination = Array[--x];
		Items = NULL;
		Total_Price = 0;
		Total_Items = 0;
	}
	
	void Add_Item(Item* I){
		cout << "Items: ";
		Item* Temp = I;
		while(Temp != NULL){
			cout << Temp->Name << "\t" << Temp->Price << "\n";
			Temp = Temp->Next;
		}
		cout << "Enter Item to Order: ";
		string N;
		cin >> N;
		Temp = I;
		while(Temp != NULL){
			if(Temp->Name == N){
				if(Items == NULL){
					Items = new Node;
					Items->Name = N;
					this->Total_Price += Temp->Price;
					this->Total_Items++;
					return;
				}
				Node* T = Items;
				while(T->Next != NULL){
					T = T->Next;
				}
				T->Next = new Node;
				T->Next->Name = N;
				this->Total_Items++;
				this->Total_Price += Temp->Price;
				return;
			}
			Temp = Temp->Next;
		}
		cout << "Nothing Found...\n";
	}	
	void Display(){
		cout << "Items Order by " << Name  << "(" << Destination << ")"<< ":\t";
		Node* Temp = Items;
		while(Temp != NULL){
			cout << Temp->Name << " ";
			Temp = Temp->Next;
		}
		cout << "\n";
	}
};
