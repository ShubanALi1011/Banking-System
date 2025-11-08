#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include<iostream>
#include <cstring>
using namespace std;

class Employee : public Person {
protected:
    int empID;
    char password[12];
    char role[20];

public:
    Employee();
    void inputEmployeeInfo();
    void printEmployeeInfo();
    void setEmpID(int id);
    void setRole(const char* r);
    void setPassword(const char* p);

    int getEmpID() const;
    virtual const char* getRole() const;
    virtual const char* getPassword() const;
};

// Implementation
Employee::Employee() : Person() {
    empID = 0;
    strcpy(role, "");
    strcpy(password, "");
}
void Employee::inputEmployeeInfo(){
    Person::inputBasicInfo();
    cout<<"\tEnter empID : ";
    cin>>empID;
    cout<<"\tEnter Password : ";
    cin>>password;
    cout<<"\tEnter Role : ";
    cin>>role;
}
void Employee::printEmployeeInfo(){
    Person::printBasicInfo();
    cout<<"EmpID : "<<empID<<endl;
    cout<<"Role : "<<role<<endl;
    cout<<"Password : "<<password<<endl;
}


void Employee::setEmpID(int id) {
    empID = id;
}

void Employee::setRole(const char* r) {
    strncpy(role, r, sizeof(role));
}

void Employee::setPassword(const char* p) {
    strncpy(password, p, sizeof(password));
}

int Employee::getEmpID() const {
    return empID;
}

const char* Employee::getRole() const {
    return role;
}

const char* Employee::getPassword() const {
    return password;
}

#endif // EMPLOYEE_H
