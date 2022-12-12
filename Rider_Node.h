#include "Rider.h"

//Just Node from Rider Class........
class Rider_Node{
public:
	Rider *Current;
	Rider_Node *Next;
	
	Rider_Node(){
		Current = new Rider;
		Next = NULL;
	}
};

