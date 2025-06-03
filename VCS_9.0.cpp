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
void deleteLogEntry(string fileName);
void readVersionFiles();
void restoreVersion();
bool comparing(int);

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
        readVersionFiles();    
        }
		else if(choice == 6){
        showLogHistory();
        }
        else if(choice == 7){
        restoreVersion();    
        }
        else if(choice == 8){
        deleteFile();
        }
		else if(choice == 9){
		system("cls");
		cout<<"\n\t \033[32mExiting...\033[0m"<<endl;
		break;
		}
//		else{
//			system("cls");
//			cout<<"Invalid choice!"<<endl;
//		}
	    }while(choice!=9);	
	
}

int choose(){
	int ch;
	system("cls");
    cout<<"\n\n\t\t\t\033[32mMINI VERSION CONTROL SYSTEM\n\n\033[0m\n";
	cout<<"\n\t\033[33m1-Write To your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m2-Append to your File.\033[0m"<<endl;
	cout<<"\n\t\033[33m3-Read From your File.\033[0m"<<endl;
    cout<<"\n\t\033[33m4-Save File Version.\033[0m"<<endl;
    cout<<"\n\t\033[33m5-Read File Versions.\033[0m"<<endl;
	cout<<"\n\t\033[33m6-Show Log History.\033[0m"<<endl;
    cout<<"\n\t\033[33m7-Restore File Version.\033[0m"<<endl;
    cout<<"\n\t\033[31m8-Delete File Version.\033[0m"<<endl;
	cout<<"\n\t\033[31m9-Exit.\033[0m"<<endl;
	cout<<"\n\033[36mEnter your choice(1-9): \033[0m";
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
		//cout<<"\n\t\033[36mYouve Choosen to OverWrite the exisitng data on file :) !!! \033[0m"<<endl;
			system("cls");	
			fstream myFile;
			string text;
		myFile.open("NewTextFile.txt",ios::out);
		cout<<"\n\t\t\t\033[31m========  FILE WRITING MENU  ========\033[0m\n\n";
		cout<<"\n\t\033[32mEnter the text to write in the txt file \033[0m \033[31m( \"exit\" to exit ) : \033[0m \n"<<endl;
			
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
		else{
		cout<<"\n\t\t\t\033[31m======== FILE WRITING MENU  ========\033[0m\n\n";
		cout<<"\033[31m\n\tSorry your file wasnt able to open! :( \033[0m"<<endl;
		cout<<"\033[35m";
		system("pause");
		cout<<"\033[0m";
		break;
		}	
		
		}while(myFile.is_open());
	}
	else if (sure == 'n') {
		system("cls");
		cout<<"\n\t\t\t\033[31m========  FILE WRITING MENU  ========\033[0m\n\n";
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
	cout<<"\n\t\t\t\033[31m========  FILE APPENDING MENU  ========\033[0m\n";
	cout<<"\033[32m\n\tEnter the text you want to append in your file!\033[0m \033[31m(\"exit\" to exit!)\033[0m"<<endl;
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
		else{ 
				
				cout<<"\n\t\t\033[31mSorry your file wasnt able to open! :( \033[0m"<<endl;
				cout<<"\033[35m";
				system("pause");
				cout<<"\033[0m";
				break;
			}
	}while(myFile.is_open());
	
}

