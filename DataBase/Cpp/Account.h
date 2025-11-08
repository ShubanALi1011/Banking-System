#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <cstring> 

class Account {
private:
    char Title[20];
    char accountID[100];
    char password[20];
    double balance;
    int isActive;            
    char accountType[20];


public:
    Account();

    void setAccountID(const char* id);
    void setTitle(const char* title);
    void setPassword(const char* pass);
    void setAccountType(const char* acc);
    void setBalance(double b);
    void setActive(int status);                  

    const char* getAccountID() const;
    const char* getAccountType() const;
    const char* getTitle() const;
    const char* getPassword() const;
    double getBalance() const;
    int getActive() const;
};

// Constructor
Account::Account() {
    strcpy(accountID, "");
    strcpy(accountType, "");
    balance = 0.0;
    isActive = 0;
}

// Setters
void Account::setAccountID(const char* id) {
    strncpy(accountID, id, sizeof(accountID));
}

void Account::setAccountType(const char* acc) {
    strncpy(accountType, acc, sizeof(accountType));
}

void Account::setBalance(double b) {
    balance = b;
}

void Account::setActive(int status) {
    isActive = status;
}
void Account::setTitle(const char* title){
    strncpy(Title, title, sizeof(Title));
}
void Account::setPassword(const char* pass){
    strncpy(password, pass, sizeof(pass));
}

// Getters
const char* Account::getAccountID() const {
    return accountID;
}

const char* Account::getAccountType() const {
    return accountType;
}

double Account::getBalance() const {
    return balance;
}
const char* Account::getPassword() const{
    return password;
};

const char* Account::getTitle() const{
    return Title;
};
int Account::getActive() const {
    return isActive;
}

#endif // ACCOUNT_H
