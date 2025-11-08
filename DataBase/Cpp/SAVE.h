// SAVE.h
#ifndef SAVE_H
#define SAVE_H

#include "employee.h"
#include "Accountant.h"
#include "Account.h"
#include "Clerk.h"
#include "Transaction.h"
#include "Customer.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <exception>
using namespace std;

class SAVE {
public:
    void saveAccountants(vector<Accountant>& Accountants);
    void saveClerks(vector<Clerk>& Clerks);
    void saveAccounts(vector<Account>& accounts);
    void saveTransactions(vector<Transaction>& trans);
    void saveCustomers(vector<Customer>& cust);
};

// Save Accountants
void SAVE::saveAccountants(vector<Accountant>& Accountants) {
    ofstream file("DataBase/Binary/accountants.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open accountants file." << endl;
        return;
    }

    for (int i = 0; i < Accountants.size(); i++) {
        file.write((char*)&Accountants[i], sizeof(Accountant));
    }

    file.close();
}

// Save Clerks
void SAVE::saveClerks(vector<Clerk>& Clerks) {
    ofstream file("DataBase/Binary/clerks.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open clerks file." << endl;
        return;
    }

    for (int i = 0; i < Clerks.size(); i++) {
        file.write((char*)&Clerks[i], sizeof(Clerk));
    }

    file.close();
}

// Save Accounts
void SAVE::saveAccounts(vector<Account>& accounts) {
    ofstream file("DataBase/Binary/accounts.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open accounts file." << endl;
        return;
    }

    for (int i = 0; i < accounts.size(); i++) {
        file.write((char*)&accounts[i], sizeof(Account));
    }

    file.close();
}

// Save Transactions
void SAVE::saveTransactions(vector<Transaction>& trans) {
    ofstream file("DataBase/Binary/transactions.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open transactions file." << endl;
        return;
    }

    for (int i = 0; i < trans.size(); i++) {
        file.write((char*)&trans[i], sizeof(Transaction));
    }

    file.close();
}

// Save Customers
void SAVE::saveCustomers(vector<Customer>& cust) {
    ofstream file("DataBase/Binary/customers.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open customers file." << endl;
        return;
    }

    for (int i = 0; i < cust.size(); i++) {
        file.write((char*)&cust[i], sizeof(Customer));
    }

    file.close();
}

#endif
