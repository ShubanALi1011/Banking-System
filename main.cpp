#include <iostream>
#include<vector>
#include<cstring>
#include <windows.h>
#include "DataBase/Cpp/Account.h"
#include "DataBase/Cpp/Manager.h"
#include "DataBase/Cpp/Customer.h"
#include "DataBase/Cpp/Clerk.h"
#include "DataBase/Cpp/Accountant.h"
#include "DataBase/Cpp/Transaction.h"
#include "DataBase/Cpp/SAVE.h"
#include "DataBase/Cpp/LOAD.h"
using namespace std;

// fun declaration
void welcome();
void showMainPortal();
void showEmployeePortal();
void showCustomerPortal();
void customerLogin();
void customerSignup();
bool hasAccount(string username_AccountNo);
bool isActive(char *AccID);
bool passCorr(string username_AccountNo, string PASS);
void AccountLogin(char *AccID);//Account &account;

void BankManagerLogin();
void BankManagerPortal();
void bankDashboard();
double getTotalBalance();
int getActiveAccounts();
void viewBalance(char *AccID);

void employeeManagement();
void manageAccountants();
void addAccountant();
void removeAccountant();
void updateAccountant();
void viewAllAccountants();
void ClerkLogin();
void searchAccountants();

void AccountManagerLogin();
void AccountManagerPortal();
void activateDeActivate();            
void viewTransactionHistory(char *AccID);
void transferFund(char *AccID);


void ClerkPortal();
void createAccount(){

}
void updateAccount(char *AccID);
void closeAccount();
void searchAccount();
void viewAllCustomer();
void deposit(char *AccID);
void withdraw(char *AccID);

void manageClerks();
void addClerk();
void removeClerk();
void updateClerk();
void viewAllClerk();
void searchClerk();

vector<Account> Accounts;
Manager manager;
vector<Customer> Customers;
vector<Clerk> clerks;
vector<Accountant> Accountants;
vector<Transaction> Transac;
SAVE save;

int main(){
    LOAD read;
    read.loadAccountants(Accountants);
    read.loadClerks(clerks);
    read.loadCustomers(Customers);
    read.loadAccounts(Accounts);
    read.loadTransactions(Transac);
    welcome();
    showMainPortal();
    return 0;
}
void welcome() {
    cout << "==========================================" << endl;
    cout << "         WELCOME TO  BANKING OS           " << endl;
    cout << "==========================================" << endl;
}

void showMainPortal(){
    cout<<"1 ) Continue as Bank Employee.\n";
    cout<<"2 ) Continue as Customer.\n";
    cout<<"3 ) Exit the System.\n";
    cout<<"------------------------------------------\n";
    string choice;
    while(true){
        cout<<"\tEnter Choice : ";
        cin>>choice;
        if(choice == "1")
            showEmployeePortal();
        else if(choice == "2")
            showCustomerPortal();
        else if(choice == "3")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }
    }
}

void showEmployeePortal(){
    while(true){
        cout << "==========================================" << endl;
        cout << "        WELCOME TO EMPLOYEE PORTAL        " << endl;
        cout << "==========================================" << endl;
        cout << "1 ) Login as Bank Manager\n";
        cout << "2 ) Login as Accountant\n";
        cout << "3 ) Login as Clerk\n";
        cout << "4 ) Back to Main Portal\n";
        cout << "5 ) Exit the system.\n";
        cout<<"------------------------------------------\n";
        cout<<"\tEnter Choice : ";
        string choice;
        cin>>choice;
        if(choice == "1")
            BankManagerLogin();
        else if(choice == "2")
            AccountManagerLogin();
        else if(choice == "3")
            ClerkLogin();
        else if(choice == "4"){
            system("cls");
            welcome();
            showMainPortal();
        }
        else if(choice == "5")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }
    }
}

