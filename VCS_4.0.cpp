#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

void write();
void read();
int choose();
void append();
void saveversion();
void showLogHistory();

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
        saveversion();
        }
		else if(choice == 5){
        showLogHistory();
        }
		else if(choice == 6){
			system("cls");
			cout<<"\n\t \033[32mExiting...\033[0m"<<endl;
			break;
			}
//		else{
//			system("cls");
//			cout<<"Invalid choice!"<<endl;
//		}
	}while(choice!=6);	
	
}

int choose(){
	int ch;
	system("cls");
	cout<<"\n\t\033[33m1-Write To your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m2-Append to your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m3-Read From your File.\033[0m"<<endl;
    cout<<"\n\t\033[33m4-Save File Version.\033[0m"<<endl;
	cout<<"\n\t\033[33m5-Show Log History.\033[0m"<<endl;
	cout<<"\n\t\033[33m6-Exit.\033[0m"<<endl;
	cout<<"\n\033[33mEnter your choice(1-6): \033[0m";
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
		cout<<"\n\n\t\033[31mYouve choosen not to overwrite the file!,Press Enter to Exit write(overwrite) mode :) !! "<<endl;
		cout<<"\n\t";
        system("pause");
        cout<<"\033[0m";
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
				cout<<"\n\t\t\033[31mThe File is EMPTY! Nothing to Read Here ~_~ "<<endl;
                cout<<"\n\n\t";
                system("pause");
                cout<<"\033[0m";
            }
			else{
			
			string line;
			cout<<"\n";
			while(getline(myFile,line)){
				cout<<line<<endl;      }	
		       }
		} 
		else{
				cout<<"\n\t\t\033[31mSorry your file wasnt able to open! :( "<<endl;
                cout<<"\n\t";
                system("pause");
                cout<<"\033[0m";
				return;
            }
		cin.get();		
}

void saveversion(){

	string verFileName;
	int verNum=1;
	while(true){													//version naem checking (no duplicate names)
		
		verFileName="Version_"+to_string(verNum)+".txt";
		ifstream test(verFileName);
		if (!test) break;
		verNum++;  
	}
	
	ifstream myFile("NewTextFile.txt");
    
	system("cls");
    //time_t now = time(0); to remembre 
	
	system("cls");

    if(myFile.peek()==EOF){													// checks if the file is empty (not to save empty file as version)
        
        cout<<"\n\t\t\033[31mERROR! CANT SAVE EMPTY FILE AS VERSION!!"<<endl;
        cout<<"\n\t";
        system("pause");
        cout<<"\033[0m";
        return;
    }

	ofstream verFile(verFileName);

    string line;															// after test it will be saved :)
    while(getline(myFile,line)){
        verFile<<line<<endl;
    }
    myFile.close();
    verFile.close();

    cout<<"\n\n\t\t\033[32mVersion Saved Sucessfully!!"<<endl;	
    cout<<"\n\t";
    system("pause");
    cout<<"\n\t\033[36m========================================\n\033[0m"<<endl;

	ofstream logFile("log.txt",ios::app);									//Log Enteriees  
	if(logFile)	{
		time_t now = time(0);
		string dt = ctime(&now);
		logFile<< verFileName << "\t saved at :  "<< dt<<endl;
		logFile.close();  
		cout<<"\t\t\033[32mLog Entry Saved Sucessfully!!"<<endl;
		cout<<"\n\t\033[36m========================================\n\t"<<endl;
		system("pause");
		cout<<"\033[0m";	
		//cout<<"\n\t";
		//system("pause");
	}
	else {
		cout<<"\n\t\t\033[31mERROR! Couldnt save Log Entry! :( ";
		cout<<"\n\t";
        system("pause");
        cout<<"\033[0m";
		
	}
    

}

void showLogHistory(){
    ifstream log("log.txt");
	
	system("cls");

	if(!log){
		cout<<"\n\t\t\033[31mNO LOG FILE FOUND!! Maybe try saving file(Version) first. :) ";
		system("pause");
		cout<<"\033[0m";
		return;
	}
	cout<<"\n\t	\033[35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;

	string line;
	bool flag = false;
	while(getline(log,line)){
		cout<<"\t\033[32m"<<line<<"\033[0m\n";
		flag = true;
	}
	if(!flag){
		cout<<"\n\t\033[31mNo LOG Enteries FOUND!! :( \033m[0m"<<endl;
	}

	cout<<"\t\t\033[35m========================================\n\t\033[0m"<<endl;
	cout<<"\033[36m";
	system("pause");
	cout<<"\033[0m";
}

    