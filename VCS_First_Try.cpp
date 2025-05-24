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
			cout<<"\n\t Exiting..."<<endl;
			break;
		}
		else{
			cout<<"Invalid choice!"<<endl;
		}
	}while(choice!=4);	
	
}

int choose(){
	int ch;
	system("cls");
	cout<<"\n\t1-Write To your File."<<endl;
	cout<<"\n\t2-Append to your File."<<endl;
	cout<<"\n\t3-Read From your File."<<endl;
	cout<<"\n\t4-Exit."<<endl;
	cout<<"\nEnter your choice(1-4): ";
	cin>>ch;
	cin.ignore();
	return ch;
}

void write(){
		system("cls");
		
		char sure;
		cout<<"This is going to overwrite any present data in your file. Are you sure you want to continue? (y/n) : ";
		cin>>sure;
		
		while(true){
			if(sure != 'y' && sure!= 'n'){
	            cout<<"Invalid choice :( , Please choose y or n !"<<endl;
	            cin>>sure;
       		}
        	else
	   		    break;
	   }
	
	if(sure == 'y'){
		cout<<"\n\tYouve Choosen to OverWrite the exisitng data on file :) !!! "<<endl;
			
			fstream myFile;
			string text;
		myFile.open("NewTextFile.txt",ios::out);
		cout<<"Enter the text to write in the txt file ( \"exit\" to exit ) : "<<endl;
			
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
		cout<<"Sorry your file wasnt able to open! :( "<<endl;	
		
		}while(myFile.is_open());
	}
	else if (sure == 'n') {
		system("cls");
		cout<<"Youve choosen not to overwrite the file!,Exiting write(overwrite) mode :) !! "<<endl;
	}
}

void append(){
	fstream myFile;
	string text;
	myFile.open("NewTextFile.txt",ios::app);
	system("cls");
	cout<<"Enter the text you want to append in your file!"<<endl;
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
				cout<<"Sorry your file wasnt able to open! :( "<<endl;
	}while(myFile.is_open());
	
}

void read(){
	fstream myFile;
	myFile.open("NewTextFile.txt",ios::in);
	system("cls");
		if(myFile.is_open()){
			if(myFile.peek() == EOF){
				cout<<"The File is EMPTY! Nothing to Read Here ~_~ "<<endl;
			}
			else{
			
			string line;
			while(getline(myFile,line)){
				cout<<line<<endl;      }	
		       }
		}
		else{
				cout<<"Sorry your file wasnt able to open! :( "<<endl;
	}
		cin.get();		
}
