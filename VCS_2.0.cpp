#include<iostream>
#include<fstream>
using namespace std;

void write();
void read();
int choose();
void append();


int main(){
	int choice;
	do{
		choice = choose();
		
		if(choice == 1){
		write(); 
		}
		else if(choice == 2){
		append();
		}
		else if(choice == 3){
		read();
		}
		else if(choice == 4){
			system("cls");
			cout<<"\n\t \033[32mExiting...\033[0m"<<endl;
			break;
			}
//		else{
//			system("cls");
//			cout<<"Invalid choice!"<<endl;
//		}
	}while(choice!=4);	
	
}

int choose(){
	int ch;
	system("cls");
	cout<<"\n\t\033[33m1-Write To your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m2-Append to your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m3-Read From your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m4-Exit.\033[0m"<<endl;
	cout<<"\n\033[33mEnter your choice(1-4): \033[0m";
	cin>>ch;
	cin.ignore();
	return ch;
}

void write(){
		system("cls");
		
		char sure;
		cout<<"\033[33m\n\tThis is going to overwrite any present data in your file. Are you sure you want to continue? (y/n) : \033[0m";
		cin>>sure;
		cin.ignore();
		
		while(true){
			if(sure != 'y' && sure!= 'n'){
	            cout<<"\033[31mInvalid choice :( , Please choose y or n !\033[0m"<<endl;
	            cin>>sure;
	            cin.ignore();
       		}
        	else
	   		    break;
	   }
	
	if(sure == 'y'){
		cout<<"\n\t\033[36mYouve Choosen to OverWrite the exisitng data on file :) !!! \033[0m"<<endl;
			
			fstream myFile;
			string text;
		myFile.open("NewTextFile.txt",ios::out);
		cout<<"\n\t\033[32mEnter the text to write in the txt file ( \"exit\" to exit ) : \033[0m \n"<<endl;
			
	do{
		if(myFile.is_open()){
						getline(cin,text);
				if(text == "exit") 
				{
					myFile.close();
					break;
				}
			
			myFile<<text<<endl;
			}
		else
		cout<<"\033[31m\n\tSorry your file wasnt able to open! :( \033[0m"<<endl;	
		
		}while(myFile.is_open());
	}
	else if (sure == 'n') {
		system("cls");
		cout<<"\n\n\t\033[31mYouve choosen not to overwrite the file!,Press Enter to Exit write(overwrite) mode :) !!\033[0m "<<endl;
		system("pause>0");
	}
}

void append(){
	fstream myFile;
	string text;
	myFile.open("NewTextFile.txt",ios::app);
	system("cls");
	cout<<"\033[32m\n\tEnter the text you want to append in your file!\033[0m"<<endl;
	do{
		if(myFile.is_open()){
			getline(cin,text);
			if(text == "exit") 
			{
				myFile.close();
			}
		
			myFile<<text<<endl;
		}
		else
				cout<<"\n\t\t\033[31mSorry your file wasnt able to open! :( \033[0m"<<endl;
	}while(myFile.is_open());
	
}

void read(){
	fstream myFile;
	myFile.open("NewTextFile.txt",ios::in);
	system("cls");
		if(myFile.is_open()){
			if(myFile.peek() == EOF){
				cout<<"\n\t\t\033[31mThe File is EMPTY! Nothing to Read Here ~_~ \033[0m"<<endl;
			}
			else{
			
			string line;
			cout<<"\n";
			while(getline(myFile,line)){
				cout<<line<<endl;      }	
		       }
		}
		else{
				cout<<"\033[31mSorry your file wasnt able to open! :(\033[0m "<<endl;
	}
		cin.get();		
}