void read(){
	fstream myFile;
	myFile.open("NewTextFile.txt",ios::in);
	system("cls");
	cout<<"\n\t\t\t\033[31m========  FILE READING MENU  ========\033[0m\n\n";
		if(myFile.is_open()){
			if(myFile.peek() == EOF){
				cout<<"\n\t\t\033[31mThe File is EMPTY! Nothing to Read Here ~_~ \033[0m"<<endl;
                cout<<"\n\n\033[35m";
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
				
				cout<<"\n\t\t\033[31mSorry your file wasnt able to open! :( \033[0m"<<endl;
                cout<<"\n\n\033[35m";
                system("pause");
                cout<<"\033[0m";
				return;
            }
		//cin.get();
		cout<<"\n\n\033[35m";
		system("pause");
		cout<<"\033[0m";
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
        system("cls");
		cout<<"\n\t\t\t\033[31m========  FILE VERSION SAVING MENU  ========\033[0m\n\n";
        cout<<"\n\t\033[31mERROR! CANT SAVE EMPTY FILE AS VERSION!!"<<endl;
        cout<<"\n\t";
        system("pause");
        cout<<"\033[0m";
        return;
    }
    
    bool compare = comparing(verNum);                																 //fn cal to chck if the files are same or not;
        if (compare){
            char choice;
			cout<<"\n\t\t\t\033[31m========  FILE VERSION SAVING MENU  ========\033[0m\n\n";
            cout<<"\n\t\033[33mThe Content is SAME as the PREVIOUS Versoin. Still want to save? (y/n): \033[0m";
            cin>>choice;
			cin.ignore();

            while(choice != 'y' && choice != 'Y'){ 
            if(choice=='n' || choice == 'N'){
				system("cls");
				cout<<"\n\t\t\t\033[31m========  FILE VERSION SAVING MENU  ========\033[0m\n";
                cout<<"\n\n\t\t\033[32mEXITING Version Save Menu!...\033[0m";
                cout<<"\n\n\n\033[35m";
				system("pause");
				cout<<"\\033[0m";
				return;
            }
            else if(choice != 'Y' && choice != 'y'){
				
                cout<<"\n\t\033[31mERROR!!INVALID CHOICE, Try Again (y/n) : \033[0m]";
				cout<<"\033[35m";
                cin>>choice;
				cout<<"\033[0m";
				cin.ignore();
            } 
          }
        }


	ofstream verFile(verFileName);

    string line;															// after test it will be saved :)
    while(getline(myFile,line)){
        verFile<<line<<endl;
    }
    myFile.close();
    verFile.close();
	system("cls");
	cout<<"\n\t\t\t\033[31m========  FILE VERSION SAVING MENU  ========\033[0m\n\n";
	cout<<"\n\t\033[36m====================================================================\n\033[0m"<<endl;
    cout<<"\t\t\033[32mVersion Saved Sucessfully!!\033[0m"<<endl;	
    cout<<"\n\033[35m";
    system("pause");
	cout<<"\033[0m";
    cout<<"\n\t\033[36m====================================================================\n\033[0m"<<endl;

	ofstream logFile("log.txt",ios::app);									//Log Enteriees  
	if(logFile)	{
		time_t now = time(0);
		string dt = ctime(&now);
		logFile<< verFileName << "\t saved at :  "<< dt<<endl;
		logFile.close();  
		cout<<"\t\t\033[32mLog Entry Saved Sucessfully!!"<<endl;
		cout<<"\n\t\033[36m====================================================================\n\t\033[0m"<<endl;
		cout<<"\033[35m";
		system("pause");
		cout<<"\033[0m";	
		//cout<<"\n\t";
		//system("pause");
	}
	else {
		
		//cout<<"\n\t\t\033[31m========  FILE VERSION SAVING MENU  ========\033[0m\n\n";
		cout<<"\n\t\t\033[31mERROR! Couldnt save Log Entry! :( \033[0m";
		cout<<"\n\n\033[35m";
        system("pause");
        cout<<"\033[0m";
		
	}
    

}

void showLogHistory(){
    ifstream log("log.txt");
	
	system("cls");

	if(!log){
		cout<<"\n\t\t\033[35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;
		cout<<"\n\t\033[31mNO LOG FILE FOUND!! Maybe try saving file(Version) first. :) \n\033[0m";
		cout<<"\033[35m";
		system("pause");
		cout<<"\033[0m";
		return;
	}
	cout<<"\n\t\t\t\033[35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;

	string line;
	bool flag = false;
	while(getline(log,line)){
		cout<<"\t\033[32m"<<line<<"\033[0m\n";
		flag = true;
	}
	if(!flag){
		cout<<"\n\t\t\t\033[35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;
		cout<<"\n\t\t\t\033[31mNo LOG Enteries FOUND!! :( \033[0m\n"<<endl;
		cout<<"\n\n\033[35m";
		system("pause"); 
		cout<<"\033[0m";
	}

	cout<<"\t\t\033[35m========================================\n\t\033[0m"<<endl;
	cout<<"\033[35m";
	system("pause");
	cout<<"\033[0m";
}

