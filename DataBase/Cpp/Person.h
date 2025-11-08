#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    char name[30];
    char cnic[20];
    char phone[15];

public:
    Person();

    void setName(const char* n);
    void setCNIC(const char* c);
    void setPhone(const char* p);
    void inputBasicInfo();
    void printBasicInfo();

    const char* getName() const;
    const char* getCNIC() const;
    const char* getPhone() const;
};

// Constructor
Person::Person() {
    strcpy(name, "");
    strcpy(cnic, "");
    strcpy(phone, "");
}
void Person::inputBasicInfo(){
    cout<<"\tEnter Name : ";
    cin>>name;
    cout<<"\tEnter CNIC : ";
    cin>>cnic;
    cout<<"\tEnter Phone : ";
    cin>>phone;
}
void Person::printBasicInfo(){
    cout<<"Name : "<<name<<endl;
    cout<<"CNIC : "<<cnic<<endl;
    cout<<"Phone : "<<phone<<endl;
    cout<<"---------------------------------\n";
}
// Setters
void Person::setName(const char* n) {
    strncpy(name, n, sizeof(name));
}

void Person::setCNIC(const char* c) {
    strncpy(cnic, c, sizeof(cnic));
}

void Person::setPhone(const char* p) {
    strncpy(phone, p, sizeof(phone));
}

// Getters
const char* Person::getName() const {
    return name;
}

const char* Person::getCNIC() const {
    return cnic;
}

const char* Person::getPhone() const {
    return phone;
}

#endif // PERSON_H
