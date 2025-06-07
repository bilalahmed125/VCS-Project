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
    cout<<"\n\t\033[36mACCOUNT ID: \033[0m";
    cin>>id;
    cout<<"\n\t\033[36mPASSWORD: \033[0m";
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
                cout<<"\n\t\033[31mPassword Incorrect! Please Try Again (Tries left:\033[0m\033[33m"<<4-i<<"\033[0m\033[31m) : \033[0m";
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
    cout<<"\n\t\033[32mLUGIN SUCCESSFUL!! \033[0m"<<endl; 
    cout<<"\n\t\033[32mWELCOME \033[0m\033[36m"<<fileacc<<"\033[0m\033[32m ! :)\033[0m "; 
    cout<<"\n\n\033[35m";
    system("pause");
    cout<<"\033[0m";
    check.close();
    return;
}
if(!sameacc) {
        cout<<"\n\t\033[31mNo ACCOUNTS with USER NAME : \033[0m\033[36m" << id <<"\033[0m"<<endl; 
        cout<<"\n\t\033[33mDo You Want to Re-enter the Account and Password?(y/n): \033[0m"; 
        cin>>choice;
        if(choice == 'n' || choice == 'N'){
            cout<<"\n\t\033[32mEXITING...\033[0m"; 
            cout<<"\n\n\033[35m";
            system("pause");
            cout<<"\033[0m";
            check.close();
            return;
        }
        else if(choice != 'y' && choice !='Y'){
            for(int i=0;i<3;i++){ 
            cout<<"\n\t\033[31mInvalid Choice! Please Try again (y/n): \033[0m" ; 
            cin>>choice;
            if(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'){
                    break;
                }
            if(i==2){
                cout<<"\n\t\033[31mToo many Failed Attempts!\033[0m"; 
                cout<<"\n\n\033[35m";
                system("pause");
                cout<<"\033[0m";
                check.close();
                return;         }
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

        cout<<"\t\033[36mACCOUNT ID: \033[0m"; 
        cin>>user[usercount].account;
        cout<<"\t\033[36mPASSWORD: \033[0m"; 
        cin>>user[usercount].pass;
        cout<<"\t\033[36mEMAIL: \033[0m"; 
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

    cout<<"\n\t\033[32mACCOUNT CREATED SUCCESSFULLY!!!\033[0m"<<endl; 
    usercount++;
    cout<<"\n\n\033[35m";
    system("pause");
    cout<<"\033[0m";
        return;
}
cout<<"\n\t\033[31mACCOUNT CREATION FAILED!!!\033[0m"<<endl; 
cout<<"\n\t\033[33mPlease Try AGAIN!\033[0m"; 
cout<<"\n\n\033[35m";
system("pause");
cout<<"\033[0m";

}

void forgotPass(){
    char choice;
    do{ 
    system("cls");
    string id,email;
    cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT FORGOT PASSWORD\n\033[0m\033[0m";
    cout<<"\n\t\033[36mEnter Your ID: \033[0m"; 
    cin>>id;
    cout<<"\n\t\033[36mEnter your EMAIL: \033[0m"; 
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
    cout<<"\n\t\033[31mNO ACCOUNT REGISTERED WITH ID : \033[0m\033[36m"<<id<<"\033[0m"<<endl; 
        cout<<"\n\t\033[33mWant to RE-ENTER account INFO? (y/n): \033[0m"; 
        cin>>choice;
        if(choice == 'n' || choice == 'N' ){
            cout<<"\n\t\033[32mEXITING....\033[0m"; 
            read.close();
            cout<<"\n\n\033[35m";
            system("pause");
            cout<<"\033[0m";
            return;
        }
        else if(choice != 'y' && choice != 'Y'){
            for(int i=0;i<3;i++){
            cout<<"\n\t\033[31mInvalid Chioce! Please enter again(y/n) : \033[0m"; 
            cin>>choice; 
            if(choice == 'y'|| choice == 'Y' || choice =='N' ||choice =='n'){
                break;
            }
            }
        }
}
else if(!foundemail){
    cout<<"\n\t\033[31mINCORRECT EMAIL! Cant Provide Passwrod without Email!\033[0m"<<endl; 
    cout<<"\n\t\033[32mExiting...\033[0m"; 
    cout<<"\n\n\033[35m";
    system("pause");
    cout<<"\033[0m";
    return;
}
else if( foundacc && foundemail){
    cout<<"\n\t\033[32mACCOUNT FOUND!!\033[0m"<<endl; 
    cout<<"\n\t\033[32mPassword for user \033[0m\033[36m" <<id<<"\033[0m\033[32m : \033[0m\033[33m"<< filepass<<"\033[0m"<<endl; 
    cout<<"\n\n\033[35m";
    system("pause");
    cout<<"\033[0m";
    return;
}

}while(choice == 'y' || choice == 'Y' );

}

void deleteUser(){
    system("cls");
    cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT DELETION \n\033[0m\033[0m";
    string id,pass;
    cout<<"\n\t\033[36mAccount ID: \033[0m"; 
    cin>>id;
    cout<<"\n\t\033[36mPassword: \033[0m"; 
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
        for(int i=0;i<usercount;i++){          
            if(user[i].account==id){
                for(int j=i;j<usercount-1;j++){
                    user[j] = user[j+1];
                }
                usercount--;
                break;
            }
        }
        cout<<"\n\t\033[32mACCOUNT \033[0m\033[36m"<<id<<"\033[0m\033[32m has been deleted SUCCESSFULLY! \033[0m"; 
    }
    else if(!flagacc){
        cout<<"\n\t\033[31mAccount with id: \033[0m\033[36m"<<id<<"\033[0m\033[31m NOT FOUND!\033[0m"; 
    }
    else if(!flagpass){
        cout<<"\n\t\033[31mINCORRECT PASSWORD for user: \033[0m\033[36m"<<id<<"\033[0m"; 
    }
    cout<<endl;
    cout<<"\n\n\033[35m";
    system("pause");
    cout<<"\033[0m";
}

void showusers(){
    system("cls");
    cout<<"\n\t\t\033[1;4;35m========  MINI-GIT DISPLAY USERS  ========\033[0m\n"<<endl;
    
    ifstream login("login.txt");

    if(!login){
        system("cls");
        cout<<"\n\t\t\033[1;4;35m========  MINI-GIT DISPLAY USERS  ========\033[0m\n"<<endl;
        cout<<"\n\t\033[31mNO USERS DATA FILE FOUND!! Maybe try adding users first. :) \n\033[0m";
        cout<<"\n\n\033[35m";
        system("pause");
        cout<<"\033[0m";
        return;
    }

    string acc,pass,email;
    bool flag = false;
    
    int i=0;
    while(login>>acc>>pass>>email){
        cout<<"\t\t\t\033[36mUSER 0"<<i+1<<" : \033[0m \033[32m"<<acc<<" \033[0m\n";
        flag = true;
        i++;
    }
    if(!flag){
        system("cls");
        cout<<"\n\t\t\t\033[1;4;35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;
        cout<<"\n\t\t\t\033[31m\tNO USERS Enteries FOUND!! :( \033[0m\n"<<endl;
        cout<<"\n\t\t\033[1;4;35m\t========================================\n\t\033[0m"<<endl; 
        cout<<"\n\n\033[35m";
        system("pause"); 
        cout<<"\033[0m";
        return; 
    }

    cout<<"\n\t\t\033[1;4;35m========================================\n\t\033[0m"<<endl;
    cout<<"\n\n\033[35m";
    system("pause");
    cout<<"\033[0m";

}