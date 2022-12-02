#include "Graph.h"

//Just to add shop in the code........
class Shop{
public:
	string Name;
	Node *items;
	Shop *Next;
	
	Shop(){
		cout << "Enter the Name of the Shop: ";
		cin >> Name;
		items = NULL;
		Next = NULL;
	}
	
	void Add_Item(Item* I){
		Item *Temp = I;
		while(Temp != NULL){
			cout << Temp->Name << "\t" << Temp->Price << endl;
			Temp = Temp->Next;
		}
		cout << "Enter Name of the Item you want to Enter: ";
		string New;
		cin >> New;
		Node *Old = items;
		Temp = I;
		bool Found = false;
		while(Temp != NULL){
			if(Temp->Name == New){
				Found = true;
				break;
			}
			Temp = Temp->Next;
		}
		if(Found != true){
			cout << "Wrong Input.......\n";
			return;
		}
		if(items == NULL){
			items = new Node;
			items->Name = New;
			cout << "Added : " << items->Name << endl;
			return;
		}
		while(Old != NULL){
			if(Old->Name == New){
				cout << "Already added into the Shop...........\n";
				return;
			}
			Old = Old->Next;
		}
		Node *T = new Node;
		T->Next = items;
		T->Name = New;
		items = T;
		cout << "Added : " << items->Name << endl;
	}
};
