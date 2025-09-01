#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "TDL.h"

using namespace std;

void Menu(){
	system("cls");
	Start:
	int choice;
	cout<<"\t\t___________________________________________________"<<endl;
	cout<<"\t\t||=====------	To do list	--------=====||"<<endl;
	cout<<"\t\t==================================================="<<endl;
	cout<<"\t\t1. Add task"<<endl;
	cout<<"\t\t2. Modify task"<<endl;
	cout<<"\t\t3. Display tasks"<<endl;
	cout<<"\t\t4. Remove task"<<endl;
	cout<<"\t\t5. Exit"<<endl;
	cout<<"\t\tChoose from choices:[1/2/3/4/5]"<<endl;
	cout<<"\t\t";
	cin>>choice;
	
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout<<"\n\t\tInvalid input"<<endl;
		goto Start;
	}
	
	switch(choice){
		case 1:
			AddTask();
			ReturnMenu();
			break;
			case 2:
				ModifyTask();
				ReturnMenu();
				break;
				case 3:
					DisplayTasks();
					ReturnMenu();
					break;
					case 4:
						RemoveTask();
						ReturnMenu();
						break;
						case 5:
							cout<<"\n\t\tExiting!....."<<endl;
							exit(0);
							break;
							default:
								cout<<"\n\t\tInvalid input!"<<endl;
								Menu();
								break;
	}
}

void ReturnMenu(){
	int choice;
	cout<<"\n\t\t1. Back to menu"<<endl;
	cout<<"\t\t2. Exit"<<endl;
	cout<<"\t\t";
	cin>>choice;
	
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout<<"Invalid input!"<<endl;
		ReturnMenu();
	}
	
	switch(choice){
		case 1:
			Menu();
			break;
			case 2:
				cout<<"\n\t\tExiting"<<endl;
				return;
				break;
				default:
					cout<<"\n\t\tInvalid input!"<<endl;
					ReturnMenu();
					break;
	}
}

void AddTask(){
	system("cls");
	string Description;
	
	cout<<"\t\t_______________________________________\n"<<endl;
	cout<<"\t\t||===--------Add new task--------====||\n"<<endl;
	cout<<"\t\t=======================================\n"<<endl;
	cout<<"\t\tEnter task:\n\t\t";
	cin>> Description;
	
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Invalid input......"<<endl;
		AddTask();
	}
	
	fstream LIST;
	LIST.open("TO_DO_List.txt",ios::app);
	if(LIST.is_open()){
		LIST<<Description<<endl;
	}
	LIST.close();
	cout<<"\n\t\tTask added successfully!"<<endl;
	ReturnMenu();
}

void DisplayTasks(){
	system("cls");
	string line;
	int num;
	cout<<"\t\t______________________________________________"<<endl;
	cout<<"\t\t||=====---------PRESENT TASKS----------=====||"<<endl;
	cout<<"\t\t==============================================\n"<<endl;
	ifstream LIST("TO_DO_List.txt");
		while(getline(LIST,line)){
			cout<<"\t\t"<<line<<endl;
		}
	LIST.close();
	cout<<"\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
	ReturnMenu();
}

void ModifyTask(){
	system("cls");
	string ModifyTarget;
	string line;
	string NewTask;
	cout<<"\t\t_______________________________________________"<<endl;
	cout<<"\t\t||=====--------- MODIFYING TASK --------=====||"<<endl;
	cout<<"\t\t==============================================="<<endl;
	cout<<"\t\tEnter task you wish to change:\n\t\t";
	cin>>ModifyTarget;
	cout<<"\n\t\tEnter modified task:\n\t\t";
	cin>>NewTask;
	ifstream LIST("TO_DO_List.txt");
	ofstream TempFile("Tempfile.txt");
		while(getline(LIST, line)){
			if(line != ModifyTarget){
				TempFile<<line<<endl;
			}
			else if(line == ModifyTarget){
				TempFile<<NewTask<<endl;
				cout<<"Task modification successfully"<<endl;
			}
		}
	LIST.close();
	TempFile.close();
	remove("TO_DO_List.txt");
	rename("Tempfile.txt", "TO_DO_List.txt");
	ReturnMenu();
}

void RemoveTask(){
	system("cls");
	string line;
	string DelTask;
	cout<<"_______________________________________________________"<<endl;
	cout<<"||========----------- REMOVE TASK -----------========||"<<endl;
	cout<<"======================================================="<<endl;
	cout<<"\t\tEnter task to remove:\n\t\t";
	cin>>DelTask;
	
	ifstream LIST("TO_DO_List.txt");
	ofstream TempFile("TempFile.txt");
	
	while(getline(LIST, line)){
		if(line != DelTask){
			TempFile<<line<<endl;
		}
	}
	LIST.close();
	TempFile.close();
	remove("TO_DO_List.txt");
	rename("TempFile.txt", "TO_DO_List.txt");
	
	ReturnMenu();
}