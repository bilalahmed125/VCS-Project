#include<iostream>
#include<fstream>
#include<ctime>     //for "TIME" function used in LOG History 
#include<cstdio>
#include<direct.h> //For _mkdir (Windows directory creation)

using namespace std;


struct id{                      //LOGIN function structure and its global aswell;
    string account, email;
    string pass;
} user[15];

int usercount = 0;
string currentUser;                     //Track logedin user


int choose();               //Login system functions
void login();
void signup();
void forgotPass();
void deleteUser();
void showusers();

void write();           //VCS functions
void read();
int vcsChoose();
void append();
void saveversion();
void showLogHistory();
void deleteFile();
void deleteLogEntry(string);
void readVersionFiles();
void restoreVersion();
bool comparing(int);
void vcsSystem();

void createUserDir();                          //Folder and Ptah functions
string getPath(string filename);            ///this one returns path like bila;_files.txt + sub file aswell of folder (like s.txt)   



int main(){                             //MAIN FUNCTOIN
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
    }while(choice != 6);
    return 0;
}

string getPath(string filename){                                 //username+"_file"+filename forexample text.txt (it will do this make a path) (bilal_files)folder->(text.txt)file 
    return currentUser+"_files/"+filename;
}

void createUserDir(){                                           //this funciotn simply creates a folder bilal_files;
    string dirName = currentUser+"_files";
    _mkdir(dirName.c_str());
}

