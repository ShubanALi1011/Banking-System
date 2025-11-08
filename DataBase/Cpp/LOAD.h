// LOAD.h
#ifndef LOAD_H
#define LOAD_H

#include "employee.h"
#include "Accountant.h"
#include "Account.h"
#include "Clerk.h"
#include "Transaction.h"
#include "Customer.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class LOAD {
public:
    void loadAccountants(vector<Accountant>& accountants);
    void loadClerks(vector<Clerk>& clerks);
    void loadAccounts(vector<Account>& accounts);
    void loadTransactions(vector<Transaction>& transactions);
    void loadCustomers(vector<Customer>& customers);
};

// Load Accountants
void LOAD::loadAccountants(vector<Accountant>& accountants) {
    ifstream file("DataBase/Binary/accountants.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open accountants file." << endl;
        return;
    }

    Accountant a;
    while (file.read((char*)&a, sizeof(Accountant))) {
        accountants.push_back(a);
    }

    file.close();
}

// Load Clerks
void LOAD::loadClerks(vector<Clerk>& clerks) {
    ifstream file("DataBase/Binary/clerks.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open clerks file." << endl;
        return;
    }

    Clerk c;
    while (file.read((char*)&c, sizeof(Clerk))) {
        clerks.push_back(c);
    }

    file.close();
}

// Load Accounts
void LOAD::loadAccounts(vector<Account>& accounts) {
    ifstream file("DataBase/Binary/accounts.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open accounts file." << endl;
        return;
    }

    Account acc;
    while (file.read((char*)&acc, sizeof(Account))) {
        accounts.push_back(acc);
    }

    file.close();
}

// Load Transactions
void LOAD::loadTransactions(vector<Transaction>& transactions) {
    ifstream file("DataBase/Binary/transactions.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open transactions file." << endl;
        return;
    }

    Transaction t;
    while (file.read((char*)&t, sizeof(Transaction))) {
        transactions.push_back(t);
    }

    file.close();
}

// Load Customers
void LOAD::loadCustomers(vector<Customer>& customers) {
    ifstream file("DataBase/Binary/customers.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Error: Cannot open customers file." << endl;
        return;
    }

    Customer c;
    while (file.read((char*)&c, sizeof(Customer))) {
        customers.push_back(c);
    }

    file.close();
}

#endif
