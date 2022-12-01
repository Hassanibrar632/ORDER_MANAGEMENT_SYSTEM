#include "Item.h"

//Just to find Path..............
class Graph{
	string *Vertices;
	int **Edges;
public:
	
	string* Get_Vertices(){
		return Vertices;
	}
	
	Graph(){
		Vertices = NULL;
		Edges = NULL;
		Set_Graph();
	}
	
	void Set_Graph(){
		Vertices = new string[7];
		string T[7] = {"H-7", "library", "H-11 || H-12", "H-8", "H-5 || H-3 || H-6 || H-4 ", " H-1 || H-9 || H-2 || H-10", "TUC"};
		for(int i=0; i<7; i++){
			Vertices[i] =T[i];
		}
		Edges = new int*[7];
		int Temp[7][7] = {
			{0,0,0,0,0,0,1},//1
			{0,0,1,1,0,0,1},//2
			{0,1,0,1,0,1,1},//3
			{0,1,1,0,1,0,1},//4
			{0,0,0,1,0,1,0},//5
			{0,0,1,0,1,0,1},//6
			{1,1,1,1,0,1,0},//7
		};
		for(int i=0; i<7; i++){
			Edges[i] = new int[7];
		}
		for(int x=0; x<7; x++){
			for(int y=0; y<7; y++){
				Edges[x][y] = Temp[x][y];
			}
		}
	}
	Node *Get_Path(string S, string E){
		int index=0;
		bool Visited [7];
		for(int i=0; i<7; i++){
			Visited[i] = false;
		}
		string To[7], From[7];
		Visited[Get_index(S)] = true;
		Node* F = NULL;
		F = new Node;
		F->Name = S;
		Node* L = F;
		bool Found = false;
		while(F != NULL){
			string Now = F->Name;
			if(Now == E){
				Found = true;
				cout << "Found......\n";
				break;
			}
			if(F == L){
				F = NULL;
				L = NULL;
			}else{
				F = F->Next;
			}
			for(int i=0; i<7; i++){
				if(Edges[Get_index(Now)][i] != 0 && Visited[i] == false){
					Visited[i] = true;
					From[index] = Now;
					To[index++] = Vertices[i];
					if(F == NULL){
						F = new Node;
						F->Name = Vertices[i];
						L = F;
					}else{
						L->Next = new Node;
						L = L->Next;
						L->Name = Vertices[i];
					}
				}
			}
		}
		if(!Found){
			cout << "Not found...\n";
			return NULL;
		}
		Node *Path = new Node;
		Path->Name = E;
		Node *Temp = Path;
		string Find = E;
		cout << "Path: ";
		for(int i=index; i>-1; i--){
			for(int X=0; X<7; X++){
				if(To[X ]== Find){
					cout << Find << " <-- ";
					Find = From[X];
					Temp->Next = new Node;
					Temp = Temp->Next;
					Temp->Name = From[X];
				}
			}
		}
		cout << S << endl;
		return Path;
	}
	void Display(){
		cout << "Vertices:\n";
		for(int i=0; i<7; i++){
			cout << 1+i << ") " << Vertices[i] << "\n";
		}
		cout << "\nEdges: " << "\n";
		for(int x=0; x<7; x++){
			cout << "\t";
			for(int y=0; y<7; y++){
				cout << Edges[x][y] << " ";
			}
			cout << "\t\t" << Vertices[x] << "\n";
		}
	}
	
	int Get_index(string A){
		for(int i=0; i<7; i++){
			if(Vertices[i] == A){
				return i;
			}
		}
	}
};