void showCustomerPortal(){
    cout << "==========================================" << endl;
    cout << "        WELCOME TO CUSTOMER PORTAL        " << endl;
    cout << "==========================================" << endl;
    cout<<"1 ) Login to Your Account .\n";
    cout<<"2 ) Create a New Bank Account.\n";
    cout<<"3 ) Back to Main Menu.\n";
    cout<<"4 ) Exit the System.\n";
    cout<<"------------------------------------------\n";
    string choice;
    while(true){
        cout<<"\tEnter Choice : ";
        cin>>choice;
        if(choice == "1")
            customerLogin();
        else if(choice == "2")
            customerSignup();
    
        else if(choice == "3")
            showMainPortal();
        else if(choice == "4")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }
    }
}

void customerLogin(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "        LOGIN CUSTOMER ACCOUNT            " << endl;
    cout << "==========================================" << endl;
    bool isfound = false;
    char AccID[100];
    cout<<"\tEnter Account No : ";
    cin>>AccID;
    char pass[12];
    cout<<"\tEnter Password : ";
    cin>>pass;
    for(int i=0; i<Accounts.size(); i++){
        if(strcmp( Accounts[i].getAccountID(), AccID ) == 0 && strcmp(Accounts[i].getPassword(), pass) == 0 ){
            isfound = true;
            AccountLogin(AccID);
        }
    }
    if(!isfound){
        system("cls");
        cout<<"\tInvalid Account No or Password.\n";
        showCustomerPortal();

    }
}
void customerSignup(){
    Customer cust;
    cust.createAccount();
    Customers.push_back(cust);
    Accounts.push_back(cust.getAccount());
    save.saveCustomers(Customers);
    save.saveAccounts(Accounts);
    string choice;
    cout<<"\nWant to Login(y,n) ? ";
    cin>>choice;
    if(choice == "y")
        customerLogin();
    else 
        showCustomerPortal();
}

bool hasAccount(string AccountNo){
    for(int i=0; i<Accounts.size(); i++){
        if(AccountNo == Accounts[i].getAccountID()){
            return true;
        }
    }
    return false;
}
bool isActive(char *AccID){
    for(int i=0; i<Accounts.size(); i++){
        if(strcmp(Accounts[i].getAccountID(), AccID) == 0){
            if(Accounts[i].getActive() == 1){
                return true;
            }
            else if(Accounts[i].getActive() == 0){
                return false;
            }
        }
    }
    return false;
}

bool passCorr(string AccountNo, string PASS){
    for(int i=0; i<Accounts.size(); i++){
        if(Accounts[i].getAccountID() == AccountNo && Accounts[i].getPassword() == PASS){
            return true;
        }
    }
    return false;
}

void AccountLogin(char *AccID){ // Account &account
    while(true){
        cout << "==========================================" << endl;
        cout << "         ALIENXOFT BANKING SYSTEM         " << endl;
        cout << "==========================================" << endl;
        cout << "            CUSTOMER MAIN MENU            " << endl;
        cout << "------------------------------------------" << endl;
        cout << "1 ) Deposit Cash" << endl;
        cout << "2 ) Withdraw Cash" << endl;
        cout << "3 ) Transfer Funds" << endl;
        cout << "4 ) View Account Balance" << endl;
        cout << "5 ) View Transaction History" << endl;
        cout << "6 ) Update Account Information" << endl;
        cout << "7 ) Logout" << endl;
        cout << "8 ) Exit."<<endl;
        cout << "==========================================" << endl;
        string choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == "1"){
            system("cls");
            deposit(AccID);
        }
        else if(choice == "2"){
            system("cls");
            withdraw(AccID);
        }
        else if(choice == "3"){
            system("cls");
            transferFund(AccID);
        }
        else if(choice == "4"){
            system("cls");
            viewBalance(AccID);
        }
        else if(choice == "5"){
            system("cls");
            viewTransactionHistory(AccID);
        }
        else if(choice == "6"){
            system("cls");
            updateAccount(AccID);
        }
        else if(choice == "7"){
            system("cls");
            showCustomerPortal();
        }
        else if(choice == "8")
            exit(0);
        else{
            system("cls");
            cout<<"*****************************************\n";
            cout<<"\t_____Wrong Password_____\n";
            cout<<"*****************************************\n";
        }
        
    }
}

