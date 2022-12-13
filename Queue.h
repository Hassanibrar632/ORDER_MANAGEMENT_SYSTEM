#include "Rider_Node.h"

//Queue for Storing Riders and Orders in code........ 
class Queue{
public:
	Order_Node *f_O, *l_O;
	Rider_Node *F_R, *L_R;
	
	Queue(){
		f_O = NULL;
		l_O = NULL;
		F_R = NULL;
		L_R = NULL;
	}
	
	void Add_Rider(){
		if(F_R == NULL && L_R == NULL){
			F_R = new Rider_Node;
			L_R = F_R;
			return;
		}
		L_R->Next = new Rider_Node;
		L_R = L_R->Next;
	}
	
	Rider* Pop_Rider(){
		if(F_R->Next == NULL){
			Rider* Temp = F_R->Current;
			F_R = NULL;
			L_R = NULL;
			return Temp;
		}
		Rider* Temp = F_R->Current;
		F_R = F_R->Next;
		return Temp;
	}
	
	void Add_Order(string Array[], int x){
		if(f_O == NULL && l_O == NULL){
			f_O = new Order_Node(Array, x);
			l_O = f_O;
			return;
		}
		l_O->Next = new Order_Node(Array, x);
		l_O = l_O->Next;
	}
	
	Order* Pop_Order(){
		if(f_O->Next == NULL){
			Order* Temp = f_O->Current;
			f_O = NULL;
			l_O = NULL;
			return Temp;
		}
		Order* Temp = f_O->Current;
		f_O = f_O->Next;
		return Temp;
	}
};
