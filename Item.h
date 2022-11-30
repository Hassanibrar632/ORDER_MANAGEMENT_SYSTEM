#include "Node.h"

//Item Class to ADD Class...................
class Item{
public:
	string Name;
	float Price;
	Item *Next;
	
	Item(){
		Next = NULL;
		cout << "Enter Name: ";
		cin >> Name;
		cout << "Entr Price: ";
		cin >> Price;
	}
};

