#include "Queue.h"

void HUB(){
	Graph Map;
	char Choice;
	Queue Data;
	Item *Base_I = NULL;
	Shop *Base_S = NULL;
	while(Choice != 'Q' && Choice != 'q'){
		system("cls");
		cout << "1) Open Item Settings\n"
			 << "2) Open Shop Settings\n"
			 << "3) Open Ordes Settings\n"
			 << "4) Open Riders Settings\n"
			 << "q) Quit\n"
			 << "Enter Your Choice: ";
		cin >> Choice;
		switch(Choice){
			case '1':{
				while(Choice != 'Q' && Choice != 'q'){
					system("cls");
					cout << "1) Add Item\n"
						 << "2) Delete Item\n"
						 << "3) Change Item\n"
						 << "4) Display\n"
						 << "q) Back to menu\n"
						 << "Enter your option: ";
					cin >> Choice;
					switch(Choice){
						case '1':{
							if(Base_I == NULL){
								Base_I =new Item;
								break;
							}
							Item *Tail = new Item;
							Tail->Next = Base_I;
							Base_I = Tail;
							break;
						}
						case '2':{
							Item* Temp = Base_I;
							cout << "Name\t\t\tPrice\n";
							while(Temp != NULL){
								cout << Temp->Name << "\t\t" << Temp->Price << "\n";
								Temp = Temp->Next;
							}
							cout << "Enter Item you Want to Delete: ";
							string input;
							cin >> input;
							Temp = Base_I;
							Item *Pre = Base_I;
							if(Temp->Name == input){
								if(Temp->Next == NULL){
									Base_I = NULL;
									break;
								}
								Base_I = Temp->Next;
								break;
							}
							while(Temp != NULL){
								if(Temp->Name == input){
									Pre->Next = Temp->Next;
									cout << "............Done............\n";
									system("pause");
									break;
								}
								Pre = Temp;
								Temp = Temp->Next;
							}
							cout << "..........NOTHING FOUND............\n";
							system("pause");
							break;
						}
						case '3':{
							Item* Temp = Base_I;
							cout << "Name\t\t\tPrice\n";
							while(Temp != NULL){
								cout << Temp->Name << "\t\t" << Temp->Price << "\n";
								Temp = Temp->Next;
							}
							cout << "Enter Item you Want to Edit: ";
							string input;
							cin >> input;
							Temp = Base_I;
							while(Temp != NULL){
								if(Temp->Name == input){
									cout << "Enter New Name: ";
									cin >> Temp->Name;
									cout << "Enter New Price: ";
									cin >> Temp->Price;
									break;
								}
								Temp = Temp->Next;
							}
							break;
						}
						case '4':{
							Item* Temp = Base_I;
							while(Temp != NULL){
								cout << Temp->Name << "\t\t" << Temp->Price << "\n";
								Temp = Temp->Next;
							}
							system("pause");
							break;
						}
					}
				}
				Choice = '0';
				break;
			}
			case '2':{
				while(Choice != 'Q' && Choice != 'q'){
					system("cls");
					cout << "1) Add Shop\n"
						 << "2) Delete Shop\n"
						 << "3) Shop items\n"
						 << "4) Display Shop\n"
						 << "5) Display Shops Names\n"
						 << "q) Back to menu\n"
						 << "Enter your option: ";
					cin >> Choice;
					switch(Choice){
						case '1':{
							if(Base_S == NULL){
								Base_S =new Shop;
							}else{
								Shop *Tail = new Shop;
								Tail->Next = Base_S;
								Base_S = Tail;
							}
							break;
						}
						case '2':{
							Shop* Temp = Base_S;
							cout << "Name:\n";
							while(Temp != NULL){
								cout << Temp->Name << "\n";
								Temp = Temp->Next;
							}
							cout << "Enter Shop you Want to Delete: ";
							string input;
							cin >> input;
							Temp = Base_S;
							Shop *Pre = Base_S;
							if(Temp->Name == input){
								if(Temp->Next == NULL){
									Base_S = NULL;
									break;
								}
								Base_S = Base_S->Next;
								break;
							}
							while(Temp != NULL){
								if(Temp->Name == input){
									Pre->Next = Temp->Next;
									cout << "............Done............\n";
									break;
								}
								Pre = Temp;
								Temp = Temp->Next;
							}
							system("pause");
							break;
						}
						
						case '3':{
							Shop* Temp = Base_S;
							cout << "Name:\n";
							while(Temp != NULL){
								cout << Temp->Name << "\n";
								Temp = Temp->Next;
							}
							cout << "Enter Shop Name: ";
							string input;
							cin >> input;
							Temp = Base_S;
							while(Temp != NULL){
								if(Temp->Name == input){
									Temp->Add_Item(Base_I);
									break;
								}
								Temp = Temp->Next;
							}
							system("pause");
							break;
						}
						
						case '4':{
							Shop* Temp = Base_S;
							cout << "Name:\n";
							while(Temp != NULL){
								cout << Temp->Name << "\n";
								Temp = Temp->Next;
							}
							cout << "Enter Shop Name: ";
							string input;
							cin >> input;
							Temp = Base_S;
							while(Temp != NULL){
								if(Temp->Name == input){
									Node* T = Temp->items;
									while(T != NULL){
										Item *I = Base_I;
										while(I != NULL){
											if(I->Name == T->Name){
												cout << I->Name << "\t\t" << I->Price << "\n";
												break;
											}
											I = I->Next; 
										}
										T = T->Next;
									}
									system("pause");
									break;
								}
								Temp = Temp->Next;
							}
							break;
						}
						
						case '5':{
							Shop* Temp = Base_S;
							cout << "Name: \n";
							while(Temp != NULL){
								cout << Temp->Name << "\n";
								Temp = Temp->Next;
							}
							system("pause");
							break;
						}
					}
				}
				Choice = '0';
				break;
			}
			case '4':{
				while(Choice != 'Q' && Choice != 'q'){
					system("cls");
					cout << "1) Add Rider\n"
						 << "2) Display Rider\n"
						 << "q) Back to menu\n"
						 << "Enter your option: ";
					cin >> Choice;
					switch(Choice){
						case '1':{
							Data.Add_Rider();
							break;
						}
						case '2':{
							Rider_Node* R = Data.F_R;
							while(R != NULL){
								cout << R->Current->Name << " ";
								R = R->Next;
							}
							cout << "\n";
							system("pause");
							break;
						}
					}
				}
				Choice = '0';
				break;
			}
			case '3':{
				while(Choice != 'Q' && Choice != 'q'){
					system("cls");
					cout << "1) Add Order\n"
						 << "2) Add items to Order\n"
						 << "3) Display Orders\n"
						 << "4) Delete Order\n"
						 << "5) Diliver Orders\n"
						 << "q) Back to menu\n"
						 << "Enter your option: ";
					cin >> Choice;
					switch(Choice){
						case '1':{
							Data.Add_Order(Map.Get_Vertices(), 7);
							break;
						}
						case '2':{
							Order_Node* Temp = Data.f_O;
							while(Temp != NULL){
								Temp->Current->Display();
								Temp = Temp->Next;
							}
							cout << "Enter the Customer Name: ";
							string N;
							cin >> N;
							Temp = Data.f_O;
							while(Temp != NULL){
								if(Temp->Current->Name == N){
									Temp->Current->Add_Item(Base_I);
								}
								Temp = Temp->Next;
							}
							break;
						}
						case '3':{
							Order_Node* Temp = Data.f_O;
							while(Temp != NULL){
								Temp->Current->Display();
								Temp = Temp->Next;
							}
							system("pause");
							break;
						}
						case '4':{
							Order_Node* Temp = Data.f_O;
							while(Temp != NULL){
								Temp->Current->Display();
								Temp = Temp->Next;
							}
							cout << "Enter the Customer Name: ";
							string N;
							cin >> N;
							if(Data.f_O->Current->Name == N){
								if(Data.f_O->Next == NULL){
									Data.Pop_Order();
									break;
								}
								Data.f_O = Data.f_O->Next;
								break;
							}
							Temp = Data.f_O;
							Order_Node* Pre = Temp;
							while(Temp != NULL){
								if(Temp->Current->Name == N){
									Pre->Next = Temp->Next;
									return;
								}
								Pre = Temp;
								Temp = Temp->Next;
							}
							break;
						}
						case '5':{
							if(Data.f_O == NULL){
								cout << "SET an Order first...\n";
								system("pause");
								break;
							}
							Order* Temp = Data.Pop_Order();
							if(Data.L_R->Current->Departure(Temp) == true){
								Rider* Done = Data.Pop_Rider();
								//path and order print
								cout << "Done:\n"
									 << "Location: " << Done->Destination
									 << "\nCustomer: " << Done->Customer
									 << "\nItems: ";
								Node* T = Done->Items;
								while(T != NULL){
									cout << T->Name << " ";
									T = T->Next;
								}
								cout << "\nTotal Items: " << Done->Total_Items
									 << "\nTotal Price: " << Done->Price << endl;
								Map.Display();
								Map.Get_Path("TUC", Done->Destination);
							}
							system("pause");
							break;
						}
					}
				}
				Choice = '0';
				break;
			}
		}//main switch end
	}//loop end main
}//funtion end