void BankManagerLogin(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "             BANK MANAGER LOGIN           " << endl;
    cout << "==========================================" << endl;
    int empId;
    cout<<"\tEnter empID : ";
    cin>>empId;
    if(empId == manager.getEmpID()){
        string pass;
        cout<<"\tEnter Password : ";
        cin>>pass;
        if(pass == string(manager.getPassword())){
            BankManagerPortal();
        }
        else{
            system("cls");
            cout<<"*****************************************\n";
            cout<<"\t_____Wrong Password_____\n";
            cout<<"*****************************************\n";
        }
        
    }else{
        system("cls");
        cout<<"*****************************************\n";
        cout<<"\t_____Wrong empID_____\n";
        cout<<"*****************************************\n";
    }
    
    
}
void BankManagerPortal(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "         BANK MANAGER CONTROL PANEL       " << endl;
    cout << "==========================================" << endl;
    cout << "1 ) View Bank Dashboard.\n";
    cout << "2 ) Manage Employees.\n";
    cout << "3 ) Logout.\n";
    cout << "4 ) Exit.\n";
    cout<<"------------------------------------------\n";
    string choice;
    while(true){
        cout<<"\tEnter Choice : ";
        cin>>choice;
        if(choice == "1")
            bankDashboard();
        else if(choice == "2")
            employeeManagement();
        else if(choice == "3")
            showEmployeePortal();
        else if(choice == "4")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }
            
    }

}

void bankDashboard(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "       WELCOME TO ASSETS DASHBOARD        " << endl;
    cout << "==========================================" << endl;
    cout<<"\tTotal Balance : "<<getTotalBalance()<<endl;
    cout<<"------------------------------------------\n";
    cout<<"\tTotal Employees : "<<clerks.size()+Accountants.size()+1<<endl;
    cout<<"------------------------------------------\n";
    cout<<"Account Managers : "<<Accountants.size()<<endl;
    cout<<"------------------------------------------\n";
    cout<<"clerk Managers : "<<clerks.size()<<endl;
    cout<<"------------------------------------------\n";
    cout<<"Total Accounts : "<<Accounts.size()<<endl;
    cout<<"------------------------------------------\n";
    cout<<"Active Accounts : "<<getActiveAccounts()<<endl;
    cout<<"------------------------------------------\n";
    cout<<"Pause Accounts : "<<Accounts.size()-getActiveAccounts()<<endl;
    cout<<"------------------------------------------\n";
    string True;
    cout<<"\tEnter 1 for back : ";
    cin>>True;
    if(True == "0")
        BankManagerPortal();
    else
        BankManagerPortal();


}
void employeeManagement(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "          EMPLOYEE MANAGEMENT PANEL       " << endl;
    cout << "==========================================" << endl;
    cout << "1 ) Manage Accountants.\n";
    cout << "2 ) Manage Clerks.\n";
    cout << "3 ) Back -> Manager Panel.\n";
    cout << "4 ) Exit the System.\n";
    cout<<"------------------------------------------\n";
    string choice;
    while(true){
        cout<<"\tEnter Choice : ";
        cin>>choice;
        if(choice == "1")
            manageAccountants();
        else if(choice == "2")
            manageClerks();
        else if(choice == "3")
            BankManagerPortal();
        else if(choice == "4")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }

    }


};

void manageAccountants(){
    string choice;
    while(true){
        cout << "==========================================" << endl;
        cout << "              MANAGE ACCOUNTANTS          " << endl;
        cout << "==========================================" << endl;
        cout << "1 ) Add New Accountant.\n";
        cout << "2 ) Remove An Accountant.\n";
        cout << "3 ) Update Accountant Info.\n";
        cout << "4 ) View All Accountants.\n";
        cout << "5 ) Search Accountant by ID\n";
        cout << "6 ) Back to Employee Management.\n";
        cout << "7 ) Exit the System.\n";
        cout<<"------------------------------------------\n";
        cout<<"\tEnter Choice : ";
        cin>>choice; 
        if(choice == "1")
            addAccountant();
        else if(choice == "2")
            removeAccountant();
        else if(choice == "3")
            updateAccountant();
        else if(choice == "4")
            viewAllAccountants();
        else if(choice == "5")
            searchAccountants();
        else if(choice == "6")
            employeeManagement();
        else if(choice == "7")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }
        
    }
};

