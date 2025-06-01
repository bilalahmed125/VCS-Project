#include<iostream>
#include<fstream>
#include<ctime> 
#include<cstdio>

using namespace std;

void write();
void read();
int choose();
void append();
void saveversion();
void showLogHistory();
void deleteFile();

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
        deleteFile();
        }
		else if(choice == 7){
		system("cls");
		cout<<"\n\t \033[32mExiting...\033[0m"<<endl;
		break;
		}
//		else{
//			system("cls");
//			cout<<"Invalid choice!"<<endl;
//		}
	    }while(choice!=7);	
	
}

int choose(){
	int ch;
	system("cls");
	cout<<"\n\t\033[33m1-Write To your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m2-Append to your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m3-Read From your File.\033[0m"<<endl;
    cout<<"\n\t\033[33m4-Save File Version.\033[0m"<<endl;
	cout<<"\n\t\033[33m5-Show Log History.\033[0m"<<endl;
    cout<<"\n\t\033[33m6-Delete File Version.\033[0m"<<endl;
	cout<<"\n\t\033[33m7-Exit.\033[0m"<<endl;
	cout<<"\n\033[33mEnter your choice(1-7): \033[0m";
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
				break;
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
		cout<<"\n\t\033[31mNo LOG Enteries FOUND!! :( \033[0m"<<endl;
	}

	cout<<"\t\t\033[35m========================================\n\t\033[0m"<<endl;
	cout<<"\033[36m";
	system("pause");
	cout<<"\033[0m";
}

void deleteFile(){

    string fileName;
    int verNum;
    char choice,logchoice,reenterchoice;
	system("cls");

    cout<<"\n\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";

    while (true) {
        cout<<"\033[33mThis process will permanently delete the file. Want to continue? (y/n): \033[0m";
        cin>>choice;
        cin.ignore();
		system("cls");
		cout<<"\n\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";
        if(choice=='y' || choice=='Y'){
			cout<<"\n\033[33m=>Do you want to See FILE VERSION HISTORY? (y/n): \033[0m";
			cin>>logchoice;
			cin.ignore();
			system("cls");
			while(true){
				if(logchoice=='Y' || logchoice == 'y'){
					showLogHistory();
					break;
				}
				else if (logchoice=='n'|| logchoice == 'N'){
					system("cls");
					cout<<"\n\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";
					cout<<"\033[35m\n\tYouve Selected Not to See FileVersion History! \n\t\t";
					system("pause");
					cout<<"\033[0m";
					break;
				}
				else{
					cout<<"\033[31m\n\tERROR! INVALID CHOICE! Try Again: \033[0m";
					cin>>logchoice;
					cin.ignore();

				}

			}	 
			cout<<"\n\n\t\033[33mEnter ONLY FileVersoin *NUMBER* , You want to Delete (Version_\033[0m\033[31m*NUMBER*\033[0m\033[33m.txt) : ";
			cin>>verNum;
			cin.ignore();
			cout<<"\033[0m";
			
			fileName = "Version_"+to_string(verNum)+".txt";
			
			while(true){
				ifstream test(fileName);
				if(test){break;}
				if(!test){
					cout<<"\n\t\t\033[31mError! There is No Such File Version Number! UNABLE To DELETE!! \033[0m"<<endl;
					cout<<"\n\t\033[33m=> Do you want to RE-ENTER File Version Number? (y/n): \033[0m ";
					cout<<"\033[31m ";
					cin>>reenterchoice;
					cin.ignore();
					cout<<"\033[0m";
					if(reenterchoice == 'y'|| reenterchoice == 'Y'){
						cout<<"\n\t\033[33mPlease RE-ENTER Version NUMBER: \033[0m";
						cin>>verNum;
						cin.ignore();
						fileName="Version_"+to_string(verNum)+".txt";
					}
					else if(reenterchoice =='n'|| reenterchoice=='N'){
						system("cls");
						cout<<"\n\t\t\033[32mYouve Selected NOT TO RE-ENTER.... EXITING DELETION MENU!...";
						cout<<"\n\t";
						system("pause");
						cout<<"\033[0m";
						return;
					}
					else{
						cout<<"\n\t\t\033[33m INVALID CHOICE!! TRY AGAIN (y/n): ";
						cin>>reenterchoice;
						cin.ignore();
					}
				}
			}
			
			if(remove(fileName.c_str()) ==0){
            cout<<"\n\t\t\033[32mDELETION of , " <<fileName<<" , SUCCESSFULL! :) ";
            cout<<"\n\t\t";
            system("pause");
            cout<<"\033[0m";
			return;
        	} 
        	else{
			system("cls");
            cout<<"\n\t\t\033[31mERROR! Couldnt Delete the File! Exiting ... ";
            cout<<"\n\t\t";
            system("pause");
            cout<<"\033[0m";
			return;
       		}
			
		}
		else if(choice =='n'|| choice=='N'){
			system("cls");
			cout<<"\n\t\t\033[32mDeletion Process Cancelled!"<<endl;
        	cout<<"\n\t\t";
        	system("pause");
        	cout<<"\033[0m";
        	return;
		}
		else {
			cout<<"\n\t\033[31mINVALID CHOIEC!! TRY AGAIN (y/n) : \033[0m";
			cout<<"\033[36m";
			cin>>choice;
			cin.ignore();
			cout<<"\033[0m";
		}  
	}
}
