#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Account.h"
#include <iostream>
#include<string.h>
using namespace std;
class Customer : public Person {
private:
    Account account;

public:
    static int counter;
    Customer();

    void createAccount();
    // Setters
    void setAccount(const Account& acc);

    // Getters
    Account getAccount() const;

    // Utility
    void displayCustomer() const;
};
int Customer::counter = 101;
// Constructor
Customer::Customer() : Person() {
    // Account initialized automatically
}

// Setter
void Customer::setAccount(const Account& acc) {
    account = acc;
}

// Getter
Account Customer::getAccount() const {
    return account;
}

// Utility Function
void Customer::displayCustomer() const {
    cout << "Name       : " << getName() << endl;
    cout << "CNIC       : " << getCNIC() << endl;
    cout << "Phone      : " << getPhone() << endl;
    cout << "Account ID : " << account.getAccountID() << endl;
    cout << "Type       : " << account.getAccountType() << endl;
    cout << "Balance    : " << account.getBalance() << endl;
}
void Customer::createAccount(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "              CREATING AN ACCOUNT         " << endl;
    cout << "==========================================" << endl;
    Person::inputBasicInfo();
    char Type[20];
    cout<<"Enter Account Type (Saving/Current) : ";
    cin>>Type;
    account.setAccountType(Type);
    account.setActive(0);
    account.setBalance(0.00);
    char title[20];
    char pass[20];
    cout<<"\tEnter Account Title (no dashes): ";
    cin>>title;
    account.setTitle(title);
    int num = rand() % 90000 + 10000; 
    char randomPart[6]; 
    sprintf(randomPart, "%d", num);   // Convert int to char array
    char count[6];
    sprintf(count, "%d", counter);  
    counter++;
    char AccountNo1[100];  
    strcpy(AccountNo1, count);           
    strcat(AccountNo1, "-");             
    strcat(AccountNo1, title);           // Add title
    strcat(AccountNo1, "-");             
    strcat(AccountNo1, randomPart);      // Add 5-digit number 
    account.setAccountID(AccountNo1);
    cout<<"\tEnter Password : ";
    cin>>pass;
    account.setPassword(pass);

    system("cls");
    cout<<"*****************************************\n";
    cout<<"\t_____Youre Account Has Been Created_____\n\n";
    cout<<"Account Title : "<<title<<" | Password : "<<pass<<endl;
    cout<<"Account No : "<<AccountNo1<<endl;
    cout<<"*****************************************\n";

};
#endif // CUSTOMER_H