void addAccountant(){
    cout << "==========================================" << endl;
    cout << "         ADDING  NEW  ACCOUNTANT          " << endl;
    cout << "==========================================" << endl;
    Accountant a;
    a.inputEmployeeInfo();
    Accountants.push_back(a);
    save.saveAccountants(Accountants);
    system("cls");
    cout<<"------------------------------------------\n";
    cout<<"\tEmployee {" <<a.getName()<<" is added as accountant.\n";
    cout<<"------------------------------------------\n";
    manageAccountants();
}
void removeAccountant(){
    cout << "==========================================" << endl;
    cout << "          REMOVE AN ACCOUNTANT            " << endl;
    cout << "==========================================" << endl;
}
void updateAccountant(){
    cout << "==========================================" << endl;
    cout << "         UPDATE AN ACCOUNTANT             " << endl;
    cout << "==========================================" << endl;
}
void searchAccountants(){
    cout << "==========================================" << endl;
    cout << "           SEARCH AN ACCOUNTANT           " << endl;
    cout << "==========================================" << endl;
}
void viewAllAccountants(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "          VIEW ALL ACCOUNTANTS               " << endl;
    cout << "==========================================" << endl;
    for(int i=0; i<Accountants.size(); i++){
        cout<<i+1 <<" ) Accountant Details :-\n";
        cout<<"#########################################\n";
        Accountants[i].printEmployeeInfo();
        cout<<"****************************************\n";
    }
}
void ClerkLogin(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "               Clerk  Login               " << endl;
    cout << "==========================================" << endl;
    bool isfound = false;
    int empID;
    cout<<"\tEnter empID [int] : ";
    cin>>empID;
    char pass[12];
    cout<<"\tEnter Password : ";
    cin>>pass;
    for(int i=0; i<clerks.size(); i++){
        if(clerks[i].getEmpID() == empID && strcmp(clerks[i].getPassword(), pass) == 0){
            isfound = true;
            ClerkPortal();
        }
    }
    if(!isfound){
        cout<<"\tInvalid empID or Password.\n";
    }
}
void ClerkPortal(){
    system("cls");
    while(true){
        cout << "==========================================" << endl;
        cout << "              CLERK CONTROL PANEL         " << endl;
        cout << "==========================================" << endl;
        cout << "1 ) Create New Customer Account.\n";
        cout << "2 ) Update Customer Info.\n";
        cout << "3 ) Close Customer Account.\n";
        cout << "4 ) Search Account by Title.\n";
        cout << "5 ) View All Customer.\n";
        cout << "6 ) Deposit Money.\n";
        cout << "7 ) Withdraw Money.\n";
        cout << "8 ) Logout.\n";
        cout << "9 ) Exit.\n";
        cout<<"------------------------------------------\n";
        char accNo[100] = "";
        string choice;
        cout<<"\tEnter Choice : ";
        cin>>choice;
        if(choice == "1")
            createAccount();
        else if(choice == "2")
            updateAccount(accNo);
        else if(choice == "3")
            closeAccount();
        else if(choice == "4")
            searchAccount();
        else if(choice == "5")
            viewAllCustomer();
        else if(choice == "6")
            deposit(accNo);
        else if(choice == "7")
            withdraw(accNo);
        else if(choice == "8")
            showEmployeePortal();
        else if(choice == "9")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }
    }
}
void closeAccount(){
    cout << "==========================================" << endl;
    cout << "           CLOSING AN ACCOUNT             " << endl;
    cout << "==========================================" << endl;
}
void updateAccount(char *AccID){
    cout << "==========================================" << endl;
    cout << "           UPDATING AN ACCOUNT             " << endl;
    cout << "==========================================" << endl;
}
void searchAccount(){
    cout << "==========================================" << endl;
    cout << "           SEARCH AN ACCOUNT             " << endl;
    cout << "==========================================" << endl;
}
void viewAllCustomer(){
    cout << "==========================================" << endl;
    cout << "           VIEW ALL CUSTOMERS             " << endl;
    cout << "==========================================" << endl;
}