int choose(){                                                   //login system functions options
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
        string id, enteredpass;
        cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT LOGIN\n\033[0m\033[0m";
        cout<<"\n\t\033[36mACCOUNT ID: \033[0m";
        cin>>id;
        cout<<"\n\t\033[36mPASSWORD: \033[0m";
        cin>>enteredpass;

        bool sameacc = false, samepass = false;
        ifstream check("login.txt");
        string fileacc, filepass, fileemail;

        while(check>>fileacc>>filepass>>fileemail){
            if(fileacc == id){
                sameacc = true;
                if(filepass == enteredpass){
                    samepass = true;
                    break;
                }
                if(filepass != enteredpass){
                    for(int i = 1; i <= 3; i++){
                        cout<<"\n\t\033[31mPassword Incorrect! Please Try Again (Tries left:\033[0m\033[33m"<<4-i<<"\033[0m\033[31m) : \033[0m";
                        cin>>enteredpass;
                        if(filepass == enteredpass){
                            samepass = true;
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
            currentUser = fileacc;                                                              //Seting current user
            createUserDir();                                                                    //Creates user own folder
            cout<<"\n\n\033[35m";
            system("pause");
            cout<<"\033[0m";
            check.close();
            vcsSystem();                                                                        //whole vcs function is called here 
            return;
        }

        if(!sameacc){
            cout<<"\n\t\033[31mNo ACCOUNTS with USER NAME : \033[0m\033[36m"<<id<<"\033[0m"<<endl;
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
                for(int i=0; i<3; i++){
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
                        return;
                    }
                }
            }
        }
    }while(choice =='y'|| choice == 'Y');
}

void signup(){
    system("cls");

    ofstream loginFile("login.txt", ios::app);

    cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT SIGN-UP\n\033[0m";
    cout<<"\n\n\t\033[1;7;32mPLEASE ENTER YOUR DETAILS!!\033[0m\n\n";


    cout<<"\t\033[36mACCOUNT ID: \033[0m";
    cin>>user[usercount].account;
    cout<<"\t\033[36mPASSWORD: \033[0m";
    cin>>user[usercount].pass;
    cout<<"\t\033[36mEMAIL: \033[0m";
    cin>>user[usercount].email;

    bool sameacc = false, sameemail = false;
    ifstream check("login.txt");
    string acc, pass, email;
    while(check>>acc>>pass>>email){
        if(acc == user[usercount].account){
            sameacc = true;
        }
        if(email == user[usercount].email){
            sameemail = true;
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
        string id, email;
        cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT FORGOT PASSWORD\n\033[0m\033[0m";
        cout<<"\n\t\033[36mEnter Your ID: \033[0m";
        cin>>id;
        cout<<"\n\t\033[36mEnter your EMAIL: \033[0m";
        cin>>email;

        string fileid, filepass, fileemail;
        ifstream read("login.txt");
        bool foundemail=false,foundacc=false;

        while(read>>fileid>>filepass>>fileemail){
            if(fileid == id){
                foundacc = true;
                if(fileemail == email){
                    foundemail = true;
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
                cout<<"\n\n\033[35m";
                system("pause");
                cout<<"\033[0m";
                return;
            }
            else if(choice != 'y' && choice != 'Y'){
                for(int i=0; i<3; i++){
                    cout<<"\n\t\033[31mInvalid Choice! Please enter again(y/n) : \033[0m";
                    cin>>choice;
                    if(choice == 'y'|| choice == 'Y' || choice =='N' ||choice =='n'){
                        break;
                    }
                }
            }
        }
        else if(!foundemail){
            cout<<"\n\t\033[31mINCORRECT EMAIL! Cant Provide Password without Email!\033[0m"<<endl;
            cout<<"\n\t\t\033[32mExiting...\033[0m";
            cout<<"\n\n\033[35m";
            system("pause");
            cout<<"\033[0m";
            return;
        }
        else if(foundacc && foundemail){
            cout<<"\n\t\033[32mACCOUNT FOUND!!\033[0m"<<endl;
            cout<<"\n\t\033[32mPassword for user \033[0m\033[36m"<<id<<"\033[0m\033[32m : \033[0m\033[33m"<<filepass<<"\033[0m"<<endl;
            cout<<"\n\n\033[35m";
            system("pause");
            cout<<"\033[0m";
            return;
        }
    }while(choice == 'y' || choice == 'Y');
}

void deleteUser(){
    system("cls");
    cout<<"\n\n\t\t\t\033[1;4;31mMINI-GIT ACCOUNT DELETION \n\033[0m\033[0m";

    string id, pass;
    cout<<"\n\t\033[36mAccount ID: \033[0m";
    cin>>id;
    cout<<"\n\t\033[36mPassword: \033[0m";
    cin>>pass;

    ifstream read("login.txt");
    ofstream write("temp_login.txt");
    string fileacc, filepass, fileemail;
    bool flagacc = false, flagpass = false;
    while(read>>fileacc>>filepass>>fileemail){
        if(fileacc == id){
            flagacc = true;
            if(filepass == pass){
                flagpass = true;
                continue;
            }
        }
        write<<fileacc<<" "<<filepass<<" "<<fileemail<<endl;
    }
    read.close();
    write.close();

    remove("login.txt");
    rename("temp_login.txt", "login.txt");
    if(flagpass && flagacc){
        for(int i=0; i<usercount; i++){
            if(user[i].account == id){
                for(int j=i; j<usercount-1; j++){
                    user[j] = user[j+1];
                }
                usercount--;
                break;
            }
        }

        string command = "rmdir /s /q "+id+"_files";     //Delete user folder and files
        system(command.c_str());                        //changes the comand to C type comand(char{]*) that sysetm expects  

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
        cout<<"\n\t\t\033[31mNO USERS DATA FILE FOUND!! Maybe try adding users first. :) \n\033[0m";
        cout<<"\n\n\033[35m";
        system("pause");
        cout<<"\033[0m";
        return;
    }

    string acc, pass, email;
    bool flag = false;

    int i=0;
    while(login>>acc>>pass>>email){
        cout<<"\t\t\t\033[36mUSER 0"<<i+1<<" : \033[0m \033[32m"<<acc<<" \033[0m\n";
        flag = true;
        i++;
    }

    if(!flag){
        system("cls");
        cout<<"\n\t\t\t\033[1;4;35m========  MINI-GIT DISPLAY USERS  ========\033[0m\n"<<endl;
        cout<<"\n\t\t\033[31m\tNO USERS Enteries FOUND!! :( \033[0m\n"<<endl;
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


int vcsChoose(){            //Starting main VCS from here..,.. 
    int ch;
    system("cls");
    cout<<"\n\n\t\t\t\033[1;4;31mMINI VERSION CONTROL SYSTEM\n\033[0m\033[0m";
    cout<<"\n\033[1;4;36m=================================================================\t\033[0m"<<endl;
    cout<<"\n\t\033[33m1-Write To your File.\033[0m"<<endl;
    cout<<"\n\t\033[33m2-Append to your File.\033[0m"<<endl;
    cout<<"\n\t\033[33m3-Read From your File.\033[0m"<<endl;
    cout<<"\n\t\033[33m4-Save File Version.\033[0m"<<endl;
    cout<<"\n\t\033[33m5-Read File Versions.\033[0m"<<endl;
    cout<<"\n\t\033[33m6-Show Log History.\033[0m"<<endl;
    cout<<"\n\t\033[33m7-Restore File Version.\033[0m"<<endl;
    cout<<"\n\t\033[31m8-Delete File Version.\033[0m"<<endl;
    cout<<"\n\t\033[31m9-Exit.\033[0m"<<endl;
    cout<<"\n\033[1;4;36m=================================================================\t\033[0m"<<endl;
    cout<<"\n\033[4;36mEnter your choice(1-9): \033[0m";
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
        if(sure != 'y' && sure != 'n'){
            cout<<"\033[31mInvalid choice :( , Please choose y or n !\033[0m"<<endl;
            cin>>sure;
            cin.ignore();
        }
        else{
            break;
        }
    }

    if(sure == 'y'){
        system("cls");
        fstream myFile;
        string text;
        myFile.open(getPath("NewTextFile.txt"), ios::out);
        cout<<"\n\t\t\t\033[1;4;31m========  FILE WRITING MENU  ========\033[0m\n\n";
        cout<<"\n\t\033[32mEnter the text to write in the txt file \033[0m \033[31m( \"exit\" to exit ) : \033[0m \n"<<endl;

        do{
            if(myFile.is_open()){
                getline(cin, text);
                if(text == "exit"){
                    myFile.close();
                    break;
                }
                myFile<<text<<endl;
            }
            else{
                cout<<"\n\t\t\t\033[1;4;31m======== FILE WRITING MENU  ========\033[0m\n\n";
                cout<<"\033[31m\n\tSorry your file wasnt able to open! :( \033[0m"<<endl;
                cout<<"\033[35m";
                system("pause");
                cout<<"\033[0m";
                break;
            }
        }while(myFile.is_open());
    }
    else if(sure == 'n'){
        system("cls");
        cout<<"\n\t\t\t\033[1;4;31m========  FILE WRITING MENU  ========\033[0m\n\n";
        cout<<"\n\n\t\033[31mYouve choosen not to overwrite the file!,Press Enter to Exit write(overwrite) mode :) !! "<<endl;
        cout<<"\n\t";
        system("pause");
        cout<<"\033[0m";
    }
}

void append(){
    
    fstream myFile;
    string text;

    myFile.open(getPath("NewTextFile.txt"), ios::app);
    system("cls");
    cout<<"\n\t\t\t\033[1;4;31m========  FILE APPENDING MENU  ========\033[0m\n";
    cout<<"\033[32m\n\tEnter the text you want to append in your file!\033[0m \033[31m(\"exit\" to exit!)\033[0m"<<endl;
    do{
        if(myFile.is_open()){
            getline(cin, text);
            if(text == "exit"){
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
    myFile.open(getPath("NewTextFile.txt"), ios::in);
    
    system("cls");
    cout<<"\n\t\t\t\033[1;4;31m========  FILE READING MENU  ========\033[0m\n\n";
    if(myFile.is_open()){
        if(myFile.peek() == EOF){
            cout<<"\n\t\t\033[31mThe File is EMPTY! Nothing to Read Here ~_~ \033[0m"<<endl;
            cout<<"\n\n\033[35m";
            system("pause");
            cout<<"\033[0m";
            return;
        }
        else{
            string line;
            cout<<"\n";
            while(getline(myFile, line)){
                cout<<line<<endl;
            }
        }
    }
    else{
        cout<<"\n\t\t\033[31mSorry your file wasnt able to open! :( \033[0m"<<endl;
        cout<<"\n\n\033[35m";
        system("pause");
        cout<<"\033[0m";
        return;
    }
    cout<<"\n\n\033[35m";
    system("pause");
    cout<<"\033[0m";
}

void saveversion(){

    string verFileName;
    int verNum=1;
    while(true){                                             //for Differnt versionnum
        verFileName = "Version_"+to_string(verNum)+".txt";
        ifstream test(getPath(verFileName));                    //chceks in users folder if same name verson num exists
        if(!test){
            break;
        }
        verNum++;
    }

    ifstream myFile(getPath("NewTextFile.txt"));
    system("cls");

    if(myFile.peek() == EOF){                      //checks f file s emtpy or not
        system("cls");
        cout<<"\n\t\t\t\033[1;4;31m========  FILE VERSION SAVING MENU  ========\033[0m\n\n";
        cout<<"\n\t\033[31mERROR! CANT SAVE EMPTY FILE AS VERSION!!"<<endl;
        cout<<"\n\t";
        system("pause");
        cout<<"\033[0m";
        myFile.close();
        return;
    }

    bool compare = comparing(verNum);                  //chceks if same as prev versn (calling funcitn comparing)
    if(compare){
        char choice;
        cout<<"\n\t\t\t\033[1;4;31m========  FILE VERSION SAVING MENU  ========\033[0m\n\n";
        cout<<"\n\t\033[33mThe Content is SAME as the PREVIOUS Version. Still want to save? (y/n): \033[0m";
        cin>>choice;
        cin.ignore();

        while(choice != 'y' && choice != 'Y'){
            if(choice == 'n' || choice == 'N'){
                system("cls");
                cout<<"\n\t\t\t\033[1;4;31m========  FILE VERSION SAVING MENU  ========\033[0m\n";
                cout<<"\n\n\t\t\033[32mEXITING Version Save Menu!...\033[0m";
                cout<<"\n\n\n\033[35m";
                system("pause");
                cout<<"\033[0m";
                return;
            }
            else if(choice != 'Y' && choice != 'y'){
                cout<<"\n\t\033[31mERROR!!INVALID CHOICE, Try Again (y/n) : \033[0m";
                cout<<"\033[35m";
                cin>>choice;
                cout<<"\033[0m";
                cin.ignore();
            }
        }
    }

    ofstream verFile(getPath(verFileName));
    string line;
    while(getline(myFile, line)){
        verFile<<line<<endl;
    }
    myFile.close();
    verFile.close();

    system("cls");
    cout<<"\n\t\t\t\033[1;4;31m========  FILE VERSION SAVING MENU  ========\033[0m\n\n";
    cout<<"\n\t\033[1;4;36m====================================================================\n\033[0m"<<endl;
    cout<<"\t\t\t\033[32mVersion Saved Sucessfully!!\033[0m"<<endl;
    cout<<"\n\t\033[1;4;36m====================================================================\n\033[0m"<<endl;
    cout<<"\n\033[35m";
    system("pause");
    cout<<"\033[0m";
    ofstream logFile(getPath("log.txt"), ios::app);
    if(logFile){
        time_t now = time(0);                   //time functoin (c typ funct)
        string dt = ctime(&now);                //passing memroy address bcz its c funct and most of the funct have the same pattern
        logFile<<verFileName<<"\t saved at :  "<<dt<<endl;
        logFile.close();
        cout<<"\n\t\033[1;4;36m====================================================================\n\033[0m"<<endl;
        cout<<"\t\t\t\033[32mLog Entry Saved Sucessfully!!"<<endl;
        cout<<"\n\t\033[1;4;36m====================================================================\n\t\033[0m"<<endl;
        cout<<"\033[35m";
        system("pause");
        cout<<"\033[0m";
    }
    else{
        cout<<"\n\t\t\033[31mERROR! Couldnt save Log Entry! :( \033[0m";
        cout<<"\n\n\033[35m";
        system("pause");
        cout<<"\033[0m";
    }
}

void showLogHistory(){
    
    ifstream log(getPath("log.txt"));
    system("cls");

    if(!log){
        cout<<"\n\t\t\033[1;4;35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;
        cout<<"\n\t\033[31mNO LOG FILE FOUND!! Maybe try saving file(Version) first. :) \n\033[0m";
        cout<<"\033[35m";
        system("pause");
        cout<<"\033[0m";
        return;
    }
    cout<<"\n\t\t\t\033[1;4;35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;

    string line;
    bool flag = false;
    while(getline(log, line)){
        cout<<"\t\033[32m"<<line<<"\033[0m\n";
        flag = true;
    }
    if(!flag){
        system("cls");
        cout<<"\n\t\t\t\033[1;4;35m========  VERSION LOG HISTORY  ========\033[0m\n"<<endl;
        cout<<"\n\t\t\t\033[31m\tNo LOG Enteries FOUND!! :( \033[0m\n"<<endl;
        cout<<"\t\t\033[1;4;35m\t========================================\n\t\033[0m"<<endl;
        cout<<"\n\n\033[35m";
        system("pause");
        cout<<"\033[0m";
        return;
    }

    cout<<"\t\t\033[1;4;35m\t========================================\n\t\033[0m"<<endl;
    cout<<"\033[35m";
    system("pause");
    cout<<"\033[0m";
}

void deleteFile(){

    string fileName;
    int verNum;
    char choice, logchoice, reenterchoice;
    system("cls");

    cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";

    while(true){
        cout<<"\033[33mThis process will permanently delete the file. Want to continue? (y/n): \033[0m";
        cin>>choice;
        cin.ignore();
        system("cls");
        cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";
        if(choice == 'y' || choice == 'Y'){
            cout<<"\n\033[33m=>Do you want to See FILE VERSION HISTORY? (y/n): \033[0m";
            cin>>logchoice;
            cin.ignore();
            system("cls");
            while(true){
                if(logchoice == 'Y' || logchoice == 'y'){
                    showLogHistory();
                    break;
                }
                else if(logchoice == 'n'|| logchoice == 'N'){
                    system("cls");
                    cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";
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
            cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========";
            cout<<"\n\n\t\033[33mEnter File *Version NUMBER* , You want to Delete (e.g 1,3,6 etc..) (Version_\033[0m\033[31m*NUMBER*\033[0m\033[33m.txt) : ";
            cin>>verNum;
            cin.ignore();
            cout<<"\033[0m";

            fileName = "Version_"+to_string(verNum)+".txt";
            string fullPath = getPath(fileName);            //points to that file in user;s folder;

            while(true){
                ifstream test(fullPath);
                if(test){                               //found that file so break and to dlt proces 
                    test.close();
                    break;
                }
                if(!test){                          //.if no file then show err and renter or not option
                    system("cls");
                    cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========\033[0m\n";
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
                        fileName = "Version_"+to_string(verNum)+".txt";
                        fullPath = getPath(fileName);
                    }
                    else if(reenterchoice == 'n'|| reenterchoice == 'N'){
                        system("cls");
                        cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========\033[0m\n\n";
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

            if(remove(fullPath.c_str()) == 0){                                  //delete if dlete succesful then enter if;
                system("cls");
                cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========\033[0m\n";
                cout<<"\n\t\033[32mDELETION of , "<<fileName<<" , SUCCESSFUL! :) \n";
                deleteLogEntry(fileName);                                  //filename is passed to deletelogentry function which dlts the file ver in log.txt
                cout<<"\033[0m\n\n\033[35m";
                system("pause");
                cout<<"\033[0m";
                return;
            }
            else{
                system("cls");
                cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========\033[0m\n";
                cout<<"\n\t\033[31mERROR! Couldnt Delete the File! Exiting ... \033[0m";
                cout<<"\n\033[35m";
                system("pause");
                cout<<"\033[0m";
                return;
            }
        }
        else if(choice == 'n'|| choice == 'N'){
            system("cls");
            cout<<"\n\t\t\t\033[1;4;31m========  DELETE FILE VERSION MENU  ========\033[0m\n";
            cout<<"\n\t\033[32mDeletion Process Cancelled!\033[0m"<<endl;
            cout<<"\n\033[35m";
            system("pause");
            cout<<"\033[0m";
            return;
        }
        else{
            cout<<"\n\t\033[31mINVALID CHOICE!! TRY AGAIN (y/n) : \033[0m";
            cout<<"\033[36m";
            cin>>choice;
            cin.ignore();
            cout<<"\033[0m";
        }
    }
}

void deleteLogEntry(string fileName){
    
    ifstream logFile(getPath("log.txt"));
    ofstream tempLogFile(getPath("temp_log.txt"));

    string line;
    bool flag = false;
    while(getline(logFile, line)){
        if(line.empty()){
            continue;
        }
        if(line.find(fileName) == string::npos){
            tempLogFile<<line<<endl;
        }
        else{
            flag = true;
        }
    }
    logFile.close();
    tempLogFile.close();

    remove(getPath("log.txt").c_str());
    rename(getPath("temp_log.txt").c_str(), getPath("log.txt").c_str());

    if(flag){
        cout<<"\n\t\t\033[32mLog entry for "<<fileName<<" removed successfully!\033[0m"<<endl;
    }
    else{
        cout<<"\n\t\t\033[31mNo log entry found for "<<fileName<<".\033[0m"<<endl;
    }
}

void readVersionFiles(){
    
    string fileName;
    int verNum;
    char reenterchoice, logchoice;
    system("cls");

    cout<<"\n\t\t\033[1;4;31m========  READ FILE VERSION MENU  ========\033[0m\n\n";
    cout<<"\n\033[33m=>Do you want to See FILE LOG? (y/n): \033[0m";
    cin>>logchoice;
    cin.ignore();
    system("cls");
    while(true){
        if(logchoice == 'Y' || logchoice == 'y'){
            cout<<"\n\t\t\033[1;4;31m========  READ FILE VERSION MENU  ========\033[0m\n\n";
            showLogHistory();
            break;
        }
        else if(logchoice == 'n'|| logchoice == 'N'){
            system("cls");
            cout<<"\n\t\t\033[1;4;31m========  FILE VERSION READING MENU  ========\033[0m\n\n";
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

    cout<<"\n\t\033[33mEnter File*Version NUMBER* , You want to READ (Version_\033[0m\033[31m*NUMBER*\033[0m\033[33m.txt) ( e.g 1,3,2,4 etc..) : \033[0m";
    cin>>verNum;
    cout<<"\033[31m";
    cin.ignore();
    cout<<"\033[0m";

    fileName = "Version_"+to_string(verNum)+".txt";
    string fullPath = getPath(fileName);

    while(true){
        ifstream test(fullPath);
        if(test){
            test.close();
            break;
        }
        if(!test){                                                                        //no ver found                 
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
                fileName = "Version_"+to_string(verNum)+".txt";
                fullPath = getPath(fileName);
            }
            else if(reenterchoice == 'n'|| reenterchoice == 'N'){
                system("cls");
                cout<<"\n\t\t\033[1;4;31m========  READ FILE VERSION MENU  ========\033[0m\n";
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

    ifstream read(fullPath);
    system("cls");
    cout<<"\n\t\t\033[1;4;31m========  READ FILE VERSION MENU  ========\033[0m\n\n";
    cout<<"\t\t\033[36mShowing Content of "<<fileName<<" :  \033[0m\n"<<endl;
    if(read.is_open()){
        if(read.peek() == EOF){
            cout<<"\n\t\t\033[31mThe File is EMPTY! Nothing to Read Here ~_~ \033[0m"<<endl;
            cout<<"\n\n\033[35m";
            system("pause");
            cout<<"\033[0m";
        }
        else{
            string line;
            while(getline(read, line)){
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
    char reenterchoice, logchoice;

    system("cls");
    cout<<"\n\t\t\033[1;4;31m========  RESTORE FILE VERSION MENU  ========\033[0m\n\n";
    cout<<"\n\033[33m=>Do you want to See FILE LOG? (y/n): \033[0m";
    cin>>logchoice;
    cin.ignore();
    system("cls");
    while(true){
        if(logchoice == 'Y' || logchoice == 'y'){
            showLogHistory();
            break;
        }
        else if(logchoice == 'n'|| logchoice == 'N'){
            system("cls");
            cout<<"\n\t\t\033[1;4;31m========  FILE VERSION RESTORING MENU  ========\033[0m\n\n";
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
    string fullPath = getPath(fileName);

    while(true){
        ifstream test(fullPath);
        if(test){
            test.close();
            break;
        }
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
                fileName = "Version_"+to_string(verNum)+".txt";
                fullPath = getPath(fileName);
            }
            else if(reenterchoice == 'n'|| reenterchoice == 'N'){
                system("cls");
                cout<<"\n\t\t\033[1;4;31m========  FILE VERSION RESTORING MENU  ========\033[0m\n";
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

    ifstream myFile(fullPath);
    ofstream mainFile(getPath("NewTextFile.txt"));
    string line;
    while(getline(myFile, line)){
        mainFile<<line<<endl;
    }
    myFile.close();
    mainFile.close();

    system("cls");
    cout<<"\n\t\t\033[1;4;31m========  RESTORE FILE VERSION MENU  ========\033[0m\n\a";
    cout<<"\n\t\t\033[32mFile Sucessfully Restored from "<<fileName<<"!\033[0m\n";
    cout<<"\n\n\n\033[35m";
    system("pause");
    cout<<"\033[0m";
}

bool comparing(int verNum){
    if(verNum == 1){                   //if ver is first no need to chck with prev
        return false;
    }

    string prevFileName = "Version_"+to_string(verNum - 1)+".txt";
    ifstream prevFile(getPath(prevFileName));
    ifstream currentFile(getPath("NewTextFile.txt"));
    if(!prevFile || !currentFile){              //mening if one of the file failes to open cant compare so return false
        return false;
    }

    string line1, line2;
    while(true){
        bool gotLine1 = (bool)getline(prevFile, line1);             //if it getsline it makes it ture else wise false          
        bool gotLine2 = (bool)getline(currentFile, line2);
        if(!gotLine1 && !gotLine2){                                 //it will only go inside if both are false meaning both rechd ther ends;
            return true;
        }

        if(!gotLine1 || !gotLine2){                                 //this returns that if one file reach end but other didnt so it will return false as the files are not same      
            return false;
        }

        if(line1 != line2){                                           //if at any point the lines become different it exits the function with fasle ;
            return false;
        }
    }
}

void vcsSystem(){                   //its called in login function only.....
    int choice;
    do{
        choice = vcsChoose();
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
            cout<<"\n\t \033[32mExiting VCS...\033[0m"<<endl;
            break;
        }
    }while(choice != 9);
}