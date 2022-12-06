#include "Order.h"

class Order_Node{
public:
	Order *Current;
	Order_Node *Next;
	
	
	
	Order_Node(string Array[], int x){
		Current = new Order(Array, x);
		Next = NULL;
	}
};