void transferFund(char *AccID){
    cout << "==========================================" << endl;
    cout << "    Transfer Amount to Another Account     " << endl;
    cout << "==========================================" << endl;
}
void deposit(char *accID){
    cout << "==========================================" << endl;
    cout << "    Deposit Money to your Account         " << endl;
    cout << "==========================================" << endl;
    if(accID == ""){
        cout<<"\t Enter Account No : ";
        cin>>accID;
    }
    if(isActive(accID)){
        double amount;
        cout<<"\tEnter Amount : ";
        cin>>amount;
        Customer c;
        Transaction t;
        Account a;
        for(int i=0; i<Accounts.size(); i++){
            if(strcmp(Accounts[i].getAccountID(), accID) == 0){
                cout<<"Account Title : "<<Accounts[i].getTitle();
                string choice;
                cout<<"\n\tEnter 1 for deposit , any other key for cancel ? : ";
                cin>>choice;
                if(choice == "1"){
                    double oldBalance = Accounts[i].getBalance();
                    double newBalance = oldBalance + amount;
                    Accounts[i].setBalance(newBalance);
                    save.saveAccounts(Accounts);

                    // save transaction details
                    t.setTitle("deposit");
                    t.setAmount(amount);
                    t.setSenderAccountNo("Banking Os");
                    t.setReceiverAccountNo(accID);
                    Transac.push_back(t);
                    save.saveTransactions(Transac);

                    cout<<"\n\nRs. "<<amount<<" deposited to "<<accID<<endl;
                    cout<<"------------------------------------------\n";
                    break;
                }
                else{
                    system("cls");
                    showMainPortal();
                }
            }else{
                cout<<"Invalid Acc no , account does not exist\n";
                showMainPortal();

            }
            
        }
    }
    else{
        system("cls");
        cout<<"\nAccount is not Activated.\n";
        showMainPortal();
    }
    
    
}
void withdraw(char *AccID){
    cout << "==========================================" << endl;
    cout << "         Withdraw Your Cash               " << endl;
    cout << "==========================================" << endl;
}
void AccountManagerLogin(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "         Account Manager Login            " << endl;
    cout << "==========================================" << endl;
    bool isfound = false;
    int empID;
    cout<<"\tEnter empID [int] : ";
    cin>>empID;
    char pass[12];
    cout<<"\tEnter Password : ";
    cin>>pass;
    for(int i=0; i<Accountants.size(); i++){
        if(Accountants[i].getEmpID() == empID && strcmp(Accountants[i].getPassword(), pass) == 0){
            isfound = true;
            AccountManagerPortal();
        }
    }
    if(!isfound){
        cout<<"\tInvalid empID or Password.\n";
    }
}
void AccountManagerPortal(){
    system("cls");
    while(true){
        cout << "==========================================" << endl;
        cout << "           ACCOUNTANT CONTROL PANEL       " << endl;
        cout << "==========================================" << endl;
        cout << "1 ) Activate/ Deactivate Account.\n";
        cout << "2 ) View Transaction History.\n";
        cout << "3 ) Transfer Funds.\n";
        cout << "4 ) Logout.\n";
        cout << "5 ) Exit.\n";
        cout<<"------------------------------------------\n";
        char accNo[100] = "";
        cin.ignore();
        string choice;
        cout<<"\tEnter Choice : ";
        cin>>choice;
        if(choice == "1")
            activateDeActivate();
        else if(choice == "2")
            viewTransactionHistory(accNo);
        else if(choice == "3")
            transferFund(accNo);
        else if(choice == "4"){
            system("cls");
            showEmployeePortal();
        }
        else if(choice == "5")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }
    }
}