void deleteFile(){

    string fileName;
    int verNum;
    char choice,logchoice,reenterchoice;
	system("cls");

    cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";

    while(true) {
        cout<<"\033[33mThis process will permanently delete the file. Want to continue? (y/n): \033[0m";
        cin>>choice;
        cin.ignore();
		system("cls");
		cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";
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
				else if(logchoice=='n'|| logchoice == 'N'){
					system("cls");
					cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";
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
			system("cls");
			cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m";	 
			cout<<"\n\n\t\033[33mEnter File *Versoin NUMBER* , You want to Delete (e.g 1,3,6 etc..) (Version_\033[0m\033[31m*NUMBER*\033[0m\033[33m.txt) : ";
			cin>>verNum;
			cin.ignore();
			cout<<"\033[0m";
			
			fileName = "Version_"+to_string(verNum)+".txt";
			
			while(true){
				ifstream test(fileName);
				if(test){break;}
				if(!test){
					system("cls");
					cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n";
					cout<<"\n\t\033[31mError! There is No Such File Version Number! UNABLE To DELETE!! \033[0m"<<endl;
					cout<<"\n\033[33m=> Do you want to RE-ENTER File Version Number? (y/n): \033[0m ";
					cout<<"\033[31m ";
					cin>>reenterchoice;
					cin.ignore();
					cout<<"\033[0m";
					if(reenterchoice == 'y'|| reenterchoice == 'Y'){
						cout<<"\n\033[33mPlease RE-ENTER Version NUMBER: \033[0m";
						cin>>verNum;
						cin.ignore();
						fileName="Version_"+to_string(verNum)+".txt";
					}
					else if(reenterchoice =='n'|| reenterchoice=='N'){
						system("cls");
						cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";
						cout<<"\n\t\033[32mYouve Selected NOT TO RE-ENTER.... EXITING DELETION MENU!...\033[0m";
						cout<<"\n\033[35m";
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
            system("cls");
			cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n";
            cout<<"\n\t\033[32mDELETION of , " <<fileName<<" , SUCCESSFULL! :) \n";
            deleteLogEntry(fileName);
            cout<<"\033[0m\n\n\033[35m";
            system("pause");
            cout<<"\033[0m";  
			return;
        	} 
        	else{
			system("cls");
			cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n";
            cout<<"\n\t\033[31mERROR! Couldnt Delete the File! Exiting ... \033[0m";
            cout<<"\n\033[35m";
            system("pause");
            cout<<"\033[0m";
			return;
       		}
			
		}
		else if(choice =='n'|| choice=='N'){
			system("cls");
			cout<<"\n\t\t\t\033[31m========  DELETE FILE VERSION MENU  ========\033[0m\n";
			cout<<"\n\t\033[32mDeletion Process Cancelled!\033[0m"<<endl;
        	cout<<"\n\033[35m";
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

void deleteLogEntry(string fileName){

	ifstream logFile("log.txt");
	ofstream tempLogFile("temp_log.txt");
	
	string line;
	bool flag = false;

	while(getline(logFile,line)){
			if(line.empty()) continue;
		if(line.find(fileName)== string::npos ){
			tempLogFile<< line <<endl;
		}
		else {
			flag=true;
		}
	}
	logFile.close();
	tempLogFile.close();

	remove("log.txt");
	rename("temp_log.txt","log.txt");

	if(flag){
		cout<<"\n\t\t\033[32mLog entry for " << fileName << " removed successfully from log.txt!\033[0m" << endl;
	}
	else{
		cout << "\n\t\t\033[31mNo log entery found for " << fileName << " in log.txt.\033[0m" << endl;
	}

}

void readVersionFiles(){
    string fileName;
    int verNum;
    char reenterchoice,logchoice;
    system("cls");

    cout<<"\n\t\t\033[31m========  READ FILE VERSION MENU  ========\033[0m\n\n";
	cout<<"\n\033[33m=>Do you want to See FILE LOG? (y/n): \033[0m";
			cin>>logchoice;
			cin.ignore();
			system("cls");
			while(true){
				if(logchoice=='Y' || logchoice == 'y'){
					cout<<"\n\t\t\033[31m========  READ FILE VERSION MENU  ========\033[0m\n\n";
					showLogHistory();
					break;
				}
				else if(logchoice=='n'|| logchoice == 'N'){
					system("cls");
					cout<<"\n\t\t\033[31m========  FILE VERSION READING MENU  ========\033[0m\n\n";
					cout<<"\033[35m\n\tYouve Selected Not to See FileVersion History! \n\t";
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
			
    cout<<"\n\t\033[33mEnter File*Versoin NUMBER* , You want to READ (Version_\033[0m\033[31m*NUMBER*\033[0m\033[33m.txt) ( e.g 1,3,2,4 etc..) : \033[0m";
    cin>>verNum;
    cout<<"\033[31m";
	cin.ignore();
	cout<<"\033[0m";
    
    fileName= "Version_"+to_string(verNum)+".txt";
    
    while(true){
        ifstream test(fileName);
        if(test){break;}
        if(!test){
            cout<<"\n\t\t\033[31mError! There is No Such File Version Number! UNABLE To READ!! \033[0m"<<endl;
            cout<<"\n\t\033[33m=>Do you want to RE-ENTER File Version Number? (y/n): \033[0m ";
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
				cout<<"\n\t\t\033[31m========  READ FILE VERSION MENU  ========\033[0m\n";
                cout<<"\n\t\t\033[32mYouve Selected NOT TO RE-ENTER.... EXITING FILE READING MENU!...\033[0m";
                cout<<"\n\t\033[35m";
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

    ifstream read(fileName);

    system("cls");
    cout<<"\n\t\t\033[31m========  READ FILE VERSION MENU  ========\033[0m\n\n";
    cout<<"\t\t\033[36mShowing Conetnt of "<<fileName<<" :  \033[0m\n"<<endl;
    if(read.is_open()){
		if(read.peek() == EOF){
				cout<<"\n\t\t\033[31mThe File is EMPTY! Nothing to Read Here ~_~ \033[0m"<<endl;
                cout<<"\n\n\033[35m";
                system("pause");
                cout<<"\033[0m";
            }
		else{ 
    		string line;
    		while(getline(read,line)){
        	cout<<line<<endl;
    		}
		} 
	}
	else{ 
		cout<<"\n\t\t\033[31mSorry your file wasnt able to open! :( \033[0m"<<endl;
		cout<<"\n\t\033[35m";
		system("pause");
		cout<<"\033[0m";
		return;
	}
    read.close();
    
    cout<<"\n\t\033[35m";
    system("pause");
    cout<<"\033[0m";
}

void restoreVersion(){
    string fileName;
    int verNum;
    char reenterchoice,logchoice;

    system("cls");
    cout<<"\n\t\t\033[31m========  RESTORE FILE VERSION MENU  ========\033[0m\n\n";
    cout<<"\n\033[33m=>Do you want to See FILE LOG? (y/n): \033[0m";
			cin>>logchoice;
			cin.ignore();
			system("cls");
			while(true){
				if(logchoice=='Y' || logchoice == 'y'){
					showLogHistory();
					break;
				}
				else if(logchoice=='n'|| logchoice == 'N'){
					system("cls");
					cout<<"\n\t\t\033[31m========  FILE VERSION RESTORING MENU  ========\033[0m\n\n";
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
    cout<<"\n\t\033[33mEnter Version NUMBER to restore (e.g., 1 for Version_1.txt): \033[0m";
    cin>>verNum;
    cin.ignore();
    fileName = "Version_"+to_string(verNum)+".txt";
    
   while(true){
        ifstream test(fileName);
        if(test){break;}
        if(!test){
            cout<<"\n\t\t\033[31mError! There is No Such File Version Number! UNABLE To RESTORE!! \033[0m"<<endl;
            cout<<"\n\t\033[33m=>Do you want to RE-ENTER File Version Number? (y/n): \033[0m ";
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
				cout<<"\n\t\t\033[31m========  FILE VERSION RESTORING MENU  ========\033[0m\n";
                cout<<"\n\t\t\033[32mYouve Selected NOT TO RE-ENTER....EXITING FILE-VERSOIN RESTORING MENU!...";
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
	 
    ifstream myFile(fileName);
    ofstream mainFile("NewTextFile.txt");
    string line;
    while(getline(myFile,line)){
        mainFile<<line<<endl;
    }
    myFile.close();
    mainFile.close();

	system("cls");
	cout<<"\n\t\t\033[31m========  RESTORE FILE VERSION MENU  ========\033[0m\n\n";
    cout<<"\n\t\t\033[32mFile Sucessfully Restored from "<<fileName<<"!\033[0m\n";
	cout<<"\n\n\n\033[35m";
	system("pause");
	cout<<"\033[0m";


}

bool comparing(int verNum){

	if(verNum==1){													//no need to compare if its the first version;
		return false;
	}
	
	verNum = verNum-1;
    string filename ="Version_"+to_string(verNum)+".txt";

	fstream file1(filename,ios::in),file2("NewTextFile.txt",ios::in);
    string line1,line2;
	
	if(!file1){													//if prev ver dsnt exist ,no comparisn neded return flase;
		return false;
	}

	if(file1 && file2){ 
    while(getline(file1,line1) && getline(file2,line2)){
		if(line1!=line2){
			return false;
			break;
		}
	}
		if(file1.eof()||file2.eof()) {
			return true;
		}
		return false;
	}
	else{
		cout<<"\n\t\t\033[31mWas'nt Able to OPEN FILE for COMPARISON! ";
		return false;
	}
}