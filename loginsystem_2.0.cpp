#include<iostream>
#include<fstream>

using namespace std;

struct id{
    string account,email;
    string pass;
}user[15];

int usercount=0;

int choose();
void login();
void signup();
void forgotPass();
void deleteUser();
void showusers();

int main(){
    int choice;
    do{
		choice = choose();
		
		if(choice == 1){
		login(); 
		}
		else if(choice == 2){
		signup();
		}
		else if(choice == 3){
		forgotPass();
		}
        else if(choice == 4){
        showusers();
        }
        else if(choice == 5){
        deleteUser();
        }
        else if(choice == 6){
        system("cls");
		cout<<"\n\t \033[32mExiting...\033[0m"<<endl;
		cout<<"\n\033[32mThanks for using the Mini Version Control System! Goodbye!\033[0m\n"<<endl;
		break;
		} 
    }while(choice!=6);
}

int choose(){
    
    system("cls");
    int ch;
    cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT LOGIN \n\033[0m\033[0m";
	cout<<"\n\033[1;4;36m=================================================================\t\033[0m"<<endl;
	cout<<"\n\t\033[33m1-Log-in Account.\033[0m"<<endl;
	cout<<"\n\t\033[33m2-Sign-up Account.\033[0m"<<endl;
	cout<<"\n\t\033[33m3-Forgot Password.\033[0m"<<endl;
    cout<<"\n\t\033[33m4-Display User IDs.\033[0m"<<endl;
    cout<<"\n\t\033[31m5-Delete Account.\033[0m"<<endl;
    cout<<"\n\t\033[31m6-Exit.\033[0m"<<endl;
    cout<<"\n\033[1;4;36m=================================================================\t\033[0m"<<endl;
    cout<<"\n\033[4;36mEnter your choice(1-9): \033[0m";
	cin>>ch;
	cin.ignore();
    return ch;

}

void login(){

	char choice;

do{ 
	system("cls");
	string id,enteredpass;

	cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT LOGIN\n\033[0m\033[0m"; 
	cout<<"ACCOUNT ID: ";
	cin>>id;
	cout<<"PASSWORD: ";
	cin>>enteredpass;

bool sameacc =false,samepass=false;
	ifstream check("login.txt");
	string fileacc,filepass,fileemail;	
	
	while(check>>fileacc>>filepass>>fileemail){ 
	if(fileacc==id){
			sameacc = true;
		if(filepass==enteredpass)
			{samepass=true;
			break;}
		if(filepass!=enteredpass){
			for(int i=1;i<=3;i++){
				cout<<"Password Incorrect! Please Try Again (Tries left:"<<4-i<<") : ";
				cin>>enteredpass;
				if(filepass==enteredpass){
					samepass=true;
					break;
				}
			}
		}
	} 
}
if(sameacc && samepass){
	system("cls");
	cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT LOGIN\n\033[0m\033[0m"; 
	cout<<"LOGIN SUCCESSFUL!! "<<endl;
	cout<<"WELCOME "<<fileacc<<" ! :) ";
	cout<<"\033[35m\n";
	system("pause");
	cout<<"\033[0m";
	check.close();
	return;
}
if(!sameacc) {
		cout<<"No ACCOUNTS with USER NAME : " << id <<endl;
		cout<<"Do You Want to Re-enter the Account and Password?(y/n): ";
		cin>>choice;
		if(choice == 'n' || choice == 'N'){
			cout<<"EXITING...";
			check.close();
			return;
		}
		else if(choice != 'y' && choice !='Y'){
			for(int i=0;i<3;i++){ 
			cout<<"Invalid Choice! Please Try again (y/n): " ;
			cin>>choice;
			if(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'){
					break;
				}
			if(i==2){
				cout<<"Too many Failed Attempts!";
				check.close();
				return;			}
			}
		}
	}
 }while(choice =='y'|| choice == 'Y');

}


void signup(){
	system("cls");

	ofstream loginFile("login.txt",ios::app);
	
	cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT SIGN-UP\n\033[0m";
	cout<<"\n\n\t\033[1;7;32mPLEASE ENTER YOUR DETAILS!!\033[0m\n\n";

		cout<<"ACCOUNT ID: ";
		cin>>user[usercount].account;
		cout<<"PASSWORD: ";
		cin>>user[usercount].pass;
		cout<<"EMAIL: ";
		cin>>user[usercount].email;
		
	bool sameacc =false,sameemail=false;
	ifstream check("login.txt");
	string acc,pass,email;	
	
	while(check>>acc>>pass>>email){ 
	if(acc==user[usercount].account){
			sameacc = true;
	}
	if(email==user[usercount].email){
		sameemail=true;
	}
	}
	check.close();
	if(sameacc){
		cout<<"\n\t\033[31mAccount ID already exists! Try another one.\033[0m"<<endl;
	}
	else if(sameemail){
		cout<<"\n\t\033[31mEMAIL linked with another account! Try another one! \033[0m"<<endl;
	}
	else{
		loginFile<<user[usercount].account<<" ";
		loginFile<<user[usercount].pass<<" ";
		loginFile<<user[usercount].email<<" "<<endl;

	cout<<"ACCOUNT CREATED SUCCESSFULLY!!!"<<endl;
	usercount++;
		return;
}
cout<<"ACCOUNT CREATION FAILED!!!"<<endl;
cout<<"Please Try AGAIN!";

}

void forgotPass(){
	char choice;
	do{ 
	system("cls");
	string id,email;
	cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT FORGOT PASSWORD\n\033[0m\033[0m";
	cout<<"Enter Your ID: ";
	cin>>id;
	cout<<"Enter your EMAIL: ";
	cin>>email;
	
	string fileid,filepass,fileemail;
	ifstream read("login.txt");
		bool foundemail=false,foundacc=false;
	while(read>>fileid>>filepass>>fileemail){
		if(fileid == id) {
			 foundacc=true;
			if(fileemail == email){
				foundemail=true;
				break;
			}
		}
}
read.close();
if(!foundacc){
	cout<<"NO ACCOUNT REGISTERED WITH ID : "<<id<<endl;
		cout<<"Want to RE-ENTER account INFO? (y/n): ";
		cin>>choice;
		if(choice == 'n' || choice == 'N' ){
			cout<<"EXITING....";
			read.close();
			system("pause");
			return;
		}
		else if(choice != 'y' && choice != 'Y'){
			for(int i=0;i<3;i++){
			cout<<"Invalid Chioce! Please enter again(y/n) : ";
			cin>>choice; 
			if(choice == 'y'|| choice == 'Y' || choice =='N' ||choice =='n'){
				break;
			}
			}
		}
}
else if(!foundemail){
	cout<<"INCORRECT EMAIL! Cant Provide Passwrod without Email!"<<endl;
	cout<<"Exiting...";
	system("pause");
	return;
}
else if( foundacc && foundemail){
	cout<<"ACCOUNT FOUND!!"<<endl;
	cout<<"Password for user " <<id<<" : "<< filepass<<endl;
	system("pause");
}

}while(choice == 'y' || choice == 'Y' );

}

void deleteUser(){
    system("cls");
    cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT DELETION \n\033[0m\033[0m";
    string id,pass;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Password: ";
    cin>>pass;

    ifstream read("login.txt");
    ofstream write("temp_login.txt");
    string fileacc,filepass,fileemail;
    bool flagacc=false,flagpass=false;

    while(read>>fileacc>>filepass>>fileemail){
        if(fileacc==id){
            flagacc=true;
            if(filepass==pass){
                flagpass=true;
                continue; 
            }
        }
        write<<fileacc<<" "<<filepass<< " "<<fileemail<<endl;
    }
    read.close();
    write.close();

    remove("login.txt");
    rename("temp_login.txt", "login.txt");

    if(flagpass && flagacc){
        for(int i=0;i<usercount;i++){			// Removung from global array if exist
            if(user[i].account==id){
                for(int j=i;j<usercount-1;j++){
                    user[j] = user[j+1];
                }
                usercount--;
                break;
            }
        }
        cout<<"ACCOUNT "<<id<<" has been deleted SUCCESSFULLY! ";
    }
    else if(!flagacc){
        cout<<"Account with id: "<<id<<" NOT FOUND!";
    }
    else if(!flagpass){
        cout<<"INCORRECT PASSWORD for user: "<<id;
    }
    cout<<endl;
    system("pause");
}

void showusers(){
    system("cls");
    cout<<"\n\t\t\033[1;4;35m========  MINI-GIT DISPLAY USERS  ========\033[0m\n"<<endl;
    
	ifstream login("login.txt");

	if(!login){
		system("cls");
		cout<<"\n\t\t\033[1;4;35m========  MINI-GIT DISPLAY USERS  ========\033[0m\n"<<endl;
		cout<<"\n\t\033[31mNO USERS DATA FILE FOUND!! Maybe try adding users first. :) \n\033[0m";
		cout<<"\033[35m";
		system("pause");
		cout<<"\033[0m";
		return;
	}

	string acc,pass,email;
	bool flag = false;
    //cin.ignore();
	int i=0;
	while(login>>acc>>pass>>email){
		cout<<"\t\t\033[36mUSER 0"<<i+1<<" : \033[0m \033[32m"<<acc<<" \033[0m\n";
		flag = true;
	}
	if(!flag){
		system("cls");
		cout<<"\n\t\t\t\033[1;4;35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;
		cout<<"\n\t\t\t\033[31m\tNO USERS Enteries FOUND!! :( \033[0m\n"<<endl;
		cout<<"\t\t\033[1;4;35m\t========================================\n\t\033[0m"<<endl; 
		cout<<"\n\n\033[35m";
		system("pause"); 
		cout<<"\033[0m";
		return; 
	}

	cout<<"\t\t\033[1;4;35m========================================\n\t\033[0m"<<endl;
	cout<<"\033[35m";
	system("pause");
	cout<<"\033[0m";

}