void activateDeActivate(){
    cout << "==========================================" << endl;
    cout << "      Activate / Deactivate Accounts      " << endl;
    cout << "==========================================" << endl;
}         
void viewTransactionHistory(char *AccID){
    cout << "==========================================" << endl;
    cout << "           VIEW TRANSACTIONS              " << endl;
    cout << "==========================================" << endl;
}
void transerFund(char *AccID){
    cout << "==========================================" << endl;
    cout << "           ADDING  NEW  CLERK             " << endl;
    cout << "==========================================" << endl;
}
void manageClerks(){
    system("cls");
    while(true){
        cout << "==========================================" << endl;
        cout << "                 MANAGE CLERK             " << endl;
        cout << "==========================================" << endl;
        cout << "1 ) Add New Clerk.\n";
        cout << "2 ) Remove An Clerk.\n";
        cout << "3 ) Update Clerk Info.\n";
        cout << "4 ) View All Clerks.\n";
        cout << "5 ) Search Clerk by ID\n";
        cout << "6 ) Back to Employee Management.\n";
        cout << "7 ) Exit the System.\n";
        cout<<"------------------------------------------\n";
        string choice;
        cout<<"\tEnter Choice : ";
        cin>>choice; 
        if(choice == "1")
            addClerk();
        else if(choice == "2")
            removeClerk();
        else if(choice == "3")
            updateClerk();
        else if(choice == "4")
            viewAllClerk();
        else if(choice == "5")
            searchClerk();
        else if(choice == "6")
            employeeManagement();
        else if(choice == "7")
            exit(0);
        else{
            cout<<"*****************************************\n";
            cout<<"\t_____Invalid Choice_____\n";
            cout<<"*****************************************\n";
        }
    }
}

void addClerk(){
    cout << "==========================================" << endl;
    cout << "           ADDING  NEW  CLERK             " << endl;
    cout << "==========================================" << endl;
    Clerk c;
    c.inputEmployeeInfo();
    clerks.push_back(c);
    save.saveClerks(clerks);
    system("cls");
    cout<<"------------------------------------------\n";
    cout<<"\tEmployee {" <<c.getName()<<" is added as clerk.\n";
    cout<<"------------------------------------------\n";
}
void removeClerk(){
    cout << "==========================================" << endl;
    cout << "           REMOVING A  CLERK             " << endl;
    cout << "==========================================" << endl;
}
void updateClerk(){
    cout << "==========================================" << endl;
    cout << "             UPDATE A  CLERK              " << endl;
    cout << "==========================================" << endl;
}
void viewAllClerk(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "           VIEW ALL CLERKS               " << endl;
    cout << "==========================================" << endl;
    for(int i=0; i<clerks.size(); i++){
        cout<<i+1 <<" ) Clerk Details :-\n";
        cout<<"#########################################\n";
        clerks[i].printEmployeeInfo();
        cout<<"****************************************\n";
    }
}
void searchClerk(){
    cout << "==========================================" << endl;
    cout << "             SEARCH A CLERK               " << endl;
    cout << "==========================================" << endl;
}

double getTotalBalance(){
    double balance;
    for(int i=0; i<Accounts.size(); i++){
        balance += Accounts[i].getBalance();
    }
    return balance;
}

int getActiveAccounts(){
    int cnt = 0;
    for(int i=0; i<Accounts.size(); i++){
        if(Accounts[i].getActive() == 1){
            cnt++;
        }
    }
    return cnt;
}
void viewBalance(char *AccID){
    cout << "==========================================" << endl;
    cout << "             VIEW BALANCE                 " << endl;
    cout << "==========================================" << endl;
    if(AccID == ""){
        cout<<"Enter Account No : ";
        cin>>AccID;
    }
    
}
