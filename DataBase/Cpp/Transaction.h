#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <cstring>
#include <string>
using namespace std;

class Transaction {
private:
    char senderAccountNo[20];
    char receiverAccountNo[20];
    char title[20];     // Deposit, Withdraw, Transfer etc.
    double amount;

public:
    Transaction();

    // Setters
    void setSenderAccountNo(const char* sender);
    void setReceiverAccountNo(const char* receiver);
    void setTitle(const char* t);
    void setAmount(double amt);

    // Getters
    const char* getSenderAccountNo() const;
    const char* getReceiverAccountNo() const;
    const char* getTitle() const;
    double getAmount() const;

    // Get readable transaction history
    string getHistory() const;
};

// Constructor
Transaction::Transaction() {
    strcpy(senderAccountNo, "");
    strcpy(receiverAccountNo, "");
    strcpy(title, "");
    amount = 0.0;
}

// Setters
void Transaction::setSenderAccountNo(const char* sender) {
    strncpy(senderAccountNo, sender, sizeof(senderAccountNo));
}

void Transaction::setReceiverAccountNo(const char* receiver) {
    strncpy(receiverAccountNo, receiver, sizeof(receiverAccountNo));
}

void Transaction::setTitle(const char* t) {
    strncpy(title, t, sizeof(title));
}

void Transaction::setAmount(double amt) {
    amount = amt;
}

// Getters
const char* Transaction::getSenderAccountNo() const {
    return senderAccountNo;
}

const char* Transaction::getReceiverAccountNo() const {
    return receiverAccountNo;
}

const char* Transaction::getTitle() const {
    return title;
}

double Transaction::getAmount() const {
    return amount;
}

// getHistory function
string Transaction::getHistory() const {
    string history = "Title: " + string(title) +
                     ", Sender: " + string(senderAccountNo) +
                     ", Receiver: " + string(receiverAccountNo) +
                     ", Amount: " + to_string(amount);
    return history;
}

#endif // TRANSACTION_H
